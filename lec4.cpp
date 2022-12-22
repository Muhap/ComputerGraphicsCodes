#include<GL/freeglut.h>
#include<math.h>
// import mathematical library

void display()
{
    gluOrtho2D(-300,300,-200,200);
    // sets up a two-dimensional orthographic viewing region

    glMatrixMode(GL_PROJECTION);
    // specify which matrix is the current matrix
    // GL_PROJECTION : Applies subsequent matrix operations to the projection matrix stack.

    glLoadIdentity();
    // replace the current matrix with the identity matrix

    float x , y , i , r = 150;
    // Creating a variables which will carry the x , y coordinates of the point P that draws the circle

    glBegin(GL_POINTS);

    glPointSize(8.0); // increase the points size

    glColor3f(1.0 , 1.0 , 0.0); // choose the color of the circle

    // creating a for loop for drawing the circle
    for (i=0 ; i <= 2 * M_PI ; i+=0.000001)
    {
        x = r * cos(i);
        y = r * sin(i);
        glVertex2i(x , y); // function used to draw a point taking two integer numbers
    }
    glEnd();
    glFlush(); // Increase the process speed
}




int main(int argc , char** argv)
{
    glutInit(&argc , argv);
    // Window Initialization .

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Initialize the working mode .
    // GLUT_SINGLE means using single buffer .
    // GLUT_RGB means using RGB color mode ( red , green , blue ).

    glutInitWindowPosition(100,100);
    //Initialize the position of windows in pixels.

    glutInitWindowSize(600,400);
    // Set window length and width in pixels.

    glutCreateWindow("New Window");
    // Creating the window.

    glutDisplayFunc(display);
    // This is an event handler calls the display

    glutMainLoop();
    // Make the code running forever except when you close it.


    return 0;
}
