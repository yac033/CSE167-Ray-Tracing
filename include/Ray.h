#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_normalized_axis.hpp>
#include <math.h>
#include "Intersection.h"
#include "Camera.h"
#include "Image.h"
#include "RTScene.h"


#ifndef __RAY_H__
#define __RAY_H__
class Ray {
public:
    glm::vec3 p0;
    glm::vec3 dir;
};

namespace RayTracer {
    void Raytrace(Camera cam, RTScene scene, Image &image);              // page 9
    Ray RayThruPixel(Camera cam, int i, int j, int width, int height); // page 10, 18 
    Intersection IntersectTri(Ray ray, Triangle triangle);         // page 30, 33
    Intersection Intersect(Ray ray, RTScene scene);                      // page 11, 28, 31
    glm::vec3 FindColor(Intersection hit, int recursion_depth, RTScene scene);        // page 15
    glm::vec3 Lightening(Intersection hit, RTScene scene);
};
#endif