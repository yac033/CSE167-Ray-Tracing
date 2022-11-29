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
        Triangle FF1;
        FF1.P.push_back({-0.5f,-0.5f,0.5f});
        FF1.P.push_back({0.5f,-0.5f,0.5f});
        FF1.P.push_back({0.5f,0.5f,0.5f});
        FF1.N.push_back({ 0.0f, 0.0f, 1.0f });
        FF1.N.push_back({ 0.0f, 0.0f, 1.0f });
        FF1.N.push_back({ 0.0f, 0.0f, 1.0f });
        elements.push_back(FF1);
        Triangle FF2;
        FF2.P.push_back({-0.5f,-0.5f,0.5f});
        FF2.P.push_back({-0.5f,0.5f,0.5f});
        FF2.P.push_back({0.5f,0.5f,0.5f});
        FF2.N.push_back({ 0.0f, 0.0f, 1.0f });
        FF2.N.push_back({ 0.0f, 0.0f, 1.0f });
        FF2.N.push_back({ 0.0f, 0.0f, 1.0f });
        elements.push_back(FF2);
        Triangle BF1;
        BF1.P.push_back({-0.5f,-0.5f,-0.5f});
        BF1.P.push_back({0.5f,-0.5f,-0.5f});
        BF1.P.push_back({0.5f,0.5f,-0.5f});
        BF1.N.push_back({ 0.0f, 0.0f, -1.0f });
        BF1.N.push_back({ 0.0f, 0.0f, -1.0f });
        BF1.N.push_back({ 0.0f, 0.0f, -1.0f });
        elements.push_back(BF1);
        Triangle BF2;
        BF2.P.push_back({-0.5f,-0.5f,-0.5f});
        BF2.P.push_back({-0.5f,0.5f,-0.5f});
        BF2.P.push_back({0.5f,0.5f,-0.5f});
        BF2.N.push_back({ 0.0f, 0.0f, -1.0f });
        BF2.N.push_back({ 0.0f, 0.0f, -1.0f });
        BF2.N.push_back({ 0.0f, 0.0f, -1.0f });
        elements.push_back(BF2);
        Triangle LF1;
        LF1.P.push_back({-0.5f,-0.5f,0.5f});
        LF1.P.push_back({-0.5f,-0.5f,-0.5f});
        LF1.P.push_back({-0.5f,0.5f,-0.5f});
        LF1.N.push_back({ -1.0f, 0.0f, 0.0f });
        LF1.N.push_back({ -1.0f, 0.0f, 0.0f });
        LF1.N.push_back({ -1.0f, 0.0f, 0.0f });
        elements.push_back(LF1);
        Triangle LF2;
        LF2.P.push_back({-0.5f,-0.5f,0.5f});
        LF2.P.push_back({-0.5f,0.5f,0.5f});
        LF2.P.push_back({-0.5f,0.5f,-0.5f});
        LF2.N.push_back({ -1.0f, 0.0f, 0.0f });
        LF2.N.push_back({ -1.0f, 0.0f, 0.0f });
        LF2.N.push_back({ -1.0f, 0.0f, 0.0f });
        elements.push_back(LF2);
        Triangle RF1;
        RF1.P.push_back({0.5f,-0.5f,0.5f});
        RF1.P.push_back({0.5f,-0.5f,-0.5f});
        RF1.P.push_back({0.5f,0.5f,-0.5f});
        RF1.N.push_back({ 1.0f, 0.0f, 0.0f });
        RF1.N.push_back({ 1.0f, 0.0f, 0.0f });
        RF1.N.push_back({ 1.0f, 0.0f, 0.0f });
        elements.push_back(RF1);
        Triangle RF2;
        RF2.P.push_back({0.5f,-0.5f,0.5f});
        RF2.P.push_back({0.5f,0.5f,0.5f});
        RF2.P.push_back({0.5f,0.5f,-0.5f});
        RF2.N.push_back({ 1.0f, 0.0f, 0.0f });
        RF2.N.push_back({ 1.0f, 0.0f, 0.0f });
        RF2.N.push_back({ 1.0f, 0.0f, 0.0f });
        elements.push_back(RF2);
        Triangle TF1;
        TF1.P.push_back({-0.5f,0.5f,0.5f});
        TF1.P.push_back({0.5f,0.5f,0.5f});
        TF1.P.push_back({0.5f,0.5f,-0.5f});
        TF1.N.push_back({ 0.0f, 1.0f, 0.0f });
        TF1.N.push_back({ 0.0f, 1.0f, 0.0f });
        TF1.N.push_back({ 0.0f, 1.0f, 0.0f });
        elements.push_back(TF1);
        Triangle TF2;
        TF2.P.push_back({-0.5f,0.5f,0.5f});
        TF2.P.push_back({-0.5f,0.5f,-0.5f});
        TF2.P.push_back({0.5f,0.5f,-0.5f});
        TF2.N.push_back({ 0.0f, 1.0f, 0.0f });
        TF2.N.push_back({ 0.0f, 1.0f, 0.0f });
        TF2.N.push_back({ 0.0f, 1.0f, 0.0f });
        elements.push_back(TF2);
        Triangle BTF1;
        BTF1.P.push_back({-0.5f,-0.5f,0.5f});
        BTF1.P.push_back({0.5f,-0.5f,0.5f});
        BTF1.P.push_back({0.5f,-0.5f,-0.5f});
        BTF1.N.push_back({ 0.0f, -1.0f, 0.0f });
        BTF1.N.push_back({ 0.0f, -1.0f, 0.0f });
        BTF1.N.push_back({ 0.0f, -1.0f, 0.0f });
        elements.push_back(BF1);
        Triangle BTF2;
        BTF2.P.push_back({-0.5f,-0.5f,0.5f});
        BTF2.P.push_back({-0.5f,-0.5f,-0.5f});
        BTF2.P.push_back({0.5f,-0.5f,-0.5f});
        BTF2.N.push_back({ 0.0f, -1.0f, 0.0f });
        BTF2.N.push_back({ 0.0f, -1.0f, 0.0f });
        BTF2.N.push_back({ 0.0f, -1.0f, 0.0f });
        elements.push_back(BF2);
    }
    
    
};

#endif 
