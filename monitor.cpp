#include "mul.cpp"

template <class T> SC_MODULE (monitor){
	// Modulo de exibicao
	sc_fifo_in <T> resultado;

	// Funcionamento do Monitor
	void monitora(){
		int contador = 0;
		cout << endl << "Resultado" << endl;

		while(true){
			// Imprime o vetor resultado
			T elemento = resultado.read();
			cout << "V" << contador << ": " << elemento << endl;
			contador++;
		}
	}

	SC_CTOR (monitor){
		SC_THREAD (monitora);
	}

};
