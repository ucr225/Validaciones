
#include <stdio.h>
#include <string.h>
// por si quieres que valide numeros para un nickname por ej
// char *letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZáéíóúüñÁÉÍÓÚÜÑ0123456789";
int esCadena(char *cadena)
{
    char *letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZáéíóúüñÁÉÍÓÚÜÑ";
    int longitud = strlen(cadena);

    // Comprueba si la cadena está vacía o comienza o termina con un espacio en blanco
    if (longitud == 0 || cadena[0] == ' ' || cadena[longitud - 1] == ' '||longitud>10)
    {
        fflush(stdin);

        return 0;
    }

    for (int i = 0; i < longitud; i++)
    {
        // Comprueba si hay más de un espacio en blanco consecutivo
        if (cadena[i] == ' ' && cadena[i + 1] == ' ')
        {
            fflush(stdin);

            return 0;
        }

        // Comprueba si el carácter es la letra ñ o Ñ
        if (cadena[i] == '\361' || cadena[i] == '\321') // ñ y Ñ en hexadecimal
        {
            continue;
        }

        if (!strchr(letras, cadena[i]) && cadena[i] != ' ') // strchr() busca el carácter actual en la cadena letras_validas
        {
            printf("NO VALIDO\n");
            fflush(stdin);

            return 0;
        }
    }

    printf("La cadena es valida.\n");
    return 1; // Retorna 1 solo si todos los caracteres son letras o espacios (pero no al inicio o al final, ni consecutivos)
}


int main()
{
    char cadena[20];
    printf("Ingrese una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);
    // cadena[strcspn(cadena, "\n")] = 0; // Eliminar el carácter de nueva línea al final de la cadena
    while (!esCadena(cadena))
    {
        printf("Ingrese una cadena: ");
        gets(cadena);
        cadena[strcspn(cadena, "\n")] = 0;
    }

    return 0;
}
