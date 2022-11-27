#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_normalized_axis.hpp>
#include <math.h>

#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <stack>

#include "Camera.h"
#include "SurfaceShader.h"
#include "Light.h"
#include "Geometry.h"
#include "Material.h"
#include "Model.h"
#ifndef __IMAGE_H__
#define __IMAGE_H__

class Image {
public:
  int width;
  int height;
  std::vector<glm::vec3> pixels; // RGB

  unsigned int fbo; // framebuffer object
  unsigned int tbo; // texture buffer object

  Image(int w, int h){
    width = w;
    height = h;
  }
  void Initialize(void);
  void draw(void);
  void init();
};

#endif 
