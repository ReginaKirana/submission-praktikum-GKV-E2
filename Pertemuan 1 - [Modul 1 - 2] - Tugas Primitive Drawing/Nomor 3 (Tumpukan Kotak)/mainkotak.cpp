/* TUGAS PRAKTIKUM GKV MODUL 1
 * Nama		: Regina Sasikirana Farikh
 * NIM		: 24060123140155
 * Kelas	: E
 * Lab		: E2
 */
 
#include <GL/glut.h> 
// Tugas Nomor 3. Membuat Kubus bertingkat dari objek primitif sekreatif mungkin. (minimal 5 kubus)
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float sy = 0.09;
    float sx = 0.045;
    float sx1 = 0.09;
    float sy1 = 0.09;

    // Tingkat 3 (1 persegi)
    glBegin(GL_QUADS);
    	glColor3f(0.5, 0.7, 1.0); // biru
        glVertex2f(-0.1, 0.5 - sy);
        glVertex2f(0.1, 0.5 - sy);
        glColor3f(1.0, 0.75, 0.85); // Pink lebih Muda
        glVertex2f(0.1, 0.3 - sy);
        glVertex2f(-0.1, 0.3 - sy);
    glEnd();

    // Tingkat 2 (2 persegi)
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.7, 1.0); // biru
		glVertex2f(-0.25 + sx, 0.2);
        glColor3f(1.0, 0.75, 0.85); // pink muda
        glVertex2f(-0.05 + sx, 0.2);
        glColor3f(1.0, 0.75, 0.85); // pink muda
        glVertex2f(-0.05 + sx, 0.0);
       	glColor3f(0.5, 0.7, 1.0); // biru
        glVertex2f(-0.25 + sx, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    	glColor3f(1.0, 0.75, 0.85); // pink muda
        glVertex2f(0.05 - sx, 0.2);
        glColor3f(0.5, 0.7, 1.0); // biru
        glVertex2f(0.25 - sx, 0.2);
        glColor3f(0.5, 0.7, 1.0); // biru
        glVertex2f(0.25 - sx, 0.0);
        glColor3f(1.0, 0.75, 0.85); // pink muda
        glVertex2f(0.05 - sx, 0.0);
    glEnd();

    // Tingkat 1 (3 persegi)
    glBegin(GL_QUADS);
    	glColor3f(0.5, 0.7, 1.0); // biru
        glVertex2f(-0.4 + sx1, -0.1 + sy1);
        glColor3f(1.0, 0.75, 0.85); // pink muda
        glVertex2f(-0.2 + sx1, -0.1 + sy1);
        glColor3f(0.5, 0.7, 1.0); // biru
        glVertex2f(-0.2 + sx1, -0.3 + sy1);
        glVertex2f(-0.4 + sx1, -0.3 + sy1);
    glEnd();

    glBegin(GL_QUADS);
    	glColor3f(1.0, 0.75, 0.85); // pink muda
        glVertex2f(-0.1, -0.1 + sy1);
        glVertex2f(0.1, -0.1 + sy1);
        glColor3f(0.5, 0.7, 1.0);  // Biru
        glVertex2f(0.1, -0.3 + sy1);
        glVertex2f(-0.1, -0.3 + sy1);
    glEnd();

    glBegin(GL_QUADS);
    	glColor3f(1.0, 0.75, 0.85); // pink muda
        glVertex2f(0.2 - sx1, -0.1 + sy1);
        glColor3f(0.5, 0.7, 1.0);  // Biru
        glVertex2f(0.4 - sx1, -0.1 + sy1);
        glColor3f(0.5, 0.7, 1.0);  // Biru
        glVertex2f(0.4 - sx1, -0.3 + sy1);
        glColor3f(0.5, 0.7, 1.0);  // Biru
        glVertex2f(0.2 - sx1, -0.3 + sy1);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Piramida Bertingkat");
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
