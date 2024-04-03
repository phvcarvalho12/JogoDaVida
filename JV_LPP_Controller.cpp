//JV_LPP_Controller.cpp
//10/10/2023
//Grupo: LPP
//Larissa Hipolito, Pedro Gabriel, Pedro Carvalho 

#include <stdio.h>
#include <stdlib.h>
#include "JV_LPP_Controller.h"
#include "JV_LPP_View.cpp"
#include <time.h>

void criamatriz()
{
    int i, j;
    for(i = dim; i >= 1; i--)
        for(j = 1; j <= dim; j++)
            matriz[i][j] = '.';
}


void matrizgg()
{
	escolhamatriz();
	criamatriz();	
}

int escolhamatriz()
{
	do
	{
		apresentaMensagem("\nEscolha o tamanho da matriz (10 - 60): ");
		scanf("%d", &dim);
			
		if(dim >= 10 && dim <= 60)
		{
			return dim;
		}
			
		else
			apresentaMensagem("Tamanho invalido, tente novamente!");
	
	}while(dim < 10 || dim > 60);

}

void mostrarmatriz()
{
    int i, j;

    printf("  ");
    for(j = 1; j <= dim; j++) // numero da coluna
        printf(" %2d ", j);
    printf("\n");

    for(i = 1; i <= dim; i++)
    {
        printf("%2d", i); //numero da linha
        for(j = 1; j <= dim; j++)
            printf("  %c ", matriz[i][j]);
        printf("\n");
    }

}

void LimpaTela()
{
	system("@cls||clear");
}

void LimparBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

	
void addcelula()
{
    {
    int i, j, g, p;


    mostrarmatriz();

    do
    {
        LimpaTela();
        apresentaMensagem("Digite as coordenadas desejadas\n");
        apresentaMensagem("Digite a linha desejada: ");
        scanf("%d", &i);
        apresentaMensagem("Digite a coluna desejada: ");
        scanf("%d", &j);
        g = 0;

        if( i > dim || i == 0 || j > dim || j == 0)
        {
            apresentaMensagem("Coordenada digitada invalida\n");
            g = 1;
        }

    }while(g != 0);


    if(matriz[i][j] == 'O')
     {
         apresentaMensagem("Coordenada ja esta ocupada\n");
         apresentaMensagem("Deseja excluir a celula? (1- sim / 0 - nao) :");
         scanf("%d", &p);

         if(p == 1)
         {
             matriz[i][j] = '.';
             apresentaMensagem("Celula Excluida com sucesso!!");
        }
    }

    else if(matriz[i][j] == '.' )
    {
        matriz[i][j] = 'O';
        apresentaMensagem("Celula adicionada\n");

     }


}
}

void menuprincipal()
{
	int opcao;
	do
	{
		opcao = menu();
		switch(opcao)
		{
			case 1:
				mostrarmatriz();
				break;
			case 2:
				break;
			case 3:
				addcelula();
				break;
			
			case 0:
				apresentaMensagem("Obrigado por jogar");
				break;
			default:
				apresentaMensagem("Opcao invalida, tente novamente\n");
		}
	}while(opcao != 0);
	
}

void aprensentarvizinha(){
	
	int l;
	int c;
	
	for (int c = 1; c < tamanho-1; c++) //Verifica apenas a primeira linha, excluindo os cantos final e inicial
		{
			if(Vida[0][c] == 'O') //Se encontra celula viva adiciona os mortos ao seu redor sem invadir espaco nao alocado
				{
					if(Vida[0][c-1]=='.')
						Vida[0][c-1]='+';
					
					if(Vida[0][c+1]=='.')
						Vida[0][c+1]='+';
					
					if(Vida[1][c-1]=='.')
						Vida[1][c-1]='+';
					
					if(Vida[1][c]=='.')
						Vida[1][c]='+';
					
					if(Vida[1][c+1]=='.')	
						Vida[1][c+1]='+';
				}	 
		}
		
	for (int c = 1; c < tamanho-1; c++) //Verifica apenas a ultima linha da matriz (tamanho -1 para adaptar o indice da matriz), excluindo os cantos final e inicial
		{
			if(Vida[tamanho-1][c] == 'O') //Se encontra celula viva adiciona os mortos ao seu redor sem invadir espaco nao alocado
				{
					if(Vida[tamanho-1][c-1]=='.')
						Vida[tamanho-1][c-1]='+';
					
					if(Vida[tamanho-1][c+1]=='.')
						Vida[tamanho-1][c+1]='+';
					
					if(Vida[tamanho-2][c-1]=='.')
						Vida[tamanho-2][c-1]='+';
					
					if(Vida[tamanho-2][c]=='.')
						Vida[tamanho-2][c]='+';
					
					if(Vida[tamanho-2][c+1]=='.')	
						Vida[tamanho-2][c+1]='+';
				}

		} 
		
	for(int l = 1; l < tamanho-1; l++) //Verifica a primeira coluna da matriz, excluindo os cantos final e inicial
		{
			if(Vida[l][0] == 'O') //Se encontra celula viva adiciona os mortos ao seu redor sem invadir espaco nao alocado
				{
					if(Vida[l-1][0]=='.')
						Vida[l-1][0]='+';
					
					if(Vida[l+1][0]=='.')
						Vida[l+1][0]='+';
					
					if(Vida[l-1][1]=='.')
						Vida[l-1][1]='+';
					
					if(Vida[l][1]=='.')
						Vida[l][1]='+';
					
					if(Vida[l+1][1]=='.')	
						Vida[l+1][1]='+';
				}
		}
		
	for(int l = 1; l < tamanho-1; l++) //Verifica a ultima coluna, excluindo os cantos final e inicial
		{
			if(Vida[l][tamanho-1] == 'O') //Se encontra celula viva adiciona os mortos ao seu redor sem invadir espaco nao alocado
				{
					if(Vida[l-1][tamanho-1]=='.')
						Vida[l-1][tamanho-1]='+';
					
					if(Vida[l+1][tamanho-1]=='.')
						Vida[l+1][tamanho-1]='+';
					
					if(Vida[l-1][tamanho-2]=='.')
						Vida[l-1][tamanho-2]='+';
					
					if(Vida[l][tamanho-2]=='.')
						Vida[l][tamanho-2]='+';
					
					if(Vida[l+1][tamanho-2]=='.')	
						Vida[l+1][tamanho-2]='+';
				}
		}
		
	//Verifica a parte interna da matriz (fora as primeiras e ultimas coluna e linha e os cantos da matriz) 	
	for(int l = 1; l < tamanho-1; l++) 
	{
		for (int c = 1; c < tamanho-1; c++) 
		{
			if(Vida[l][c] == 'O') //Se encontra celula viva adiciona os mortos ao seu redor sem invadir espaco nao alocado
				{
					if(Vida[l-1][c-1]=='.')
						Vida[l-1][c-1]='+';
						
					if(Vida[l-1][c]=='.')
						Vida[l-1][c]='+';
					
					if(Vida[l-1][c+1]=='.')
						Vida[l-1][c+1]='+';
					
					if(Vida[l][c-1]=='.')
						Vida[l][c-1]='+';
					
					if(Vida[l][c+1]=='.')
						Vida[l][c+1]='+';
					
					if(Vida[l+1][c-1]=='.')
						Vida[l+1][c-1]='+';
					
					if(Vida[l+1][c]=='.')
						Vida[l+1][c]='+';
					
					if(Vida[l+1][c+1]=='.')
						Vida[l+1][c+1]='+';
					
				}
		}
	} 
	
	if(Vida[0][0]=='O') //Verifica o canto superior esquerdo da matriz
		{
			//Se encontra celula viva adiciona os mortos ao seu redor sem invadir espaco nao alocado
			if(Vida[0][1]=='.')
				Vida[0][1]='+';
			
			if(Vida[1][0]=='.')
				Vida[1][0]='+';
			
			if(Vida[1][1]=='.')
				Vida[1][1]='+';
		}
				
	if(Vida[0][tamanho-1]=='O') //Verifica o canto superior direito da matriz
		{
			//Se encontra celula viva adiciona os mortos ao seu redor sem invadir espaco nao alocado
			if(Vida[0][tamanho-2]=='.')
				Vida[0][tamanho-2]='+';
			
			if(Vida[1][tamanho-2]=='.')
				Vida[1][tamanho-2]='+';
			
			if(Vida[1][tamanho-1]=='.')
				Vida[1][tamanho-1]='+';	
		}
				
	if(Vida[tamanho-1][0]=='O') //Verifica o canto inferior esquerdo da matriz
		{
			//Se encontra celula viva adiciona os mortos ao seu redor sem invadir espaco nao alocado
			if(Vida[tamanho-2][0]=='.')
				Vida[tamanho-2][0]='+';
			
			if(Vida[tamanho-2][1]=='.')
				Vida[tamanho-2][1]='+';
			
			if(Vida[tamanho-1][1]=='.')
				Vida[tamanho-1][1]='+';
		}
				
	if(Vida[tamanho-1][tamanho-1]=='O') //Verifica o canto inferior direito da matriz
		{
			//Se encontra celula viva adiciona os mortos ao seu redor sem invadir espaco nao alocado
			if(Vida[tamanho-2][tamanho-2]=='.')
				Vida[tamanho-2][tamanho-2]='+';
			
			if(Vida[tamanho-1][tamanho-2]=='.')
				Vida[tamanho-1][tamanho-2]='+';
			
			if(Vida[tamanho-2][tamanho-1]=='.')
				Vida[tamanho-2][tamanho-1]='+';
		}
}