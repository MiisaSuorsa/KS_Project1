#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct lines {
	char string[255];
	struct lines* next;
};

struct lines *start = NULL;
struct lines *pNew, *ptr;

void readFile (char* input);
void writeFile (char* output);
void freeMemory();

//tarkistaa parametrien määrän
int main(int argc, char* argv[]) {
	
	if (argc == 3){
		//menee aliohjelmaan lukee tiedosto
		readFile(argv[1]);
		//menee aliohjelmaan kirjoittaa tiedosto
		writeFile(argv[2]);
	}
	
	//Liian vähän tai liikaa parametreja
	else {
		fprintf(stderr, "usage: reverse <input> <output>\n");
		exit(1);
	}
	
	freeMemory();
}


//lukee tiedostoa
void readFile (char* input){
	FILE* file;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	
	//avaa tiedoston lukemista varten
	file = fopen(input, "r");
	if (file == NULL){
		fprintf(stderr, "error: cannot open file '%s'\n", input);
		exit(1);
	}

	//luetaan tiedostoa rivi kerrallaan
	while ((nread = getline(&line, &len, file)) != -1) {
               printf("%s", line);
               
               if ((pNew = (struct lines*) malloc(sizeof(struct lines))) == NULL ){
               	fprintf(stderr, "error: cannot ");
			exit(1);
               }
               
               //tallennetaan uusi rivi listan alkuun
               strcpy(pNew->string, line);
               
               if (start == NULL){
               	start = pNew;
               }
               else {
               	pNew->next = start;
               	start = pNew;
               }

	}


   
        free(line);
        fclose(file);
	
}

//kirjoittaa tiedostoon
void writeFile (char* output){
	FILE* file;
	
	//avaa tiedoston kirjoittamista varten
	file = fopen(output, "w");
	
	printf("%s\n", output);
	
	//käydään listaa läpi alusta loppuun
	//tulostetaan näytölle sekä kirjoitetaan tiedostoon
	ptr = start;
	while(ptr != NULL) {        
		printf("%s", ptr->string);
		fprintf(file, "%s", ptr->string);
		ptr = ptr->next;
	}
	
	if(fwrite != 0){
		printf("Linked List stored in the file successfully\n");
	}
	else {
		printf("Error While Writing\n");
	}
    
	fclose(file);
}

void freeMemory (){

	//tyhjennetään listan muisti käymällä se läpi alusta loppuun
	while(start != NULL) {
		ptr = start;        
		start = start->next;
		free(ptr);
	}
}
