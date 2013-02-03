
#include "SquareShape.h"

#include "modulefactory.h"

#include <iostream>

REGISTER_CLASS( ShapeInterface, SquareShape, "square" )

using namespace std;

void SquareShape::destroy()
{
    delete this;
}

void SquareShape::draw()
{
    cout << endl;
    cout << "##########" << endl;
    cout << "##########" << endl;
    cout << "##########" << endl;
    cout << "##########" << endl;
    cout << "##########" << endl;
    cout << "##########" << endl;
    cout << endl;
}

