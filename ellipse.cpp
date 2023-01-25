#include<GL/freeglut.h>

// point struct
struct screen_point_struct{

GLint x , y ;

};

// point class appears on screen
class Point_on_screen{

public :
    GLint x , y;
public :
    Point_on_screen(){

    x = 0;
    y = 0;

    }
    void setcord (GLint x_val , GLint y_val)
    {
        x = x_val;
        y = y_val;
    }
    GLint getx() const{
    return x;}
    GLint gety() const{
    return y;}

    void incx(){
    x++;}
    void incy(){
    y++;}

    void decy(){
    y--;}

};
// function setting a pixel
void setpixel(GLint x , GLint y)
{
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}

// plotting all parts coordinates of ellipse
void plotFourPoints(screen_point_struct center , Point_on_screen p )
{
    setpixel(center.x + p.getx() , center.y + p.gety());
    setpixel(center.x - p.getx() , center.y + p.gety());
    setpixel(center.x + p.getx() , center.y - p.gety());
    setpixel(center.x - p.getx() , center.y - p.gety());
}
// midpoint algorithm function
void MidpointAlg(screen_point_struct center , GLint rx , GLint ry)
{
    Point_on_screen current_point;
    current_point.setcord(0 , ry);
    GLint p1 = ry*ry - rx*rx*ry + 0.25*rx*rx;
    GLint dx = 2*ry*ry*current_point.getx();
    GLint dy = 2*rx*rx*current_point.gety();
    while(dx < dy)
    {
        plotFourPoints(center , current_point);
        current_point.incx();

        if(p1 < 0)
        {
            dx = 2 * ry * ry * current_point.getx();
            p1 = p1 + rx*rx + dx;
        }
        else{

            current_point.decy();
            dx = 2*ry*ry*current_point.getx();
            dy = 2*rx*rx*current_point.gety();
            p1 = p1 + dx + ry*ry -dy ;
        }
    }
    GLint p2 = ry*ry*(current_point.getx() + 0.5) * (current_point.getx() + 0.5)
        + rx * rx * (current_point.gety() -1 ) * (current_point.gety() -1 ) - rx*rx*ry*ry;
    while(current_point.gety() >= 0)
    {
        plotFourPoints(center , current_point);
        current_point.decy();

        if(p2 > 0)
        {
            dy = 2*rx*rx*current_point.gety();
            p2 = p2 + rx * rx - dy;
        }
        else{

            current_point.incx();
            dx = 2*ry*ry*current_point.getx();
            dy = 2*rx*rx*current_point.gety();
            p2 = p2 + dx + rx*rx -dy ;
        }
    }


}


// initializing the window
void init(){
glClearColor(1 , 1 , 1 , 1);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,600,0,600);

}
// display function
void display(){
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(5);

screen_point_struct center ;
center.x=300;
center.y=300;
glColor3f(0,0,0);
// algorithm
MidpointAlg(center , 200 , 100);

glFlush();

}
int main(int argc , char **argv)
{
    glutInit(&argc , argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("ellipse");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}










