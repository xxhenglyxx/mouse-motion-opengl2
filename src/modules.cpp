
#include "modules.h"

namespace NonStd {

    Camera::Camera () :
    eye_coordinate ( new double [ 3 ] { .0, .0, .0 } ),
    reference_coordinate ( new double [ 3 ] { .0, .0, .0 } ),
    vector_up_coordinate ( new double [ 3 ] { .0, .0, .0 } ) {

    };

    Camera::~Camera () {

        delete [] this -> eye_coordinate;
        delete [] this -> reference_coordinate;
        delete [] this -> vector_up_coordinate;

    };

    void Camera::setEyeX ( const double x ) {

        this -> eye_coordinate [ 0 ] += x;

    };

    void Camera::setEyeY ( const double y ) {

        this -> eye_coordinate [ 1 ] += y;

    };

    void Camera::setEyeZ ( const double z ) {

        this -> eye_coordinate [ 2 ] += z;

    };

    void Camera::setReferenceX ( const double x ) {

        this -> reference_coordinate [ 0 ] += x;

    };

    void Camera::setReferenceY ( const double y ) {

        this -> reference_coordinate [ 1 ] += y;

    };

    void Camera::setReferenceZ ( const double z ) {

        this -> reference_coordinate [ 2 ] += z;

    };

    void Camera::setVectorUpX ( const double x ) {

        this -> vector_up_coordinate [ 0 ] += x;

    };

    void Camera::setVectorUpY ( const double y ) {

        this -> vector_up_coordinate [ 1 ] += y;

    };

    void Camera::setVectorUpZ ( const double z ) {

        this -> vector_up_coordinate [ 2 ] += z;

    };

    void Camera::lookAt (

        const double eye_x,
        const double eye_y,
        const double eye_z,
        const double ref_x,
        const double ref_y,
        const double ref_z,
        const double vec_x,
        const double vec_y,
        const double vec_z

    ) {

        this -> setEyeX ( eye_x );
        this -> setEyeY ( eye_y );
        this -> setEyeZ ( eye_z );

        this -> setReferenceX ( ref_x );
        this -> setReferenceY ( ref_y );
        this -> setReferenceZ ( ref_z );

        this -> setVectorUpX ( vec_x );
        this -> setVectorUpY ( vec_y );
        this -> setVectorUpZ ( vec_z );

    };

    void Camera::look () {

        gluLookAt (

            this -> eye_coordinate [ 0 ],
            this -> eye_coordinate [ 1 ],
            this -> eye_coordinate [ 2 ],
            this -> reference_coordinate [ 0 ],
            this -> reference_coordinate [ 1 ],
            this -> reference_coordinate [ 2 ],
            this -> vector_up_coordinate [ 0 ],
            this -> vector_up_coordinate [ 1 ],
            this -> vector_up_coordinate [ 2 ]

        );

    };

    void setPerspectiveView (

        const double foxy,
        const double aspect_ratio,
        const double near_plane,
        const double far_plane

    ) {

        glMatrixMode ( GL_PROJECTION );
        glLoadIdentity ();
        gluPerspective ( foxy, aspect_ratio, near_plane, far_plane );
        glMatrixMode ( GL_MODELVIEW );

    };

};