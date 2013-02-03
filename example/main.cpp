#include "ShapeInterface.h"
#include "modulefactory.h"

int main()
{
    ModuleFactory<ShapeInterface>::add_module( "./libcircle_shape.so" );
    ModuleFactory<ShapeInterface>::add_module( "./libsquare_shape.so" );

    ShapeInterface *a = ModuleFactory<ShapeInterface>::create_object("circle");
    ShapeInterface *b = ModuleFactory<ShapeInterface>::create_object("square");
    ShapeInterface *c = ModuleFactory<ShapeInterface>::create_object("builtin");

    a->draw();
    b->draw();
    c->draw();

    a->destroy();
    b->destroy();
    c->destroy();

    return 0;
}

