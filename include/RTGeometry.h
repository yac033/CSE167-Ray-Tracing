/**************************************************
Geometry is an abstract class for a geometric object.
 A derived class of Geometry will have an implemention of
   ```void init(void)```
 or
   ```void init(const char* s).```
 The option for const char* input is for a derived class
 that requires reading external files.
 The implementation of the `init` is for initializing the
 geometry (i.e. setting up the buffers etc).
 
 The draw command is fixed.  We can call
 
 glBindVertexArray(obj.vao);
 glDrawElements(obj.mode, obj.count, obj.type, 0);
 
which should explain the purpose of those class members.
 We can also just call the "draw()" member function, which
 is equivalent to the commands above.
 
The array of buffers is encapsulated in std::vector so
we do not need to manually allocate/free the memory for
arrays of unknown size.
*****************************************************/
#include <vector>
#include "Triangle.h"
#ifndef __RTGEOMETRY_H__
#define __RTGEOMETRY_H__
class RTGeometry {
public:
  int count;                      // number of elements to draw
  std::vector<Triangle> elements; // list of triangles
  virtual void init(){};
  virtual void init(const char *s){};
};
#endif
