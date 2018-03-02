#include <stdio.h>
#include <stdlib.h>

void pages(int);

int main(){
	int digits[50];
	int contador = 0;

	printf("Ingresa los digitos de los libros:\n");
	
	while(scanf("%d", &digits[contador])){
		contador++;
	}

	for(int i = 0; i < contador; i++)
		pages(digits[i]);

	return EXIT_SUCCESS;
}

void pages(int digits){
	int pages = 0;
	while(digits > 0){
		if(pages < 9){
			pages ++;
			digits --;
		}else if(pages < 99){
			pages ++;
			digits -= 2;
		}else if(pages < 999){
			pages ++;
			digits -= 3;
		}else if(pages < 9999){
			pages ++;
			digits -= 4;
		}else if(pages < 99999){
			pages ++;
			digits -= 5;
		}else if(pages < 999999){
			pages ++;
			digits -= 6;
		}else if(pages < 9999999){
			pages ++;
			digits -= 7;
		}else if(pages < 99999999){
			pages ++;
			digits -= 8;
		}else if(pages < 999999999){
			pages ++;
			digits -= 9;
		}
	}
	if(digits == 0)
		printf("%d\n", pages);
	else
		printf("Imposible\n");
}