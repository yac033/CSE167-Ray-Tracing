#include "Ray.h"
#include "Intersection.h"
int MAX_RECURSION_DEPTH = 5;
void RayTracer::Raytrace(Camera cam, RTScene scene, Image &image)
{
    int w = image.width;
    int h = image.height;
    for (int j = 0; j < h; j++)
    {
        for (int i = 0; i < w; i++)
        {
            // std::cout << "new ray" << std::endl;

            Ray ray = RayThruPixel(cam, i, j, w, h);

            Intersection hit = Intersect(ray, scene);
            image.pixels[j * w + i] = FindColor(hit, 1, scene);
        }
        std::cout << j << std::endl;
    }
}

glm::vec3 RayTracer::FindColor(Intersection hit, int recursion_depth, RTScene scene)
{
    glm::vec3 color = glm::vec3({0.3f,0.1f,0.3f});
    if (recursion_depth >= MAX_RECURSION_DEPTH){
        return  color;
    }
    // if hit is less than infinity
    if (hit.dist > -1) //if (hit.dist < INFINITY)
    {
        // for loop for color 
        for (int i = 0; i < scene.shader->nlights; i++){
            color += glm::vec3(hit.triangle.material->diffuse) * glm::vec3(scene.shader->lightcolors[i]) * glm::max(glm::dot(hit.N, glm::vec3(scene.shader->lightpositions[i])), 0.0f);
        }
        // color += glm::vec3(hit.triangle.material->specular) * Lightening(hit, scene);
        /* recursive iterate the light position*/
        for(int i = 0; i < scene.shader->nlights; i++){
            Ray second_ray;
            // second_ray.p0 = hit.P * 1.03f; // glm::vec3(0.0f,0.0f,0.0f);
            second_ray.p0 = hit.P + (hit.triangle.N[0]*0.03f);
            second_ray.dir = glm::normalize(glm::vec3(scene.shader->lightpositions[i]) - hit.P);
            Intersection second_hit = Intersect(second_ray, scene);
            
            if (second_hit.dist == -1) //if (second_hit.dist == INFINITY)
            {
                // reflection: Generate mirror-reflected ray
                Ray reflect_ray;
                // reflect_ray.p0 = hit.P * 1.03f;
                reflect_ray.p0 = hit.P + (hit.triangle.N[0]*0.03f);
                reflect_ray.dir = (2 * glm::dot(hit.N, hit.V)*hit.N) - hit.V;
                Intersection hit2 = Intersect(reflect_ray, scene);
                glm::vec3 shader_model = FindColor(hit2, recursion_depth + 1, scene);
                color += glm::vec3(hit.triangle.material->specular) * shader_model;
            }
            // shadow here
            else
            {
                // color = glm::vec3(0.0f, 0.0f, 0.0f);
                color = glm::vec3(hit.triangle.material->ambient);
            }   
        }            
    }
    return color;
}

// glm::vec3 RayTracer::Lightening(Intersection hit, RTScene scene)
// {
//     // change coordinate from model to camera
//     // n' = normalize(A^-T * n)
//     glm::mat4 modelview = scene.shader->modelview;
//     glm::mat4 view = scene.shader->view;
//     glm::vec3 normal = hit.N;
//     glm::vec3 position = hit.P;
//     int nlights = scene.light.size();
    
//     glm::vec4 ambient = hit.triangle.material->ambient;
//     glm::vec4 diffuse = hit.triangle.material->diffuse;
//     glm::vec4 specular = hit.triangle.material->specular;
//     float shininess = hit.triangle.material->shininess;
    
//     glm::vec4 emission = hit.triangle.material->emision;
//     std::vector<glm::vec4> lightpositions = scene.shader->lightpositions;
 
//     std::vector<glm::vec4> lightcolors = scene.shader->lightcolors;

//     glm::mat3 A = glm::mat3(modelview[0][0], modelview[0][1], modelview[0][2],
//                   modelview[1][0], modelview[1][1], modelview[1][2],
//                   modelview[2][0], modelview[2][1], modelview[2][2]);

//     glm::mat3 A_inverse = inverse(transpose(A));
//     glm::vec3 normal_cam = normalize(A_inverse * normal);
    
//     // change position from world to world
//     glm::vec4 new_position = glm::vec4(position,1);

//     glm::vec3 v = -1.0f * glm::normalize(glm::vec3(new_position) / new_position.w);
    
//     glm::vec4 sum = glm::vec4(0);
//     // HW3: You will compute the lighting here.
//     for (int i = 0; i < nlights; i++)
//     {

//         // change light from world to world
//         glm::vec4 new_light = lightpositions[i];

//         glm::vec3 d = normalize(new_position[3] * glm::vec3(new_light) - new_light[3] * glm::vec3(new_position));

//         glm::vec3 h = normalize(d + v);

//         sum += lightcolors[i] *
//                (ambient +
//                 (diffuse * glm::max(dot(normal_cam, d), 0.0f)) +
//                 (specular * pow(glm::max(dot(normal_cam, h), 0.0f), shininess)));
//     }
//     return glm::vec3(emission + sum);
// }

Intersection RayTracer::Intersect(Ray ray, RTScene scene)
{
    float mindist = INFINITY;
    Intersection hit;

    for (Triangle tri : scene.triangle_soup)
    { // Find closest intersection; test all objects
        // std::cout << "new triangle" << std::endl;
        
        Intersection hit_temp = IntersectTri(ray, tri);
        // std::cout << hit_temp.dist << std::endl;
        if (hit_temp.dist < mindist)
        { // closer than previous hit
            if (hit_temp.dist != -1)
            {
                mindist = hit_temp.dist;
                // hit.dist = hit_temp.dist;
                // hit.N = hit_temp.N;
                // hit.P = hit_temp.P;
                // hit.V = hit_temp.V;
                // hit.triangle = hit_temp.triangle;
                hit = hit_temp;

            }
        }
    }
    return hit;
}

Intersection RayTracer::IntersectTri(Ray ray, Triangle tri)
{

    glm::mat4 firstMatrix = {glm::vec4(tri.P[0], 1.0f), glm::vec4(tri.P[1], 1.0f), glm::vec4(tri.P[2], 1.0f), glm::vec4(-ray.dir, 0.0f)};
    glm::vec4 secondMatrix = glm::vec4(ray.p0, 1.0f);
    glm::vec4 result = glm::inverse(firstMatrix) * secondMatrix;
    
    Intersection q;
    
    if (result.x >= 0 && result.y >= 0 && result.z >= 0 && result.w >= 0)
    {
        
        q.P = result.x * tri.P[0] + result.y * tri.P[1] + result.z * tri.P[2];

        q.N = glm::normalize(result.x * tri.N[0] + result.y * tri.N[1] + result.z * tri.N[2]);
        q.V = -ray.dir;
        q.triangle = tri;
        q.dist = result.w;
        
        return q;
    }else{
        
    }
    // std::cout << result.x << " " << result.y << " " << result.z << std::endl;
    return q;
}

Ray RayTracer::RayThruPixel(Camera cam, int i, int j, int width, int height)
{
    glm::vec3 w = glm::normalize(cam.eye - cam.target);
    glm::vec3 u = glm::normalize(glm::cross(cam.up,w));
    glm::vec3 v = glm::cross(w, u);
    float a = width / height * 1.0f;
    float fovy = cam.fovy * M_PI / 180.0f;
    float alpha = 2 * ((i + 0.5f) / width) - 1;
    float beta = -(1 - 2 * ((j + 0.5f) / height));
    Ray ret;
    ret.p0 = cam.eye;
    ret.dir = glm::vec3(alpha * a * tan(fovy * 0.5f) * u + beta * tan(fovy * 0.5f) * v - w);
    ret.dir = glm::normalize(ret.dir);
    return ret;
}
// void Raytrace(Camera cam, RTScene scene, Image &image);              // page 9
//     Ray RayThruPixel(Camera cam, int i, int j, int width, int height); // page 10, 18
//     Intersection Intersect(Ray ray, Triangle triangle);         // page 30, 33
//     Intersection Intersect(Ray ray, RTScene scene);                      // page 11, 28, 31
//     glm::vec3 FindColor(Intersection hit, int recursion_depth);        // page 15