#pragma once 

#include "Math.h"
#include "GraphicsManager.h"

#include <vector>
#include <string>
#include <iostream>

class ObjModel
{
  private:
    std::vector <unsigned int> vertex_indices;
    std::vector <unsigned int> uv_indices;
    std::vector <unsigned int> normal_indices;
    
    std::vector <vec3> vertices;
    std::vector <vec2> uvs;
    std::vector <vec3> normals;

    bool isValid;

    std::string modelName;
    std::string textureName;

    bool readFile();
    void readTriplet(std::string,unsigned int&,unsigned int&,unsigned int&);


    vec3 position;
    vec3 scale;
    vec4 rotation;

  public:
    ObjModel(std::string,std::string);
    ~ObjModel();
    const void print();
    const bool getIsValid();
    const std::string getModelName();

    friend const bool GraphicsManager::loadObjModel(const ObjModel&);
    friend const bool GraphicsManager::unloadObjModel(const ObjModel&);
    friend const bool GraphicsManager::renderObjModel(const ObjModel&);

    void setPosition(const vec3&);
    void setScale(const vec3&);
    void setRotation(const vec4&);

    void addPosition(const vec3&);
};
