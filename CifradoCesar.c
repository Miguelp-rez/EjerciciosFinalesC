#include <stdio.h>
#include <stdlib.h>

void cifrarPalabra(int, int);
char swap(int, int, int, char);
char mensajes[10][200];
int llave[10];

int main(){
	int bandera=1, cont=0, contFrase=0;
	puts("Ingresa el desplazamiento y el mensaje a cifrar");
	while(bandera != 0){
		bandera = scanf("%d%*c%[^\n]%*c", &llave[cont],&mensajes[cont][0]);
		cont++;
	}
	for(int frase=0; frase < cont; frase++){
		cifrarPalabra(llave[frase], frase);
	}
	for(int frase=0; frase < cont; frase++){
		contFrase=0;
		while(mensajes[frase][contFrase]!='\0'){
			printf("%c", mensajes[frase][contFrase]);
			contFrase++;
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}

void cifrarPalabra(int rango,int fraseActual){
	char aux;
	int caracterActual = 0;
	int recorridoLetras = rango/26;
	int recorridoNum = rango/10;
	
	recorridoLetras = rango - recorridoLetras*26;
	recorridoNum = rango - recorridoNum*10;

	while(mensajes[fraseActual][caracterActual] != '\0'){
		if(mensajes[fraseActual][caracterActual]>64 && mensajes[fraseActual][caracterActual]<91){
			aux = mensajes[fraseActual][caracterActual];
			mensajes[fraseActual][caracterActual] = swap(65, 91, recorridoLetras, aux);
		}else if(mensajes[fraseActual][caracterActual]>96 && mensajes[fraseActual][caracterActual]<123){
			aux = mensajes[fraseActual][caracterActual];
			mensajes[fraseActual][caracterActual] = swap(97, 123, recorridoLetras, aux);
		}else if(mensajes[fraseActual][caracterActual]>47 && mensajes[fraseActual][caracterActual]<58){
			aux = mensajes[fraseActual][caracterActual];
			mensajes[fraseActual][caracterActual] = swap(48, 58, recorridoNum, aux);
		}
		caracterActual++;
	}
}
char swap(int inicio, int fin, int recorrido, char numActual){
	if(recorrido < 0){
		for(int x=-recorrido; x>0; x--){
			numActual--;
			if(numActual < inicio)
				numActual = fin-1;
		}
	}else if(recorrido > 0){
		for(int x=0; x<recorrido; x++){
			numActual++;
			if(numActual > fin-1)
				numActual = inicio;
		}
	}
	return numActual;
}