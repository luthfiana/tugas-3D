#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

/*
Kelas IF-9
Nama:
     1. 10107286 - Restiana Ayunita 
     2. 10108431 - Luthfiana Adityarini
     3. 10108439 - R. Adzie Ramadani Kusumah
     4. 10108445 - Alfiyah 
*/

static int a = 0;

void displayKepala(void)
{
	glMatrixMode(GL_PROJECTION); // set the view volume shape
	glLoadIdentity();
	glOrtho(-2.0*64/48.0, 2.0*64/48.0, -2.0, 2.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW); // position and aim the camera
	glLoadIdentity();
	gluLookAt(2.0, 10.0, 2.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
	
	glClear(GL_COLOR_BUFFER_BIT); // clear the screen
	
	
	glRotatef((GLfloat) a, 0.0,1.0,0.0);
	
	//sphere
    glColor3d(1,1,1);     	
	glPushMatrix();	
	glScaled(2,2,2);
	glTranslated(0.0,0.4,0.0);	
	glRotated(43,0,3,0);
	glutSolidSphere(0.25, 10, 20);
	glPopMatrix();
    
    glRotatef((GLfloat) a, 0.0,0.0,0.0);
    glColor3d(0,0,0);
    glPushMatrix();	
	glTranslated(-0.3,0.35,0.0);	
	glRotated(-53,0,3,0);
	glutSolidSphere(0.1, 3, 8);
	glPopMatrix();	
	
	glPushMatrix();	
	glTranslated(0.2,1.5,0.0);	
	glRotated(-41,0,3,0);
	glutSolidSphere(0.1, 3, 8);
	glPopMatrix();	
	
	//cone
	glRotatef((GLfloat) a, 0.0,0.0,0.0);
	glColor3d(1,0,0);
	glPushMatrix();	
	glScaled(2,2,2);
	glTranslated(0.0,1,0.0);	
	glRotated(-135,0,1,0);
	glutSolidCone(0.2, 0.5, 10, 20);
	glPopMatrix();
	
	

	glFlush();
}

void reshape(int w, int h){
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (w <= h) {
glOrtho(-1.5, 1.5, -1.5 * (GLfloat) h / (GLfloat) w, 1.5 * (GLfloat) h
/ (GLfloat) w, -10.0, 10.0);
} else {
glOrtho(-1.5 * (GLfloat) w / (GLfloat) h, 1.5 * (GLfloat) w
/ (GLfloat) h, -1.5, 1.5, -10.0, 10.0);
}
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

// glLoadIdentity();

}

void keyboard(unsigned char key, int x, int y){
switch(key){
case 'a' : a = (a+1) % 90;
glutPostRedisplay();
break;
case 'A' : a = (a-1) %90;
glutPostRedisplay();
break;

default : break;
}
}




int main(int argc, char** argv){
glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tugas Bentuk 3D");
	glutDisplayFunc(displayKepala);
    glutKeyboardFunc(keyboard);
	glClearColor(0,0,0,0);  
	glViewport(0, 0, 640, 480);
	glutMainLoop();

}
