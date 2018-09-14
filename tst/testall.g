#
# This file runs the package tests. It is also referenced in the package
# metadata in PackageInfo.g.
#
LoadPackage( "RegisterPackageTNUMDemo" );
TestDirectory( DirectoriesPackageLibrary("RegisterPackageTNUMDemo", "tst"), rec(exitGAP := true ) );
FORCE_QUIT_GAP(1);
