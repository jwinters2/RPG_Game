#pragma once 

#include "Camera.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <map>

class GLFWwindow;
class ObjModel;

class GraphicsManager
{
  public:
    static GraphicsManager* getInstance(int=800,int=600);

    bool init();
    bool deinit();

    bool startFrame();
    bool endFrame();

    bool loadObjModel(ObjModel*);
    bool unloadObjModel(const ObjModel&);
    bool renderObjModel(std::string,std::string,const vec3&,const vec3&,const vec4&);

    bool closeButtonPressed() const;

    ObjModel* getObjModel(std::string);

    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;

    void setCamera(Camera*);

    // THIS IS ONLY PUBLIC FOR TESTING
    // NEEDS TO BE PRIVATE
    /*--*/  GLuint LoadBMP(std::string);

    void getMouseSpeed(double&,double&);
    bool getKeyDown(int) const;
    float getDeltaTime() const;

  private:
    GraphicsManager(int,int);
    ~GraphicsManager();

    static GraphicsManager* instance;

    GLFWwindow* window;

    Camera* camera;
    void getViewFromCamera();
    
    float deltaTime;
    float currentTime;
    float previousTime;

    // THIS SECTION IS FOR TESTING
    /*--*/  GLuint VertexArrayID;
    /*--*/  GLuint TextureID;
    ///*--*/  GLuint vertexbuffer;
    ///*--*/  GLuint uvbuffer;
    std::map<std::string,GLuint> vertex_buffers;
    std::map<std::string,GLuint> uv_buffers;
    std::map<std::string,GLuint> texture_buffers;
    std::map<std::string,ObjModel*> model_pointers;

    /*--*/  GLuint LoadShaders(const char *,const char*);
    /*--*/  //GLuint LoadBMP(const char *);

    /*--*/  GLuint programID;
    /*--*/  glm::mat4 Projection;
    /*--*/  glm::mat4 View;
    /*--*/  glm::mat4 Model;
    /*--*/  glm::mat4 MVP;
    /*--*/  GLuint MatrixID;

    /*--*/  glm::vec3 toGlmVec3(const vec3&);

    /*--*/  glm::mat4 getTranslationMatrix(const vec3&);
    /*--*/  glm::mat4 getRotationMatrix(const vec4&);
    /*--*/  glm::mat4 getScaleMatrix(const vec3&);
};
