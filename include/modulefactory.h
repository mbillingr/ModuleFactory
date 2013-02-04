/*
    This library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Copyright 2013 Martin Billinger
*/

/**
 * @file modulefactory.h
 *
 * @brief Include the correct implementation (WIN/GCC).
 */

#ifndef MODULEFACTORY_H
#define MODULEFACTORY_H

#ifdef WIN32
#include "modulefactory_win.h"
#else
#include "modulefactory_gcc.h"
#endif

// =====================================================================

/**
 * Macro to register a class with the ModuleFactory.
 * @param intrface     type of the intrface (base class)
 * @param derived       actual class to be registered
 * @param id            unique identifier that is used by the factory for creating instances
 */
#define REGISTER_CLASS( intrface, derived, id ) \
    Proxy<intrface, derived> proxy_instance_ ## intrface ## _ ## derived ## ___( id );

// =====================================================================

/**
 * Proxy class registers the class derived with the correct factory of the interface.
 * @tparam intrface Interface implemented by the derived class
 * @tparam derived   Class to be registered with the factory
 */
template<class intrface, class derived>
class Proxy
{
public:
    /**
     * Constructor. Derived class is registered with the correct factory.
     * @param class_id unique id of the class
     */
    Proxy( const typename intrface::keytype_t &class_id )
    {
        ModuleFactory<intrface>::registrate( class_id, create_instance );
    }

private:
    /**
     * @brief create_instance creates an instance of the class derived.
     * @return pointer to the new instance.
     */
    static intrface *create_instance( )
    {
        return new derived( );
    }
};

// =====================================================================

#endif // MODULEFACTORY_H
