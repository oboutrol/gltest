#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glut.h>

/* Old code with no refresh -> init and static
 *
 *
 *

void renderFunction()
{
    //glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glColor3f(1.0, 1.0, 1.0);
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5, -0.5, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();

    glutSwapBuffers();
    //glFlush();
}
*/

float angle = 0.0f;

void renderFunction()
{
    //glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glColor3f(1.0, 1.0, 1.0);
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    
    glLoadIdentity();

    gluLookAt(	0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

    glRotatef(angle, 0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);
        glVertex3f(-2.0f, -2.0f, 0.0f);
        glVertex3f(2.0f, 0.0f, 0.0);
        glVertex3f(0.0f, 2.0f, 0.0);
    glEnd();

    angle += 0.1f;
    glutSwapBuffers();
    //glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");

    glutDisplayFunc(renderFunction);
    glutIdleFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
