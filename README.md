# entneko

![alt text](https://github.com/naoko6124/entneko/blob/master/entneko-export.png?raw=true)

Simple ECS (Entity-Component-System) library.

## Getting Started

entneko is a header-only library, so just include `entneko.h` into your project.
```cpp
#define ENTNEKO_IMPLEMENTATION
#include "entneko.h"
```

## How to use

First, you need to create an world where entities can be stored.
```cpp
entneko::world world;
```

Now you can create entities.
```cpp
entneko::entity entity = world.create_entity();
```

And add components to those entities.
```cpp
struct position
{
  float x = 0.0f;
  float y = 0.0f;
};

position& pos_ref = world.add_component<position>(entity);
pos_ref.x = 4.0f;
pos_ref.y = 2.0f;
```

And verify if an entity has an component too.
```cpp
bool has_position = world.has_component<position>(entity);
```

And get a reference to a component.
```cpp
position& pos_ref = world.get_component<position>(entity);
std::cout << pos_ref.x << std::endl;
```

And subtract a component of an entity too.
```cpp
world.sub_component<position>(entity);
```

And finally, destroy an entity.
```cpp
world.destroy_entity(entity);
```

Now, if you want to query the world.
```
world.query<position>([&world](entneko::entity e) {
  position& pos = world.get_component<position>(e);
  std::cout << "For each entity: " << pos.x << std::endl;
});
```
