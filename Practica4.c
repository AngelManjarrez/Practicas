#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
return (*(int *)a - *(int *)b);
}


int teamChemistry(int *skill, int size) {
if (size % 2 != 0) return -1; 

qsort(skill, size, sizeof(int), compare); 

int totalSum = 0;
int expectedSum = skill[0] + skill[size - 1]; 

printf("\nEquipos formados:\n");

for (int i = 0; i < size / 2; i++) {
int teamSum = skill[i] + skill[size - 1 - i];

if (teamSum != expectedSum) {
return -1; 
}

printf("Equipo %d: (%d, %d)\n", i + 1, skill[i], skill[size - 1 - i]);
totalSum += skill[i] * skill[size - 1 - i]; 
}

return totalSum;
}

int main() {
int size;


printf("Ingrese la cantidad de jugadores (debe ser un numero par): ");
scanf("%d", &size);

if (size % 2 != 0) {
printf("-1\n");
return 0;
}

int skill[size];


printf("Ingrese las habilidades de los jugadores:\n");
for (int i = 0; i < size; i++) {
scanf("%d", &skill[i]);
}


int result = teamChemistry(skill, size);


printf("\nSuma total de la química de los equipos: %d\n", result);

return 0;
}
