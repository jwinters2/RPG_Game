#pragma once

#include <vector>

class ObjModel;

class ModelManager
{
  public:
    ModelManager* getInstance(); 
  
  private:
    ModelManager();
    ~ModelManager();

    static ModelManager* instance;

    std::vector<ObjModel*> modelList;
};
