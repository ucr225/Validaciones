#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

int esCaracterValido(char caracter)
{
    char *letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZáéíóúüñÁÉÍÓÚÜÑ";

    // Comprueba si el carácter es un espacio en blanco o una nueva línea
    if (caracter == ' ' || caracter == '\n')
    {
        printf("NO VALIDO\n");
        return 0;
    }

    // Comprueba si el carácter es la letra ñ o Ñ
    if (caracter == '\361' || caracter == '\321') // ñ y Ñ en hexadecimal
    {
        printf("El caracter es valido.\n");
        return 1;
    }

    if (!strchr(letras, caracter)) // strchr() busca el carácter actual en la cadena letras
    {
        printf("NO VALIDO\n");
        return 0;
    }

    printf("El caracter es valido.\n");
    return 1; // Retorna 1 solo si el caracter es una letra
}

int main()
{
    char caracter;
    int valido;

    do
    {
        printf("Por favor, ingresa un caracter: ");
        scanf("%c", &caracter); // El espacio antes de %c ignora cualquier espacio en blanco antes del carácter

        valido = esCaracterValido(caracter);
    } while (!valido); // Repite mientras el carácter no sea válido

    return 0;
}