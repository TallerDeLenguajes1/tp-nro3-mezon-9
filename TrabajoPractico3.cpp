#include <stdio.h>
#include <stdlib.h>

enum TRaza{Orco, Humano, Mago, Enano, Elfo};

struct TDatos {
	TRaza Raza; //nota 1
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

void cargarCaracteristicas(TCaracteristicas *cargar);
void mostrarCaracterist(TCaracteristicas *mostrar);

int main(){
	TCaracteristicas *caract;

	caract=(TCaracteristicas*)malloc(sizeof(TCaracteristicas));
	cargarCaracteristicas(caract);
	mostrarCaracterist(caract);


	return 0;
}
void cargarCaracteristicas(TCaracteristicas *cargar)
{
	srand (time(NULL));
	cargar->velocidad = 1 + rand()%11-1;	
	cargar->destreza = 1 + rand()%6-1;
	cargar->fuerza = 1 +rand()%11-1;
	cargar->Nivel = 1 + rand()%11-1;
	cargar->Armadura = 1 + rand()%11-1;
}
void mostrarCaracterist(TCaracteristicas *mostrar)
{
	printf("Velocida: %d\n",mostrar->velocidad);
	printf("Destreza: %d\n",mostrar->destreza);
	printf("fueza: %d\n",mostrar->fuerza);
	printf("Nivel: %d\n",mostrar->Nivel);
	printf("Armadura: %d\n",mostrar->Armadura);
}