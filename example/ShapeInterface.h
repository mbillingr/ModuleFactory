#ifndef SHAPEINTERFACE_H
#define SHAPEINTERFACE_H

#include <map>
#include <string>
#include <iostream>

class ShapeInterface
{
public:
    // These typedefs are required by the Factory class!
    typedef ShapeInterface* create_t();
    typedef std::string keytype_t;
    typedef std::map<keytype_t, create_t*> factorymap_t;
    typedef void (*regfunc_p)( keytype_t, create_t* );

    // Good practice declares the destructor virtual
    virtual ~ShapeInterface( ) { std::cout << "~ShapeInterface" << std::endl; }

    // Although not required, it is adivced to use a member function for destroying
    virtual void destroy() = 0;

    // Rest of the interface, open to customization...

    virtual void draw() = 0;
};

#endif // SHAPEINTERFACE_H
