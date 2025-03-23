/* TUGAS PRAKTIKUM GKV - PERTEMUAN 3
 * Nama		: Regina Sasikirana Farikh
 * NIM		: 24060123140155
 * Kelas	: E
 * Lab		: E2
 */
 
/* TUGAS PERTEMUAN 3 - LENGAN DENGAN TANGAN DAN JARI */
#include <GL/glut.h>
#include <string.h>
#include <stdio.h>

// Variabel untuk kontrol sudut
static int shoulder = 0, elbow = 0;

// Variabel untuk kontrol telapak tangan dan jari-jari
static int wrist = 0;
static int thumb[3] = {0, 0, 0};
static int index[3] = {0, 0, 0};
static int middle[3] = {0, 0, 0};
static int ring[3] = {0, 0, 0};
static int pinky[3] = {0, 0, 0};

// Faktor skala global
#define SCALE_FACTOR 1.9

// ========== JARI DENGAN 3 SEGMEN ==========
// Fungsi untuk menggambar jari dengan 3 segmen
void drawFinger(float length, float width, int joint1, int joint2, int joint3) {
    // Segmen bawah jari
    glPushMatrix();
    glRotatef((GLfloat)joint1, 0.0, 0.0, 1.0);
    glTranslatef(length/2, 0.0, 0.0);
    glPushMatrix();
    glScalef(length, width, width);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Segmen tengah jari
    glTranslatef(length/2, 0.0, 0.0);
    glRotatef((GLfloat)joint2, 0.0, 0.0, 1.0);
    glTranslatef(length/2, 0.0, 0.0);
    glPushMatrix();
    glScalef(length, width*0.9, width*0.9);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Segmen atas jari (dengan kuku)
    glTranslatef(length/2, 0.0, 0.0);
    glRotatef((GLfloat)joint3, 0.0, 0.0, 1.0);
    glTranslatef(length/2, 0.0, 0.0);
    glPushMatrix();
    glScalef(length*0.8, width*0.8, width*0.8);
    glutWireCube(1.0);
    
    // Kuku
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(0.6, 0.0, 0.0);
    glScalef(0.3, 0.9, 1.2);
    glutSolidCube(1.0);
    glColor3f(1.0, 1.0, 1.0);
    glPopMatrix();
    
    glPopMatrix();
}

// Fungsi untuk menampilkan teks
void renderText(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    int len = (int)strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

// ========== DISPLAY ==========
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Tampilkan model tangan
    glPushMatrix();
    glScalef(SCALE_FACTOR, SCALE_FACTOR, SCALE_FACTOR); // Skala keseluruhan objek
    glTranslatef(-1.0, -2.3, 0.0);
    
    // Bahu dan lengan atas
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(3.0, 0.8, 1.6);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Lengan bawah
    glTranslatef(1.6, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.6, 0.0, 0.0);
    glPushMatrix();
    glScalef(3.2, 0.7, 1.4);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Telapak tangan
    glTranslatef(2.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 1.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(1.5, 1.0, 1.8); 
    glutWireCube(1.0);
    glPopMatrix();
    
    // Ibu jari 
    glPushMatrix();
    glTranslatef(0.3, -0.3, 0.9);
    glRotatef(-20, 0.0, 1.0, 0.0);
    glRotatef(-30, 1.0, 0.0, 0.0);
    drawFinger(0.6, 0.25, thumb[0], thumb[1], thumb[2]);
    glPopMatrix();
    
    // Jari telunjuk
    glPushMatrix();
    glTranslatef(0.8, 0.3, 0.7);
    drawFinger(0.7, 0.17, index[0], index[1], index[2]);
    glPopMatrix();
    
    // Jari tengah
    glPushMatrix();
    glTranslatef(0.8, 0.3, 0.2);
    drawFinger(0.8, 0.17, middle[0], middle[1], middle[2]);
    glPopMatrix();
    
    // Jari manis
    glPushMatrix();
    glTranslatef(0.8, 0.3, -0.3);
    drawFinger(0.75, 0.17, ring[0], ring[1], ring[2]);
    glPopMatrix();
    
    // Jari kelingking
    glPushMatrix();
    glTranslatef(0.8, 0.3, -0.7);
    drawFinger(0.6, 0.15, pinky[0], pinky[1], pinky[2]);
    glPopMatrix();
    
    // Set up untuk menampilkan teks 2D
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 1024, 0.0, 768);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    
    // Warna teks
    glColor3f(1.0, 1.0, 1.0);
    
    // Kontrol untuk bahu dan siku
    renderText(10, 740, GLUT_BITMAP_HELVETICA_12, "LENGAN:");
    renderText(10, 720, GLUT_BITMAP_HELVETICA_12, "s/S: Rotasi bahu naik/turun");
    renderText(10, 700, GLUT_BITMAP_HELVETICA_12, "e/E: Rotasi siku naik/turun");
    renderText(10, 680, GLUT_BITMAP_HELVETICA_12, "w/W: Rotasi pergelangan tangan");
    
    // Kontrol untuk ibu jari
    renderText(250, 740, GLUT_BITMAP_HELVETICA_12, "IBU JARI:");
    renderText(250, 720, GLUT_BITMAP_HELVETICA_12, "1/!: Segmen bawah ibu jari naik/turun");
    renderText(250, 700, GLUT_BITMAP_HELVETICA_12, "2/@: Segmen tengah ibu jari naik/turun");
    renderText(250, 680, GLUT_BITMAP_HELVETICA_12, "3/#: Segmen atas ibu jari naik/turun");
    
    // Kontrol untuk jari telunjuk
    renderText(490, 740, GLUT_BITMAP_HELVETICA_12, "JARI TELUNJUK:");
    renderText(490, 720, GLUT_BITMAP_HELVETICA_12, "4/$: Segmen bawah telunjuk naik/turun");
    renderText(490, 700, GLUT_BITMAP_HELVETICA_12, "5/%: Segmen tengah telunjuk naik/turun");
    renderText(490, 680, GLUT_BITMAP_HELVETICA_12, "6/^: Segmen atas telunjuk naik/turun");
    
    // Kontrol untuk jari tengah
    renderText(730, 740, GLUT_BITMAP_HELVETICA_12, "JARI TENGAH:");
    renderText(730, 720, GLUT_BITMAP_HELVETICA_12, "7/&: Segmen bawah tengah naik/turun");
    renderText(730, 700, GLUT_BITMAP_HELVETICA_12, "8/*: Segmen tengah tengah naik/turun");
    renderText(730, 680, GLUT_BITMAP_HELVETICA_12, "9/(: Segmen atas tengah naik/turun");
    
    // Kontrol untuk jari manis
    renderText(10, 640, GLUT_BITMAP_HELVETICA_12, "JARI MANIS:");
    renderText(10, 620, GLUT_BITMAP_HELVETICA_12, "t/T: Segmen bawah manis naik/turun");
    renderText(10, 600, GLUT_BITMAP_HELVETICA_12, "g/G: Segmen tengah manis naik/turun");
    renderText(10, 580, GLUT_BITMAP_HELVETICA_12, "b/B: Segmen atas manis naik/turun");
    
    // Kontrol untuk jari kelingking
    renderText(250, 640, GLUT_BITMAP_HELVETICA_12, "JARI KELINGKING:");
    renderText(250, 620, GLUT_BITMAP_HELVETICA_12, "y/Y: Segmen bawah kelingking naik/turun");
    renderText(250, 600, GLUT_BITMAP_HELVETICA_12, "h/H: Segmen tengah kelingking naik/turun");
    renderText(250, 580, GLUT_BITMAP_HELVETICA_12, "n/N: Segmen atas kelingking naik/turun");
    
    // ESC untuk keluar
    renderText(730, 600, GLUT_BITMAP_HELVETICA_12, "ESC: Keluar");
    
    // Status sudut saat ini (opsional)
    char angleInfo[100];
    sprintf(angleInfo, "Bahu: %d  Siku: %d  Pergelangan: %d", shoulder, elbow, wrist);
    renderText(730, 580, GLUT_BITMAP_HELVETICA_12, angleInfo);
    
    // Kembali ke mode 3D
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    
    glPopMatrix();
    glutSwapBuffers();
}

// ========== RESHAPE ==========
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(55.0, (GLfloat)w / (GLfloat)h, 1.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -20.0);
}

// ========== KEYBOARD UNTUK KONTROL TANGAN ==========
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Kontrol bahu dan siku
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        
        // Kontrol pergelangan tangan
        case 'w': wrist = (wrist + 5) % 360; break;
        case 'W': wrist = (wrist - 5) % 360; break;
        
        // Kontrol jari jempol
        case '1': thumb[0] = (thumb[0] + 5) % 360; break;
        case '!': thumb[0] = (thumb[0] - 5) % 360; break;
        case '2': thumb[1] = (thumb[1] + 5) % 360; break;
        case '@': thumb[1] = (thumb[1] - 5) % 360; break;
        case '3': thumb[2] = (thumb[2] + 5) % 360; break;
        case '#': thumb[2] = (thumb[2] - 5) % 360; break;
        
        // Kontrol jari telunjuk
        case '4': index[0] = (index[0] + 5) % 360; break;
        case '$': index[0] = (index[0] - 5) % 360; break;
        case '5': index[1] = (index[1] + 5) % 360; break;
        case '%': index[1] = (index[1] - 5) % 360; break;
        case '6': index[2] = (index[2] + 5) % 360; break;
        case '^': index[2] = (index[2] - 5) % 360; break;
        
        // Kontrol jari tengah
        case '7': middle[0] = (middle[0] + 5) % 360; break;
        case '&': middle[0] = (middle[0] - 5) % 360; break;
        case '8': middle[1] = (middle[1] + 5) % 360; break;
        case '*': middle[1] = (middle[1] - 5) % 360; break;
        case '9': middle[2] = (middle[2] + 5) % 360; break;
        case '(': middle[2] = (middle[2] - 5) % 360; break;
        
        // Kontrol jari manis
        case 't': ring[0] = (ring[0] + 5) % 360; break;
        case 'T': ring[0] = (ring[0] - 5) % 360; break;
        case 'g': ring[1] = (ring[1] + 5) % 360; break;
        case 'G': ring[1] = (ring[1] - 5) % 360; break;
        case 'b': ring[2] = (ring[2] + 5) % 360; break;
        case 'B': ring[2] = (ring[2] - 5) % 360; break;
        
        // Kontrol jari kelingking
        case 'y': pinky[0] = (pinky[0] + 5) % 360; break;
        case 'Y': pinky[0] = (pinky[0] - 5) % 360; break;
        case 'h': pinky[1] = (pinky[1] + 5) % 360; break;
        case 'H': pinky[1] = (pinky[1] - 5) % 360; break;
        case 'n': pinky[2] = (pinky[2] + 5) % 360; break;
        case 'N': pinky[2] = (pinky[2] - 5) % 360; break;
        
        // Keluar
        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Regina - Tugas Praktikum 3 - Lengan Dengan Tangan dan Jari");
    init();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
