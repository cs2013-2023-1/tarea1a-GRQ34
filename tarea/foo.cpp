#include "foo.h"

void Matriz2D::construir(){
    ptr = new float*[filas];

    for (int i = 0; i < filas; ++i)
        ptr[i] = new float[columnas];

    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            ptr[i][j] = (1 + rand() % (99 + 1 - 1)) * 0.01;;
}

Matriz2D::Matriz2D(){
    // Constructor por defecto
    filas = columnas = 3;
    construir();
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
    filas = columnas = n;
    construir();
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
    filas = n;
    columnas = m;
    construir();
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    filas = m.filas;
    columnas = m.columnas;

    ptr = new float*[filas];

    for (int i = 0; i < filas; ++i)
        ptr[i] = new float[columnas];

    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            ptr[i][j] = m.ptr[i][j];
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    filas = m.filas;
    columnas = m.columnas;
    ptr = m.ptr;

    m.ptr = nullptr;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D transpuesta;
    transpuesta.filas = m.columnas;
    transpuesta.columnas = m.filas;

    transpuesta.ptr = new float * [transpuesta.filas];

    for (int i = 0; i < transpuesta.filas; ++i)
        transpuesta.ptr[i] = new float [transpuesta.columnas];

    for (int i = 0; i < transpuesta.filas; ++i)
        for (int j = 0; j < transpuesta.columnas; ++j)
            transpuesta.ptr[i][j] = m.ptr[j][i];

    return transpuesta;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j)
            os << m.ptr[i][j] << " ";
        os << endl;
    }
    os << endl;
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    Matriz2D r;
    r.filas = m1.filas;
    r.columnas = m1.columnas;

    r.ptr = new float * [r.filas];

    for (int i = 0; i < r.filas; ++i)
        r.ptr[i] = new float [r.columnas];

    for (int i = 0; i < r.filas; ++i)
        for (int j = 0; j < r.columnas; ++j)
            r.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];

    return r;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    Matriz2D r;
    r.filas = m1.filas;
    r.columnas = m1.columnas;

    r.ptr = new float * [r.filas];

    for (int i = 0; i < r.filas; ++i)
        r.ptr[i] = new float [r.columnas];

    for (int i = 0; i < r.filas; ++i)
        for (int j = 0; j < r.columnas; ++j)
            r.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];

    return r;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    Matriz2D r;
    r.filas = m1.filas;
    r.columnas = m2.columnas;

    r.ptr = new float * [r.filas];

    for (int i = 0; i < r.filas; ++i)
        r.ptr[i] = new float [r.columnas];

    float s;

    for (int i = 0; i < r.filas; ++i)
        for (int j = 0; j < r.columnas; ++j) {
            s = 0;
            for (int k = 0; k < m1.columnas; ++k)
                s += m1.ptr[i][k] * m2.ptr[k][j];
            r.ptr[i][j] = s;
        }

    return r;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D r;
    r.filas = m.filas;
    r.columnas = m.columnas;

    r.ptr = new float * [r.filas];

    for (int i = 0; i < r.filas; ++i)
        r.ptr[i] = new float [r.columnas];

    for (int i = 0; i < r.filas; ++i)
        for (int j = 0; j < r.columnas; ++j)
            r.ptr[i][j] = m.ptr[i][j] + n;

    return r;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D r;
    r.filas = m.filas;
    r.columnas = m.columnas;

    r.ptr = new float * [r.filas];

    for (int i = 0; i < r.filas; ++i)
        r.ptr[i] = new float [r.columnas];

    for (int i = 0; i < r.filas; ++i)
        for (int j = 0; j < r.columnas; ++j)
            r.ptr[i][j] = m.ptr[i][j] - n;

    return r;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D r;
    r.filas = m.filas;
    r.columnas = m.columnas;

    r.ptr = new float * [r.filas];

    for (int i = 0; i < r.filas; ++i)
        r.ptr[i] = new float [r.columnas];

    for (int i = 0; i < r.filas; ++i)
        for (int j = 0; j < r.columnas; ++j)
            r.ptr[i][j] = m.ptr[i][j] * n;

    return r;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D r;
    r.filas = m.filas;
    r.columnas = m.columnas;

    r.ptr = new float * [r.filas];

    for (int i = 0; i < r.filas; ++i)
        r.ptr[i] = new float [r.columnas];

    for (int i = 0; i < r.filas; ++i)
        for (int j = 0; j < r.columnas; ++j)
            r.ptr[i][j] = m.ptr[i][j] / n;

    return r;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
