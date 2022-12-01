#include "Ray.h"

#include "Intersection.h"



void RayTracer::Raytrace(Camera cam, RTScene scene, Image &image)
{
    int w = image.width;
    int h = image.height;
    for (int j = 0; j < h; j++)
    {
        for (int i = 0; i < w; i++)
        {
            Ray ray = RayThruPixel(cam, i, j, w, h);
            Intersection hit = Intersect(ray, scene);
            image.pixels[j*w+i] = FindColor(hit,1);
        }
    }
}

glm::vec3 RayTracer::FindColor(Intersection hit, int recursion_depth){
    return glm::vec3({1.0f,0.0f,0.0f});
}

Intersection RayTracer::Intersect(Ray ray, RTScene scene)
{
    float mindist = INFINITY;
    Intersection hit;
    for (Triangle tri :  scene.triangle_soup)
    { // Find closest intersection; test all objects
        Intersection hit_temp = IntersectTri(ray, tri);
        if (hit_temp.dist < mindist)
        { // closer than previous hit
            mindist = hit_temp.dist;
            hit = hit_temp;
        }
    }
    return hit;
}

Intersection RayTracer::IntersectTri(Ray ray, Triangle tri){
    glm::mat4 firstMatrix = {glm::vec4(tri.P[0],1.0f),glm::vec4(tri.P[1],1.0f),glm::vec4(tri.P[2],1.0f),glm::vec4(-ray.dir,0.0f)};
    glm::vec4 secondMatrix = glm::vec4(ray.p0,1.0f);
    glm::vec4 result = glm::inverse(firstMatrix) * secondMatrix;
    Intersection q;
    if(result.x >= 0 && result.y >= 0 && result.z >= 0 && result.w >= 0){
        q.P = result.x * tri.P[0] +  result.y * tri.P[1] + result.z * tri.P[2];
        q.N = glm::normalize(result.x * tri.N[0] + result.y * tri.N[1] + result.z * tri.N[2]);
        q.V = -ray.dir;
        q.triangle = &tri;
        q.dist = result.w;
    }
    return q;
}
// void Raytrace(Camera cam, RTScene scene, Image &image);              // page 9
//     Ray RayThruPixel(Camera cam, int i, int j, int width, int height); // page 10, 18 
//     Intersection Intersect(Ray ray, Triangle triangle);         // page 30, 33
//     Intersection Intersect(Ray ray, RTScene scene);                      // page 11, 28, 31
//     glm::vec3 FindColor(Intersection hit, int recursion_depth);        // page 15