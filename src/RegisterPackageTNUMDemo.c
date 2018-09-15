//
// RegisterPackageTNUMDemo: Demo for RegisterPackageTNUM functionality
//

#include "src/compiled.h"    // GAP headers

// storage for the TNUM we will register
static Int T_DEMO;

// This type is imported from the GAP level, all wrapped objects will have the
// same type
static Obj TYPE_DEMO;

static UInt demoObjectsAllocated;
static UInt demoObjectsFreed;


typedef struct {
    Obj    capacity;
    Obj    used;
    void * data;
} DemoObject;


Obj TypeDemoObj(Obj o)
{
    return TYPE_DEMO;
}

DemoObject * DEMO_OBJ(Obj o)
{
    return (DemoObject *)ADDR_OBJ(o);
}

const DemoObject * CONST_DEMO_OBJ(Obj o)
{
    return (const DemoObject *)CONST_ADDR_OBJ(o);
}

inline void SET_DEMO_CAPACITY(Obj o, Obj c)
{
    DEMO_OBJ(o)->capacity = c;
}

inline Obj GET_DEMO_CAPACITY(Obj o)
{
    return CONST_DEMO_OBJ(o)->capacity;
}

inline void SET_DEMO_USED(Obj o, Obj u)
{
    DEMO_OBJ(o)->used = u;
}

inline Obj GET_DEMO_USED(Obj o)
{
    return CONST_DEMO_OBJ(o)->used;
}

inline void SET_DEMO_OBJ(Obj o, void * b)
{
    DEMO_OBJ(o)->data = b;
}

inline void * GET_DEMO_OBJ(Obj o)
{
    return CONST_DEMO_OBJ(o)->data;
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
    demoObjectsFreed++;
    // here we could free resources: e.g. free memory allocations,
    // close file descriptors, reap child processes, etc.
    //free(GET_DEMO_OBJ(o));
}

Obj FuncNewDemoObj(Obj self, Obj c)
{
    Obj o;

    if (!IS_POS_INTOBJ(c)) {
        ErrorQuit("NewDemoObj: <capacity> must a positive small integer", 0,
                  0);
    }

    o = NewBag(T_DEMO, sizeof(DemoObject));
    demoObjectsAllocated++;

    DemoObject * data = (DemoObject *)ADDR_OBJ(o);
    SET_DEMO_CAPACITY(o, c);
    SET_DEMO_USED(o, INTOBJ_INT(0));
    //SET_DEMO_OBJ(o, malloc(INT_INTOBJ(c)));

    return o;
}

Obj FuncDemoObjCapacity(Obj self, Obj o)
{
    return GET_DEMO_CAPACITY(o);
}

Obj FuncDemoObjUsed(Obj self, Obj o)
{
    return GET_DEMO_USED(o);
}

Obj FuncDemoObjectsAllocated(Obj self)
{
    return ObjInt_UInt(demoObjectsAllocated);
}

Obj FuncDemoObjectsFreed(Obj self)
{
    return ObjInt_UInt(demoObjectsFreed);
}

// Table of functions to export
static StructGVarFunc GVarFuncs[] = {
    GVAR_FUNC(NewDemoObj, 1, "capacity"),
    GVAR_FUNC(DemoObjCapacity, 1, "demoobj"),
    GVAR_FUNC(DemoObjUsed, 1, "demoobj"),

    GVAR_FUNC(DemoObjectsAllocated, 0, ""),
    GVAR_FUNC(DemoObjectsFreed, 0, ""),

    { 0 } /* Finish with an empty entry */

};

/****************************************************************************
**
*F  InitKernel( <module> )  . . . . . . . . initialise kernel data structures
*/
static Int InitKernel(StructInitInfo * module)
{
    ImportGVarFromLibrary("TypeDemoObj", &TYPE_DEMO);

    T_DEMO = RegisterPackageTNUM("DemoTNUM", TypeDemoObj);

    InitFreeFuncBag(T_DEMO, FreeDemoObj);
    InitMarkFuncBags(T_DEMO, MarkDemoObj);

    InitHdlrFuncsFromTable(GVarFuncs);

    return 0;
}

/****************************************************************************
**
*F  InitLibrary( <module> ) . . . . . . .  initialise library data structures
*/
static Int InitLibrary(StructInitInfo * module)
{
    InitGVarFuncsFromTable(GVarFuncs);
    return 0;
}

/****************************************************************************
**
*F  InitInfopl()  . . . . . . . . . . . . . . . . . table of init functions
*/
static StructInitInfo module = {
    .type = MODULE_DYNAMIC,
    .name = "RegisterPackageTNUMDemo",
    .initKernel = InitKernel,
    .initLibrary = InitLibrary,
};

StructInitInfo * Init__Dynamic(void)
{
    return &module;
}
