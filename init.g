#
# RegisterPackageTNUMDemo: Demo for RegisterPackageTNUM functionality
#
# Reading the declaration part of the package.
#
_PATH_SO:=Filename(DirectoriesPackagePrograms("RegisterPackageTNUMDemo"), "RegisterPackageTNUMDemo.so");
if _PATH_SO <> fail then
    LoadDynamicModule(_PATH_SO);
fi;
Unbind(_PATH_SO);

ReadPackage( "RegisterPackageTNUMDemo", "gap/RegisterPackageTNUMDemo.gd");
