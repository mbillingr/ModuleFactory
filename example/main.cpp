#include "ShapeInterface.h"
#include "modulefactory.h"

#include <iostream>

int main()
{
    // ugly OS hack
    /// @todo determine correct file names inside ModuleFactory implementation
#ifdef WIN32
    ModuleFactory<ShapeInterface>::add_module( "./circle_shape.dll" );
    ModuleFactory<ShapeInterface>::add_module( "./square_shape.dll" );
#else
    ModuleFactory<ShapeInterface>::add_module( "./libcircle_shape.so" );
    ModuleFactory<ShapeInterface>::add_module( "./libsquare_shape.so" );
#endif

    std::list<ShapeInterface::keytype_t> ids = ModuleFactory<ShapeInterface>::get_IDs();
    std::list<ShapeInterface::keytype_t>::iterator it = ids.begin();
    std::cout << "Registered Classes: " << std::endl;
    for( ; it!=ids.end(); it++ )
    {
        std::cout << " -> " << *it << std::endl;
        ShapeInterface *shape = ModuleFactory<ShapeInterface>::create_object( *it );
        shape->draw( );
        shape->destroy( );
    }


    return 0;
}

