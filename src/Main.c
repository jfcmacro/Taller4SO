#include <stdio.h>
#ifdef _LINUX_
#include <unistd.h>
#endif
#include "ParBeginThread.h"

THREAD_TYPE hilo1(void *argumento) {

	for (;;) {
		printf("Hilo 1\n");
#ifdef _WIN32_
		Sleep(1000);
#endif
#ifdef _LINUX_
		sleep(1);
#endif
	}      
}

THREAD_TYPE hilo2(void* argumento) {
	
	for (;;) {
		printf("Hilo 2\n");
#ifdef _WIN32_
		Sleep(2000);
#endif
#ifdef _LINUX_
		sleep(2);
#endif
	}
}

int
main() {
	ArgumentosParBeginThread h1 = {"PrimerHilo", hilo1, NULL};
	ArgumentosParBeginThread h2 = {"SegundoHilo", hilo2, NULL};

	ParBeginThread(&h1, &h2, NULL);	
	return 0;
}

