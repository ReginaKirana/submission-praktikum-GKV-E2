/* TUGAS PRAKTIKUM GKV MODUL 1
 * Nama		: Regina Sasikirana Farikh
 * NIM		: 24060123140155
 * Kelas	: E
 * Lab		: E2
 */

/* Nomor 2. buatlah program yang memanfaatkan fungsi GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLE_FAN, 
*			GL_TRIANGLE_STRIP, GL_QUADS, GL_QUAD_STRIP. */

#include <GL/glut.h> 
// A. GL_LINE_STRIP (Panah)
void PanahStrip(void) {
	float sc =  0.2;
    glLineWidth(2.0f);
	glColor3f(1.0, 1.0, 1.0); // Warna putih
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.7 + sc, 0.6 - sc); // Titik pertama (bawah kiri kotak)
        glVertex2f(-0.6 + sc, 0.6 -sc); // Bawah kanan kotak
        glVertex2f(-0.6 + sc, 0.7 - sc); // Atas kanan kotak
        glVertex2f(-0.5 + sc, 0.7 - sc); // Ujung kanan panah
        glVertex2f(-0.65 + sc, 0.8 - sc); // Puncak panah
        glVertex2f(-0.8 + sc, 0.7 - sc); // Ujung kiri panah
        glVertex2f(-0.7 + sc, 0.7 - sc); // Atas kiri kotak
        glVertex2f(-0.7 +sc, 0.6 - sc); // Kembali ke titik pertama (tidak menutup loop)
    glEnd();
    glFlush();  // Render gambar ke layar
}


// B. GL_LINE_LOOP (Panah Rumah)
void PanahRumah() {
	float scale = 0.30;
    glLineWidth(2.0); 
    glColor3f(1.0, 1.0, 1.0); // Warna merah
    glBegin(GL_LINE_LOOP);

    glVertex2f(0.0 * scale + 0.3, 0.5 * scale + 0.5);    // Titik atas
    glVertex2f(-0.5 * scale + 0.3, 0.0 * scale + 0.5); // Titik kiri bawah
    glVertex2f(0.5 * scale + 0.3, 0.0 * scale + 0.5);  // Titik kanan bawah
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.3 * scale + 0.3, 0.0 * scale + 0.5);  // Titik kiri atas
    glVertex2f(0.3 * scale + 0.3, 0.0 * scale + 0.5);   // Titik kanan atas
    glVertex2f(0.3 * scale + 0.3, -0.5 * scale + 0.5);  // Titik kanan bawah
    glVertex2f(-0.3 * scale + 0.3, -0.5 * scale + 0.5); // Titik kiri bawah
    glEnd();
    glFlush();
}


// C. GL_TRIANGLE_FAN (SegiLima) 
void SegiLima() {
	float sl = 1.20;
	float sa = 0.1;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0, 0.0, 1.0);  // Biru tua (Tengah)
        glVertex2f(0.3 * sl, -0.6 * sl + sa);     // Titik tengah segi lima
        
		glColor3f(0.0, 1.0, 1.0);  // Cyan (Hijau kebiruan)
        glVertex2f(0.225 * sl, -0.55 * sl + sa);  // Titik kiri atas
        glVertex2f(0.375 * sl, -0.55 * sl + sa);  // Titik kanan atas
        
		glColor3f(0.0, 0.7, 1.0);  // Biru muda
        glVertex2f(0.45 * sl, -0.65 * sl + sa);   // Titik kanan bawah
        
		glColor3f(0.0, 1.0, 0.8);  // Cyan terang
        glVertex2f(0.3 * sl, -0.7 * sl + sa);     // Titik tengah bawah
        
		glColor3f(0.0, 0.7, 1.0);  // Biru muda
        glVertex2f(0.15 * sl, -0.65 * sl + sa);   // Titik kiri bawah
        
		glColor3f(0.0, 1.0, 0.8);  // Cyan terang
        glVertex2f(0.225 * sl, -0.55 * sl + sa);  // Kembali ke titik kiri atas
    glEnd();
    glFlush();
}


// D. GL_TRIANGLE_STRIP (Segitiga Tumpuk)
void SegitigaTumpuk(){
    // Menggambar segitiga pertama
    glBegin(GL_TRIANGLE_STRIP);
    // Titik pertama segitiga pertama (warna hijau)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.15 - 0.7, 0.15 -0.3);
    // Titik kedua segitiga pertama (warna biru)
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex2f(0.15 - 0.7, 0.15 - 0.3);
    // Titik ketiga segitiga pertama (warna kuning)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.15 - 0.7, -0.15 - 0.3);
    glEnd();

    // Menggambar segitiga kedua (mirroring dari segitiga pertama)
    glBegin(GL_TRIANGLE_STRIP);    
    // Titik pertama segitiga kedua (warna biru)
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.15 - 0.7, 0.15 - 0.3);
    // Titik kedua segitiga kedua (warna kuning)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.15 - 0.7, -0.15 - 0.3); 
    // Titik ketiga segitiga kedua (warna kuning)
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex2f(-0.15 - 0.7, -0.15 -0.3);    
	glEnd();
    glFlush();
}


// E. GL_QUADS (Trapesium)
void Trapesium() {
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0); // Putih (Sudut kiri atas)
        glVertex2f(-0.21 -0.2, 0.105 - 0.6); 
        glColor3f(1.0, 0.8, 0.6); // Peach (Sudut kanan atas)
        glVertex2f(-0.07 - 0.2, 0.105 - 0.6); 
        glColor3f(1.0, 0.0, 0.5); // Pink (Sudut kanan bawah)
        glVertex2f(0.14 - 0.2, -0.105 - 0.6); 
        glColor3f(1.0, 0.5, 0.0); // Jingga (Sudut kiri bawah)
        glVertex2f(-0.21 - 0.2, -0.105 - 0.6); 
    glEnd();
    glFlush();
}


// F. GL_QUAD_STRIP (Fork)
void Fork() {
	float scale = 0.20;
    // Segitiga pertama (Merah)
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0, 1.0, 1.0); // Putih
    glVertex2f(-0.5 * scale + 0.7, 0.4 * scale - 0.3);
    glColor3f(0.0, 0.0, 1.0); // Biru
    glVertex2f(0.4 * scale + 0.7, 0.5 * scale - 0.3);
    glColor3f(0.0, 0.0, 1.0); // Biru
    glVertex2f(1.0 * scale + 0.7, -0.5 * scale - 0.3);
	glColor3f(1.0, 0.6, 0.8); // Pink Muda
    glVertex2f(1.0 * scale + 0.7, -0.5 * scale - 0.3);   
    glEnd();
    
    // Segitiga kedua (Biru) - Mirror dari segitiga pertama
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.0, 0.0, 1.0); // Biru
        glVertex2f(-0.5 * scale + 0.7, 0.5 * scale - 0.3);   
		glColor3f(1.0, 0.6, 0.8); // Pink Muda
		glVertex2f(0.4 * scale + 0.7, 0.5 * scale - 0.3);  
		glColor3f(1.0, 0.6, 0.8); // Pink Muda
		glVertex2f(-1.0 * scale + 0.7, -0.5 * scale - 0.3);
		glColor3f(1.0, 1.0, 1.0); // Putih
		glVertex2f(-1.0 * scale + 0.7, -0.5 * scale - 0.3);    
    glEnd();    
    glFlush();
}


// Fungsi display untuk menampilkan semua bentuk
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    PanahStrip();
    PanahRumah();
    SegiLima();
    Trapesium();
    SegitigaTumpuk();
    Fork();
    glFlush();
}

// Fungsi untuk mengatur properti tampilan
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set warna latar belakang menjadi hitam
    glMatrixMode(GL_PROJECTION);        // Set mode proyeksi
    glLoadIdentity();                   // Reset matriks proyeksi
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  // Set proyeksi ortogonal
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);  // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Mode tampilan
    glutInitWindowSize(500, 500);  // Ukuran window
    glutCreateWindow("Praktikum 1 - Regina Sasikirana Farikh");  // Nama window
    init();  // Panggil fungsi inisialisasi
    glutDisplayFunc(display);  // Tentukan fungsi display yang akan dipanggil
    glutMainLoop();  // Mulai loop GLUT
    return 0;
}
