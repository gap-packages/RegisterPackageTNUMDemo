#
# RegisterPackageTNUMDemo: Demo for RegisterPackageTNUM functionality
#
# This file contains package meta data. For additional information on
# the meaning and correct usage of these fields, please consult the
# manual of the "Example" package as well as the comments in its
# PackageInfo.g file.
#
SetPackageInfo( rec(

PackageName := "RegisterPackageTNUMDemo",
Subtitle := "Demo for RegisterPackageTNUM functionality",
Version := "0.2",
Date := "14/09/2018", # dd/mm/yyyy format
License := "GPL-2.0-or-later",

Persons := [
  rec(
    LastName      := "Pfeiffer",
    FirstNames    := "Markus",
    IsAuthor      := true,
    IsMaintainer  := true,
    Email         := "markus.pfeiffer@st-andrews.ac.uk",
    WWWHome       := "https://www.morphism.de/~markusp",
    PostalAddress := Concatenation(
                       "School of Computer Science\n",
                       "University of St Andrews\n",
                       "Jack Cole Building, North Haugh\n",
                       "St Andrews, Fife, KY16 9SX\n",
                       "United Kingdom" ),
    Place         := "St Andrews",
    Institution   := "University of St Andrews"
  ),
  rec(
    LastName      := "Horn",
    FirstNames    := "Max",
    IsAuthor      := true,
    IsMaintainer  := true,
    Email         := "horn@mathematik.uni-kl.de",
    WWWHome       := "https://www.quendi.de/math",
    PostalAddress := Concatenation(
                       "Fachbereich Mathematik\n",
                       "TU Kaiserslautern\n",
                       "Gottlieb-Daimler-Straße 48\n",
                       "67663 Kaiserslautern\n",
                       "Germany" ),
    Place         := "Kaiserslautern, Germany",
    Institution   := "TU Kaiserslautern"
  ),
],

PackageWWWHome := "https://gap-packages.github.io/RegisterPackageTNUMDemo/",

ArchiveURL     := Concatenation("https://github.com/gap-packages/RegisterPackageTNUMDemo/",
                                "releases/download/v", ~.Version,
                                "/RegisterPackageTNUMDemo-", ~.Version),
README_URL     := Concatenation( ~.PackageWWWHome, "README.md" ),
PackageInfoURL := Concatenation( ~.PackageWWWHome, "PackageInfo.g" ),
SourceRepository := rec( 
  Type := "git", 
  URL := "https://github.com/gap-packages/RegisterPackageTNUMDemo"
),
IssueTrackerURL := Concatenation( ~.SourceRepository.URL, "/issues" ),
ArchiveFormats := ".tar.gz",

##  Status information. Currently the following cases are recognized:
##    "accepted"      for successfully refereed packages
##    "submitted"     for packages submitted for the refereeing
##    "deposited"     for packages for which the GAP developers agreed
##                    to distribute them with the core GAP system
##    "dev"           for development versions of packages
##    "other"         for all other packages
##
Status := "dev",

AbstractHTML   :=  "",

PackageDoc := rec(
  BookName  := "RegisterPackageTNUMDemo",
  ArchiveURLSubset := ["doc"],
  HTMLStart := "doc/chap0_mj.html",
  PDFFile   := "doc/manual.pdf",
  SixFile   := "doc/manual.six",
  LongTitle := "Demo for RegisterPackageTNUM functionality",
),

Dependencies := rec(
  GAP := ">= 4.9",
  NeededOtherPackages := [ ],
  SuggestedOtherPackages := [ ],
  ExternalConditions := [ ],
),

AvailabilityTest := function()
        return true;
    end,

TestFile := "tst/testall.g",

#Keywords := [ "TODO" ],

));


