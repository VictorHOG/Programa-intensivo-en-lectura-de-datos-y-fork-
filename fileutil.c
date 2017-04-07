#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "fileutil.h"

char **retornarArchivos(char* ruta,int *numeroArchivos ){

	DIR *directorio = NULL;
	struct dirent *ent = NULL;
	int contador = 0;
	int iterador = 0;
	char** archivos;

	archivos = (char**) malloc(1*sizeof(char*));

	directorio = opendir(ruta);

	if (directorio != NULL) {

		while ((ent = readdir(directorio)) != NULL) {

			if (ent->d_type != DT_DIR) {

				contador++;
				char** archivos_temporal = (char**) realloc(archivos,contador*sizeof(char*));

				if (archivos_temporal) {  // Si es diferente de NULL
					archivos = archivos_temporal;
				} else {
					printf("Error al reasignar la memoria");
				}

				archivos[iterador] = (char*) malloc(strlen(ent->d_name)+ strlen(ruta));

				strcpy(archivos[iterador],ruta);
				strcat(archivos[iterador],"/");
				strcat(archivos[iterador], ent->d_name);

				iterador++;

			}
		}

		closedir(directorio);

	} else {
		perror("No se puede abrir el directorio. ");
	}

	*numeroArchivos = iterador;
	return archivos;

}


int calcularBytesArchivos(char *nombreArhivo) {

	FILE *fp;
	int contador = 0;

	fp = fopen(nombreArhivo,"r");
	if (fp == NULL) {
		perror("calcularBytesArchivos - No se pudo abrir archivo\n");
		return -1;
	}
	while (fgetc(fp) != EOF) {
		contador++;
	}
	fclose(fp);
	return contador;
}
