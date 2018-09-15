#
# RegisterPackageTNUMDemo: Demo for RegisterPackageTNUM functionality
#
# Implementations
#

InstallMethod(PrintObj , "for a demo project", [ IsDemoObject ],
function(o)
    Print("<a demo object of size ",
          DemoObjUsed(o), "/",
          DemoObjCapacity(o), ">");
end );

