#include <systemc.h>

template <class T> SC_MODULE (driver){
	// Modulo de acionamento
	sc_fifo_out <T> acionamento;

	// Constante para acionamento
	T cte;

	// Funcionamento do driver
	void drive(){
		int contador = 0;

		// Geracao de 0s para o acionamento do sistema
		while(contador < 3){
			acionamento.write(cte);
			cout << "Gerou um " << cte << endl;

			contador++;
		}
	}

	// Utilizando construtor de C++
	SC_HAS_PROCESS(driver);

	driver (sc_module_name n, const T& c):
	sc_module(n), cte(c){
		SC_THREAD (drive);
	}
};
