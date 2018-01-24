
#if __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#elif __WINDOW__
#include <GL/gl.h>
#include <GL/freeglut.h>
#endif

#ifndef GLUT_TORUS_H
#define GLUT_TORUS_H

struct GlutTorus {

    static constexpr double DEGREE_TO_RAD = 3.14 / 180;

    double coordinate [ 3 ], rotation [ 3 ], angle_degree;
    GLdouble inner_radius, outer_radius;
    GLint nsides, rings;

    GlutTorus (

        const GLdouble inner_radius,
        const GLdouble outer_radius,
        GLint nsides,
        GLint rings

    );

    void draw ();

    void rotateX ( const double angle_degree );
    void rotateY ( const double angle_degree );
    void rotateZ ( const double angle_degree );

};

#endif