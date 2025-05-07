#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool esPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}

int generarFibonacciFiltrado(int fib[], int K) {
    int a = 0, b = 1, pos = 1, count = 0;
    while (a <= K) {
        if (!esPrimo(pos)) {
            fib[count++] = a;
        }
        int temp = a + b;
        a = b;
        b = temp;
        pos++;
    }
    return count;
}

int minTerminosFibonacci(int K, int fib[], int n, int resultado[]) {
    int count = 0;
    int i = n - 1;
    while (K > 0 && i >= 0) {
        while (i >= 0 && fib[i] > K)
            i--;
        if (i < 0) break;
        resultado[count++] = fib[i];
        K -= fib[i];
        i -= 2;
    }
    return count;
}

int main() {
    int dia = 25, mes = 12, anio = 1995;
    int K = dia * 100 + mes * 10 + (anio % 100);
    printf("K calculado: %d\n", K);

    int fib[100];
    int resultado[50];
    int n = generarFibonacciFiltrado(fib, K);

    printf("Secuencia de Fibonacci filtrada: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", fib[i]);
    printf("\n");

    int numTerminos = minTerminosFibonacci(K, fib, n, resultado);

    printf("Terminos seleccionados: ");
    for (int i = 0; i < numTerminos; ++i)
        printf("%d ", resultado[i]);
    printf("\nNumero minimo de terminos: %d\n", numTerminos);

    return 0;
}
