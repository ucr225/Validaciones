// Incluye las bibliotecas necesarias
#include <stdio.h>
#include <string.h>
#include <math.h>

// Define la función esFlotante
int esFlotante(char *cadena)
{
    // Declara las variables que se utilizarán en la función
    float valor;
    char temp;

    // Comprueba si la cadena comienza o termina con un espacio en blanco o un punto
    if (cadena[0] == ' ' || cadena[strlen(cadena) - 1] == ' ' || cadena[strlen(cadena) - 1] == '.')
    {
        fflush(stdin);
        return 0;
    }

    // Intenta leer un número flotante y un carácter de la cadena
    int elementosLeidos = sscanf(cadena, "%f%c", &valor, &temp);

    // Redondea el valor a 4 decimales
    float valorRedondeado = roundf(valor * 10000) / 10000;

    // Comprueba si la lectura fue exitosa, si el valor está en el rango permitido y si tiene hasta 4 decimales
    // Si todas estas condiciones se cumplen, devuelve 1 para indicar que la cadena es un número flotante válido
    // Si no, devuelve 0
    if ((elementosLeidos == 1 || (elementosLeidos > 1 && temp == '\n')) &&
        valor >= -999999999.0 && valor <= 999999999.0 &&
        valor == valorRedondeado)
    {
        return 1;
    }
    else
    {
        fflush(stdin);

        return 0;
    }
}

// Define la función principal del programa
int main()
{
    // Declara las variables que se utilizarán en la función
    char cadena[100];
    int valido = 0;
    float numero = 0;

    // Entra en un bucle mientras la cadena no sea un número flotante válido
    while (valido != 1)
    {
        // Pide al usuario que introduzca una cadena
        printf("Ingrese un número con decimales: ");
        fgets(cadena, sizeof(cadena), stdin);

        // Comprueba si la cadena es un número flotante válido
        if (esFlotante(cadena))
        {
            // Si la cadena es un número flotante válido, imprime un mensaje de éxito
            printf("La cadena es un número flotante válido.\n");

            // Convierte la cadena a un número flotante
            numero = atof(cadena);

            // Imprime el número flotante
            printf("El numero flotante es: %.2f\n", numero);

            // Indica que la cadena es un número flotante válido para salir del bucle
            valido = 1;
        }
        else
        {
            // Si la cadena no es un número flotante válido, imprime un mensaje de error
            printf("La cadena NO es un número flotante válidooo.\n");
        }
    }

    // Termina la función principal y devuelve 0 para indicar que el programa se ha ejecutado correctamente
    return 0;
}
