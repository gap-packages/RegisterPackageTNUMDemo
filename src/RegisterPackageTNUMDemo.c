/*
 * RegisterPackageTNUMDemo: Demo for RegisterPackageTNUM functionality
 */

#include "src/compiled.h"          /* GAP headers */

Int T_DEMO;

/* This type is imported from the GAP level, all wrapped objects
   will have the same type
 */
Obj TYPE_DEMO;
Obj TypeDemoObj(Obj o)
{
    return TYPE_DEMO;
}

void MarkDemoObj(Obj o)
{
}

void SweepDemoObj(Bag *src, Bag *dst, UInt len)
{
}

Obj NewDemoObj(Obj self)
{
    Obj o;
    void *m;

    o = NewBag(T_DEMO, 4096);

    return o;
}

Obj InfoDemoObj(Obj self, Obj o)
{
    /* simply return the first parameter */
    return o;
}


typedef Obj (* GVarFunc)(/*arguments*/);

#define GVAR_FUNC_TABLE_ENTRY(srcfile, name, nparam, params) \
  {#name, nparam, \
   params, \
   (GVarFunc)name, \
   srcfile ":Func" #name }

// Table of functions to export
static StructGVarFunc GVarFuncs [] = {
    GVAR_FUNC_TABLE_ENTRY("RegisterPackageTNUMDemo.c", NewDemoObj, 0, ""),
    GVAR_FUNC_TABLE_ENTRY("RegisterPackageTNUMDemo.c", InfoDemoObj, 1, "demoobj"),

	{ 0 } /* Finish with an empty entry */

};

/******************************************************************************
*F  InitKernel( <module> )  . . . . . . . . initialise kernel data structures
*/
static Int InitKernel( StructInitInfo *module )
{
    ImportGVarFromLibrary("TypeDemoObj", &TYPE_DEMO);

    T_DEMO = RegisterPackageTNUM("DemoTNUM", TypeDemoObj);

    InitMarkFuncBags(T_DEMO, MarkDemoObj);
    InitSweepFuncBags(T_DEMO, SweepDemoObj);

    /* init filters and functions */
    InitHdlrFuncsFromTable( GVarFuncs );

    /* return success */
    return 0;
}

/******************************************************************************
*F  InitLibrary( <module> ) . . . . . . .  initialise library data structures
*/
static Int InitLibrary( StructInitInfo *module )
{

    /* init filters and functions */
    InitGVarFuncsFromTable( GVarFuncs );

    /* return success                                                      */
    return 0;
}

/******************************************************************************
*F  InitInfopl()  . . . . . . . . . . . . . . . . . table of init functions
*/
static StructInitInfo module = {
 /* type        = */ MODULE_DYNAMIC,
 /* name        = */ "RegisterPackageTNUMDemo",
 /* revision_c  = */ 0,
 /* revision_h  = */ 0,
 /* version     = */ 0,
 /* crc         = */ 0,
 /* initKernel  = */ InitKernel,
 /* initLibrary = */ InitLibrary,
 /* checkInit   = */ 0,
 /* preSave     = */ 0,
 /* postSave    = */ 0,
 /* postRestore = */ 0
};

StructInitInfo * Init__Dynamic ( void )
{
    return &module;
}
