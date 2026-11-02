#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* routine() {
    printf("Test from threads\n");
    sleep(3);
    printf("Ending thread\n");
}

int main() {
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
        return 1;
    } 
    // como lo que envia la funcion es un int se le puede colocar un if que 
    //valide si es distinto de 0 y si es asi devuelva un numero distinto 
    //para saber donde fallo
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}