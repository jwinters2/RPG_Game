#include "ObjModel.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

ObjModel::ObjModel(std::string mn,std::string tn):
      modelName(mn),textureName(tn),vertices(),uvs(),normals(),isValid(false),
      position(0.0f),scale(1.0f),rotation(0.0f,1.0f,0.0f,0.0f)
{
  readFile();
}

ObjModel::~ObjModel()
{
}

bool ObjModel::readFile()
{
  std::vector<vec3> vertices_temp;
  std::vector<vec2> uvs_temp;
  std::vector<vec3> normals_temp;

  std::ifstream file(modelName);
  if(!file.is_open())
  {
    std::cout << "cannot open file" << std::endl;
    return false;
  }
  
  std::string header;
  std::string junk;

  while(true)
  {
    if(file.eof())
    {
      break;
    }

    file >> header;
  
    if(header.compare("v")==0)
    {
      vec3 temp;
      file >> temp.x >> temp.y >> temp.z;    
      vertices_temp.push_back(temp);      
    }
    else if(header.compare("vt")==0)
    {
      vec2 temp;
      file >> temp.x >> temp.y;    
      uvs_temp.push_back(temp);      
    }
    else if(header.compare("vn")==0)
    {
      vec3 temp;
      file >> temp.x >> temp.y >> temp.z;    
      normals_temp.push_back(temp);      
    }
    else if(header.compare("f")==0)
    {
      unsigned int temp_vert[3];
      unsigned int temp_uv[3];
      unsigned int temp_norm[3];
      std::string triplet;

      file >> triplet; 
      readTriplet(triplet,temp_vert[0],temp_uv[0],temp_norm[0]);
      file >> triplet; 
      readTriplet(triplet,temp_vert[1],temp_uv[1],temp_norm[1]);
      file >> triplet; 
      readTriplet(triplet,temp_vert[2],temp_uv[2],temp_norm[2]);

      if(temp_vert[0] != 0)
      {
        vertex_indices.push_back(temp_vert[0]);
        vertex_indices.push_back(temp_vert[1]);
        vertex_indices.push_back(temp_vert[2]);
        uv_indices.push_back(temp_uv[0]);
        uv_indices.push_back(temp_uv[1]);
        uv_indices.push_back(temp_uv[2]);
        normal_indices.push_back(temp_norm[0]);
        normal_indices.push_back(temp_norm[1]);
        normal_indices.push_back(temp_norm[2]);
      }
    }
    else
    {
      getline(file,junk);
    }
  }

  //std::cout << vertex_indices.size() << std::endl;
  //std::cout << uv_indices.size() << std::endl;
  //std::cout << normal_indices.size() << std::endl;

  for(unsigned int i=0; i<vertex_indices.size(); i++)
  {
    unsigned int vertex_index = vertex_indices[i];
    //std::cout << i << std::endl ;
    //std::cout << vertex_index-1 << std::endl ;
    //std::cout << vertices_temp[vertex_index-1].toString() << std::endl;
    vec3 vertex(vertices_temp[vertex_index-1]);
    vertices.push_back(vertex);
  }
  for(unsigned int i=0; i<uv_indices.size(); i++)
  {
    unsigned int uv_index = uv_indices[i];
    //std::cout << i << std::endl ;
    //std::cout << uv_index << std::endl ;
    //std::cout << uvs_temp[uv_index-1].toString() << std::endl;
    vec2 uv(uvs_temp[uv_index-1]);
    uvs.push_back(uv);
  }
  for(unsigned int i=0; i<normal_indices.size(); i++)
  {
    unsigned int normal_index = normal_indices[i];
    //std::cout << i << std::endl ;
    //std::cout << normal_index-1 << std::endl ;
    //std::cout << normals_temp[normal_index-1].toString() << std::endl;
    vec3 normal(normals_temp[normal_index-1]);
    normals.push_back(normal);
  }

  file.close();
  
  isValid=true;

  return true;
}

void ObjModel::readTriplet(std::string data,unsigned int& x,unsigned int& y,unsigned int& z)
{
  int temp=0;
  int index=0;

  while(index < data.size() && data[index] != '/')
  {
    temp = (temp*10) + (data[index]-'0');
    index++;
  }
  x = (float)temp;
  //std::cout << x << " ";
  temp=0;
  index++;

  while(index < data.size() && data[index] != '/')
  {
    temp = (temp*10) + (data[index]-'0');
    index++;
  }
  y = (float)temp;
  //std::cout << y << " ";
  temp=0;
  index++;

  while(index < data.size() && data[index] != '/')
  {
    temp = (temp*10) + (data[index]-'0');
    index++;
  }
  z = (float)temp;
  //std::cout << z << std::endl;
}

const void ObjModel::print()
{
  std::cout << "vertices: " << std::endl;
  for(int i=0; i<vertices.size(); i++)
  {
    std::cout << "   " << vertices.at(i).toString() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "uvs: " << std::endl;
  for(int i=0; i<uvs.size(); i++)
  {
    std::cout << "   " << uvs.at(i).toString() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "normals: " << std::endl;
  for(int i=0; i<normals.size(); i++)
  {
    std::cout << "   " << normals.at(i).toString() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "vertex indices: " << std::endl;
  for(int i=0; i<vertex_indices.size(); i++)
  {
    std::cout << "   " << vertex_indices[i] << std::endl;
  }
  std::cout << std::endl;

  std::cout << "uv indices: " << std::endl;
  for(int i=0; i<uv_indices.size(); i++)
  {
    std::cout << "   " << uv_indices[i] << std::endl;
  }
  std::cout << std::endl;

  std::cout << "normal indices: " << std::endl;
  for(int i=0; i<normal_indices.size(); i++)
  {
    std::cout << "   " << normal_indices[i] << std::endl;
  }
  std::cout << std::endl;
}

const bool ObjModel::getIsValid()
{
  return isValid;
}

const std::string ObjModel::getModelName()
{
  return modelName;
}

void ObjModel::setPosition(const vec3& p)
{
  position = p;
}

void ObjModel::setScale(const vec3& s)
{
  scale = s;
}

void ObjModel::setRotation(const vec4& r)
{
  rotation = r;
}

void ObjModel::addPosition(const vec3& p)
{
  position += p;
}
