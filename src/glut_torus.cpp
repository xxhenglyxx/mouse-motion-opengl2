
#include "glut_torus.h"

GlutTorus::GlutTorus (

    const GLdouble inner_radius,
    const GLdouble outer_radius,
    GLint nsides,
    GLint rings

) : inner_radius ( inner_radius ), outer_radius ( outer_radius ), nsides ( nsides ), rings ( rings ), angle_degree ( 0 ) {

};

void GlutTorus::rotateX ( const double angle_degree ) {

    this -> angle_degree += angle_degree;
    this -> rotation [ 0 ] = 1.0;

};

void GlutTorus::rotateY ( const double angle_degree ) {

    this -> angle_degree += angle_degree;
    this -> rotation [ 1 ] = 1.0;

};

void GlutTorus::rotateZ ( const double angle_degree ) {

    this -> angle_degree += angle_degree;
    this -> rotation [ 2 ] = 1.0;

};

void GlutTorus::draw () {

    const double ( & coord ) [ 3 ] = this -> coordinate;
    const double ( & rotate ) [ 3 ] = this -> rotation;

    glTranslated (

        coord [ 0 ],
        coord [ 1 ],
        coord [ 2 ]

    );

    glRotated (

        this -> angle_degree,
        rotate [ 0 ],
        rotate [ 1 ],
        rotate [ 2 ]

    );

    glutWireTorus (

        this -> inner_radius,
        this -> outer_radius,
        this -> nsides,
        this -> rings

    );

};