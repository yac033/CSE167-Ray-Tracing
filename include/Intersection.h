#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_normalized_axis.hpp>
#include <math.h>
#include "Triangle.h"

#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__
class Intersection {
public:
    glm::vec3 P;
    glm::vec3 N;
    glm::vec3 V;
    Triangle* triangle;
    float dist;
    Intersection(){
        P = glm::vec3(0.0f);
        N = glm::vec3(0.0f);
        V = glm::vec3(0.0f);
        dist = INFINITY;
        triangle = nullptr;
    }
};

#endif