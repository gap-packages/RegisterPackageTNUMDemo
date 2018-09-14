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

inline void SET_DEMO_CAPACITY(Obj o, Obj c)
{
    ADDR_OBJ(o)[0] = c;
}

inline Obj GET_DEMO_CAPACITY(Obj o)
{
    return ADDR_OBJ(o)[0];
}

inline void SET_DEMO_USED(Obj o, Obj u)
{
    ADDR_OBJ(o)[1] = u;
}

inline Obj GET_DEMO_USED(Obj o)
{
    return ADDR_OBJ(o)[1];
}

inline void SET_DEMO_OBJ(Obj o, void *b)
{
    ADDR_OBJ(o)[2] = b;
}

inline void *GET_DEMO_OBJ(Obj o)
{
    return ADDR_OBJ(o)[2];
}


/*
 * Garbage collector
 */
void MarkDemoObj(Bag o)
{
    MarkBag(GET_DEMO_CAPACITY(o));
    MarkBag(GET_DEMO_USED(o));
}

void FreeDemoObj(Obj o)
{
    free(GET_DEMO_OBJ(o));
}

Obj NewDemoObj(Obj self, Obj c)
{
    Obj o;

    if(!IS_INTOBJ(c)) {
        ErrorQuit( "Usage: NewDemoObj(integer)", 0L, 0L);
    }
    o = NewBag(T_DEMO, 2*sizeof(Obj));

    SET_DEMO_CAPACITY(o, c);
    SET_DEMO_USED(o, INTOBJ_INT(0u));
    SET_DEMO_OBJ(o, malloc(INT_INTOBJ(c)));

    return o;
}

Obj DemoObjCapacity(Obj self, Obj o)
{
    return GET_DEMO_CAPACITY(o);
}

Obj DemoObjUsed(Obj self, Obj o)
{
    return GET_DEMO_USED(o);
}

typedef Obj (* GVarFunc)(/*arguments*/);

#define GVAR_FUNC_TABLE_ENTRY(srcfile, name, nparam, params) \
  {#name, nparam, \
   params, \
   (GVarFunc)name, \
   srcfile ":Func" #name }

// Table of functions to export
static StructGVarFunc GVarFuncs [] = {
    GVAR_FUNC_TABLE_ENTRY("RegisterPackageTNUMDemo.c", NewDemoObj, 1, ""),
    GVAR_FUNC_TABLE_ENTRY("RegisterPackageTNUMDemo.c", DemoObjCapacity, 1, "demoobj"),
    GVAR_FUNC_TABLE_ENTRY("RegisterPackageTNUMDemo.c", DemoObjUsed, 1, "demoobj"),

  { 0 } /* Finish with an empty entry */

};

/******************************************************************************
*F  InitKernel( <module> )  . . . . . . . . initialise kernel data structures
*/
static Int InitKernel( StructInitInfo *module )
{
    ImportGVarFromLibrary("TypeDemoObj", &TYPE_DEMO);

    T_DEMO = RegisterPackageTNUM("DemoTNUM", TypeDemoObj);

    InitFreeFuncBag(T_DEMO, FreeDemoObj);
    InitMarkFuncBags(T_DEMO, MarkDemoObj);

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
    .type = MODULE_DYNAMIC,
    .name = "RegisterPackageTNUMDemo",
    .initKernel = InitKernel,
    .initLibrary = InitLibrary,
};

StructInitInfo * Init__Dynamic ( void )
{
    return &module;
}
