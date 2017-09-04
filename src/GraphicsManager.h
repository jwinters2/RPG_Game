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

    const bool loadObjModel(const ObjModel&);
    const bool unloadObjModel(const ObjModel&);
    const bool renderObjModel(const ObjModel&,const vec3&,const vec3&,const vec4&);

    const bool closeButtonPressed();

    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    
    // THIS IS ONLY PUBLIC FOR TESTING
    // NEEDS TO BE PRIVATE
    /*--*/  GLuint LoadBMP(std::string);
    void moveCamera(const vec3&);

  private:
    GraphicsManager(int,int);
    ~GraphicsManager();

    static GraphicsManager* instance;

    GLFWwindow* window;

    Camera camera;

    // THIS SECTION IS FOR TESTING
    /*--*/  GLuint VertexArrayID;
    /*--*/  GLuint TextureID;
    ///*--*/  GLuint vertexbuffer;
    ///*--*/  GLuint uvbuffer;
    std::map<std::string,GLuint> vertex_buffers;
    std::map<std::string,GLuint> uv_buffers;
    std::map<std::string,GLuint> texture_buffers;

    /*--*/  static const GLfloat g_vertex_buffer_data[9];

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
