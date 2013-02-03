#ifndef SQUARESHAPE_H
#define SQUARESHAPE_H

#include "ShapeInterface.h"

class SquareShape : public ShapeInterface
{
public:
    virtual ~SquareShape( ) { std::cout << "~SquareShape" << std::endl; }
    void destroy( );
    void draw( );
};

#endif // SQUARESHAPE_H
