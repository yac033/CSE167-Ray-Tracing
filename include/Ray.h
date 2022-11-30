#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_normalized_axis.hpp>
#include <math.h>


#ifndef __RAY_H__
#define __RAY_H__
class Ray {
public:
    glm::vec3 p0;
    glm::vec3 dir;
};
#endif