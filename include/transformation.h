
#include "glut_torus.h"

#if __APPLE__
#include <OpenGL/gl.h>
#elif __WINDOW__
#include <GL/gl.h>
#endif

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

template < typename T = GlutTorus >
class Transformation {

    public:

        static void rotateX ( const double angle_degree, T & rotation );
        static void rotateY ( const double angle_degree, T & rotation );
        static void rotateZ ( const double angle_degree, T & rotation );

};

// #include "transformation.cpp"

#endif