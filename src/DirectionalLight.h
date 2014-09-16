#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "BaseLight.h"

class DirectionalLight : public BaseLight
{
public:
  DirectionalLight(glm::vec3 color, float intensity);

  virtual void updateShader(Shader *shader);
};

#endif