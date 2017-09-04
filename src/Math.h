#pragma once

#include <string>

struct vec2
{
  vec2();
  vec2(const vec2&);
  vec2(float);
  vec2(float,float);
  const float length();
  const std::string toString();

  float x,y;
};

struct vec3
{
  vec3();
  vec3(const vec3&);
  vec3(float);
  vec3(float,float,float);
  const float length();
  const std::string toString();

  float x,y,z;
};

struct vec4
{
  vec4();
  vec4(const vec4&);
  vec4(float);
  vec4(float,float,float,float);
  const float length();
  const std::string toString();

  float x,y,z,w;
};

vec2 operator+(const vec2&,const vec2&);
vec2 operator+=(vec2&,const vec2&);
vec2 operator*(const vec2&,float);
vec2 operator*(float,const vec2&);

vec3 operator+(const vec3&,const vec3&);
vec3 operator+=(vec3&,const vec3&);
vec3 operator*(const vec3&,float);
vec3 operator*(float,const vec3&);

vec4 operator+(const vec4&,const vec4&);
vec4 operator+=(vec3&,const vec4&);
vec4 operator*(const vec4&,float);
vec4 operator*(float,const vec4&);

class Math
{
  static const double PI;
};
