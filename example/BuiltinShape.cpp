
#include "BuiltinShape.h"

#include "modulefactory.h"

#include <iostream>

REGISTER_CLASS( ShapeInterface, BuiltinShape, "builtin" )

using namespace std;

void BuiltinShape::destroy()
{
    delete this;
}

void BuiltinShape::draw()
{
    cout << endl;
    cout << "BBBBBBBBBB" << endl;
    cout << "B        B" << endl;
    cout << "B   BB   B" << endl;
    cout << "B   BB   B" << endl;
    cout << "B        B" << endl;
    cout << "BBBBBBBBBB" << endl;
    cout << endl;
}
