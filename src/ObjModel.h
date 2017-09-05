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
    void print() const;
    bool getIsValid() const;
    std::string getModelName() const;
    int getSize() const;

    friend bool GraphicsManager::loadObjModel(ObjModel*);
    friend bool GraphicsManager::unloadObjModel(const ObjModel&);
    friend bool GraphicsManager::renderObjModel(std::string,std::string,
                                                      const vec3&,const vec3&,const vec4&);

    void setPosition(const vec3&);
    void setScale(const vec3&);
    void setRotation(const vec4&);

    void addPosition(const vec3&);
};
