#include "monitor.cpp"

template <class T> SC_MODULE (sistema){
	// Instanciacao dos modulos a serem utilizados
	driver 	<T> driver_mul;
	mul 	<T> mul1;
	mul 	<T> mul2;
	mul 	<T> mul3;
	monitor <T> monitor_mul;

	// FIFOs para conectar os modulos
	sc_fifo <T> driver_mul1;
	sc_fifo <T> mul1_mul2;
	sc_fifo <T> mul2_mul3;
	sc_fifo <T> mul3_monitor;

	// Interconexao
	SC_CTOR (sistema): driver_mul("driver_mul", 0),
					   mul1("mul1"),
			           mul2("mul2"),
			           mul3("mul3"),
			           monitor_mul("monitor_mul"){

		// Conectando o driver ao 1 mul
		driver_mul.acionamento(driver_mul1);
		mul1.soma_in(driver_mul1);

		// Conectando o 1 mul ao 2 mul
		mul1.resultado_out(mul1_mul2);
		mul2.soma_in(mul1_mul2);

		// Conectando o 2 mul ao 3 mul
		mul2.resultado_out(mul2_mul3);
		mul3.soma_in(mul2_mul3);

		// Conectando o 3 mul ao monitor
		mul3.resultado_out(mul3_monitor);
		monitor_mul.resultado(mul3_monitor);
	}
};
