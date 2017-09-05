#pragma once

#include "Entity.h"
#include "Math.h"

#include <string>

class Object : public Entity
{
  private:
    std::string model_name;
    std::string texture_name;

  protected:
    vec3 position; 
    vec3 velocity; 
    vec4 rotation; 

  public:
    Object(std::string,std::string);
    ~Object();

    static Object* insertInstance(std::string,std::string);

    virtual bool logic(int);
    virtual bool render();

    vec3 getPosition() const;
    void setPosition(const vec3&);
    void addPosition(const vec3&);

    vec3 getVelocity() const;
    void setVelocity(const vec3&);
    void addVelocity(const vec3&);

    vec4 getRotation() const;
    void setRotation(const vec4&);
    void addRotation(const vec4&);
};
