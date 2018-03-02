#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int decimal(int);

int main(){

	char input;
	char tangamandapenses[10][20];
	int index[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int entradas = 0, longitud = 0;
	int numerosDecimales[20];

	printf("Ingresa numeros tangamandapenses:\n");
	
	do{
		scanf("%c", &input);
		if(input == '\n'){
			index[entradas] = longitud;
			entradas++;
			longitud = 0;			
		}else{
			tangamandapenses[entradas][longitud] = input;
			longitud++;
		}
	}while(input != '#');

	int resultados[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for(int i=0; i<entradas; i++)
		for(int j=0; j<index[i]; j++){
			numerosDecimales[j] = decimal(tangamandapenses[i][j]);
			resultados[i] = resultados[i] + numerosDecimales[j] * pow(6, index[i]-j-1);
		}

	for(int i=0; i<entradas; i++)
		printf("\n%d", resultados[i]);

	return EXIT_SUCCESS;

}

int decimal(int a){
	switch(a){
		case 37: 
			return 0;

		case 41:
			return 1;

		case 126:  
			return 2; 

		case 64: 
			return 3;

		case 63: 
			return 4; 

		case 92:
			return 5; 

		case 36:
			return -1;
	}
	return 0;
}

