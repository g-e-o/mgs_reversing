#include "linker.h"
#include "gcl.h"
#include "mts_new.h"

GCL_CommandChain *dword_800AB3B8 = 0; //sdata

void GCL_80020B68(void);
void sub_80021264(void);
void GCL_AddBasicBuiltInCommands_8002040C(void);
int GCL_LoadData_80020064(unsigned char *);

void GV_SetFileHandler_80015418(char, void *);

int SECTION(".sbss") gGcl_main_or_demo_800AB990;

int SECTION(".sbss") dword_800AB994;

int SECTION(".sbss") dword_800AB998;

int GCL_FileHandler_8001FC88(unsigned char *pFileData, int hashedName)
{
    if (hashedName == gGcl_main_or_demo_800AB990)
    {
        GCL_LoadData_80020064(pFileData);
    }
    return 1;
}

void GCL_SetMainOrDemo_8001FCB0(int bMain)
{
    gGcl_main_or_demo_800AB990 = (bMain == 1) ? 0x6A242 : 0x6EA54;
}

void GCL_StartDaemon_8001FCDC(void)
{
    GCL_80020B68();
    sub_80021264();
    GCL_AddBasicBuiltInCommands_8002040C();
    GV_SetFileHandler_80015418('g', GCL_FileHandler_8001FC88);
    GCL_SetMainOrDemo_8001FCB0(0);
}

void GCL_Null_8001FD24(void)
{
}

int GCL_InitCommandTable_8001FD2C(GCL_CommandChain *pChain)
{
    // Set the new chains next to the existing chain
    pChain->pNext = dword_800AB3B8;

    // Update the existing chain to be the new chain
    dword_800AB3B8 = pChain;

    return 0;
}

extern const char aCommandNotFoun[];

GCL_CommandTableEntry *GCL_FindCommand_8001FD40(int hashedName)
{
    GCL_CommandTableEntry *pTableIter;
    int commandCount;
    GCL_CommandChain *pChainIter;

    for (pChainIter = dword_800AB3B8; pChainIter; pChainIter = pChainIter->pNext)
    {
        pTableIter = pChainIter->pTable;
        for (commandCount = pChainIter->commandTableSize; 0 < commandCount; commandCount--)
        {
            if (pTableIter->hashCode == hashedName)
            {
                return pTableIter;
            }
            pTableIter++;
        }
    }
    mts_printf_8008BBA0(aCommandNotFoun);
    return 0;
}

void GCL_Push_80020934(unsigned char *);
void GCL_80020690(unsigned char *);
void GCL_Pop_80020950(void);

int GCL_ExecuteCommand_8001FDB0(unsigned char *pScript)
{
    int commandRet;

    GCL_CommandTableEntry *pFoundCommand = GCL_FindCommand_8001FD40(GCL_ReadShort(pScript));
    GCL_AdvanceShort(pScript);

    GCL_Push_80020934(pScript + GCL_ReadByte(pScript));
    GCL_AdvanceByte(pScript);

    GCL_80020690(pScript); // save command return address?

    commandRet = pFoundCommand->function(pScript);

    GCL_Pop_80020950();

    return commandRet;
}

#define GCL_SwapShort(p) (((char *)p)[1]) | (((char *)p)[0] << 8)

typedef struct
{
    unsigned short procNameHashed;
    unsigned short offset;
} GCL_ProcTableEntry;

GCL_ProcTableEntry *GCL_ByteSwap_ProcTable_8001FE28(GCL_ProcTableEntry *pTable)
{
    GCL_ProcTableEntry *pIter = pTable;
    while (*(int *)pIter)
    {
        pIter->procNameHashed = GCL_SwapShort(&pIter->procNameHashed);
        pIter->offset = GCL_SwapShort(&pIter->offset);
        pIter++;
    }
    return pIter + 1;
}

typedef struct
{
    GCL_ProcTableEntry *field_0_procTable;
    unsigned char *field_4_pByteCode;
    unsigned char *field_8_pMainProc;
    unsigned char *pData2;
} GCL_FileData;

GCL_FileData SECTION(".gGCL_fileData_800B3C18") gGCL_fileData_800B3C18;
extern const char aProcXNotFound[];

unsigned char *GCL_FindProc_8001FE80(int procNameHashed)
{
    GCL_ProcTableEntry *pProcIter;
    for (pProcIter = gGCL_fileData_800B3C18.field_0_procTable; *(int *)pProcIter; pProcIter++)
    {
        if (pProcIter->procNameHashed == procNameHashed)
        {
            return gGCL_fileData_800B3C18.field_4_pByteCode + pProcIter->offset;
        }
    }
    mts_printf_8008BBA0(aProcXNotFound, procNameHashed);
    return 0;
}

void GCL_RunProc_8001FEFC(int procNameHashed, GCLArgsPtr *pArgs)
{
    GCL_Run_80020118(GCL_FindProc_8001FE80(procNameHashed) + 3, pArgs);
}

extern const char aProcDCancel[];

extern int gFlags_800AB3D0;
extern int dword_800ABA50;

int GCL_RunOrCancelProc_8001FF2C(int procId, GCLArgsPtr *param_2)
{
    if (gFlags_800AB3D0 || (dword_800ABA50 & 0x2000))
    {
        mts_printf_8008BBA0(aProcDCancel, procId);
        return 0;
    }
    return GCL_Run_80020118(GCL_FindProc_8001FE80(procId) + 3, param_2);
}

extern const char aTooManyArgsPro[];

#define GCL_MakeShort(b1, b2) ((b1) | (b2 << 8))

int GCL_RunProc_8001FFA0(unsigned char *pScript)
{
    int args[8];
    GCLArgsPtr argsPtr;
    int exec_ret;
    int readArgValue;
    int arg_idx;

    int b1 = pScript[0];
    int b2 = pScript[1];

    int procId = GCL_MakeShort(b2, b1);
    GCL_AdvanceShort(pScript);

    arg_idx = 0;

    // TODO: Can't match without comma operator ??
    while (pScript = GCL_Execute_8002069C(pScript, &exec_ret, &readArgValue), exec_ret != 0)
    {
        if (arg_idx >= 8)
        {
            mts_printf_8008BBA0(aTooManyArgsPro);
        }
        args[arg_idx++] = readArgValue;
    }

    argsPtr.count = arg_idx;
    argsPtr.pArgs = args;

    GCL_RunOrCancelProc_8001FF2C(procId, &argsPtr);
    return 0;
}

void font_set_font_addr_80044BC0(int arg1, void *data);

static inline long GCL_GetLong(char *ptr)
{
    unsigned char *p;
    p = (unsigned char *)ptr;
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | (p[3]);
}

int GCL_LoadData_80020064(unsigned char *pScript)
{
    GCL_ProcTableEntry *pTableStart;
    unsigned char *tmp;
    unsigned int len;

    pTableStart = (GCL_ProcTableEntry *)(pScript + sizeof(int));

    len = GCL_GetLong(pScript);
    gGCL_fileData_800B3C18.field_0_procTable = pTableStart;
    gGCL_fileData_800B3C18.field_4_pByteCode = (char *)GCL_ByteSwap_ProcTable_8001FE28(pTableStart);
    tmp = ((char *)gGCL_fileData_800B3C18.field_0_procTable) + len;
    gGCL_fileData_800B3C18.field_8_pMainProc = tmp + sizeof(int);

    // Points to script data end
    font_set_font_addr_80044BC0(2, gGCL_fileData_800B3C18.field_8_pMainProc + GCL_GetLong(tmp) + sizeof(int));

    return 0;
}

int *GCL_PushArgs_8002087C(GCLArgsPtr *pArgs);
void GCL_SetStackPointer_800208F0(int *pStack);
void GCL_8002058C(unsigned char *pScript, void *ptr);

extern const char aScriptCommandE[];
extern const char aErrorInScript[];

int GCL_Run_80020118(unsigned char *pScript, GCLArgsPtr *pArgs)
{
    int *pOldStack = GCL_PushArgs_8002087C(pArgs);
    while (pScript)
    {
        switch (*pScript)
        {
        // ??
        case 0x30:
        {
            int auStack24[2]; // TODO: probably an arg pair ??
            GCL_8002058C(pScript + 2, auStack24);
            pScript++;
            pScript += *pScript;
        }
        break;

        // Command
        case 0x60:
            if (GCL_ExecuteCommand_8001FDB0(pScript + 3) == 1)
            {
                return 1;
            }

            pScript++;
            pScript += (short)GCL_MakeShort(pScript[1], pScript[0]);
            break;

        // Call
        case 0x70:
            GCL_RunProc_8001FFA0(pScript + 2);
            pScript++;
            pScript += *pScript;
            break;

        // Return ?
        case 0x0:
            GCL_SetStackPointer_800208F0(pOldStack);
            return 0;

        default:
            mts_printf_8008BBA0(aScriptCommandE, (unsigned int)*pScript);
        }
    }
    mts_printf_8008BBA0(aErrorInScript);
    return 1;
}

extern const char aNotScriptData[];
extern GCLArgsPtr gGCL_NullArgs_800AB3BC;

void GCL_RunMainProc_80020228(unsigned char* param_1, int param_2)
{
    unsigned char *pMainProc = gGCL_fileData_800B3C18.field_8_pMainProc;
    if (*pMainProc != 0x40)
    {
        mts_printf_8008BBA0(aNotScriptData);
    }
    GCL_Run_80020118(pMainProc + 3, &gGCL_NullArgs_800AB3BC);
}
