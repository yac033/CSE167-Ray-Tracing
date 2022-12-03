/**************************************************
Cube is subclass class of Geometry
that represents a 3D cube.
*****************************************************/
#include "RTGeometry.h"
#ifndef __RTCUBE_H__
#define __RTCUBE_H__

class RTCube : public RTGeometry {
public:

    void init(void){
    //     Triangle FF1;
    //     FF1.P.push_back({-0.5f,-0.5f,0.5f});
    //     FF1.P.push_back({0.5f,-0.5f,0.5f});
    //     FF1.P.push_back({0.5f,0.5f,0.5f});
    //     FF1.N.push_back({ 0.0f, 0.0f, 1.0f });
    //     FF1.N.push_back({ 0.0f, 0.0f, 1.0f });
    //     FF1.N.push_back({ 0.0f, 0.0f, 1.0f });
    //     elements.push_back(FF1);
    //     Triangle FF2;
    //     FF2.P.push_back({-0.5f,-0.5f,0.5f});
    //     FF2.P.push_back({-0.5f,0.5f,0.5f});
    //     FF2.P.push_back({0.5f,0.5f,0.5f});
    //     FF2.N.push_back({ 0.0f, 0.0f, 1.0f });
    //     FF2.N.push_back({ 0.0f, 0.0f, 1.0f });
    //     FF2.N.push_back({ 0.0f, 0.0f, 1.0f });
    //     elements.push_back(FF2);
    //     Triangle BF1;
    //     BF1.P.push_back({-0.5f,-0.5f,-0.5f});
    //     BF1.P.push_back({0.5f,-0.5f,-0.5f});
    //     BF1.P.push_back({0.5f,0.5f,-0.5f});
    //     BF1.N.push_back({ 0.0f, 0.0f, -1.0f });
    //     BF1.N.push_back({ 0.0f, 0.0f, -1.0f });
    //     BF1.N.push_back({ 0.0f, 0.0f, -1.0f });
    //     elements.push_back(BF1);
    //     Triangle BF2;
    //     BF2.P.push_back({-0.5f,-0.5f,-0.5f});
    //     BF2.P.push_back({-0.5f,0.5f,-0.5f});
    //     BF2.P.push_back({0.5f,0.5f,-0.5f});
    //     BF2.N.push_back({ 0.0f, 0.0f, -1.0f });
    //     BF2.N.push_back({ 0.0f, 0.0f, -1.0f });
    //     BF2.N.push_back({ 0.0f, 0.0f, -1.0f });
    //     elements.push_back(BF2);
    //     Triangle LF1;
    //     LF1.P.push_back({-0.5f,-0.5f,0.5f});
    //     LF1.P.push_back({-0.5f,-0.5f,-0.5f});
    //     LF1.P.push_back({-0.5f,0.5f,-0.5f});
    //     LF1.N.push_back({ -1.0f, 0.0f, 0.0f });
    //     LF1.N.push_back({ -1.0f, 0.0f, 0.0f });
    //     LF1.N.push_back({ -1.0f, 0.0f, 0.0f });
    //     elements.push_back(LF1);
    //     Triangle LF2;
    //     LF2.P.push_back({-0.5f,-0.5f,0.5f});
    //     LF2.P.push_back({-0.5f,0.5f,0.5f});
    //     LF2.P.push_back({-0.5f,0.5f,-0.5f});
    //     LF2.N.push_back({ -1.0f, 0.0f, 0.0f });
    //     LF2.N.push_back({ -1.0f, 0.0f, 0.0f });
    //     LF2.N.push_back({ -1.0f, 0.0f, 0.0f });
    //     elements.push_back(LF2);
    //     Triangle RF1;
    //     RF1.P.push_back({0.5f,-0.5f,0.5f});
    //     RF1.P.push_back({0.5f,-0.5f,-0.5f});
    //     RF1.P.push_back({0.5f,0.5f,-0.5f});
    //     RF1.N.push_back({ 1.0f, 0.0f, 0.0f });
    //     RF1.N.push_back({ 1.0f, 0.0f, 0.0f });
    //     RF1.N.push_back({ 1.0f, 0.0f, 0.0f });
    //     elements.push_back(RF1);
    //     Triangle RF2;
    //     RF2.P.push_back({0.5f,-0.5f,0.5f});
    //     RF2.P.push_back({0.5f,0.5f,0.5f});
    //     RF2.P.push_back({0.5f,0.5f,-0.5f});
    //     RF2.N.push_back({ 1.0f, 0.0f, 0.0f });
    //     RF2.N.push_back({ 1.0f, 0.0f, 0.0f });
    //     RF2.N.push_back({ 1.0f, 0.0f, 0.0f });
    //     elements.push_back(RF2);
    //     Triangle TF1;
    //     TF1.P.push_back({-0.5f,0.5f,0.5f});
    //     TF1.P.push_back({0.5f,0.5f,0.5f});
    //     TF1.P.push_back({0.5f,0.5f,-0.5f});
    //     TF1.N.push_back({ 0.0f, 1.0f, 0.0f });
    //     TF1.N.push_back({ 0.0f, 1.0f, 0.0f });
    //     TF1.N.push_back({ 0.0f, 1.0f, 0.0f });
    //     elements.push_back(TF1);
    //     Triangle TF2;
    //     TF2.P.push_back({-0.5f,0.5f,0.5f});
    //     TF2.P.push_back({-0.5f,0.5f,-0.5f});
    //     TF2.P.push_back({0.5f,0.5f,-0.5f});
    //     TF2.N.push_back({ 0.0f, 1.0f, 0.0f });
    //     TF2.N.push_back({ 0.0f, 1.0f, 0.0f });
    //     TF2.N.push_back({ 0.0f, 1.0f, 0.0f });
    //     elements.push_back(TF2);
    //     Triangle BTF1;
    //     BTF1.P.push_back({-0.5f,-0.5f,0.5f});
    //     BTF1.P.push_back({0.5f,-0.5f,0.5f});
    //     BTF1.P.push_back({0.5f,-0.5f,-0.5f});
    //     BTF1.N.push_back({ 0.0f, -1.0f, 0.0f });
    //     BTF1.N.push_back({ 0.0f, -1.0f, 0.0f });
    //     BTF1.N.push_back({ 0.0f, -1.0f, 0.0f });
    //     elements.push_back(BF1);
    //     Triangle BTF2;
    //     BTF2.P.push_back({-0.5f,-0.5f,0.5f});
    //     BTF2.P.push_back({-0.5f,-0.5f,-0.5f});
    //     BTF2.P.push_back({0.5f,-0.5f,-0.5f});
    //     BTF2.N.push_back({ 0.0f, -1.0f, 0.0f });
    //     BTF2.N.push_back({ 0.0f, -1.0f, 0.0f });
    //     BTF2.N.push_back({ 0.0f, -1.0f, 0.0f });
    //     elements.push_back(BF2);
    // }
        const GLfloat positions[24][3] ={
            // Front face
            { -0.5f, -0.5f, 0.5f },{ -0.5f, 0.5f, 0.5f },{ 0.5f, 0.5f, 0.5f },{ 0.5f, -0.5f, 0.5f },
            // Back face
            { -0.5f, -0.5f, -0.5f },{ -0.5f, 0.5f, -0.5f },{ 0.5f, 0.5f, -0.5f },{ 0.5f, -0.5f, -0.5f },
            // Left face
            { -0.5f, -0.5f, 0.5f },{ -0.5f, 0.5f, 0.5f },{ -0.5f, 0.5f, -0.5f },{ -0.5f, -0.5f, -0.5f },
            // Right face
            { 0.5f, -0.5f, 0.5f },{ 0.5f, 0.5f, 0.5f },{ 0.5f, 0.5f, -0.5f },{ 0.5f, -0.5f, -0.5f },
            // Top face
            { 0.5f, 0.5f, 0.5f },{ -0.5f, 0.5f, 0.5f },{ -0.5f, 0.5f, -0.5f },{ 0.5f, 0.5f, -0.5f },
            // Bottom face
            { 0.5f, -0.5f, 0.5f },{ -0.5f, -0.5f, 0.5f },{ -0.5f, -0.5f, -0.5f },{ 0.5f, -0.5f, -0.5f }
        };
        // vertex normals
        const GLfloat normals[24][3] = {
            // Front face
            { 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },
            // Back face
            { 0.0f, 0.0f, -1.0f },{ 0.0f, 0.0f, -1.0f },{ 0.0f, 0.0f, -1.0f },{ 0.0f, 0.0f, -1.0f },
            // Left face
            { -1.0f, 0.0f, 0.0f },{ -1.0f, 0.0f, 0.0f },{ -1.0f, 0.0f, 0.0f },{ -1.0f, 0.0f, 0.0f },
            // Right face
            { 1.0f, 0.0f, 0.0f },{ 1.0f, 0.0f, 0.0f },{ 1.0f, 0.0f, 0.0f },{ 1.0f, 0.0f, 0.0f },
            // Top face
            { 0.0f, 1.0f, 0.0f },{ 0.0f, 1.0f, 0.0f },{ 0.0f, 1.0f, 0.0f },{ 0.0f, 1.0f, 0.0f },
            // Bottom face
            { 0.0f, -1.0f, 0.0f },{ 0.0f, -1.0f, 0.0f },{ 0.0f, -1.0f, 0.0f },{ 0.0f, -1.0f, 0.0f }
        };
        // Cube indices
        const GLuint indices[36] = {
            0, 1, 2, 0, 2, 3, // Front face
            4, 5, 6, 4, 6, 7, // Back face
            8, 9, 10, 8, 10, 11, // Left face
            12, 13, 14, 12, 14, 15, // Right face
            16, 17, 18, 16, 18, 19, // Top face
            20, 21, 22, 20, 22, 23 // Bottom face
        };
        for(int i = 0; i < 24;i++){
            Triangle temp_tri1;
            Triangle temp_tri2;
            temp_tri1.P.push_back({positions[i][0],positions[i][1],positions[i][2]});
            temp_tri1.P.push_back({positions[i+1][0],positions[i+1][1],positions[i+1][2]});
            temp_tri1.P.push_back({positions[i+2][0],positions[i+2][1],positions[i+2][2]});
            temp_tri2.P.push_back({positions[i+1][0],positions[i+1][1],positions[i+1][2]});
            temp_tri2.P.push_back({positions[i+2][0],positions[i+2][1],positions[i+2][2]});
            temp_tri2.P.push_back({positions[i+3][0],positions[i+3][1],positions[i+3][2]});
            temp_tri1.N.push_back({normals[i][0],normals[i][1],normals[i][2]});
            temp_tri1.N.push_back({normals[i+1][0],normals[i+1][1],normals[i+1][2]});
            temp_tri1.N.push_back({normals[i+2][0],normals[i+2][1],normals[i+2][2]});
            temp_tri2.N.push_back({normals[i+1][0],normals[i+1][1],normals[i+1][2]});
            temp_tri2.N.push_back({normals[i+2][0],normals[i+2][1],normals[i+2][2]});
            temp_tri2.N.push_back({normals[i+3][0],normals[i+3][1],normals[i+3][2]});
            elements.push_back(temp_tri1);
            elements.push_back(temp_tri2);
            i += 3;
        }

        // std::cout << elements.size() << std::endl;
        // for(Triangle tri : elements){
        //     std::cout << "(" << tri.P[0].x << ", " << tri.P[0].y << ", " << tri.P[0].z << "), (" << tri.P[1].x << ", " << tri.P[1].y << ", " << tri.P[1].z << ") , (" << tri.P[2].x << ", " << tri.P[2].y << ", " << tri.P[2].z << ") " << std::endl;
            
        // }
    }
};

#endif 
