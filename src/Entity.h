#pragma once

class GraphicsManager;

class Entity
{
  public:
    Entity();
    ~Entity();

    virtual bool logic(int);
    virtual bool render();

    unsigned int getId() const;

    static Entity* insertInstance();

  private:
    const unsigned int id;
    
    static unsigned int master_id;
};
