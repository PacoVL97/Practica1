#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int G;
char comensal[20];
void guardar1(char nombre[50], char comensal[20], char com [100]);
void guardar2(char nombre[50], char comensal[20], char com [100]);
void guardar3(char nombre[50], char comensal[20], char com [100]);

int main(void) {
	pid_t pid1, pid2;
    int status1, status2, i;
   

	printf("Bienvenido. \n");
	printf("Ingrese su nombre. (max 20)\n");
	scanf("%s",comensal);
	
	
	do{
	
	printf("Quedesea ordenar hoy. \n");
	printf("las opciones son: \n");
	printf("1.-Desayuno.\n");
	printf("2.-Comida.\n");
	printf("3.-Cena.\n");
	printf("4.-Desayuno y Comida. \n");
	printf("5.-Comida y cena. \n");
	printf("6.-Desayuno, Comida y Cena. \n");	
	printf("7.-SALIR. \n");
	scanf("%d",&G);

	switch(G)
		{
		case 1:
			if((pid1=fork())==0){ //como solo se selecciona una opcion no se utiliza el hijo

			}
			else
			{
				//wait(&status1);
				printf("El desayuno es: \n");
				printf("Hot cakes, fruta con yoghurt y jugo de naranja. proceso:%d\n", getpid());
                
                //break;
			}
		
			guardar1(" desayuno ", comensal, "Hot cakes, fruta con yoghurt, jugo de naranja.\n");
			exit(0);
			break;
		case 2:
			if((pid1=fork())==0){ //como solo se selecciona una opcion no se utiliza el hijo

			}
			else
			{
				//wait(&status1);
				printf("la comida es arrachera con queso fundido proceso %d.\n", getpid());
				guardar2(" comida ", comensal, "Arrachera con queso fundido.\n");
			}
			exit(0);
			break;
		case 3:
			if((pid1=fork())==0){ //como solo se selecciona una opcion no se utiliza el hijo

			}
			else
			{
				//wait(&status1);
				printf("la cena es Empanada de atun y cafe %d.\n", getpid());
				guardar3(" cena ", comensal, "Empanada de atun y cafe.\n");
			}
			exit(0);
			break;
		case 4:
			if((pid1=fork())==0){ 
				printf("El desayuno es: \n");
				printf("Hot cakes, fruta con yoghurt, jugo de naranja proceso %d\n", getpid());
				guardar1(" desayuno ", comensal, "Hot cakes, fruta con yoghurt, jugo de naranja.\n");
			}
			else{
				wait(&status1);
				printf("la comida es arrachera con queso fundido proceso %d.\n", getpid());
				guardar2(" comida ", comensal, "Arrachera con queso fundido.\n");
			}
			exit(0);
			break;
		case 5:
			if((pid1=fork())==0){ 
				printf("la comida es arrachera con queso fundido proceso %d.\n", getpid());
				guardar2(" comida ", comensal, "Arrachera con queso fundido.\n");
			}
			else{
				wait(&status1);
				printf("la cena es Empanada de atun y cafe %d.\n", getpid());
				guardar3(" cena ", comensal, "Empanada de atun y cafe.\n");
			}
			exit(0);
			break;
		case 6:	
			if((pid1=fork())==0){ 
				if((pid1=fork())==0){
					printf("la cena es Empanada de atun y cafe %d.\n", getpid());
					guardar3(" cena ", comensal, "Empanada de atun y cafe.\n");
				}
				else{
					wait(&status2);
					printf("la comida es arrachera con queso fundido proceso %d.\n", getpid());
					guardar2(" comida ", comensal, "Arrachera con queso fundido.\n");
				}
			}
			else{
				wait(&status1);
				printf("la cena es Empanada de atun y cafe %d.\n", getpid());
				guardar1(" desayuno ", comensal, "Hot cakes, fruta con yoghurt, jugo de naranja.\n");
			}
			exit(0);
			break;
		default: 
			return 0;
		}
	}while(G!=7);
	return 0;	
}

void guardar1(char nom[50], char comensal[20], char com [100]){
    FILE* fichero;
    fichero = fopen("desayuno.txt", "a+");
    fputs(comensal, fichero);
    fputs(nom, fichero);
    fputs(com, fichero);
    fclose(fichero);
    return;
}

void guardar2(char nom[50], char comensal[20], char com [100]){
    FILE* fichero;
    fichero = fopen("comida.txt", "a+");
    fputs(comensal, fichero);
    fputs(nom, fichero);
    fputs(com, fichero);
    fclose(fichero);
    return;
}

void guardar3(char nom[50], char comensal[20], char com [100]){
    FILE* fichero;
    fichero = fopen("cena.txt", "a+");
    fputs(comensal, fichero);
    fputs(nom, fichero);
    fputs(com, fichero);
    fclose(fichero);
    return;
}
