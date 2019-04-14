#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

enum TRaza{Orco, Humano, Mago, Enano, Elfo};
char Nombres[6][10]={"juan","esteban","armando","augusto","gian","maxi"};
char Apellidos[6][10]={"fasito","quito","sneider","servimoto","Soul","rifa"};
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

void CargarDatos(TPersonaje *dato);
void MostrarDatos(TPersonaje *D);
void cargar_caract(TPersonaje *D);
void Mostrar_caract(TPersonaje *D);
void game(TPersonaje *D1,TPersonaje *D2);
int main()
{
	TPersonaje *D;
	srand(time(NULL));
	
	int P1,P2;
	
	
	D=(TPersonaje *)malloc(sizeof(TPersonaje)*5);
	//printf("**********************************\n");
	for (int i = 0; i < 5; i++)
	{
		// l=rand()%5;
		// k=rand()%5;
		// n= (char *)malloc(sizeof(char)*(strlen(Nombres[l])));
		// a= (char *)malloc(sizeof(char)*(strlen(Apellidos[k])));
		// n=strcat(Nombres[l],"\0");
		// a=strcat(Apellidos[k],"\0");
		// strcpy(n,Nombres[l]);
			CargarDatos (D+i);
			cargar_caract(D+i);

	}
	for (int i = 0; i < 5; i++)
	{

		printf("\nPersonaje Numero %d\n",i+1 );		
		MostrarDatos(D+i);
		printf("**************************************************\n");
		printf("Caracteristicas:\n");
		Mostrar_caract(D+i);
		printf("**************************************************\n");
	}
	printf("\n\n");
	printf("Player1 elija su personaje al escribir su numero: \n");
	scanf("%d",&P1);
	printf("Player2 elija su personaje al escribir su numero: \n");
	scanf("%d",&P2);
	game(D+(P1-1),D+(P2-1));
	//cargar_caract(&p);
	free(D);
	return 0;
}
void CargarDatos(TPersonaje *dato){
	
	int a = rand()%(5);
	int b = rand()%(5);
	
	dato->DatosPersonales=(TDatos *)malloc(sizeof(TDatos));

	dato->DatosPersonales->ApellidoNombre = (char *)malloc(sizeof(char)*(strlen(Apellidos[b]) + strlen(Nombres[a]) + 1));
	strcpy(dato->DatosPersonales->ApellidoNombre, Apellidos[b]);
	strcat(dato->DatosPersonales->ApellidoNombre, " ");
	strcat(dato->DatosPersonales->ApellidoNombre, Nombres[a]);
	
	dato->DatosPersonales->edad = rand()%300;
	dato->DatosPersonales->Salud = 100;
}

void MostrarDatos(TPersonaje *D){
	
	printf("Apellido Y Nombre: %s\n", D->DatosPersonales->ApellidoNombre);
	printf("Raza: ");
	switch((D->DatosPersonales->Raza)+1){
		case 1:{
			printf("Orco\n");
			break;
		}
		case 2:{
			printf("Humano\n");
			break;
		}
		case 3:{
			printf("Mago\n");
			break;
		}
		case 4:{
			printf("Enano\n");
			break;
		}
		case 5:{
			printf("Elfo\n");
			break;
		}
	}
	printf("Edad: %d\n",D->DatosPersonales->edad );
	printf("Salud: %.2f\n\n", D->DatosPersonales->Salud);
}

void cargar_caract(TPersonaje *D){
	
	

	D->Caracteristicas=(TCaracteristicas *)malloc(sizeof(TCaracteristicas ));
	D->Caracteristicas->velocidad=1 + rand()%(1+9);
	D->Caracteristicas->destreza=1 + rand()%(1+4);
	D->Caracteristicas->fuerza =1 + rand()%(1+9);
	D->Caracteristicas->Nivel=1 + rand()%(1+9);
	D->Caracteristicas->Armadura=1 + rand()%(1+9);
}
void Mostrar_caract(TPersonaje *D){
	printf("velocidad=%d\n\r",D->Caracteristicas->velocidad);
	printf("destreza=%d\n\r",D->Caracteristicas->destreza);
	printf("fuerza=%d\n\r",D->Caracteristicas->fuerza);
	printf("nivel=%d\n\r",D->Caracteristicas->Nivel);
	printf("armadura=%d\n\r",D->Caracteristicas->Armadura);
	
}
void game(TPersonaje *D1,TPersonaje *D2){
	printf("\n\tPlayer1:\n");
	MostrarDatos(D1);
	Mostrar_caract(D1);

	printf("\n\n\tPlayer2:\n");
	MostrarDatos(D2);
	Mostrar_caract(D2);
	printf("\n\nPresione una tecla para la batalla  mas epica q hayas visto en una juego...");
	getch();

	for (int i = 0; i <3 && D2->DatosPersonales->Salud > 0 && D1->DatosPersonales->Salud > 0; i++)
	{
		double PD1, PD2, ED1, ED2, VA1, VA2, PDEF1, PDEF2, DP1, DP2, MDP;
		MDP=50000;
		PD1=D1->Caracteristicas->destreza*D1->Caracteristicas->fuerza*D1->Caracteristicas->Nivel;
		ED1=rand()%(1+99);
		VA1=PD1*ED1;
		PDEF1=D1->Caracteristicas->Armadura*D1->Caracteristicas->velocidad;
		PD2=D2->Caracteristicas->destreza*D2->Caracteristicas->fuerza*D2->Caracteristicas->Nivel;
		ED2=rand()%(1+99);
		VA2=PD2*ED2;
		PDEF2=D2->Caracteristicas->Armadura*D2->Caracteristicas->velocidad;
		printf("\n\nPresione una tecla para que ataque Player1");
		getch();
		DP1=((VA1-PDEF2)/MDP)*100;
		D2->DatosPersonales->Salud = D2->DatosPersonales->Salud - DP1;
		printf("Ataque Player1 quita a player 2: '%.2f' puntos de vida\n", DP1);
		if (D2->DatosPersonales->Salud <= 0)
		{
		printf("Salud de Player2: '0'\n");
		break;
			
		}else{
		printf("Salud de Player2: '%.2f'\n", D2->DatosPersonales->Salud);			
		}
		printf("\n\nPresione una tecla para que ataque Player2");
		getch();
		DP2=((VA2-PDEF1)/MDP)*100;
		D1->DatosPersonales->Salud = D1->DatosPersonales->Salud - DP2;
		printf("Ataque Player2 quita a Player 1: '%.2f' puntos de vida\n", DP2);

		if (D1->DatosPersonales->Salud <= 0)
		{
		printf("Salud de Player1: '0'");
		break;
		}else{
		printf("Salud de Player2: '%.2f'\n", D1->DatosPersonales->Salud);
		}
	
	}
	if (D2->DatosPersonales->Salud > D1->DatosPersonales->Salud)
		{
			printf("\n\t'----****Ganador Player2****---'\n");
		}
		else{
			if (D2->DatosPersonales->Salud == D1->DatosPersonales->Salud)
			{
				printf("\n\t'----****EMPATE****---'\n");
			}else{
				printf("\n\t'----****Ganador Player1****---'\n");
			}
		}
		
}