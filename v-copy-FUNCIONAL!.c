#include <stdio.h>
#include <signal.h>

int main() 
{ 
    // Se ignora la señal ,se escribe eso
    signal(SIGINT, SIG_IGN); 

    printf("Presiona CTRL+C para  que veas que no puedes salir del programa\n"); 

    while(1) ; 

    return 0; 
} 
