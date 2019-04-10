#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum TRaza{Orco = 1, Humano, Mago, Enano, Elfo};
char Nombres[6][10]={"juan","esteban","armando","augusto","gian","maxi"};
char Apellidos[6][10]={"fasito","quito","sneider","servimoto","casa","rifa"};

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
void cargar_datos(struct TDatos *datos);
void mostrar_datos(TDatos *datos);
void cargarCaracteristicas(TCaracteristicas *cargar);
void mostrarCaracterist(TCaracteristicas *mostrar);

int main(){
	srand (time(NULL));

	//---------------------------------------------------------------//	
	TDatos *datos;
	datos=(TDatos*)malloc(sizeof(TDatos));

	cargar_datos(datos);
	mostrar_datos(datos);
	//-------------------------------------------------------------//
	TCaracteristicas *caract;

	caract=(TCaracteristicas*)malloc(sizeof(TCaracteristicas));
	cargarCaracteristicas(caract);
	mostrarCaracterist(caract);
	//--------------------------------------------------------------//
	printf("\n---------------------------------\n");
	int n;
	printf("Ingrese el numero de jugadores: ");
	scanf("%d", &n);
	printf("\n---------------------------------\n");

	for (int i = 0; i < n; ++i)
	{
		printf("Datos del jugador numero: %d\n",i+1 );
		TDatos *datos;
		datos=(TDatos*)malloc(sizeof(TDatos));

		cargar_datos(datos);
		mostrar_datos(datos);
		caract=(TCaracteristicas*)malloc(sizeof(TCaracteristicas));
		cargarCaracteristicas(caract);
		mostrarCaracterist(caract);
		printf("---------------------------------\n");

	}


	return 0;
}
void cargarCaracteristicas(TCaracteristicas *cargar)
{
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

void cargar_datos(struct TDatos *datos)
{
	datos->ApellidoNombre = (char *) malloc (10);
	strcpy(datos->ApellidoNombre, Nombres[0 + rand()% (6-1)]);
	printf("Nombre y Apellido: %s ", datos->ApellidoNombre );

	strcpy(datos->ApellidoNombre, Apellidos[0 + rand()% (6-1)]);
	printf("%s\n", datos->ApellidoNombre );

	datos->edad = 0 + rand()%(301-1);
	datos->Salud = 100;

}

void mostrar_datos(TDatos *datos)
{
	int Raza = 1+rand()%(6-1);

	switch(Raza){
		case 1: printf("Raza: Orco\n");
			break;
		case 2: printf("Raza: Humano\n");
			break;
		case 3: printf("Raza: Mago\n");
			break;
		case 4: printf("Raza: Enano\n");
			break;
		case 5: printf("Raza: Elfo\n");
			break;
	}
	//printf("Nombre y Apellido: %s\n", datos->ApellidoNombre );
	printf("Edad: %d\n", datos->edad);
	printf("Salud: %2.f\n",datos->Salud );

}