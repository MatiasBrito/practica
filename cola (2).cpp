/*En una empresa de servicios de telefonía celular se registra la información de los clientes a ser
atendidos en una estructura de cola, de cada uno de los N clientes se ingresa la siguiente
información:
? Número de atención.
? Número de celular.
? Tipo de reclamo: (F: Facturación, C:Compra, T:Técnico)

a) Ingresar los datos en la cola dinámica.*
b) Mostrar los datos del próximo cliente a atender y borrarlo de la cola.*
c) Indicar el porcentaje de clientes que fueron por problemas técnicos*/

#include <stdio.h>
#include <stdlib.h>

struct cliente{
	int nro_atencion;
	int nro_cel;
	char tipo;
	cliente *sig;
};

void carga(cliente *&frente, cliente *&fondo);
void muestra(cliente *frente);
void atender(cliente *&frente, int &cont);

main(){
	cliente *frente = NULL, *fondo = NULL;
	int n, cont = 0;
	printf("ingrese la cantidad de clientes: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		carga(frente, fondo);
	}
	
	muestra(frente);
	atender(frente, cont);
	muestra(frente);
	printf("el porcentaje de clientes por temas tecnicos es %f", (float)cont*100/n);
}

void carga(cliente *&frente, cliente *&fondo){
	
	cliente *nuevo = new cliente;

	printf("ingrese el nro de atencion\n");
	scanf("%d", &nuevo->nro_atencion);
	printf("ingrese el nro de celular\n");
	scanf("%d", &nuevo->nro_cel);
	printf("ingrese el tipo de atencion\n");
	_flushall();
	scanf("%c", &nuevo->tipo);
	nuevo->sig = NULL;
	
	if (frente == NULL){
		frente = nuevo;		
	}
	else{
		fondo->sig = nuevo;				
	}
	
	fondo = nuevo;
}


void muestra(cliente *frente){
	cliente *aux = frente;
	while(aux != NULL){
		printf("Nro atencion: %d\n", aux->nro_atencion);
		printf("Nro celular: %d\n", aux->nro_cel);
		printf("Tipo: %c\n", aux->tipo);
		
		aux = aux->sig;
	}	
}


void atender(cliente *&frente, int &cont){
	cliente *aux;
	
	while(frente != NULL){
		aux = frente;
		printf("Nro atencion: %d\n", aux->nro_atencion);
		printf("Nro celular: %d\n", aux->nro_cel);
		printf("Tipo: %c\n", aux->tipo);
		if (aux->tipo == 't') cont++;
		frente = aux->sig;
		delete aux;	
		system("PAUSE");
	}
}
