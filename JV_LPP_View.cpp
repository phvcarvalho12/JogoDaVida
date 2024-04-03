//JV_LPP_View.cpp
//10/10/2023
//Grupo: LPP
//Larissa Hipolito, Pedro Gabriel, Pedro Carvalho 


#include "JV_LPP_View.h"

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
    printf(" 4 - Mostrar/Esconder vizinhos mortos\n");
    printf(" 5 - Iniciar Processo                \n");
    printf(" 6 - Apresentar as Listas            \n");
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

void quervizinhas(){
	printf("Voce deseja mostrar celululas vizinhas?(S/N) ")
	scanf("%d", &op);
	
	if (op == 'S' || op == 's'){
		aprensentarvizinha();
	}
			
	else
		continue;
}