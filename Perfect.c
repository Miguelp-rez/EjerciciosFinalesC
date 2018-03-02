#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int ejecuciones;
bool isPerfect(int);

int main(){
    printf("Ingresa el numero de ejecuciones:\n");
    scanf("%d", &ejecuciones);

    int inicio[ejecuciones], evaluaciones[ejecuciones];

    for(int i=0; i<ejecuciones; i++){
        printf("Ingresa el inicio y numeros a evaluar:\n");
        scanf("%d%*c%d", &inicio[i], &evaluaciones[i]);
    }

    for(int i=0; i<ejecuciones; i++)
        for(int j=0; j<evaluaciones[i]+1; j++){
            if(isPerfect(inicio[i]+j))
                printf("EL numero %d es perfecto\n", inicio[i]+j);
            else
                printf("EL numero %d no es perfecto\n", inicio[i]+j);
        }
    
    return EXIT_SUCCESS;
}

bool isPerfect(int numero){
    int suma = 0;
    for(int i=1; i < numero; i++){
        if(numero % i == 0)
            suma += i;
    }
    if(suma == numero)
        return true;
    else
        return false;  

}