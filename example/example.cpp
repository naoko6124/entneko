#include <iostream>
#include "entneko.h"

struct position
{
    float x = 0.0f;
    float y = 0.0f;
};

struct velocity
{
    float x = 0.0f;
    float y = 0.0f;
};

struct tag
{
    const char* name;
};

void deleting_entities()
{
    entneko::world world;
    entneko::entity entity1 = world.create_entity();
    position& pos1 = world.add_component<position>(entity1);
    pos1.x = 4;
    position& posref1 = world.get_component<position>(entity1);
    std::cout << "value: " << posref1.x << std::endl;
    world.destroy_entity(entity1);
    entneko::entity entity2 = world.create_entity();
    position& pos2 = world.add_component<position>(entity2);
    std::cout << "value: " << pos2.x << std::endl;
}

void testing_view()
{
    entneko::world world;
    entneko::entity entity1 = world.create_entity();
    tag& tag1 = world.add_component<tag>(entity1);
    tag1.name = "entidade 1";
    position& pos1 = world.add_component<position>(entity1);
    pos1.x = 4.0f;
    pos1.y = 2.0f;
    entneko::entity entity2 = world.create_entity();
    tag& tag2 = world.add_component<tag>(entity2);
    tag2.name = "entidade 2";
    position& pos2 = world.add_component<position>(entity2);
    pos2.x = 3.0f;
    pos2.y = 1.0f;
    entneko::entity entity3 = world.create_entity();
    tag& tag3 = world.add_component<tag>(entity3);
    tag3.name = "entidade 3";
    position& pos3 = world.add_component<position>(entity3);
    pos3.x = 5.0f;
    pos3.y = 6.0f;
    world.destroy_entity(entity2);
    world.query<tag, position>([&world](entneko::entity e) {
        tag& t = world.get_component<tag>(e);
        position& pos = world.get_component<position>(e);
        std::cout << t.name << " (" << pos.x << ", " << pos.y << ")" << std::endl;
    });
    
    world.sub_component<position>(entity1);
    bool test1 = world.has_component<position>(entity1);
    bool test2 = world.has_component<velocity>(entity1);
    std::cout << test1 << std::endl;
    std::cout << test2 << std::endl;
}

void multiple_worlds()
{
    entneko::world w1;
    entneko::entity e1 = w1.create_entity();
    position& p1 = w1.add_component<position>(e1);
    p1.x = 2;
    p1.y = 4;
    velocity& v1 = w1.add_component<velocity>(e1);
    v1.x = 1;
    v1.y = 3;
    entneko::world w2;
    entneko::entity e2 = w2.create_entity();
    position& p2 = w2.add_component<position>(e2);
    p2.x = 6;
    p2.y = 8;
    tag& t2 = w2.add_component<tag>(e2);
    t2.name = "aaa";

    w1.query<position, velocity>([&w1](entneko::entity e){
        position& p = w1.get_component<position>(e);
        velocity& v = w1.get_component<velocity>(e);
        printf("w1(%f, %f)(%f, %f)\n", p.x, p.y, v.x, v.y);
    });

    w2.query<position, tag>([&w2](entneko::entity e){
        position& p = w2.get_component<position>(e);
        tag& t = w2.get_component<tag>(e);
        printf("w2(%f, %f)(%s)\n", p.x, p.y, t.name);
    });
}

int main()
{
    try
    {
        //deleting_entities();
        //testing_view();
        multiple_worlds();
    }
    catch(const entneko::exception& e)
    {
        std::cerr << e << std::endl;
    }
}