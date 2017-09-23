#include "Math.h"

#include <vector>

class CollisionMesh
{
  public:
    CollisionMesh(); 
    ~CollisionMesh(); 

    virtual bool checkCollision(
                                const vec3&,const vec3&,const vec4&,  // position, scale and rotation of this
                                const CollisionMesh&,                 // other
                                const vec3&,const vec3&,const vec4&   // position, scale and rotation of other
                               )=0;
};
