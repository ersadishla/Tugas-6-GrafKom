#include <cstdlib>
// Tempat library glut.h ada pada folder GL
#include <GL/glut.h>
// Include yang digunakan untuk mempermudah pembacaan file bitmap
#include "RgbImage.h"

// Variabel untuk menyimpan BMP file bitmap
GLuint	texture[1];

// Variabel untuk menyimpan penambahan sudut
static GLfloat theta[] = { 0.0,0.0,0.0 };

// Variabel untuk menyimpan arah putaran
static GLint axis = 1;

// Variabel untuk menyimpan nama file yang digunakan untuk texture
char* filename = "./bg.bmp";

// Fungsi untuk membaca file bitmap
void loadTextureFromFile(char *filename)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);

	// Deklarasi texture[0] sebagai tempat menyimpan bitmap
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	// Fungsi untuk menyesuaikan besar bitmap
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Pembuatan texture
	glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
}

// Fungsi callback utama, melakukan render gambar dan texture
void display(void)
{
	// Membersihkan buffer frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glLoadIdentity();

	// Melakukan rotasi
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

	// Menggambar sisi yang mempunyai 4 titik
	glBegin(GL_QUADS);
	//Sisi Depan
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // E
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  // H
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);  // B
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  // A
	//Sisi Atap Depan
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  // A
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  // B
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, 2.0f);  // I
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 0.0f, 2.0f);  // J
	//Sisi Belakang
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);  // G
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  // F
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  // D
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);  // C
	//Sisi Atap Belakang
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);  // C
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  // D
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 0.0f, 2.0f);  // J
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 0.0f, 2.0f);  // I
	//Sisi Kanan
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  // H
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);  // G
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);  // C
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);  // B
	//Kiri
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  // F
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // E
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  // A
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  // D
	//Sisi Bawah
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  // F
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);  // G
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);  // H
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // E
	glEnd();

	// Menggambar sisi yang mempunyai 3 titik
	glBegin(GL_TRIANGLES);
	//Sisi Atap Kanan
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  // B
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);  // C
	glTexCoord2f(0.5f, 0.5f); glVertex3f(1.0f, 0.0f, 2.0f);  // I
	//Sisi Atap Kiri
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  // D
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  // A
	glTexCoord2f(0.5f, 0.5f); glVertex3f(-1.0f, 0.0f, 2.0f);  // J
	glEnd();

	glFlush();
	glDisable(GL_TEXTURE_2D);
}

// Fungsi callback, untuk memutar sesuai sudut yang dipilih
void spinCube()
{
	theta[axis] += 0.02;
	// Jika lebih dari 360 maka akan dikembalikan ke 0
	if (theta[axis] > 360.0) theta[axis] -= 360.0;
	display();
}

// Fungsi callback, untuk memilih sudut yang diputar
void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}

// Fungsi untuk melakukan re-Shape
void myReshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	// Mengganti matriks yang sekarang dengan matriks identitas
	glLoadIdentity();
	// Mendefinisikan matriks proyeksi ortografi 2D
	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	// Menentukan viewport
	glViewport(0, 0, w, h);
}

// Fungsi utama
int main(int argc, char **argv)
{
	// Inisialisasi library GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	// Inisialisasi ukuran display
	glutInitWindowSize(500, 500);
	// Inisialisasi posisi display
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Spinning textured house");

	// Fungsi untuk memanggil file bitmap yang telah dipilih
	loadTextureFromFile(filename);

	// Melakukan display callback untuk display saat ini
	glutDisplayFunc(display);
	// Melakukan callback untuk fungsi myReshape
	glutReshapeFunc(myReshape);
	// Melakukan callback ketika sedang idle
	glutIdleFunc(spinCube);
	// Melakukan callback untuk trigger mouse
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	// Masuk ke dalam GLUT loop
	// Harus dipanggil setidaknya sekali, akan berjalan terus
	glutMainLoop();
	return 0;
}
