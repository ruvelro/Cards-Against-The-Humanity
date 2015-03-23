//****************************************//
//Cards Against The Humanity - ruvelro ed.//
//****************************************//


#include <stdio.h>
#include <string.h>
#include <time.h> // Para time()
#include <stdlib.h> // Para exit (), rand() y srand

int main() {
	//Variables
	char bcard[150];
	char wcard[150];
	char readline[150];
	int line = 0;
	int count = 0;
	

//abrir los archivos txt de las cards
static const char filenameb[] = "bcards.txt"; //bcard
FILE *fileb = fopen(filenameb, "r");
static const char filenamew[] = "wcards.txt"; //wcard
FILE *filew = fopen(filenamew, "r");

/* Si hay un error, el programa se cierra */
if (fileb == NULL || filew == NULL){
	printf("Error! opening black cards file"); //bcard
    exit(1);         
}

//Calculamos carta aleatoria bcard
srand(time(NULL));
line=(rand()%76); //Linea aleatoria a leer
//Leemos el fichero 
for (count = 0; count < 76; count++) {
fgets(readline, sizeof readline, fileb);
//Guardamos la línea en la variable para mostrarla
if (count == line) {
strcpy(bcard, readline);
}
}

//Calculamos carta aleatoria wcard
srand(time(NULL));
line=(rand()%538); //Linea aleatoria a leer
//Leemos el fichero 
for (count = 0; count < 538; count++) {
fgets(readline, sizeof readline, filew);
//Guardamos la línea en la variable para mostrarla
if (count == line) {
strcpy(wcard, readline);
}
}

//Cerramos los archivos
fclose(fileb);
fclose(filew);

//Magic
printf(bcard,wcard);
return 0; //Salir
}
