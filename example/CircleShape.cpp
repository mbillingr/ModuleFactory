
#include "CircleShape.h"

#include "modulefactory.h"

#include <iostream>

REGISTER_CLASS( ShapeInterface, CircleShape, "circle" )

using namespace std;

void CircleShape::destroy()
{
    delete this;
}

void CircleShape::draw()
{
    cout << endl;
    cout << "   ####   " << endl;
    cout << " ######## " << endl;
    cout << "##########" << endl;
    cout << "##########" << endl;
    cout << " ######## " << endl;
    cout << "   ####   " << endl;
    cout << endl;
}
