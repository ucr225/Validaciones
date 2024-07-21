#include <ctype.h> //obligatorio
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
// #include <locale.h>
// fflush(stdin); LIMPIA EL BUFER ANTES DE CADA RETURN 0!!!
int esEntero(char *cadena)
{
    int arbitro, menos = 0;
    int longitud;
    int borrar;
    int soloCeros = 1;
    char *punto = strchr(cadena, '.');
    longitud = strlen(cadena);

    if (longitud == 0 || cadena[0] == '\0')
    {
        printf("ESTIMADO USUARIO,NO INGRESO NINGUN VALOR! \n");
        fflush(stdin);
        return arbitro = 0;
    }

    if (cadena[0] == '-')
    {
        menos++;
    }

    for (int i = menos; i < longitud; i++)
    {
        if (longitud == 1 && cadena[i] == '0')
        {
            return arbitro = 1;
        }

        if (!isdigit(cadena[i]) || (cadena[0] == '0' && menos == 0) || longitud > 9 || cadena[0] == ' ' || cadena[longitud - 1] == ' ' || longitud == 0 || menos > 1)
        {
            fflush(stdin);
            return arbitro = 0;
        }
    }

    return arbitro = 1;
}

// if (cadena[longitud - 2] == '.' && cadena[longitud - 1] == '0')
//{
//   cadena[longitud - 2] = '\0'; // Borramos los dos últimos caracteres
//  Borramos los dos últimos caracteres
// longitud -= 2; // Actualizamos la longitud de la cadena
//}
// programa ejemplo donde invocas la funcion y la metes dentreo de un bucle mientras que el valor no sea valido,que se vuelva a pedir
int main()
{
    // setlocale(LC_ALL, "es_ES.UTF-8");
    int valido, longitud;
    char cadena[100];

    while (valido != 1)
    {
        printf("Ingrese un numero  de maximo 9 digitos: ");
        gets(cadena);
        longitud = strlen(cadena);
        if (esEntero(&cadena)) // llamas la funcion,siempre a la variable debes pasarle el &  CUANDO NO SON ARREGLOS
        {
            printf("Los datos ingresados  numeros son enteros.\n");

            long long int numero = atoll(cadena); // enteros MUCHO mas grandes
            printf(" El numero es: %lld\n", numero);

            valido = 1; // como es valido el valor cambia entonces ya no se vuelve a pedir la cadena
        }
        else
        {
            printf("NO valido,por favor ingrese su numero entero sin ceros al inicio/un numero mas corto/un numeros sin decimales\n");
            fflush(stdin);
            valido = 0; // como es invalido se vuelve a pedir hasta que sea valido
        }
    }

    return 0;
}
