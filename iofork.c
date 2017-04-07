#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	char ** archivos;
	char * ruta;
	int numeroArchivos ;
	int numeroBytes;

	int bytesPadre;
	int bytesHijo;
	int mitad;
	int fd[2];
	pid_t pid;

	numeroArchivos = 0;
	numeroBytes =0;
	bytesPadre = 0;
	bytesHijo = 0;
	mitad = 0;
	ruta = (char*) malloc (100 * sizeof(char*)) ;
	ruta = argv[1];

	archivos = retornarArchivos(ruta, &numeroArchivos);
	mitad = numeroArchivos/2;

	pipe(fd);
	pid = fork();

	if (pid == 0) {

		for (int i=0; i<mitad; i++) {
			bytesPadre += calcularBytesArchivos(archivos[i]);
		}

		read(fd[0], &bytesHijo , sizeof(bytesHijo));

		printf("Estudiante: 201532342\n");
		printf("Total archivos: %d\n", numeroArchivos);
		printf("Total bytes: %d\n", bytesPadre+bytesHijo);


	} else  {

		for (int i=mitad; i<numeroArchivos; i++) {
			bytesPadre += calcularBytesArchivos(archivos[i]);
		}

		write(fd[1], &bytesPadre , sizeof(bytesPadre));
	}

}
