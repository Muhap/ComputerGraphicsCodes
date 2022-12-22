#include<GL/freeglut.h>
#include<stdio.h>
#include<math.h>


int first=0 , xs , ys , xf , yf; //variables of the starting point and ending point of the line

char initialpoint[10] , finalpoint[10]; // char array to display the coordinates of each point

void *font = GLUT_BITMAP_HELVETICA_18; // the font of the display



// function to display the coordinates of the point in window using the arrays in line 5

void showstring(int x , int y , char *string)
{
    glRasterPos2i(x,y);
    int str_length = (int) strlen(string);
    for(int i=0 ; i <= str_length ; i++)
    {
        glutBitmapCharacter(font , string[i]); // renders a bitmap character using OpenGL
    }
}

// a function that draws a pixel

void drawpixel(GLint x, GLint y)
{
    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}


// a function of the bresenham algorithm to draw a line between two points in windows

void bresenham(int x1 , int y1 , int x2 , int y2)
{
    int dx , dy , p0;
    dx = x2 - x1 ;
    dy = y2 - y1 ;
    int xinc = (dx < 0) ? -1 : 1 ;
    int yinc = (dy < 0) ? -1 : 1 ;

    dx = abs(dx) ;
    dy = abs(dy) ;

    int xk = x1 ;
    int yk = y1 ;

    if (dy<dx)
    {
        p0 = 2*dy-dx;
        drawpixel(x1,y1);
        for (int i=x1 ; i < x2 ; i++)
        {
            if(p0 < 0)
            {
                drawpixel(++xk , yk);
                p0+= 2*dy;
            }
            else
            {
                drawpixel(++xk, yk += yinc);
                p0+= 2*dy - 2*dx ;
            }
        }
    }
    else{

         p0 = 2*dx-dy;
        drawpixel(x1,y1);
        for (int i=y1 ; i < y2 ; i++)
        {
            if(p0 < 0)
            {
                drawpixel(xk , ++yk);
                p0+= 2*dy;
            }
            else
            {
                drawpixel(xk += xinc, yk);
                p0+= 2*dx - 2*dy ;
            }
        }


    }

}



// a function to display the line and the coordinates of the two points

void display (void)
{
    glClearColor( 0.0 , 0.0 , 0.0 , 0.0 );
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1.0 , 0.0 , 0.0 );
    showstring(xs+5,ys,initialpoint);
    showstring(xf+5,yf,finalpoint);

    if(first == 0)
    {
        int dx = xf-xs ;
        int dy = yf-ys ;
        if(abs(dy) < abs(dx))
        {
            if(xs < xf)
                bresenham(xs,ys,xf,yf);
            else
                bresenham(xf,yf,xs,ys);
        }
        else
        {
            if(ys < yf)
                bresenham(xs,ys,xf,yf);
            else
                bresenham(xf,yf,xs,ys);
        }
    }
    glFlush();
}


/*
    a function stores the coordinates of the position where the user right click on the window for the first time
    as a starting point for the line and the second click for the finishing point of the line
*/
void mouse (int bnt , int state , int x , int y)
{
    if(bnt == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        switch(first) // first is a global variable switching between 1 , 0 indicates if the click is the first or second
        {
        case 0:
            sprintf(initialpoint, " "); // sprintf() function sends formatted output to a string pointed to, by str
            sprintf(finalpoint, " ");
            xs = x;
            ys = 600 - y;
            sprintf(initialpoint, "%d,%d" , xs , ys);
            first = 1 ;
            break;
        case 1:
            xf = x ;
            yf = 600 - y;
            sprintf(finalpoint, "%d,%d" , xf , yf);
            first = 0;
            break;
        }
    }
}


int main(int argc , char **argv)
{
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // select display mode
    glutInitWindowPosition(0,0); // set the initial window position
    glutInitWindowSize(800,600); // set the initial window size
    glutCreateWindow("Bresenham's LDA"); // creates a top-level window
    gluOrtho2D(0,800,0,600); // sets up a two-dimensional orthographic viewing region
    glutDisplayFunc(display); //  sets the display callback for the current window
    glutMouseFunc(mouse); /*    sets the mouse callback for the current window.
                                When a user presses and releases mouse buttons in the window    */

    glutMainLoop(); // enters the GLUT event processing loop
    return 0;
}
