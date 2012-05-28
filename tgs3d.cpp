/*
Kelas IF-9
Nama:
     1. 10107286 - Restiana Ayunita 
     2. 10108431 - Luthfiana Adityarini
     3. 10108439 - R. Adzie Ramadani Kusumah
     4. 10108445 - Alfiyah 
*/
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

static int spin=0;
static float lampu = 0.0;

void display(void)
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glPushMatrix();
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glTranslatef(0.0f, 0.0f, -8.0f);
  
//======Rotasi==========     
	glRotatef(spin, 0.0, 0.1, 0.0); 

//cahaya
	GLfloat lightColor1[] = {1.0f, 1.0f, 1.0f, 1.0f };//0.0f, 0.0f, -8.0f
     GLfloat lightPos1[] = {0.75, 0.40, 0.0,0.0};
     glLightfv(GL_LIGHT1, GL_AMBIENT, lightColor1);
     glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

//+++++++tiang lampu+++++++
	glPushMatrix();
		glColor3f(0.3, 0.2, 0.1);       //glColor3f(0.4, 0.8, 0.1);-->warna hijau
		glTranslatef(0.1, 0.8, 0.0);
		glScalef(0.1, 2.40, 0.1);
		glutSolidCube(0.5);
	glPopMatrix();

//++++++++++++++++dasar lampu++++++++++++++
	glPushMatrix();
		glColor3f(180, 180, 179);
		glTranslatef(0.1, 0.1, 0.0);
		glScalef(0.3, 0.04, 0.3);
		glutSolidSphere(0.5, 30, 30);
	glPopMatrix();

//++++++++++++++++penyangga lampu++++++++++++++
	glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		glTranslatef(0.1, 0.35, 0.0);
		glScalef(0.2, 0.99, 0.2);
		glutSolidCube(0.5);
	glPopMatrix();

//++++++++++++++++penahan lampu1++++++++++++++
	glPushMatrix();
		glColor3f(0.3, 0.2, 0.1);
		glTranslatef(0.35, 1.28, 0.0);
		glScalef(1.5, 0.1, 0.1);
		glutSolidCube(0.5);
	glPopMatrix();

//++++++++++++++++penahan lampu2++++++++++++++
	glPushMatrix();
		glColor3f(0.3, 0.2, 0.1);
		glTranslatef(0.20, 1.15, 0.0);
		glScalef(0.7, 0.1, 0.1);
		glutSolidCube(0.5);
	glPopMatrix();


//++++++++++++++++penahan lampu3++++++++++++++
	glPushMatrix();
		glColor3f(0.3, 0.2, 0.1);
		glTranslatef(0.20, 1.20, 0.0);
		glScalef(0.1, 0.5, 0.1);
		glutSolidCube(0.5);
	glPopMatrix();

//++++++++++++++++atap lampu++++++++++++++
	glPushMatrix();
		glColor3f(0.5, 0.3, 0.2);
		glTranslatef(0.75, 1.23, 0.0);
		glScalef(0.3, 0.04, 0.3);
		glutSolidSphere(0.8, 210, 10);
	glPopMatrix();

//++++++++++++++paku penahan lampu+++++++++++
	glPushMatrix();
		glColor3f(180, 180, 179);
		glTranslatef(0.75, 1.28, 0.0);
		glScalef(0.3, 0.3, 0.3);
		glutSolidSphere(0.10, 10, 10);
	glPopMatrix();

//++++++++++++++bola lampu+++++++++++
	glPushMatrix();
		glColor3f(1.0, 1.0, 0.0+lampu);
		glTranslatef(0.75, 1.15, 0.0);
		glScalef(0.8, 0.8, 0.8);
		glutSolidSphere(0.10, 20, 20);
	glPopMatrix();

	glPopMatrix();
	glFlush();
}
void reshape(int w, int h)
{
     glViewport(0, 0, (GLsizei) w, (GLsizei) h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     if (w<=h)
		glOrtho(-10, 10, -10*(GLfloat)h/(GLfloat)w,   
		10*(GLfloat)h/(GLfloat)w, -100.0, 100.0);
     else
		glOrtho(-1.5*(GLfloat)w/(GLfloat)h,   
		1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0); 
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
}

void init(void)
{
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_COLOR_MATERIAL);
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     
     glEnable(GL_NORMALIZE);
     glShadeModel(GL_SMOOTH);
     GLfloat ambientColor[] = {0.3f, 0.3f, 0.3f, 1.0f};
     glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
     GLfloat lightColor0[] = {1.0f, 1.0f, 1.0f, 1.0f};
     GLfloat lightPos0[] = {1.0f, 1.0f, 1.0f, 1.0f};
     glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
     glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
     
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
	case 'a':
		spin = (spin + 5) % 360;
		glutPostRedisplay();
	break;
	case'd':
		spin = (spin - 5) % 360;
		glutPostRedisplay();
	break;
	case 'q':
		glEnable(GL_LIGHT1);
		lampu = lampu + 0.4;
		glutPostRedisplay();
	break;
	case 'w':
		glDisable(GL_LIGHT1);
		lampu = lampu - 0.4;
		glutPostRedisplay();
	break;
	default:
	break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 1024);
    glutInitWindowPosition(200, 80);
    glutCreateWindow("Lampu");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
    //glutIdleFunc(berputar);
    //glutInitializeFunc(Initialize);
    glutMainLoop();
    return 0;/* ISO C requires main to return int. */
}
