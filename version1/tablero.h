class Tablero {
private:
	Matriz matriz;
	int turno;

public:
	Tablero() : Matriz() {}
	Tablero(int filas, int columnas) : matriz(filas,columnas) {
		matriz.Set((GetFilas()/2)-1, (GetColumnas()/2)-1, 2);
		matriz.Set((GetFilas()/2), (GetColumnas()/2), 2);
		matriz.Set((GetFilas()/2)-1, (GetColumnas()/2), 1);
		matriz.Set((GetFilas()/2), (GetColumnas()/2)-1, 1);
	}	
	int Filas();
	int Columnas();
	void VerPosicion(int i, int j);
	int Turno();
	int Ganador();

	void ColocarFicha(int i, int j, int ficha);
	void Reinicia();

};