#include "sistema.cpp"

int sc_main (int arc, char * argv[]){

	// Instanciacao do sistema, definindo o tipo da matriz e do vetor
	sistema <int> sistema_instance("sistema_instance");

	// Definindo a matriz
	// Coluna 1
	sistema_instance.mul1.matriz_in.write(1);
	sistema_instance.mul1.matriz_in.write(4);
	sistema_instance.mul1.matriz_in.write(7);

	// Coluna 2
	sistema_instance.mul2.matriz_in.write(2);
	sistema_instance.mul2.matriz_in.write(5);
	sistema_instance.mul2.matriz_in.write(8);

	// Coluna 3
	sistema_instance.mul3.matriz_in.write(3);
	sistema_instance.mul3.matriz_in.write(6);
	sistema_instance.mul3.matriz_in.write(9);
	// |1 2 3|
	// |4 5 6|
	// |7 8 9|

	// Definindo o vetor
	sistema_instance.mul1.vetor_in.write(1);
	sistema_instance.mul2.vetor_in.write(2);
	sistema_instance.mul3.vetor_in.write(3);
	// (1)
	// (2)
	// (3)

	sc_start();

	return 0;
}
