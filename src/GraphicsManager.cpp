#include "GraphicsManager.h"
#include "ObjModel.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GraphicsManager* GraphicsManager::instance = NULL;

GraphicsManager::GraphicsManager(int w,int h):SCREEN_WIDTH(w),SCREEN_HEIGHT(h),camera(NULL)
{
}

GraphicsManager::~GraphicsManager()
{
  if(GraphicsManager::instance != NULL)
  {
    delete GraphicsManager::instance;
  }
}

GraphicsManager* GraphicsManager::getInstance(int w,int h)
{
  if(instance == NULL)
  {
    GraphicsManager::instance = new GraphicsManager(w,h);
  }

  return GraphicsManager::instance;
}

void GraphicsManager::setCamera(Camera* c)
{
  camera = c;
}

/*
 * init
 *
 * @return : bool : whether or not it worked
 *
 * sets up whatever graphics engine we're using for this particular OS
 */
bool GraphicsManager::init()
{
  std::cout << "init" << std::endl;
  
  // return false if it won't open
  if(!glfwInit())
  {
    std::cout << "glfw failed to init" << std::endl;
    return false;
  }
  
  // set some window hints
  glfwWindowHint(GLFW_SAMPLES,4);                                 // 4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);                   // opengl version 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);             // MacOS needs this for some reason
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);   // new opengl only

  window = glfwCreateWindow(1440,900,"RPG Game Alpha",NULL,NULL); // create the window
  if(window == NULL)
  {
    // if it failed, print an error and quit
    std::cout << "failed to open a GLFW window" << std::endl;
    glfwTerminate();
    return false;
  }
  
  glfwMakeContextCurrent(window);   // initialize GLEW
  glewExperimental = true;
  
  if(glewInit() != GLEW_OK)
  {
    std::cout << "failed to initialize GLEW" << std::endl;
    return false;
  }

  glfwSetInputMode(window,GLFW_STICKY_KEYS,GL_TRUE);
  glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_HIDDEN);

  currentTime = (float)glfwGetTime();

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);

  glClearColor(0.0f,0.0f,0.4f,0.0f);

  // THIS SECTION IS JUST FOR TESTING
  /*--*/  glGenVertexArrays(1,&VertexArrayID);
  /*--*/  glBindVertexArray(VertexArrayID);

  /*--*/  //glGenBuffers(1, &vertexbuffer);
  /*--*/  //glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);
  /*--*/  //glGenBuffers(1, &uvbuffer);
  /*--*/  //glBindBuffer(GL_ARRAY_BUFFER,uvbuffer);

  /*--*/  programID = LoadShaders("../src/VertexShader.glsl","../src/FragmentShader.glsl");

  /*--*/  Projection = glm::perspective(
  /*--*/                                glm::radians(45.0f), 
  /*--*/                                (float)SCREEN_WIDTH/(float)SCREEN_HEIGHT, 
  /*--*/                                0.1f,
  /*--*/                                100.0f);

  ///*--*/  View = glm::lookAt(
  ///*--*/                     toGlmVec3(camera.getPosition()),
  ///*--*/                     toGlmVec3(camera.getTarget()),
  ///*--*/                     toGlmVec3(camera.getUp()));

          getViewFromCamera();
  /*--*/  Model = glm::mat4(1.0f);

  /*--*/  MVP = Projection * View * Model;

  /*--*/  MatrixID = glGetUniformLocation(programID,"MVP");
  /*--*/  TextureID = glGetUniformLocation(programID,"TextureSampler");

  return true;
}

/*--*/  glm::vec3 GraphicsManager::toGlmVec3(const vec3& v)
/*--*/  {
/*--*/    return glm::vec3(v.x,v.y,v.z);
/*--*/  }

bool GraphicsManager::deinit()
{
  std::cout << "deinit" << std::endl;
  glDeleteProgram(programID);
  glDeleteVertexArrays(1,&VertexArrayID);
  glfwTerminate();
  // THIS SECTION IS JUST FOR TESTING
  /*--*/  //glDeleteBuffers(1, &vertexbuffer);
  /*--*/  //glDeleteVertexArrays(1, &VertexArrayID);
  return true;
}

bool GraphicsManager::startFrame()
{
  // THIS SECTION IS JUST FOR TESTING
  /*--*/  //camera.move(vec3(0.0f,0.0f,0.05f));
  ///*--*/  View = glm::lookAt(
  ///*--*/                     toGlmVec3(camera.getPosition()),
  ///*--*/                     toGlmVec3(camera.getTarget()),
  ///*--*/                     toGlmVec3(camera.getUp()));
          getViewFromCamera();
  /*--*/  MVP = Projection * View * Model;

  /*--*/  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /*--*/  glUseProgram(programID);

  glfwSetCursorPos(window,(double)SCREEN_WIDTH/2,(double)SCREEN_HEIGHT/2);



  ///*--*/  glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);
  ///*--*/  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
  ///*--*/  glDrawArrays(GL_TRIANGLES,0,3);


  return true;
}

bool GraphicsManager::endFrame()
{
  /*--*/  glDisableVertexAttribArray(0);
  /*--*/  glDisableVertexAttribArray(1);
  glfwSwapBuffers(window);
  glfwPollEvents();

  previousTime = currentTime;
  currentTime = (float)glfwGetTime();
  deltaTime = currentTime-previousTime;

}


void GraphicsManager::getViewFromCamera()
{
  if(camera==NULL)
  {
    return;
  }

  vec3 forward(0.0f,0.0f,-1.0f);
  vec3 up(0.0f,1.0f,0.0f);

  View = glm::lookAt(
                     toGlmVec3(camera->getPosition()),
                     toGlmVec3(camera->getPosition() + applyQuatToVec3(camera->getRotation(),forward)),
                     toGlmVec3(up));
}



bool GraphicsManager::loadObjModel(ObjModel* m)
{
  if(m != NULL && m->isValid)
  {
    // check if the model is already loaded (exists in vertex_buffers)
    if(vertex_buffers.find(m->modelName) == vertex_buffers.end())
    {
      // not found, load it
      GLuint vbuffer;
      glGenBuffers(1,&vbuffer);
      glBufferData(GL_ARRAY_BUFFER,m->vertices.size() * sizeof(vec3), &m->vertices[0], GL_STATIC_DRAW);

      GLuint uvbuffer;
      glGenBuffers(1,&uvbuffer);
      glBufferData(GL_ARRAY_BUFFER,m->uvs.size() * sizeof(vec2), &m->uvs[0], GL_STATIC_DRAW);
      
      // add to vertex_buffers
      vertex_buffers[m->modelName] = vbuffer;
      uv_buffers[m->modelName] = uvbuffer;
      model_pointers[m->modelName] = m;
    }
    else
    {
      std::cout << "Model \"" << m->modelName << "\" has already been loaded" << std::endl;
    }

    if(texture_buffers.find(m->textureName) == texture_buffers.end())
    {
      GLuint texbuffer = LoadBMP(m->textureName);
      texture_buffers[m->textureName] = texbuffer;
    }
    else
    {
      std::cout << "Texture \"" << m->textureName << "\" has already been loaded" << std::endl;
    }

    return true;
  }

  return false;
}

bool GraphicsManager::unloadObjModel(const ObjModel& m)
{
  if(m.isValid)
  {
    glDeleteBuffers(1, &vertex_buffers[m.modelName]);
    glDeleteBuffers(1, &uv_buffers[m.modelName]);
    glDeleteBuffers(1, &texture_buffers[m.textureName]);
    return true;
  }
  return false;
}

bool GraphicsManager::renderObjModel(std::string mn,std::string tn,
                                     const vec3& pos,const vec3& scale,const vec4& rot)
{
  ObjModel* m = model_pointers[mn];

  if(m != NULL && m->isValid)
  {
    Model = getTranslationMatrix(pos) * getRotationMatrix(rot) * 
            getScaleMatrix(scale) * glm::mat4(1.0f);
    MVP = Projection * View * Model;
    glUniformMatrix4fv(MatrixID,1,GL_FALSE,&MVP[0][0]);


    GLuint vbuffer = vertex_buffers[mn];
    GLuint uvbuffer = uv_buffers[mn];
    GLuint texbuffer = texture_buffers[tn];

    //std::cout << "v:" << vbuffer << " u:" << uvbuffer << " t:" << texbuffer << std::endl;

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,texbuffer);
    glUniform1i(TextureID,0);

    
    glEnableVertexAttribArray(0); 
    glBindBuffer(GL_ARRAY_BUFFER,vbuffer);
    glBufferData(GL_ARRAY_BUFFER,m->vertices.size() * sizeof(vec3), &m->vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

    glEnableVertexAttribArray(1); 
    glBindBuffer(GL_ARRAY_BUFFER,uvbuffer);
    glBufferData(GL_ARRAY_BUFFER,m->uvs.size() * sizeof(vec2), &m->uvs[0], GL_STATIC_DRAW);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,(void*)0);

    glDrawArrays(GL_TRIANGLES,0,m->vertices.size());

    //glDisableVertexAttribArray(0);
    //glDisableVertexAttribArray(1);

    return true;
  }

  return false;
}

ObjModel* GraphicsManager::getObjModel(std::string mn)
{
  if(model_pointers.find(mn) == model_pointers.end())
  {
    return NULL;
  }
  return model_pointers[mn];
}


glm::mat4 GraphicsManager::getTranslationMatrix(const vec3& p)
{
  return glm::translate(glm::mat4(1.0f),toGlmVec3(p));
}

glm::mat4 GraphicsManager::getRotationMatrix(const vec4& r)
{
  /*
   *  the matrix for quaternion Q = [w,x,y,z] is :
   *
   *  |   1-2y^2-2z^2   2xy+2wz       2xz-2wy       0   |
   *
   *  |   2xy-2wz       1-2x^2-2z^2   2yz+2wx       0   |
   *
   *  |   2xz+2wy       2yz-2wz       1-2x^2-2y^2   0   |
   *
   *  |   0             0             0             1   |
   *
   *
   *  where w,x,y,z are normalized ( ||Q|| = 1 )
   *
   *  also glm::mat4 uses m[column][row]
   */
  //vec3 axis(r.x,r.y,r.z);
  //return glm::rotate(glm::mat4(1.0f),r.w,toGlmVec3(axis));
  const float n = 1.0f/r.length();
  const float qw = r.w * n;
  const float qx = r.x * n;
  const float qy = r.y * n;
  const float qz = r.z * n;

  glm::mat4 retval;

  // first row
  retval[0][0] = 1.0f - 2*qy*qy - 2*qz*qz;
  retval[1][0] =        2*qx*qy + 2*qw*qz;
  retval[2][0] =        2*qx*qz - 2*qw*qy;
  retval[3][0] = 0.0f;

  // second row
  retval[0][1] =        2*qx*qy - 2*qw*qz;
  retval[1][1] = 1.0f - 2*qx*qx - 2*qz*qz;
  retval[2][1] =        2*qy*qz + 2*qw*qx;
  retval[3][1] = 0.0f;

  // third row
  retval[0][2] =        2*qx*qz + 2*qw*qy;
  retval[1][2] =        2*qy*qz - 2*qw*qx;
  retval[2][2] = 1.0f - 2*qx*qx - 2*qy*qy;
  retval[3][2] = 0.0f;

  // fourth row
  retval[0][3] = 0.0f;
  retval[1][3] = 0.0f;
  retval[2][3] = 0.0f;
  retval[3][3] = 1.0f;

  return retval;
}

glm::mat4 GraphicsManager::getScaleMatrix(const vec3& s)
{
  return glm::scale(glm::mat4(1.0f),toGlmVec3(s));
}





bool GraphicsManager::closeButtonPressed() const
{
  return glfwWindowShouldClose(window) || getKeyDown(256); // 256 = esc
}

void GraphicsManager::getMouseSpeed(double& dx,double& dy)
{
  glfwGetCursorPos(window,&dx,&dy);
  dx -= (double)SCREEN_WIDTH/2;
  dy -= (double)SCREEN_HEIGHT/2;
}

bool GraphicsManager::getKeyDown(int key) const
{
  return glfwGetKey(window,key) == GLFW_PRESS;
}

float GraphicsManager::getDeltaTime() const
{
  return deltaTime;
}

GLuint GraphicsManager::LoadShaders(const char * vertex_file,const char* fragment_file)
{
  GLuint VertexShaderID   = glCreateShader(GL_VERTEX_SHADER);
  GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);


  // read contents of vertex code into a string
  std::string VertexShaderCode;
  std::ifstream VertexShaderStream(vertex_file,std::ios::in);

  if(VertexShaderStream.is_open())
  {
    std::string line = "";
    while(getline(VertexShaderStream, line))
    {
      VertexShaderCode += "\n" + line; 
    }
    VertexShaderStream.close();
  }
  else
  {
    std::cout << "can't open " << vertex_file << std::endl;
    return 0;
  }


  // read contents of fragment code into a string
  std::string FragmentShaderCode;
  std::ifstream FragmentShaderStream(fragment_file,std::ios::in);

  if(FragmentShaderStream.is_open())
  {
    std::string line = "";
    while(getline(FragmentShaderStream, line))
    {
      FragmentShaderCode += "\n" + line; 
    }
    FragmentShaderStream.close();
  }
  else
  {
    std::cout << "can't open " << fragment_file << std::endl;
    //return 0;
  }


  GLint Result = GL_FALSE;
  int InfoLogLength;

  // compine vertex shader
  std::cout << "compiling shader : " << vertex_file << std::endl;
  char const * VertexSourcePointer = VertexShaderCode.c_str();
  glShaderSource(VertexShaderID,1,&VertexSourcePointer,NULL);
  glCompileShader(VertexShaderID);

  // verify
  glGetShaderiv(VertexShaderID,GL_COMPILE_STATUS,&Result);
  glGetShaderiv(VertexShaderID,GL_INFO_LOG_LENGTH,&InfoLogLength);
  if(InfoLogLength > 0)
  {
    std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
    glGetShaderInfoLog(VertexShaderID,InfoLogLength,NULL,&VertexShaderErrorMessage[0]);
    std::cout << &VertexShaderErrorMessage[0] << std::endl;
  }
  

  // compine fragment shader
  std::cout << "compiling shader : " << fragment_file << std::endl;
  char const * FragmentSourcePointer = FragmentShaderCode.c_str();
  glShaderSource(FragmentShaderID,1,&FragmentSourcePointer,NULL);
  glCompileShader(FragmentShaderID);

  // verify
  glGetShaderiv(FragmentShaderID,GL_COMPILE_STATUS,&Result);
  glGetShaderiv(FragmentShaderID,GL_INFO_LOG_LENGTH,&InfoLogLength);
  if(InfoLogLength > 0)
  {
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
    glGetShaderInfoLog(FragmentShaderID,InfoLogLength,NULL,&FragmentShaderErrorMessage[0]);
    std::cout << &FragmentShaderErrorMessage[0] << std::endl;
  }


  // link the program
  std::cout << "linking program" << std::endl;
  GLuint ProgramID = glCreateProgram();
  glAttachShader(ProgramID,VertexShaderID);
  glAttachShader(ProgramID,FragmentShaderID);
  glLinkProgram(ProgramID);

  // check program
  glGetShaderiv(ProgramID,GL_COMPILE_STATUS,&Result);
  glGetShaderiv(ProgramID,GL_INFO_LOG_LENGTH,&InfoLogLength);
  if(InfoLogLength > 0)
  {
    std::vector<char> ProgramErrorMessage(InfoLogLength+1);
    glGetShaderInfoLog(ProgramID,InfoLogLength,NULL,&ProgramErrorMessage[0]);
    std::cout << &ProgramErrorMessage[0] << std::endl;
  }

  // clean
  glDetachShader(ProgramID,VertexShaderID);
  glDetachShader(ProgramID,FragmentShaderID);

  glDeleteShader(VertexArrayID);
  glDeleteShader(FragmentShaderID);

  return ProgramID;
}

GLuint GraphicsManager::LoadBMP(std::string filename)
{
  std::cout << "loading texture file " << filename << std::endl;

  char header[54];
  unsigned int pos;
  unsigned int width,height;
  unsigned int size;
  char* data;

  std::ifstream file(filename, std::ios::in | std::ios::binary);
  if(!file.is_open())
  {
    return 0;
  }

  file.get(header,54);

  // needs to be 24bpp file
  if( *(int*)&header[0x1E] != 0 || *(int*)&header[0x1C] != 24)
  {
    std::cout << "incorrect .bmp file" << std::endl;
    return 0;
  }

  pos = *(int*)&header[0x0A];
  size = *(int*)&header[0x22];
  width = *(int*)&header[0x12];
  height = *(int*)&header[0x16];

  if(size==0)
  {
    size = width*height*3;
  }

  if(pos==0)
  {
    pos = 54;
  }

  data = new char [size];
  file.read(data,size); 
  file.close();

  GLuint textureID;
  glGenTextures(1,&textureID);
  glBindTexture(GL_TEXTURE_2D,textureID);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_BGR,GL_UNSIGNED_BYTE,data);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
  glGenerateMipmap(GL_TEXTURE_2D);

  delete [] data;

  return textureID;
}
