#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int registros, difHoras, difMinutos, totalMinutos=0, promedio;

int main(){
    printf("Ingresa el numero de registros:\n");
    scanf("%d", &registros);

    int oHora[registros], oMinuto[registros], aHora[registros], aMinuto[registros];

    printf("Ingresa registros:\n");
    for(int i=0; i<registros; i++)
        scanf("%d%*c%d%*c%d%*c%d", &oHora[i], &oMinuto[i], &aHora[i], &aMinuto[i]);
    
    for(int i=0; i<registros; i++){
        difHoras = aHora[i] - oHora[i];
        difMinutos = aMinuto[i] - oMinuto[i];
        totalMinutos += difMinutos + difHoras*60;
    }

    promedio = totalMinutos/registros;
    printf("El promedio de retraso en minutos es: %d\n", promedio);

    return EXIT_SUCCESS;
}