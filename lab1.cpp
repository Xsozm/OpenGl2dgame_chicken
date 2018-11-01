#include <GL/glut.h>
void Display();

int main(int argc, char** argr) {
    glutInit(&argc, argr);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Lab 01");
    glutDisplayFunc(Display);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glPointSize(9.0);
    //glLineWidth(9.0);
    gluOrtho2D(0.0, 1000.0, 0.0, 600.0);
    glutMainLoop();
    return 0;
}

/*

GL_POINTS : Treats each vertex as a single point.

GL_LINES :Treats each pair of vertices as an independent line segment

GL_LINE_STRIP : Draws a connected group of line segments from the first vertex  to the last.

GL_LINE_LOOP  : Draws a connected group of line segments from the first vertex to the last, then back to the first.

GL_TRIANGLES : Treats each triplet of vertices as an independent triangle

GL_TRIANGLE_STRIP :Draws a connected group of triangles.  One triangle is defined for each vertex presented after the first two vertices

GL_TRIANGLE_FAN :Draws a connected group of triangles.One triangle is defined for each vertex presented after the first two vertices

GL_QUADS :Treats each group of four vertices as an independent quadrilateral.

GL_QUAD_STRIP :Draws a connected group of quadrilaterals.One quadrilateral is defined for each pair of vertices presented after the first pair.

GL_POLYGON :Draws a single,convex polygon.Vertices 1 through N define this polygon

*/


void Display() {
    glClear(GL_COLOR_BUFFER_BIT);


//    glColor3f(1.0f, 0.0f, 0.0f);
//    glBegin(GL_POINTS);
//    glVertex3f(100.0f, 100.0f, 0.0f);
//    glVertex3f(200.0f, 100.0f, 0.0f);
//    glEnd();


//    glPushMatrix(); // marking the initial state of the transformations matrix
//
//    //-----------------
//    glScaled(3,1,1);
//
////    glBegin(GL_LINES);
////    glColor3f(1.0f, 0.0f, 0.0f);
////    glVertex3f(10.0f, 10.0f, 0.0f);
////    //glVertex3f(20.0f, 20.0f, 0.0f);
////    //glVertex3f(30.0f, 30.0f, 0.0f);
////    glColor3f(0.0f, 0.0f, 1.0f);
////    glVertex3f(200.0f, 200.0f, 0.0f);
//
//    glPopMatrix();


    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(10.0f, 10.0f, 0.0f);
    //glVertex3f(20.0f, 20.0f, 0.0f);
    //glVertex3f(30.0f, 30.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(200.0f, 200.0f, 0.0f);


    glEnd();



//    glBegin(GL_LINE_LOOP); // GL_LINE_STRIP, GL_LINE_LOOP
//    //glColor3f(1.0f, 0.0f, 0.0f);
//    glVertex3f(10.0f, 10.0f, 0.0f);
//    glVertex3f(20.0f, 20.0f, 0.0f);
//    glVertex3f(35.0f, 30.0f, 0.0f);
//    //glColor3f(0.0f, 0.0f, 1.0f);
//    glVertex3f(200.0f, 255.0f, 0.0f);
//    glEnd();


//
//    glBegin(GL_TRIANGLES);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glVertex3f(100.0f, 100.0f, 0.0f);
//
//    glColor3f(0.0f, 1.0f, 0.0f);
//    glVertex3f(150.0f, 100.0f, 0.0f);
//
//    glColor3f(0.0f, 0.0f, 1.0f);
//    glVertex3f(125.0f, 50.0f, 0.0f);
//
//    glEnd();


    /*
    glBegin(GL_TRIANGLES); // GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
    glVertex3f(100.0f, 100.0f, 0.0f);
    glVertex3f(150.0f, 100.0f, 0.0f);
    glVertex3f(125.0f, 50.0f, 0.0f);
    glVertex3f(150.0f, 150.0f, 0.0f);
    glVertex3f(250.0f, 250.0f, 0.0f);
    glVertex3f(350.0f, 150.0f, 0.0f);
    glEnd();
    //*/

    /*
    glBegin(GL_QUADS); // GL_QUAD_STRIP
    glVertex3f(100.0f, 100.0f, 0.0f);
    glVertex3f(100.0f, 200.0f, 0.0f);
    glVertex3f(200.0f, 200.0f, 0.0f);
    glVertex3f(200.0f, 100.0f, 0.0f);

    glVertex3f(300.0f, 300.0f, 0.0f);
    glVertex3f(500.0f, 500.0f, 0.0f);
    glVertex3f(700.0f, 500.0f, 0.0f);
    glVertex3f(500.0f, 300.0f, 0.0f);
    glEnd();
    //*/

    /*
    glBegin(GL_POLYGON);
    glVertex3f(100.0f, 100.0f, 0.0f);
    glVertex3f(100.0f, 200.0f, 0.0f);
    glVertex3f(200.0f, 200.0f, 0.0f);
    glVertex3f(200.0f, 100.0f, 0.0f);
    glVertex3f(300.0f, 300.0f, 0.0f);
    glVertex3f(500.0f, 500.0f, 0.0f);
    glVertex3f(700.0f, 500.0f, 0.0f);
    glVertex3f(500.0f, 300.0f, 0.0f);
    glEnd();
    //*/


    glFlush();
}
