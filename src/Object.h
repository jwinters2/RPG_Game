#pragma once

#include "Entity.h"
#include "Math.h"

class Object : public Entity
{
  private:
    vec3 position; 
    vec3 velocity; 
    vec4 rotation; 

    ObjModel* model;
};
