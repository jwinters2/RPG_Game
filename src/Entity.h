#pragma once

class Entity
{
  public:
    unsigned int id;
    Entity();
    ~Entity();

  private:
    static unsigned int master_id;
};
