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
 * @file modulefactory_gcc.h
 * GCC implementation
 * Single-file header-only library, that provides a factory class for any base type.
 * Classes derived from that base type are registered to the factory at run-time.
 * Classes may be compiled in, or loaded from run-time modules.
 *
 * @brief Factory class that supports built-in and run-time modules.
 */

#ifndef MODULEFACTORY_GCC_H
#define MODULEFACTORY_GCC_H

#include <map>
#include <list>
#include <stdexcept>
#include <dlfcn.h>
#include <string>

/**
 * Generic Factory, that supports creation of classes derived from a common interface.
 * @tparam interface Interface type for the factory
 */
template<class interface>
class ModuleFactory
{
public:
    /// type of the unique class identifier
    typedef typename interface::keytype_t keytype_t;

    /// Destructor. All loaded modules are closed.
    ~ModuleFactory()
    {
        std::list<void*>::iterator it = dl_list.begin();
        for( ; it!=dl_list.end(); it++ )
        {
            dlclose(*it);
        }
    }

    /**
     * @brief add_module loads a module and registers with the factory
     * @param filename file name of the module to load
     */
    static void add_module( const std::string &filename )
    {
        void *dlib = dlopen( filename.c_str(), RTLD_NOW );
        if( !dlib )
        {
            throw std::runtime_error( dlerror() );
        }
        get_instance().dl_list.push_back( dlib );
    }

    /**
     * @brief create_object creates an instance of a registered class
     * @param class_id unique identifier of the class that should be created
     * @return pointer to the new instance.
     */
    static interface* create_object( const keytype_t &class_id )
    {
        factorymap_t &f = get_instance().factory;
        typename factorymap_t::iterator it = f.find(class_id);
        if( it == f.end() )
            throw std::runtime_error( "Unknown class ID." );

        return get_instance().factory[class_id]();
    }

protected:

    template<class A, class B> friend class Proxy;

    /**
     * @brief registrate registers a class with a unique class identifier
     * @param class_id      unique identifier for the class
     * @param creator_func  function pointer to a function that creates the actual instance
     */
    static void registrate( const keytype_t &class_id, typename interface::create_t* creator_func )
    {
        factorymap_t &f = get_instance().factory;
        typename factorymap_t::iterator it = f.find(class_id);
        if( it != f.end() )
            throw std::runtime_error( "Class ID already defined." );

        f[class_id] = creator_func;
    }

	/**
     * @brief get_IDs returns a list of registered class IDs.
     * @return list of class IDs.
     */
    static std::list<keytype_t> get_IDs( )
	{
		std::list ids;
		factorymap_t &f = get_instance().factory;
		typename factorymap_t::iterator it = f.begin();
		for( ; it!=f.end(); it++ )
		{
			ids.push_back( it->first );
		}
		return ids;
	}

private:
    typedef typename interface::factorymap_t factorymap_t;

    // hide constructors
    ModuleFactory( const ModuleFactory &other );
    ModuleFactory() { }

    /**
     * @brief get_instance returns static instance of the factory. Only used internally.
     * @return reference to the instance
     */
    static ModuleFactory& get_instance( )
    {
        static ModuleFactory instance;
        return instance;
    }

    factorymap_t factory;
    std::list<void*> dl_list;
};

// =====================================================================

#endif // MODULEFACTORY_GCC_H
