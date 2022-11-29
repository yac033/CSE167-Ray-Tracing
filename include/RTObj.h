/**************************************************
Obj is subclass class of Geometry
that loads an obj file.
*****************************************************/
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "Geometry.h"
#ifndef __RTOBJ_H__
#define __RTOBJ_H__

class RTObj : public RTGeometry {
public:

    void init(const char * filename);
        
};

#endif 