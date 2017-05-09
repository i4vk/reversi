#include "matriz.h"

Matriz::Matriz() {
	fils = cols = 0;
}

Matriz::Matriz(int filas, int columnas) {
	fils = filas;
	cols = columnas;

	for (int i = 0; i < fils; i++) {
		for (int j = 0; j < cols; j++) {
			matriz[i][j] = 0;
		}
	}
}

int Matriz::GetFilas() {
	return fils;
}

int Matriz::GetColumnas() {
	return cols;
}

int Matriz::VerPosicion(int i, int j) {
	return matriz[i][j];
}

void Matriz::Set(int i, int j, int valor) {
	matriz[i][j] = valor;
}

bool Matriz::EstaDentro(int i, int j) {
	bool esta_dentro;

	if (i >= 0 && i < fils && j >= 0 && j < cols) {
		esta_dentro = true;
	} else {
		esta_dentro = false;
	}

	return esta_dentro;
}