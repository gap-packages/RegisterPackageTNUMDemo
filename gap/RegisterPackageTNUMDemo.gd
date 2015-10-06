#
# RegisterPackageTNUMDemo: Demo for RegisterPackageTNUM functionality
#
# Declarations
#

DeclareCategory( "IsDemoObject", IsObject );

#! @Description
#!    Family of DemoObj
BindGlobal( "DemoObjFamily", NewFamily("DemoObjFamily") );

#! @Description
#!    Type of DemoObj
BindGlobal( "TypeDemoObj", NewType(DemoObjFamily, IsDemoObject) );
