#include <stdio.h>
#include <stdlib.h>


struct TDatos {
//	TRaza Raza; //nota 1
	char *ApellidoNombre; //nota 2
	int edad; //entre 0 a 300
	double Salud;//100
};
	struct TCaracteristicas{
	int velocidad;// 1 a 10
	int destreza; //1 a 5
	int fuerza;//1 a 10
	int Nivel; //1 a 10
	int Armadura; //1 a 10
};
	struct TPersonaje {
	TDatos * DatosPersonales;
	TCaracteristicas * Caracteristicas;
};

int main(){

	int rnd = Random(10) + 20;
	printf("%d",rnd);

	return 0;
}