#include <stdio.h>
#include <signal.h>

int main() 
{ 
    // Se ignora la señal ,se escribe eso
    signal(SIGINT, SIG_IGN); 

    printf("Presiona CTRL+C para  que veas que no puedes salir del programa r\n"); 
    printf("Presiona CTRL+C MI PANA! para que veas que no puedes parar el programa jejeje\n");

    while(1) ; 

    return 0; 
} 
