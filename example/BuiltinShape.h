#ifndef BUILTINSHAPE_H
#define BUILTINSHAPE_H

#include "ShapeInterface.h"

class BuiltinShape : public ShapeInterface
{
public:
    virtual ~BuiltinShape( ) { std::cout << "~BuiltinShape" << std::endl; }
    void destroy();
    void draw( );
};

#endif // BUILTINSHAPE_H
