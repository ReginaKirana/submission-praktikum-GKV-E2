/* TUGAS PRAKTIKUM GKV MODUL 1
 * Nama		: Regina Sasikirana Farikh
 * NIM		: 24060123140155
 * Kelas	: E
 * Lab		: E2
 */


// 1. Selain membuat titik menggunakan GL_POINT, garis menggunakan GL_LINES
//    Membuat bingkai foto (GL_LINES), berisi gambar bintang (GL_POINTS)

#include <GL/glut.h>
#include <cmath>
#include <vector>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // 1. Gambar Frame (Biru Muda)
    glColor3f(0.5f, 0.8f, 1.0f); // Biru muda
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        // Kotak (Frame)
        glVertex2f(-0.6f,  0.6f);  glVertex2f( 0.6f,  0.6f);
        glVertex2f(-0.6f, -0.6f);  glVertex2f( 0.6f, -0.6f);
        glVertex2f(-0.6f,  0.6f);  glVertex2f(-0.6f, -0.6f);
        glVertex2f( 0.6f,  0.6f);  glVertex2f( 0.6f, -0.6f);
    glEnd();

    // 2. Titik-Titik Bintang (Kuning)
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    float outerRadius  = 0.3f;
    float innerRadius  = 0.15f;
    float centerX      = 0.0f;
    float centerY      = 0.0f;
    float offsetAngle  = 90.0f;

    //     i genap  -> titik luar (outerRadius)
    //     i ganjil -> titik dalam (innerRadius)
    const int TOTAL_VERTICES = 10;
    std::vector<float> starX(TOTAL_VERTICES), starY(TOTAL_VERTICES);

    for(int i = 0; i < TOTAL_VERTICES; i++) {
        float angleDeg = offsetAngle + i * (360.0f / TOTAL_VERTICES); // kelipatan 36°
        float angleRad = angleDeg * 3.14159f / 180.0f;
        float r        = (i % 2 == 0) ? outerRadius : innerRadius;   

        starX[i] = centerX + r * cos(angleRad);
        starY[i] = centerY + r * sin(angleRad);
    }

    // 2b. Interpolasi titik di antara setiap pasangan vertex
    const int POINTS_PER_EDGE = 20; 
    for(int i = 0; i < TOTAL_VERTICES; i++) {
        // vertex[i] ke vertex[i+1] (loop terakhir nyambung ke vertex[0])
        int next = (i + 1) % TOTAL_VERTICES;

        float x1 = starX[i];
        float y1 = starY[i];
        float x2 = starX[next];
        float y2 = starY[next];

        // Interpolasi linear dari (x1, y1) ke (x2, y2)
        for(int step = 0; step <= POINTS_PER_EDGE; step++) {
            float t = (float)step / (float)POINTS_PER_EDGE; 
            float x = x1 + t * (x2 - x1);
            float y = y1 + t * (y2 - y1);
            glVertex2f(x, y);
        }
    }

    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Frame Bintang");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
