project(dynclassldr)
cmake_minimum_required(VERSION 2.8)

include_directories( ../include )

add_executable(${PROJECT_NAME}
    main.cpp
    ShapeInterface.h
#    modulefactory.h

    BuiltinShape.h
    BuiltinShape.cpp
)

if( WIN32 )
else()
	target_link_libraries( ${PROJECT_NAME} dl )
endif()


add_library( circle_shape MODULE
    CircleShape.cpp
    CircleShape.h
    ShapeInterface.h
)


add_library( square_shape MODULE
    SquareShape.cpp
    SquareShape.h
    ShapeInterface.h
)
