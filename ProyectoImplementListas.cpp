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

struct nodo{
	TPersonaje personaje;
	struct nodo *sig;
};

nodo *crearpersonaje(nodo *D);
void CargarDatos(nodo *dato);
void MostrarDatos(nodo *D);
void cargar_caract(nodo *D);
void Mostrar_caract(nodo *D);
void mostrarpersonajes(nodo *D);
void game(nodo *D1,nodo *D2);

int main()
{
	
	nodo *P=NULL,*nuevo,*P1,*P2;
	srand(time(NULL));
	 int x;
	nuevo=crearpersonaje(P);
	P=nuevo;
	
	// D=(TPersonaje *)malloc(sizeof(TPersonaje));
	//printf("**********************************\n");
	for (int i = 0; i < 4; i++)
	{
		P=crearpersonaje(P);

		// l=rand()%5;
		// k=rand()%5;
		// n= (char *)malloc(sizeof(char)*(strlen(Nombres[l])));
		// a= (char *)malloc(sizeof(char)*(strlen(Apellidos[k])));
		// n=strcat(Nombres[l],"\0");
		// a=strcat(Apellidos[k],"\0");
		// strcpy(n,Nombres[l]);
			// CargarDatos (P);
			// cargar_caract(P);

	}


	mostrarpersonajes(P);
	P1=P;
	P2=P;
	printf("\n\n");
	printf("Player1 elija su personaje al escribir su numero: \n");
	scanf("%d",&x);
	for (int i = 1; i < x; ++i)
	{
		P1=P1->sig;
	}
	printf("Player2 elija su personaje al escribir su numero: \n");
	scanf("%d",&x);
	for (int i = 1; i < x; ++i)
	{
		P2=P2->sig;
	}
	game(P1,P2);
	//cargar_caract(&p);
	free(P);
	return 0;
}

nodo *crearpersonaje(nodo *D){

	nodo *nuevo;
	nuevo=(nodo*)malloc(sizeof(nodo)); 
	CargarDatos(nuevo);
	cargar_caract(nuevo);
	nuevo->sig=D;
	return(nuevo);

}


void CargarDatos(nodo *dato){
	
	int a = rand()%(5);
	int b = rand()%(5);
	static int x=0;

	dato->personaje.DatosPersonales=(TDatos *)malloc(sizeof(TDatos));

	dato->personaje.DatosPersonales->ApellidoNombre = (char *)malloc(sizeof(char)*(strlen(Apellidos[b]) + strlen(Nombres[a]) + 1));
	strcpy(dato->personaje.DatosPersonales->ApellidoNombre, Apellidos[b]);
	strcat(dato->personaje.DatosPersonales->ApellidoNombre, " ");
	strcat(dato->personaje.DatosPersonales->ApellidoNombre, Nombres[a]);
	
	dato->personaje.DatosPersonales->Raza=x++;
	dato->personaje.DatosPersonales->edad = rand()%300;
	dato->personaje.DatosPersonales->Salud = 100;
}

void MostrarDatos(nodo *D){
	
	printf("Apellido Y Nombre: %s\n", D->personaje.DatosPersonales->ApellidoNombre);
	printf("Raza: ");

	switch((D->personaje.DatosPersonales->Raza)+1){
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
	printf("Edad: %d\n",D->personaje.DatosPersonales->edad );
	printf("Salud: %.2f\n\n", D->personaje.DatosPersonales->Salud);
}

void cargar_caract(nodo *D){
	
	D->personaje.Caracteristicas=(TCaracteristicas *)malloc(sizeof(TCaracteristicas ));
	D->personaje.Caracteristicas->velocidad = 1 + rand()%(1+9);
	D->personaje.Caracteristicas->destreza = 1 + rand()%(1+4);
	D->personaje.Caracteristicas->fuerza = 1 + rand()%(1+9);
	D->personaje.Caracteristicas->Nivel = 1 + rand()%(1+9);
	D->personaje.Caracteristicas->Armadura = 1 + rand()%(1+9);
}
void Mostrar_caract(nodo *D){
	printf("velocidad=%d\n\r",D->personaje.Caracteristicas->velocidad);
	printf("destreza=%d\n\r",D->personaje.Caracteristicas->destreza);
	printf("fuerza=%d\n\r",D->personaje.Caracteristicas->fuerza);
	printf("nivel=%d\n\r",D->personaje.Caracteristicas->Nivel);
	printf("armadura=%d\n\r",D->personaje.Caracteristicas->Armadura);
	
}
void mostrarpersonajes(nodo *D){
	nodo *pers;
  	int i;
	pers = D;
	if(pers == NULL)printf("¡la lista esta vacia!");
	else
	{

      for(i=0;pers!=NULL;pers=pers->sig,i++)
      {
		printf("\nPersonaje Numero  %d\n",i+1);		
      	printf("\n Datos: \n");
        MostrarDatos(pers);
        printf("\nCaracteristicas:\n");
        Mostrar_caract(pers);
        printf("********************************************\n");
      }
     
	}
}
void game(nodo *D1,nodo *D2){
	system("cls");
	printf("\n\tPlayer1:\n");
	MostrarDatos(D1);
	Mostrar_caract(D1);

	printf("\n\n\tPlayer2:\n");
	MostrarDatos(D2);
	Mostrar_caract(D2);
	printf("\n\nPresione una tecla para la batalla  mas epica q hayas visto en una juego...");
	getch();

	for (int i = 0; i <3 && D2->personaje.DatosPersonales->Salud > 0 && D1->personaje.DatosPersonales->Salud > 0; i++)
	{
		system("cls");
		
		textcolor(14);

		cprintf("\nRound %d, fight!\n",i+1 );
		double PD1, PD2, ED1, ED2, VA1, VA2, PDEF1, PDEF2, DP1, DP2, MDP;
		MDP=50000;
		PD1=D1->personaje.Caracteristicas->destreza*D1->personaje.Caracteristicas->fuerza*D1->personaje.Caracteristicas->Nivel;
		ED1=rand()%(1+99);
		VA1=PD1*ED1;
		PDEF1=D1->personaje.Caracteristicas->Armadura*D1->personaje.Caracteristicas->velocidad;
		PD2=D2->personaje.Caracteristicas->destreza*D2->personaje.Caracteristicas->fuerza*D2->personaje.Caracteristicas->Nivel;
		ED2=rand()%(1+99);
		VA2=PD2*ED2;
		PDEF2=D2->personaje.Caracteristicas->Armadura*D2->personaje.Caracteristicas->velocidad;
		printf("\n\nPresione una tecla para que ataque Player1");
		getch();
		DP1=((VA1-PDEF2)/MDP)*100;
		D2->personaje.DatosPersonales->Salud = D2->personaje.DatosPersonales->Salud - DP1;
		printf("\nAtaque Player1 quita a player 2: '%.2f' puntos de vida\n", DP1);
		textcolor(9);
		if (D2->personaje.DatosPersonales->Salud <= 0)
		{
		cprintf("Salud de Player2: '0'\n");
		break;
			
		}else{
		cprintf("Salud de Player2: '%.2f'\n", D2->personaje.DatosPersonales->Salud);			
		}
		printf("\n\nPresione una tecla para que ataque Player2");
		getch();
		DP2=((VA2-PDEF1)/MDP)*100;
		D1->personaje.DatosPersonales->Salud = D1->personaje.DatosPersonales->Salud - DP2;
		printf("\nAtaque Player2 quita a Player 1: '%.2f' puntos de vida\n", DP2);
		if (D1->personaje.DatosPersonales->Salud <= 0)
		{
		cprintf("Salud de Player1: '0'");
		break;
		}else{
		cprintf("Salud de Player1: '%.2f'\n", D1->personaje.DatosPersonales->Salud);
		}
		textcolor(1);
		cprintf("\npresione para siguiente Round...\n");
		getch();
	}
	textcolor(5);
	clrscr();
	gotoxy(10,5);
	if (D2->personaje.DatosPersonales->Salud > D1->personaje.DatosPersonales->Salud)
		{
			cprintf("\n'---****Ganador Player2****---'\n");
		}
		else{
			if (D2->personaje.DatosPersonales->Salud == D1->personaje.DatosPersonales->Salud)
			{
				cprintf("\n'---****EMPATE****---'\n");
			}else{
				cprintf("\n'---****Ganador Player1****---'\n");
			}
		}
		
}