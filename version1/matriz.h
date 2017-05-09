class Matriz {
private:
	int matriz[10][10];
	int fils, cols;

public:
	Matriz();

	Matriz(int filas, int columnas);

	int GetFilas();

	int GetColumnas();

	int VerPosicion(int i, int j);

	void Set(int i, int j, int valor);

	bool EstaDentro(int i, int j);
};