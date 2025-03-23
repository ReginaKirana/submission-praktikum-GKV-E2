/* TUGAS PRAKTIKUM GKV - PERTEMUAN 2
 * Nama		: Regina Sasikirana Farikh
 * NIM		: 24060123140155
 * Kelas	: E
 * Lab		: E2
 */
 
/* TUGAS PERTEMUAN 2 - MOBIL */
/* ceritanya lagi hujan */
/* mobil bisa bergerak, 'a' untuk maju dan 'd' untuk mundur */

#include <GL/glut.h>
#include <cstdlib>  
#include <ctime>    
#include <cmath>
#include <math.h>

const int numDrops = 100;  
float rainDrops[numDrops][2];  
// Fungsi untuk menginisialisasi posisi awal tetesan hujan secara acak
void initRain() {
    srand(time(0));
    for (int i = 0; i < numDrops; i++) {
        rainDrops[i][0] = (rand() % 356 - 178) / 100.0f;
        rainDrops[i][1] = (rand() % 200 - 100) / 100.0f;
    }
}

// Fungsi menggambar latar belakang dengan gradasi biru
void drawBackground() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.2f); // Biru tua (atas)
    glVertex2f(-1.78f, 1.0f);
    glVertex2f(1.78f, 1.0f);
    glColor3f(0.3f, 0.3f, 0.6f); // Biru muda (bawah)
    glVertex2f(1.78f, -1.0f);
    glVertex2f(-1.78f, -1.0f);
    glEnd();
}

// Fungsi menggambar jalan raya yang lebih besar
void drawRoad() {
    // Jalan abu-abu (lebih besar dari sebelumnya)
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f); // Warna abu-abu gelap
    glVertex2f(-1.78f, -0.3f);
    glVertex2f(1.78f, -0.3f);
    glVertex2f(1.78f, -1.0f);
    glVertex2f(-1.78f, -1.0f);
    glEnd();
    // Garis putih putus-putus di tengah jalan
    glColor3f(1.0f, 1.0f, 1.0f); 
    glLineWidth(3);
    glBegin(GL_LINES);
    for (float x = -1.6f; x < 1.7f; x += 0.4f) {
        glVertex2f(x, -0.6f);
        glVertex2f(x + 0.2f, -0.6f);
    }
    glEnd();
}

// Fungsi menggambar roda dengan velg di tengah
void drawWheelWithGears(float cx, float cy) {
	// Lingkaran luar roda
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * 3.14159265 / 180.0;
        glVertex2f(cx + 0.08f * cos(angle), cy + 0.08f * sin(angle));
    }
    glEnd();
    // Lingkaran dalam roda (warna abu-abu gelap)
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * 3.14159265 / 180.0;
        glVertex2f(cx + 0.04f * cos(angle), cy + 0.04f * sin(angle));
    }
    glEnd();
	// Jari-jari roda (spokes)
    glColor3f(0.7f, 0.7f, 0.7f);
    for (int i = 0; i < 360; i += 60) {
        float angle = i * 3.14159265 / 180.0;
        float outerX = cx + 0.04f * cos(angle);
        float outerY = cy + 0.04f * sin(angle);
        float innerX = cx;
        float innerY = cy;
        glBegin(GL_LINES);
        glVertex2f(innerX, innerY);
        glVertex2f(outerX, outerY);
        glEnd();
    }
	// Menggambar lingkaran tengah velg
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * 3.14159265 / 180.0;
        glVertex2f(cx + 0.02f * cos(angle), cy + 0.02f * sin(angle));
    }
    glEnd();
}

// Fungsi membuat Mobil
float carX = 0.0f;  // Variabel posisi mobil
void drawCar() {
	glPushMatrix(); 
    glTranslatef(carX, 0.0f, 0.0f);  // Untuk geser mobil
	// Tambahkan lampu depan kiri
    glColor3f(1.0f, 1.0f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-0.51f, -0.35f - 0.10);
    glVertex2f(-0.42f, -0.35f - 0.10);
    glVertex2f(-0.42f, -0.30f - 0.10);
    glVertex2f(-0.51f, -0.30f - 0.10);
    glEnd();
    // Badan mobil (Oranye)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f); // Warna oranye
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.45f, -0.22f);
    glVertex2f(-0.45f, -0.22f);
    glEnd();
    // Atap mobil (Gradasi lebih gelap)
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.4f, 0.0f); // Warna oranye lebih gelap
    glVertex2f(-0.3f, -0.22f);
    glVertex2f(0.3f, -0.22f);
    glVertex2f(0.25f, 0.01f);
    glVertex2f(-0.25f, 0.01f);
    glEnd();
    // Jendela depan
    glColor3f(0.6f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.27f, -0.20f);
    glVertex2f(0.03 - 0.05f, -0.20f);
    glVertex2f(0.06 - 0.05f, -0.02f);
    glVertex2f(-0.23f, -0.02f);
    glEnd();  
    // Jendela belakang
    glColor3f(0.6f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.02f, -0.20f);
    glVertex2f(0.27f, -0.20f);
    glVertex2f(0.24f, -0.02f);
    glVertex2f(0.05f, -0.02f);
    glEnd();
    // Sekat pintu
    glColor3f(0.8f, 0.4f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.02f- 0.02, -0.50f);
    glVertex2f(0.02f -0.02, -0.22f);
    glEnd();
    // Sekat Jendela
    glColor3f(0.6f, 0.3f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, -0.48 + 0.28f);
    glVertex2f(0.03f, -0.20 + 0.18f);
    glEnd();
    // Menggambar roda depan dan belakang dengan velg
    drawWheelWithGears(-0.35f, -0.55f);
    drawWheelWithGears(0.35f, -0.55f);
	// Gagang pintu mobil depan
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(-0.25f, -0.35f);
    glVertex2f(-0.18f, -0.35f);
    glVertex2f(-0.18f, -0.33f);
    glVertex2f(-0.25f, -0.33f);
    glEnd();
    // Gagang pintu mobil belakang
    glBegin(GL_QUADS);
    glVertex2f(0.05f, -0.35f);
    glVertex2f(0.12f, -0.35f);
    glVertex2f(0.12f, -0.33f);
    glVertex2f(0.05f, -0.33f);
    glEnd();
	glPopMatrix(); 
}

// Fungsi keyboard untuk menggerakkan mobil
void keyboard(unsigned char key, int x, int y) {
    if (key == 'a' || key == 'A') {
        if (carX > -1.20f) {  // Batas kiri
            carX -= 0.1f;
        }
    }
    if (key == 'd' || key == 'D') {
        if (carX < 1.20f) {  // Batas kanan
            carX += 0.1f;
        }
    }
    glutPostRedisplay();  
}

// Fungsi Membuat Bulan
void moon(){
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8, 0.8, 0.8); // Outer part (lighter gray)
    glVertex2f(0.7, 0.7);
    int num_segments = 100;
    for (int i = 0; i <= num_segments; i++) {
        float angle = i * 2.0f * 3.14159265f / num_segments;
        float x = 0.1 * cos(angle);
        float y = 0.1 * sin(angle);
        glColor3f(0.6, 0.6, 0.6); // Inner part (darker gray)
        glVertex2f(0.7 + x, 0.7 + y);
    }
    glEnd();
}

// Fungsi untuk menampilkan teks di layar
void drawText(const char* text, float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f); // Warna putih
    glRasterPos2f(x, y); // Posisi teks di layar
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}

// Display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawBackground(); 
    drawRoad();  
    drawCar();
    moon();
    drawText("Tekan 'a' untuk maju, 'd' untuk mundur", -0.9f, 0.7f);
    glColor3f(0.5f, 0.5f, 1.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < numDrops; i++) {
        glVertex2f(rainDrops[i][0], rainDrops[i][1]);
        glVertex2f(rainDrops[i][0], rainDrops[i][1] - 0.05f);
    }
    glEnd();
    glutSwapBuffers();
}

void update(int value) {
    for (int i = 0; i < numDrops; i++) {
        rainDrops[i][1] -= 0.02f;  
        if (rainDrops[i][1] < -1.0f) {
            rainDrops[i][0] = (rand() % 356 - 178) / 100.0f;
            rainDrops[i][1] = 1.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(33, update, 0);
}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.78, 1.78, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 450);
    glutCreateWindow("Tugas Modul 3 - Mobil (ceritanya lagi hujan)");
    initGL();
    initRain();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(33, update, 0);
    glutMainLoop();
    return 0;
}
