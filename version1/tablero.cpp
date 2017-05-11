#include "tablero.h"
#include "matriz.h"	

int Tablero::Filas() {
	return matriz.GetFilas();
}

int Tablero::Columnas() {
	return matriz.GetColumnas();
}

int Tablero::VerPosicion(int i, int j) {
	assert(i < matriz.GetFilas() && j < matriz.GetColumnas());
	return matriz.VerPosicion(i,j);
}

int Tablero::Turno() {
	return turno;
}

void Tablero::CambiarTurno() {
	if (turno == 1) {
		turno = 2;
	} else {
		turno = 1;
	}
}

int Tablero::Ganador() {
	int contador_1 = contador_2 = 0;
	int ganador;

	for (int i = 0; i < Filas(); i++) {
		for (int j = 0; j < Columnas(); j++) {
			if (VerPosicion(i,j) == 1) {
				contador_1++;
			}
			else if (VerPosicion(i,j) == 2) {
				contador_2++;
			}
		}
	}

	if (contador_1 == contador_2) {
		ganador = 0;
	}
	else {
		if (contador_1 > contador_2) {
			ganador = 1;
		}

		if (contador_2 > contador_1) {
			ganador = 2;
		}
	}

	return ganador;
}

bool Tablero::ColocarFicha(int i, int j) {
	bool colocada = false;
	
	if (PosValida(i, j, turno){
		
		colocada = true;

		for (int k = -1; k <= 1; k++) {
			for (int q = -1; q <= 1; q++) {
				int ci = i; //copia de donde voy a poner el turno
				int cj = j; 
				
				if (turno == 1) {
					while (matriz.VerPosicion(ci, cj) == 2 && matriz.EstaDentro(ci, cj) && !(k == 0 && q == 0)){

						ci = ci + k;
						cj = cj + q;

						if(matriz.VerPosicion(ci, cj) == 1){
							int l , m;
							l = i;
							m = j;

							while (l != ci && m != cj){
								l = l + k;
								m = m + q;

								matriz.Set(l, m, 1);
							}

						}
					}
				}

				if (turno == 2) {
					while (matriz.VerPosicion(ci, cj) == 1 && matriz.EstaDentro(ci, cj) && !(k == 0 && q == 0)){

						ci = ci + k;
						cj = cj + q;

						if(matriz.VerPosicion(ci, cj) == 2){
							int l , m;
							l = i;
							m = j;

							while (l != ci && m != cj){
								l = l + k;
								m = m + q;

								matriz.Set(l, m, 2);
							}
						}
					}
				}
			}   
		}
	}
	return colocada;
}

void Tablero::Reinicia() {
	for (int i = 0; i < Filas(); i++) {
		for (int j = 0; j < Columnas(); j++) {
			matriz.Set(i,j,0);
		}
	}

	matriz.Set((GetFilas()/2)-1, (GetColumnas()/2)-1, 2);
	matriz.Set((GetFilas()/2), (GetColumnas()/2), 2);
	matriz.Set((GetFilas()/2)-1, (GetColumnas()/2), 1);
	matriz.Set((GetFilas()/2), (GetColumnas()/2)-1, 1);
}

bool Tablero::PosValida(int i, int j, int ficha) {
	assert(i < matriz.GetFilas() && i >= 0 && j < matriz.GetColumnas() && j >= 0);

	bool es_valida = false;

	if (matriz.VerPosicion(i,j) == 0) {
		for (int k = -1; k <= 1 && !es_valida; k++) {
			for (int q = -1; q <= 1 && !es_valida; q++) {
				int ci = i;
				int cj = j;
				
				if (ficha == 1) {
					while (!es_valida && matriz.EstaDentro(ci, cj) && !(k == 0 && q == 0)){

						ci = ci + k;
						cj = cj + q;

						es_valida = matriz.VerPosicion(ci, cj) == 1;
					}
				}

				if (ficha == 2) {
					while (!es_valida && matriz.EstaDentro(ci, cj) && !(k == 0 && q == 0)){

						ci = ci + k;
						cj = cj + q;

						es_valida = matriz.VerPosicion(ci, cj) == 2;
					}
				}
			}
		}
	
	return es_valida;
}

bool Tablero::Finalizada() {
	bool finalizada = true;

	if (MovPosible(1) == true || MovPosible(2) == true) {
		finalizada = false;
	}

	return finalizada;
}

bool Tablero::MovPosible(int jugador) {
	bool movim_posible = false;

	for (int i = 0; i < matriz.GetFilas(); i++) {
		for (int j = 0; j < matriz.GetColumnas(); j++) {
			if (PosValida(i,j,jugador) == true) {
				movim_posible = true;
			}
		}
	}

	return movim_posible;
}
	
void Tablero::prettyPrint() {
	

}
