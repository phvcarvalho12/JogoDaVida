//Acer-jogodavida-view.cpp
//27/09/2023

#include "Acer-jogodavida-view.h"
#include<stdio.h>
#include<iostream>

void recebetamanho()
{
	while(1)
	{
	printf("digite o tamanho do mundo: ");
	scanf("%d", &tamanho);
	if(tamanho > 60 || tamanho < 10)
		printf("tamanho invalido\n");
	else
		{
		printf("\no tamanho do mundo e %d\n", tamanho);
		break;	
		}
	}
	
}

int mostramenuprincipal()
{
	int opc;
	printf("JOGO DA VIDA\n");
	printf("1- mudar uma celula no jogo\n");
	printf("2- mostrar mundo\n");
	printf("3- mostrar celulas vizinhas-mortas\n");
	printf("4- nao mostrar vizinhas\n");
	printf("5- apagar celulas: ");
	scanf("%d", &opc);
	return opc;
}

void mostramundo()
{
	int i , j;
	system("cls");
	printf("\n");
	printf("\t ");
	for(j = 0; j < tamanho; j++)
		printf("%2d  ", j);
	printf("\n\n");
	
	for(i = 0; i < tamanho ; i++)
	{
	printf("%2d \t", i);
	for(j = 0; j < tamanho ; j++)
		printf("%3c ", celula[i][j]);
	printf("\n");
	}	
}

void colocarcelula()
{
	int l, c , op;
	printf("\ncolocar celula\n");
	do
	{
	printf("\nlinha: (-1 para sair): ");
	scanf("%d", &l);
	
	if(l == -1)
		break;
	
	if(l < 0||l > tamanho)
		{
		printf("linha incorreta\n");
		continue;
		}
	
	
	printf("\nColuna: ");
	scanf("%d", &c);
	
	if(c > tamanho || c < 0)
		{
		printf("Coluna incorreta\n");
		continue;
		}
	else if(celula[l][c] == 'O')
		{
		printf("voce quer tirar a celula?(1 = sim ; 2 = nao): ");
		scanf("%d", &op);
		if(op == 2)
		{
			continue;
		}
		else if(op == 1)
		{
			celula[l][c] = '.';
			system("cls");
			mostramundo();
			printf("celula apagada\n");
			continue;
		}
		else
		{
			printf("opcao incorreta\n");
			continue;
		}
		}
	else
		{
		celula[l][c] = 'O';
		system("cls");
		mostramundo();
		continue;
		}
	
	
	
	}while(l != -1);
}