// Importing free glut library.
#include<GL/freeglut.h>


//Creating a function to display a color in window initialized in main function

void display1()
{
    glClearColor(1,0,0,1);
    // Setting the color which will clear the window
    glClear(GL_COLOR_BUFFER_BIT);
    // applying the color in window

    glFlush();
    // Increase the process speed

}
//-------------------------------------------------------------------------------------------------------------



//Creating a function to display a red triangle in the window initialized in main

void display2()
{
    // This Combination can be given a primitive and it will draw it
    glBegin(GL_TRIANGLES);

    // choose coloring type which is 3 f ; Accepting 3 float point
    // red color
    glColor3f(1.0 , 0.0 , 0.0);

    // Set three vertices of the triangle
    glVertex3f(-0.5 , -0.5 , 0.0);
    glVertex3f(0.5, -0.5 , 0.0);
    glVertex3f(0.0 , 0.7 , 0.0);

    glEnd();

    glFlush();
    // Increase the process speed

}

//-------------------------------------------------------------------------------------------------------------


//Creating a function to display a multi-colored triangle in the window initialized in main

void display3()
{
    // This Combination can be given a primitive and it will draw it
    glBegin(GL_TRIANGLES);

        // choose coloring type which is 3 f ; Accepting 3 float point

        // red color
        glColor3f(1.0 , 0.0 , 0.0);
        glVertex3f(-0.5 , -0.5 , 0.0);

        //green color
        glColor3f(0.0 , 1.0 , 0.0);
        glVertex3f(0.5, -0.5 , 0.0);

        //blue color
        glColor3f(0.0 , 0.0 , 1.0);
        glVertex3f(0.0 , 0.7 , 0.0);

    glEnd();

    glFlush();
    // Increase the process speed
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

    glutDisplayFunc(display3);
    // This is an event handler calls the display 1 or display 2 function

    glutMainLoop();
    // Make the code running forever except when you close it.


    return 0;
}

