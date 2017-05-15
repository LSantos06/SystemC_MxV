#include "driver.cpp"

template <class T> SC_MODULE (mul){
	// Entradas
	sc_signal   <T> vetor_in;
	sc_fifo     <T> matriz_in;
	sc_fifo_in  <T> soma_in;

	// Saidas
	sc_fifo_out <T> resultado_out;

	// Funcionamento do modulo
	void opera(){
		while(true){
			// Resultado = Soma + Vetor * Matriz
			resultado_out.write((soma_in.read() + (vetor_in.read() * matriz_in.read())));
		}
	}

	SC_CTOR (mul){
		SC_THREAD(opera);
	}

};
