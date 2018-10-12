#include <string.h>
#include <stdio.h>
#include <GL/glut.h>

// unit
int main(int argc, char **argv)
{
    argc++;

    char *args[argc];
    char *option = "-sync";

    args[argc-1] = option;
    glutInit(&argc, args);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Window 1");

    glutMainLoop();

    return 0;
}