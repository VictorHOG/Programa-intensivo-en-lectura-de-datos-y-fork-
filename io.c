#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "fileutil.h"

int main(int argc, char *argv[]) {

	char ** archivos;
	char * ruta;
	int numeroArchivos ;
	int numeroBytes;

	numeroArchivos = 0;
	numeroBytes =0;
	ruta = (char*) malloc (100 * sizeof(char*)) ;
	ruta = argv[1];
	archivos = retornarArchivos(ruta, &numeroArchivos);

	for (int i=0; i<numeroArchivos; i++) {
		numeroBytes += calcularBytesArchivos(archivos[i]);
	}

	printf("Estudiante: 201532342\n");
	printf("Total archivos: %d\n", numeroArchivos);
	printf("Total bytes: %d\n", numeroBytes);

}
