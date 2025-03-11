#include <stdio.h>

#include <string.h>



int main() {



    const char *teclado[] = {"",    "",    "abc", "def", "ghi", "jkl", 

                             "mno", "pqrs", "tuv", "wxyz"};



    char digitos[5]; // Máximo 4 dígitos según restricciones

    printf("Ingrese los digitos (2-9): ");

    scanf("%4s", digitos); // Leer hasta 4 caracteres



    int longitud = strlen(digitos);

    if (longitud == 0) return 0; // Si no hay entrada, salir



    char combinaciones[100][5]; // Almacenar combinaciones

    int total = 1; // Número total de combinaciones




    for (int i = 0; i < longitud; i++) {

        int num = digitos[i] - '0';

        total *= strlen(teclado[num]); // Multiplicamos por las opciones de cada dígito

    }





    for (int i = 0; i < total; i++) {

        int temp = i;

        for (int j = 0; j < longitud; j++) {

            int num = digitos[j] - '0';

            int opciones = strlen(teclado[num]);

            combinaciones[i][j] = teclado[num][temp % opciones];

            temp /= opciones;

        }

        combinaciones[i][longitud] = '\0'; // Agregar terminador de cadena

        printf("%s\n", combinaciones[i]); // Imprimir cada combinación

    }



    return 0;

}

