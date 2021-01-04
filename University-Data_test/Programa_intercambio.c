#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

//Si la funcion no es void, se debe declarar su funcion prototipo
float promedio_examenes(float califMat, float califFisica, float califQuimica, float califHistoria);
float calificacion_toefl(float puntosToelf);


int main ()
{	double orig_v[200][200]; int carrera[46], cant_carreras[5]={0,0,0,0,0}, clave_carrera[5] = {102,103,202,303,404};
	FILE *archivo;
	float aux1, aux2, aux3, aux4, aux5, aux6, aux7, aux8;
	
	//Abrir archivo .txt
	archivo=fopen("datos_Universidad.txt","r");
    if (archivo == NULL)	
            printf("\nAPERTURA DE ARCHIVO 'datos_Universidad.txt' FALLIDA\n\n");
        else printf("APERTURA DE ARCHIVO 'datos_Universidad.txt' EXITOSA\n\n");
        

	//Lee archivo y lo guarda en una matriz
	int i = 0;
    while(fscanf(archivo,"%f*-*%f*-*%f*-*%f*-*%f*-*%f*-*%f*-*%f",&aux1,&aux2,&aux3,&aux4,&aux5,&aux6,&aux7,&aux8)==8)
    {
    	orig_v[i][0]=aux1; orig_v[i][1]=aux2; orig_v[i][2]=aux3; orig_v[i][3]=aux4; orig_v[i][4]=aux5; orig_v[i][5]=aux6; orig_v[i][6]=aux7; orig_v[i][7]=aux8;
    	carrera[i] = aux2;
		i++;	
	}
	
	
    printf("Arreglo original\n"); imprimir_arreglo(orig_v); //Funcion para imprimir arreglo original
    //Esto está comentado para no hacer las modificaciones, el archivo a trabajar para ya estar modificado (al parecer)
    //mod_prom_Mat(orig_v); mod_prom_Fisica(orig_v); mod_prom_Quimica(orig_v); mod_prom_Historia(orig_v);
	printf("Arreglo modificado\n"); //imprimir_arreglo(orig_v); //Funcion para imprimir arreglo modificado
	
	for (i = 0; i<45; i++)
	{
		orig_v[i][8] = calificacion_toefl(orig_v[i][7]);
		orig_v[i][9] = (promedio_examenes(orig_v[i][3], orig_v[i][4], orig_v[i][5], orig_v[i][6]) + orig_v[i][2])/2;
		if ((orig_v[i][3] >=9) && (orig_v[i][4]>=9) && (orig_v[i][5]>=9) && (orig_v[i][6]>=9))
			orig_v[i][10] = 1;
		else orig_v[i][10] = 0;
		if (orig_v[i][10] == 1)
		{
			if (orig_v[i][9] >= 9.5) orig_v[i][11] = 50;
			else if ((orig_v[i][9] > 9) && (orig_v[i][9] < 9.5)) orig_v[i][11] = 20;	
		}
		else orig_v[i][11] = 0;
	}
		
	imprimir_arreglo_promedios(orig_v);
	
	ordenamiento_burbuja(carrera);
	for (i=0; i<45; i++)
		switch (carrera[i]){
			case 102: cant_carreras[0]++;
				break;
			case 103: cant_carreras[1]++;
				break;
			case 202: cant_carreras[2]++;
				break;
			case 303: cant_carreras[3]++;
				break;
			case 404: cant_carreras[4]++;
				break;}
	for (i=0; i<5; i++)
		printf("Clave carrera: %d\t Cant. Solicitantes: %d\n", clave_carrera[i], cant_carreras[i]);
			
return 0;
}





//Funcion para imprimir el arreglo
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimir_arreglo(double arregloBidimensional[200][200])
{
	int  i = 0;
	printf("------------------------------------------------------------------------------\n");
	printf("claveAlumno   claveCarrera promPrepa  califMat   califFisica  califQuimica  califHistoria   puntajeTOEFL\n");
	while(i<45)
	{
		printf("%f   %f   %f   %f   %f     %f      %f        %f \n", arregloBidimensional[i][0],arregloBidimensional[i][1],arregloBidimensional[i][2],arregloBidimensional[i][3],arregloBidimensional[i][4],arregloBidimensional[i][5],arregloBidimensional[i][6],arregloBidimensional[i][7]);
		i++;
	}
	printf("\n------------------------------------------------------------------------------\n\n");
}

//Funcion para imprimir el arreglo con calculos de beca
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimir_arreglo_promedios(double arregloBidimensional[200][200])
{
	int  i = 0;
	printf("------------------------------------------------------------------------------\n");
	printf("claveAlumno   claveCarrera promPrepa  califMat   califFisica  califQuimica  califHistoria   puntajeTOEFL  califTOEFL   PromCalif-Prepa  CandidatosBeca     %%BECA\n");
	for(i=0; i<45; i++)
		printf("%f   %f   %f   %f   %f     %f      %f        %f    %f     %f         %f           %f\n", arregloBidimensional[i][0],arregloBidimensional[i][1],arregloBidimensional[i][2],arregloBidimensional[i][3],arregloBidimensional[i][4],arregloBidimensional[i][5],arregloBidimensional[i][6],arregloBidimensional[i][7],  arregloBidimensional[i][8], arregloBidimensional[i][9], arregloBidimensional[i][10], arregloBidimensional[i][11]);
	printf("\n------------------------------------------------------------------------------\n\n");
}

//Funcion para modificar calificacion de Mat
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mod_prom_Mat(double arregloBidimensional[100][100])
{
	int i = 0;
	while(i<45)
	{
		arregloBidimensional[i][3] = (1/(exp(arregloBidimensional[i][3] + 0.5))) + (3*sin(arregloBidimensional[i][3]));
		i++;
	}
}

//Funcion para modificar calificacion de Fisica
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mod_prom_Fisica(double arregloBidimensional[100][100])
{
	int i = 0, n = 0; float aux = 0;
	while(i<45)
	{
		for(n = 1; n<15; n++)
			aux += 5*pow(arregloBidimensional[i][4], exp(n)) - 3*arregloBidimensional[i][4] + 1;
		arregloBidimensional[i][4] = aux;
		i++;
	}
}

//Funcion para modificar calificacion de Quimica
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mod_prom_Quimica(double arregloBidimensional[100][100])
{
	int i = 0;
	while(i<45)
	{
		arregloBidimensional[i][5] = tan(1/cos(arregloBidimensional[i][5])) + (0.25*arregloBidimensional[i][5]);
		i++;
	}
}

//Funcion para modificar calificacion de Historia
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mod_prom_Historia(double arregloBidimensional[100][100])
{
	int i = 0, n = 0; float aux = 0;
	while(i<45)
	{	
		for(n = 1; n<10; n++)
			aux += 0.5*pow(arregloBidimensional[i][6], 2) - tan(n/2) + exp(0.3*arregloBidimensional[i][6]);
		arregloBidimensional[i][6] = aux;
		i++;
	}
}

//Funcion para calcular calificacion ingles
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float promedio_examenes(float califMat, float califFisica, float califQuimica, float califHistoria)
{	return (califMat + califFisica + califQuimica + califHistoria)/4;}

//Funcion para calcular calificacion ingles
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float calificacion_toefl(float puntosToelf)
{	return puntosToelf*10/550; }


void ordenamiento_burbuja(int arreglo[46])
{
	int i, j, auxiliar = 0;
	//for (i=0; i<45; i++)
	//	printf("%d \n", arreglo[i]);
	for (j=0; j<45; j++)	
		for (i=0; i<45-1; i++)
			if (arreglo[i] > arreglo[i+1])
			{
				auxiliar = arreglo[i];
				arreglo[i] = arreglo[i+1];
				arreglo[i+1] = auxiliar;
			}
	//printf("\n");		
	//for (i=0; i<45-1; i++)
	//	printf("%d \n", arreglo[i]);
}
	
