#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

enum TRaza{Orco, Humano, Mago, Enano, Elfo};
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

void CargarDatos(TPersonaje *dato, TRaza raza,char *nombre ,char *apellido,int edad,double salud);
void MostrarDatos(TPersonaje *D);
void cargar_caract(TCaracteristicas *p);

int main()
{
	TPersonaje *D;
	TCaracteristicas p;
	//char *n,*a;
	char n[100]="Juan",a[100]="Rodriguez";
	/*printf("Ingrese nombre: ");
	scanf("%s",&n);
	printf("Ingrese apellido: ");
	scanf("%s",&a);
	printf("\n");*/
//	n="Juan";
//	a="Rodriguez";
	D=(TPersonaje *)malloc(sizeof(TPersonaje));
	//printf("**********************************\n");
	CargarDatos(D,Mago,n,a,200,50);
	MostrarDatos(D);
	printf("\n\n");

	cargar_caract(&p);
	//printf("**********************************\n");
	return 0;
}
void CargarDatos(TPersonaje *dato,TRaza raza,char *nombre ,char *apellido,int edad,double salud){
	
	dato->DatosPersonales=(TDatos *)malloc(sizeof(TDatos));
//	dato->DatosPersonales->ApellidoNombre=(char *)malloc(sizeof(char)*(strlen(nombre)+strlen(apellido)));
	dato->DatosPersonales->ApellidoNombre=(char *)malloc(sizeof(char)*(strlen(nombre)+strlen(apellido)+2));
	dato->DatosPersonales->ApellidoNombre=strcat(apellido," ");
	dato->DatosPersonales->ApellidoNombre=strcat(dato->DatosPersonales->ApellidoNombre,nombre);
	dato->DatosPersonales->ApellidoNombre=strcat(dato->DatosPersonales->ApellidoNombre,"\0");
	//printf("%s\n", dato->DatosPersonales->ApellidoNombre);
	dato->DatosPersonales->Raza=raza;
	dato->DatosPersonales->edad=edad;
	dato->DatosPersonales->Salud=salud;
}

void MostrarDatos(TPersonaje *D){
	
	printf("Apellido Y Nombre: %s\n", D->DatosPersonales->ApellidoNombre);
	printf("Raza: %d\n", D->DatosPersonales->Raza);
	printf("Edad: %d\n",D->DatosPersonales->edad );
	printf("Salud: %.2f\n", D->DatosPersonales->Salud);
}

void cargar_caract(TCaracteristicas *p){

	srand(time(NULL));
	p -> velocidad=1 + rand()%(1+9);
	p -> destreza=1 + rand()%(1+5);
	p -> fuerza =1 + rand()%(1+9);
	p -> Nivel=1 + rand()%(1+9);
	p -> Armadura=1 + rand()%(1+9);

	printf("velocidad=%d\n\r",p -> velocidad);
	printf("destreza=%d\n\r",p -> destreza);
	printf("fuerza=%d\n\r",p -> fuerza);
	printf("nivel=%d\n\r",p -> Nivel);
	printf("armadura=%d\n\r",p -> Armadura);
	
}

