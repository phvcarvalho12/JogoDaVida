//Acer-jogodavida-controller.cpp
//27/09/2023

#include "Acer-jogodavida-controller.h"
#include "Acer-jogodavida-view.cpp"
#include<stdio.h>

void criarmundo()
{	
	int i , j; 
	for(i=0; i < tamanho; i++)       
		for(j=0 ; j < tamanho; j++)
		{
			celula[i][j] = '.' ;
		}
}


void menuprincipal()
{	
	int opc, i , j;
	do
	{
		opc = mostramenuprincipal();
		switch(opc)
		{
			case 1:
				colocarcelula();
				system("cls");
				mostramundo();
				break;
			case 2:
				{
				mostramundo();
				break;
				}
			case 3:
				vizinha();
				mostramundo();
				break;
			case 4:
				{
				for(i=0; i < tamanho; i++)       
					for(j=0 ; j < tamanho; j++)
					{
						if(celula[i][j] == '+')
						celula[i][j] = '.' ;
					}
				mostramundo();
				break;
				}
			case 5:
				criarmundo();
				mostramundo();
				break;
			case 0:
				break;
		}
		
	}while(opc != 0);
}

void vizinha()
{
	int i , j;
	for(i=0; i < tamanho; i++)       
		for(j=0 ; j < tamanho; j++)
			if(celula[i][j] == 'O')
				{
					if(celula[i-1][j] != 'O')
						celula[i-1][j] = '+';
					if(celula[i+1][j] != 'O')
						celula[i+1][j] = '+';
					if(celula[i][j-1] != 'O')
						celula[i][j-1] = '+';
					if(celula[i][j+1] != 'O')
						celula[i][j+1] = '+';
					
					if(celula[i-1][j-1] != 'O')
						celula[i-1][j-1] = '+';
					if(celula[i+1][j+1] != 'O')
						celula[i+1][j+1] = '+';
					if(celula[i+1][j-1] != 'O')
						celula[i+1][j-1] = '+';
					if(celula[i-1][j+1] != 'O')
						celula[i-1][j+1] = '+';
				
						
					
					
				}
}


