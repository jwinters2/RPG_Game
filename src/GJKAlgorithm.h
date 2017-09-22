#pragma once

#include "Math.h"

#include <vector>

class GJK
{
  private:
    GJK();

    static vec3 support(const std::vector<vec3>&,const vec3&);
    static vec3 support(const std::vector<vec3>&,const std::vector<vec3>&,const vec3&);

    static vec3 dir(const vec3&,const vec3&);
    static vec3 norm(const vec3&,const vec3&,const vec3&);
    static vec3 norm_out(const vec3&,const vec3&,const vec3&);

    static bool nearestSimplex(std::vector<vec3>&,vec3&);

    static bool simp2(std::vector<vec3>&,vec3&);
    static bool simp3(std::vector<vec3>&,vec3&);
    static bool simp4(std::vector<vec3>&,vec3&);

    static float triangleDistanceFromOrigin(const std::vector<vec3>&);

    static vec3 EPAAlgorithm(const std::vector<vec3>&,const std::vector<vec3>&,const std::vector<vec3>&);

    static bool edgeListContainsEdge(std::vector<std::vector<vec3>>&,std::vector<vec3>);
  public:
    static bool GJKAlgorithm(const std::vector<vec3>&,const std::vector<vec3>&);
    static bool GJKAlgorithm(const std::vector<vec3>&,const std::vector<vec3>&,vec3&);
};
