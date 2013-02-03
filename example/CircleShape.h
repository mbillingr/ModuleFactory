#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "ShapeInterface.h"

class CircleShape : public ShapeInterface
{
public:
    virtual ~CircleShape( ) { std::cout << "~CircleShape" << std::endl; }
    void destroy();
    void draw( );
};

#endif // CIRCLESHAPE_H
