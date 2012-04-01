#ifdef _WIN32_
#include <windows.h>
#endif
#ifdef _LINUX_
#include <unistd.h>
#endif
#include <stdio.h>
#include "ParBeginThread.h"

/* Variable global, compartida entre los dos hilos */

int turno; 

THREAD_TYPE proceso_0(void *arg) {

  for (;;) {

    /* Entra a la seccion critica */
    while (turno != 0) 
      ; /* No hace nada */

    /* Dentro de la sección critica */
    printf("Proceso 0 dentro de la seccion critica\n");
    turno = 1;
  }
}

THREAD_TYPE proceso_1(void *arg) {

   for (;;) {

    /* Entra a la seccion critica */
    while (turno != 1) 
      ; /* No hace nada */
    /* Dentro de la sección critica */
    printf("Proceso 1 dentro de la seccion critica\n");
    turno = 0;
  } 
}

int
main() {

  ArgumentosParBeginThread h1 = {"Proceso 0", proceso_0, NULL};
  ArgumentosParBeginThread h2 = {"Proceso 1", proceso_1, NULL};

  turno = 0;
  
  ParBeginThread(&h2, &h1, NULL);

  return 0;
}

  
  
