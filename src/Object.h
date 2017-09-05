#pragma once

#include "Entity.h"
#include "Math.h"

#include <string>

class Object : public Entity
{
  private:
    vec3 position; 
    vec3 velocity; 
    vec4 rotation; 

    std::string model_name;
    std::string texture_name;

  public:
    Object(std::string,std::string);
    ~Object();

    static Object* insertInstance(std::string,std::string);

    virtual bool logic(int);
    virtual bool render();

    void setPosition(const vec3&);

    void setRotation(const vec4&);
    void rotate(const vec4&);
};
