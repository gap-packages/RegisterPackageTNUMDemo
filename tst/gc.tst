#
gap> GASMAN("collect");
gap> DemoObjectsAllocated() - DemoObjectsFreed();
0

# allocate a new demo object
gap> o:=NewDemoObj(1);;
gap> DemoObjectsAllocated() - DemoObjectsFreed();
1

# since we hold a reference to the object, it won't be collected
gap> GASMAN("collect");
gap> DemoObjectsAllocated() - DemoObjectsFreed();
1

# if we drop the reference, it won't be freed immediately ...
gap> Unbind(o);
gap> DemoObjectsAllocated() - DemoObjectsFreed();
1

# ... but only after a garbage collection
gap> GASMAN("collect");
gap> DemoObjectsAllocated() - DemoObjectsFreed();
0
