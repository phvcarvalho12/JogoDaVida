//JV_LPP_View.cpp
//10/10/2023
//Grupo: LPP
//Larissa Hipolito, Pedro Gabriel, Pedro Carvalho 


#include "JV2_LPP_View.h"

void apresentaMensagem(char mens[100])
{
	printf("%s", mens);
}

int menu() //menu de uso 
{
	int op;
    printf("             JOGO DA VIDA            \n");
    printf("             Menu Geral:             \n");
    printf(" 1 - Apresentar Mapa                 \n");
    printf(" 2 - Limpar Mesa                     \n");
    printf(" 3 - Incluir/Excluir celulas         \n");
    printf(" 4 - Mostrar vizinhos mortos\n");
    printf(" 5 - Esconder vizinhos mortos\n");
    printf(" 6 - Iniciar Processo                \n");
    //printf(" 7 - Apresentar as Listas            \n");
    printf(" 7 - Gravar uma geracao inicial      \n");
    printf(" 8 - Recuperar geracao cadastrada    \n");
    printf(" 9 - Limpar Cadastro                 \n");
    printf(" 10 - Regras de evolucao das celulas \n");
    printf(" 0 - Sair                            \n");
    printf("Escolha uma opcao: ");
	scanf("%d", &op);
	LimpaTela();
	printf("\n");
	return op;
}


void MostraLvivo()
{
	int c=0;
	TipoCel *aux;
	aux=pvivo;
	if(totvivo>0)
	{
		printf("Celulas vivas: ");
		while(aux->next!=NULL)
		{
			printf("(%d,%d)  ",aux->lin,aux->col);
			aux=aux->next;
			c++;
			if(c%10==0)
				printf("\n\t\t\t ");
			
		}
		printf("(%d,%d)\n",aux->lin,aux->col);
	}
	printf("\n");
}


void MostraLmorto()
{
	int c=0;
	TipoCel *aux;
	aux=pmorto;
	if(totmorto>0)
	{
		printf("Celulas mortas-vizinhas: ");
		while(aux->next!=NULL)
		{
			printf("(%d,%d)  ",aux->lin,aux->col);
			aux=aux->next;
			c++;
			if(c%10==0)
				printf("\n\t\t\t ");
		}
		printf("(%d,%d)  ",aux->lin,aux->col);
	}
	printf("\n\n");
}
