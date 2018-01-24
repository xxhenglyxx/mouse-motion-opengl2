
#include <iostream>

#if __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#elif __WINDOW__
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#ifndef MODULES_H
#define MODULES_H

namespace NonStd {

    class Camera {

        private:

            double
                * eye_coordinate,
                * reference_coordinate,
                * vector_up_coordinate;

        public:

            Camera ();
            ~Camera ();

            void lookAt (

                const double eye_x,
                const double eye_y,
                const double eye_z,
                const double ref_x,
                const double ref_y,
                const double ref_z,
                const double vec_x,
                const double vec_y,
                const double vec_z

            );

            void look ();

            void setEyeX ( const double x );
            void setEyeY ( const double y );
            void setEyeZ ( const double z );

            void setReferenceX ( const double x );
            void setReferenceY ( const double y );
            void setReferenceZ ( const double z );

            void setVectorUpX ( const double x );
            void setVectorUpY ( const double y );
            void setVectorUpZ ( const double z );

    };

    void setPerspectiveView (

        const double foxy,
        const double aspect_ratio,
        const double near_plane,
        const double far_plane

    );

    void setOrthographicView (

        const double frame_left_length,
        const double frame_right_length,
        const double frame_bottom_length,
        const double frame_top_length,
        const double near_plane,
        const double far_plane

    );

    template < typename T >
    static void log ( const T log_message ) {

        std::cout << log_message << std::endl;

    };

};

#endif