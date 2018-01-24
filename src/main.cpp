
#include "modules.h"
#include "transformation.h"
#include "glut_torus.h"

#if __APPLE__
#include <GLUT/glut.h>
#elif __WINDOW__
#include <GL/freeglut.h>
#endif

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define GRAVITY 9.8

// global vars
NonStd::Camera camera = NonStd::Camera ();
GlutTorus torus (

    static_cast < GLdouble > ( 3.0 ),
    static_cast < GLdouble > ( 10.0 ),
    static_cast < GLint > ( 10 ),
    static_cast < GLint > ( 100 )

);

int mouse_press;
double angle_interpolate;

void render ();
void slowRotateTransition ();
void mouseOnClick ( int button, int state, int x, int y );
void windowOnChange ( int width, int height );

int main ( int args_len, char ** args_context ) {

    glutInit ( &args_len, args_context );
    glutInitDisplayMode ( GLUT_DOUBLE );
    glutInitWindowSize ( WINDOW_WIDTH, WINDOW_HEIGHT );
    glutInitWindowPosition ( 100, 100 );
    glutCreateWindow ( "Mouse Motion - OpenGL2" );

    camera.lookAt ( .0, .0, 30.0, .0, .0, -1.0, .0, 1.0, .0 );
    camera.look ();

    glutDisplayFunc ( render );
    glutMouseFunc ( mouseOnClick );
    glutReshapeFunc ( windowOnChange );

    glutMainLoop ();

    return 0;

};

void render () {

    glClearColor ( .2, .3, .5, .8 );
    glClear ( GL_COLOR_BUFFER_BIT );

    glPushMatrix ();

        torus.draw ();

        // local glutIdleFunc
        glutIdleFunc ( slowRotateTransition );

    glPopMatrix ();

    glFlush ();
    glutSwapBuffers ();

};

void windowOnChange ( int width, int height ) {

    glViewport ( 0, 0, width, height );

    NonStd::setPerspectiveView ( 60, static_cast < GLfloat > ( width ) / static_cast < GLfloat > ( height ), .01, 300.0 );

};

void mouseOnClick ( int button, int state, int x, int y ) {

    if ( button == 0 ) {

        mouse_press = 0;

    } else {

        mouse_press = 1;

    }

    angle_interpolate = 30.0;

};

void slowRotateTransition () {

    if ( angle_interpolate > .0 ) {

        if ( mouse_press == 0 ) {

            torus.rotateX ( angle_interpolate / GRAVITY );

        } else {

            torus.rotateY ( angle_interpolate / GRAVITY );

        }

    }

    -- angle_interpolate;

    glutPostRedisplay ();

};