//#include <cstdlib>
//#include <GL/glut.h>
//#include "RgbImage.h"
//GLfloat xRotated, yRotated, zRotated;
//GLuint	texture[1];			// Storage For One Texture ( NEW )
///*
//* Read a texture map from a BMP bitmap file.
//*/
//void loadTextureFromFile(char *filename)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//	glEnable(GL_DEPTH_TEST);
//
//	RgbImage theTexMap(filename);
//
//	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
//	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );
//
//
//	glGenTextures(1, &texture[0]);					// Create The Texture
//	glBindTexture(GL_TEXTURE_2D, texture[0]);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	 
//	// Typical Texture Generati on Using Data From The Bitmap
//
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
//}
//
///*
//* Draw the texture in the OpenGL graphics window
//*/
//void drawScene(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texture[0]);
//	glLoadIdentity();
//	glTranslatef(0.0, 0.0, -5);
//	glRotatef(xRotated, 1, 0, 0);
//	glRotatef(yRotated, 0, 1, 0);
//	glRotatef(zRotated, 0, 0, 1);
//
//	glBegin(GL_QUADS);
//	//Depan
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);  // Top Right Of The Texture and Quad
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  // Top Left Of The Texture and Quad
//	//Atap Depan
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  // Bottom Left Of The Texture and Quad
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  // Bottom Right Of The Texture and Quad
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, 2.0f);  // Top Right Of The Texture and Quad
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 0.0f, 2.0f);  // Top Left Of The Texture and Quad
//	//Belakang
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  // Top Right Of The Texture and Quad
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);  // Top Left Of The Texture and Quad
//	//Atap Belakang
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);  // Bottom Left Of The Texture and Quad
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  // Bottom Right Of The Texture and Quad
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 0.0f, 2.0f);  // Top Right Of The Texture and Quad
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 0.0f, 2.0f);  // Top Left Of The Texture and Quad
//	//Kanan
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);  // Top Right Of The Texture and Quad
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);  // Top Left Of The Texture and Quad
//	//Kiri
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  // Top Right Of The Texture and Quad
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  // Top Left Of The Texture and Quad
//	//Bawah
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	//Atap Kanan
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  // Bottom Left Of The Texture and Quad
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);  // Bottom Right Of The Texture and Quad
//	glTexCoord2f(0.5f, 0.5f); glVertex3f(1.0f, 0.0f, 2.0f);  // Middle Of The Texture and Quad
//	//Atap Kiri
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  // Bottom Left Of The Texture and Quad
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  // Bottom Right Of The Texture and Quad
//	glTexCoord2f(0.5f, 0.5f); glVertex3f(-1.0f, 0.0f, 2.0f);  // Middle Of The Texture and Quad
//	glEnd();
//
//	glFlush();
//	glDisable(GL_TEXTURE_2D);
//
//}
//
//void resizeWindow(int x, int y)
//{
//	if (y == 0 || x == 0) return;  //Nothing is visible then, so return
//	   //Set a new projection matrix
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	//Angle of view:40 degrees
//	//Near clipping plane distance: 0.5
//	//Far clipping plane distance: 20.0
//
//	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//	glViewport(0, 0, x, y);  //Use the whole window for rendering
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case 27:
//		exit(0);
//		break;
//	default:
//		break;
//	}
//}
//
//char* filename = "./e.bmp";
//void idleFunc(void)
//{
//	xRotated += 0.01;
//	yRotated += 0.01;
//	//zRotated += 0.01;
//	drawScene();
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(240, 240);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//
//	loadTextureFromFile(filename);
//
//	glutDisplayFunc(drawScene);
//	glutReshapeFunc(resizeWindow);
//	glutKeyboardFunc(keyboard);
//	glutIdleFunc(idleFunc);
//	glutMainLoop();
//	return 0;
//}
