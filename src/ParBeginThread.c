#include "ParBeginThread.h"
#include <stdarg.h>
#include <stdio.h>
#ifdef _WIN32_
#include <windows.h>
#endif
#ifdef _LINUX_
#include <pthread.h>
#endif

int
ParBeginThread(PArgumentosParBeginThread primerHilo, ...) {
	va_list pa;
	PArgumentosParBeginThread infoHilo;
#ifdef _WIN32_
	HANDLE hUltimoHilo;
#endif 
#ifdef _LINUX_
	pthread_t hUltimoHilo;
#endif
	
	infoHilo = primerHilo;

#ifdef _WIN32_
	hUltimoHilo = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) infoHilo->funcion, infoHilo->argumentos, 0, NULL);
#endif

#ifdef _LINUX_
	pthread_create(&hUltimoHilo, NULL, infoHilo->funcion, infoHilo->argumentos);
#endif
	
	va_start(pa, primerHilo);
	
	do {
		infoHilo = va_arg(pa, PArgumentosParBeginThread);
		 
		if (infoHilo) {
#ifdef _WIN32_
			CloseHandle(hUltimoHilo);
			hUltimoHilo = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) infoHilo->funcion, infoHilo->argumentos, 0, NULL);
#endif

#ifdef _LINUX_
			pthread_create(hUltimoHilo, NULL, infoHilo->funcion, infoHilo->argumentos);
#endif			
			
		}
		
	} while (infoHilo);
	
#ifdef _WIN32_
	WaitForSingleObject(hUltimoHilo, INFINITE);
#endif

#ifdef _LINUX_
	pthread_join(hUltimoHilo, NULL);
#endif
	
	
	return 0;
}
