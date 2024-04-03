//JV_LPP_Controller.cpp
//10/10/2023
//Grupo: LPP
//Larissa Hipolito, Pedro Gabriel, Pedro Carvalho 

#include <stdio.h>
#include <stdlib.h>
#include "JV2_LPP_Controller.h"
#include "JV2_LPP_View.cpp"
#include <time.h>

void criamatriz()
{
    int i, j;
    for(i = 1; i <= dim; i++)
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
		apresentaMensagem("Diga o tamanho da matriz (10-60): \n");
		scanf("%d", &dim);
		LimpaTela();
		if(dim >= 10 && dim <= 60)
		{
			return dim;
		}
			
		else
			LimpaTela();
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
    // Coordenadas das celulas vivas
    printf("\nCoordenadas das celulas vivas:\n");
    for (i = 1; i <= dim; i++)
    {
        for (j = 1; j <= dim; j++)
        {
            if (matriz[i][j] == 'O')
            {
                printf("(%d,%d) ", i, j);
            }
        }
    }
    printf("\n");

    // Coordenadas dos vizinhos mortos
    printf("\nCoordenadas dos vizinhos mortos:\n");
    for (i = 1; i <= dim; i++)
    {
        for (j = 1; j <= dim; j++)
        {
            if (matriz[i][j] != 'O')
            {
                int vizinhosVivos = ContarVizinhosVivos(i, j);

                
                if (vizinhosVivos == 2 || vizinhosVivos == 3)
                {
                    printf("(%d,%d) ", i, j);
                }
            }
        }
    }
    printf("\n");

    MostraLvivo();
    MostraLmorto();
   
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
    int i, j, p;
    int continuar = 1;

    do {
        apresentaMensagem("Digite as coordenadas que voce deseja (0 para sair).\n");
        apresentaMensagem("Digite a linha que voce quer: ");
        scanf("%d", &i);
        LimpaTela();

        if (i == 0) {
            continuar = 0;  // Sai do loop se 0 for digitado
        } else {
            apresentaMensagem("Digite a coluna que voce quer: ");
            scanf("%d", &j);

            if (i > dim || i < 0 || j > dim || j < 0) {
                apresentaMensagem("Coordenada digitada invalida\n");
            } else {
                if (matriz[i][j] == 'O') {
                    apresentaMensagem("Coordenada ja tem uma celula\n");
                    apresentaMensagem("Deseja excluir a celula? (1- sim / 0 - nao) :");
                    scanf("%d", &p);
                    LimpaTela();

                    if (p == 1) {
                        matriz[i][j] = '.';
                        apresentaMensagem("Celula Excluida!\n");
                    }
                } else if (matriz[i][j] == '.') {
                    matriz[i][j] = 'O';
                    apresentaMensagem("Celula adicionada!\n");
                }
                LimpaTela();

                mostrarmatriz();  // Exibe a matriz após cada adição ou exclusão
            }
        }
    } while (continuar);

    apresentaMensagem("Saindo da inclusao de celulas.\n");
}

int ContarVizinhosVivos(int linha, int coluna) 
{
    int vizinhosVivos = 0;

    for (int i = linha - 1; i <= linha + 1; i++) 
	{
        for (int j = coluna - 1; j <= coluna + 1; j++) 
		{
            if ((i != linha || j != coluna) && i >= 1 && i <= dim && j >= 1 && j <= dim) 
			{
                if (matriz[i][j] == 'O') {
                    vizinhosVivos++;
                }
            }
        }
    }

    return vizinhosVivos;
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
				limpamesa();
				mostrarmatriz();
				break;
			case 3:
				addcelula();
				break;
			case 4:
				mostrarvizinhos();
				mostrarmatriz();
				break;
			case 5:
				escondevizinha();
				mostrarmatriz();
				break;
			case 6:
				geracao();
				break;
			case 7:
				salvarGeracoesEmArquivo();
				apresentaMensagem("Jogo salvo com sucesso");
                break;
            case 8:
            	carregarGeracoesDeArquivo();
            	apresentaMensagem("Jogo recuperado com sucesso");
            	break;
			case 0:
				apresentaMensagem("Saindo...");
				break;
			default:
				apresentaMensagem("Opcao invalida, tente novamente\n");
		}
	}while(opcao != 0);
	
}

void limpamesa()
{
	int i;
	int j;
	for(i=1; i <= dim; i++)
        for(j=1 ; j <= dim; j++)
            if((matriz[i][j] == 'O') || (matriz[i][j] == '+'))
            {			
            	matriz[i][j] = '.';
        	}
			
}

void mostrarvizinhos()
{
	int i, j;
	g = 1;
	for(i = 1; i <= dim; i++)
        for(j = 1 ; j <= dim; j++)
            if(matriz[i][j] == 'O')
                {
                    if(matriz[i-1][j] != 'O')
                        matriz[i-1][j] = '+';
                    if(matriz[i+1][j] != 'O')
                        matriz[i+1][j] = '+';
                    if(matriz[i][j-1] != 'O')
                        matriz[i][j-1] = '+';
                    if(matriz[i][j+1] != 'O')
                        matriz[i][j+1] = '+';

                    if(matriz[i-1][j-1] != 'O')
                        matriz[i-1][j-1] = '+';
                    if(matriz[i+1][j+1] != 'O')
                        matriz[i+1][j+1] = '+';
                    if(matriz[i+1][j-1] != 'O')
                        matriz[i+1][j-1] = '+';
                    if(matriz[i-1][j+1] != 'O')
                        matriz[i-1][j+1] = '+';
                    }
        
		}
        
void escondevizinha()
{
	int i, j;
	g = 0;	
	for(i = 1; i <= dim; i++)
        for(j = 1 ; j <= dim; j++)
            if(matriz[i][j] == '+')
            {
            	matriz[i][j] = '.';
			}		
}

int contavizinho(int p, int g) 
{
    int vizinho = 0;

    for (int i = p - 1; i <= p + 1; i++) 
	{
        for (int j = g - 1; j <= g + 1; j++) 
		{
            if (i != p || j != g) 
			{
                if (matriz[i][j] == 'O') 
				{
                    vizinho++;
                }
            }
        }
    }

    return vizinho;
}

void geracao()
{
	int sim, next, qntger;
	
	apresentaMensagem("         Iniciar Simulacao         \n");
	apresentaMensagem("1. Passar geracao manualmente?\n");
	apresentaMensagem("2. Digitar um tempo para cada passagem\n");
	scanf("%d", &sim );
	
	
	if(sim == 1)
	{
		do
		{
			apresentaMensagem("Proxima geracao?(5 para a proxima)\n");
			apresentaMensagem("0 para sair!");
			scanf("%d", &next);
			
			
			if(next == 5)
			{
				aplicaregra();
				LimpaTela();
				mostrarvizinhos();
				mostrarmatriz();
			}
		}while(next != 0);
	}
	
	else if(sim == 2)
	{
		apresentaMensagem("Quantas geracoes ira ter?");
		scanf("%d", &qntger);
		apresentaMensagem("Qual o tempo entre cada geracao?");
		scanf("%d", &atraso);
		
		for(int i = 0; i < qntger; i++)
		{
			aplicaregra();
			LimpaTela();
			mostrarvizinhos();
			mostrarmatriz();
			
			time_t lt1, lt2;
			//atraso de tempo
			lt1 = time(NULL);
			lt2 = lt1;
			while (difftime(lt2, lt1) < atraso)
			{
				lt2 = time(NULL);
			}
				
		}
	}
	
	else if(sim == 0)
		apresentaMensagem("Saindo...");
	
	else
		apresentaMensagem("Opcao errada! Digite novamente!");
}

void aplicaregra() 
{
    int p, g;  
    
    for (p = 1; p <= dim; p++) {
        for (g = 1; g <= dim; g++) {

            // Aplicar as regras do Jogo da Vida
            if (matriz[p][g] == 'O') {
                if (contavizinho(p, g)  < 2 || contavizinho(p, g) > 3) 
				{
                    maux[p][g] = '.';  
                } 
				
				else 
				{
                    maux[p][g] = 'O'; 
                }
            } 
			else 
			{
                if (contavizinho(p, g) == 3) 
				{
                    maux[p][g] = 'O';  
                } 
				
				else 
				{
                    maux[p][g] = '.';  
                }
            }
        }
    }
        for (p = 1; p <= dim; p++) {
        for (g = 1; g <= dim; g++) {
            matriz[p][g] = maux[p][g];
        }
    }

}

void carregaVivo(int ii, int jj)
{
	TipoCel *aux = (TipoCel*)malloc(sizeof(TipoCel));
	
	if (maux == NULL)
	{
		apresentaMensagem("Sem espaco na memoria para inclusao de celula viva\n");
		return;
	}
	
	aux->lin = ii; 
	
	aux->col = jj;
	if(totvivo == 0) 
	{
		pvivo = aux;
		pvivo->next = NULL; 
	}
	
	else 
	{
		aux->next = pvivo; 
		pvivo = aux; 
	 }
	 
	 totvivo++; 
}

void carregaProV(int ii, int jj)
{
	 TipoCel *aux = (TipoCel*)malloc(sizeof(TipoCel));
	 if (aux == NULL)
	 {
		apresentaMensagem("Sem espaco na memoria para inclusao de celula viva para a proxima geracao\n");
		return;
	 }
	 aux->lin = ii;
	 aux->col = jj;
	 if(totvivoprox == 0) 
	 {
		 pvivoprox = aux;
		 pvivoprox->next = NULL;
	 }
	 else 
	 {
		 aux->next = pvivoprox;
		 pvivoprox = aux; 
	 }
	 
	 totvivoprox++;
}

bool VerifMorto(int ii, int jj)
{
	 TipoCel *aux;
	 aux = pmorto;
	 if (totmorto == 0)
	 	return FALSE;
	 do
	 {
		 if (aux->lin == ii && aux->col == jj)
		 return TRUE;
		 aux = aux->next;
	 } while (aux != NULL);
	 
	 return FALSE;
}

void carregaMorto(int ii, int jj)
{
	 if ((ii < 0) || (jj < 0)) 
	 	return;
	 if ((ii >= dim) || (jj >=dim)) 
	 	return;
	 if(maux[ii][jj] == VIVO) 
	 	return;
	 
	 if (VerifMorto(ii, jj)== TRUE)
	 	return;
	 
	 TipoCel *aux = (TipoCel*)malloc(sizeof(TipoCel));
	 if (aux == NULL)
	 {
		 apresentaMensagem("Sem espaco na memoria para inclusao de celula morta-vizinha\n");
		 return;
	 }
	 
	 aux->lin = ii;
	 aux->col = jj;
	 if(totmorto == 0) 
	 {
		 pmorto = aux;
		 pmorto->next = NULL;
	 }
	 else 
	 {
		 aux->next = pmorto;
		 pmorto = aux; 
	 }
	 totmorto++;
	 if (fviz == TRUE) 
	 	maux[ii][jj] = VIZINHO;
	 else
	 	maux[ii][jj] = MORTO;
}

void carregaMortosViz()
{
	 int k, i, ii, jj;
	 struct
	 {
	 	int li, co;
	 } a,b,c,d,e,f,g,h; 
	 
	 totmorto = 0;
	 TipoCel *aux;
	 aux = pvivo;
	 if (totvivo == 0)
		 return;
	 do
	 {
		 ii = aux->lin;
		 jj = aux->col;
		 a.li = ii-1; a.co = jj-1;
		 b.li = ii-1; b.co = jj;
		 c.li = ii-1; c.co = jj+1;
		 d.li = ii; d.co = jj-1;
		 e.li = ii; e.co = jj+1;
		 f.li = ii+1; f.co = jj-1;
		 g.li = ii+1; g.co = jj;
		 h.li = ii+1; h.co = jj+1;
		 carregaMorto(a.li, a.co);
		 carregaMorto(b.li, b.co);
		 carregaMorto(c.li, c.co);
		 carregaMorto(d.li, d.co);
		 carregaMorto(e.li, e.co);
		 carregaMorto(f.li, f.co);
		 carregaMorto(g.li, g.co);
		 carregaMorto(h.li, h.co);
		 if(aux->next == NULL)
		 	break;
		 aux = aux->next;
	 }while(TRUE);
}

void atualizaViz()
{
	 int i, j, ii, jj, vii, vjj, ct;
	 liberaLista(pvivoprox, totvivoprox);
	 pvivoprox = NULL; 
	 if (pvivo == NULL)
	 	return;
	 
	 TipoCel *aux, *aux2;
	 aux = pvivo;
	 do
	 {
		 ct = 0; 
		 ii = aux->lin;
		 jj = aux->col;
		 aux2 = pvivo;
		 do
		 {
			 vii = aux2->lin;
			 vjj = aux2->col;
			 if (vii != ii || vjj != jj) 
			 	if(abs(ii-vii)<=1 && abs(jj-vjj)<=1) 
			 		ct++;
			 aux2 = aux2->next;
		 } while(aux2 != NULL);
		 
		 if (ct == 2 || ct == 3)
		 	carregaProV(ii,jj); 
		 
		 aux = aux->next;
	 } while(aux != NULL);
	 if (pmorto == NULL)
	 	return;
	 
	 aux = pmorto;
	 do
	 {
		 ct = 0; 
		 ii = aux->lin;
		 jj = aux->col;
		 aux2 = pvivo;
		 do
		 {
			 vii = aux2->lin;
			 vjj = aux2->col;
			 if(abs(ii-vii)<=1 && abs(jj-vjj)<=1) 
			 	ct++;
			 aux2 = aux2->next;
		 } while(aux2 != NULL);
		 
		 if (ct == 3)
		 	carregaProV(ii,jj); 
		 aux = aux->next;
	 } while(aux != NULL);
}

void excluiLVivo(int ii, int jj)
{
	 TipoCel *aux, *aux2; 
	 aux = pvivo;
	 aux2 = aux; 
	 if (totvivo > 0)
	 {
		 while (aux->lin != ii || aux->col != jj)
		 {
			 aux2 = aux;
			 aux = aux->next;
		 }
		 
		 if (aux->lin == ii && aux->col == jj)
		 {
			 if (aux2 == aux) 
			 	pvivo = aux->next;
			 else
			 	aux2->next = aux->next;
			 free(aux);
		}
		 totvivo--;
	 }
}

void liberaLista(TipoCel *aux, int tot)
{
	if(aux == NULL || tot == 0) //já está liberada
		return;
	TipoCel *aux2;
	do
	{
		aux2 = aux;
		aux = aux->next;
		free(aux2); //libera memoria
	}
	while(aux != NULL);
}

void alocamem()
{
	aux = (TipoCel*)malloc(sizeof(TipoCel));
	if (aux == NULL)
	 {
		 apresentaMensagem("Sem espaco na memoria\n");
		 return; 
 	}
}

void iniciaListas()
{
	 liberaLista(pvivo, totvivo);
	 liberaLista(pmorto, totmorto);
	 liberaLista(pvivoprox, totvivoprox);
	 pvivo = pmorto = pvivoprox = NULL; 
	 totvivo = totmorto = totvivoprox = 0; 
}

void salvarGeracoesEmArquivo()
 {
    FILE *arquivo;
    arquivo = fopen("geracoes_salvas.txt", "w");

    if (arquivo == NULL) 
	{
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivo, "%d\n", dim);  

    for (int i = 1; i <= dim; i++) 
	{
        for (int j = 1; j <= dim; j++) 
		{
            fprintf(arquivo, "%c ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

void carregarGeracoesDeArquivo() 
{
    FILE *arquivo;
    arquivo = fopen("geracoes_salvas.txt", "r");

    if (arquivo == NULL) 
	{
        fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    fscanf(arquivo, "%d", &dim);  // Lê a dimensão da matriz

    for (int i = 1; i <= dim; i++) 
	{
        for (int j = 1; j <= dim; j++)
		{
            fscanf(arquivo, " %c", &matriz[i][j]);
        }
    }

    fclose(arquivo);
}







/*void carregaVivo(int ii, int jj)
{
	TipoCel* maux = (TipoCel*)malloc(sizeof(TipoCel));
	if(maux==NULL)
	{
		apresentaMensagem("Sem espaco na memoria para inclusao de celula viva\n");
		return;
	}
	maux->lin=ii;
	maux->col=jj;
	if(totvivo==0)
	{
		pvivo=maux;
		pvivo->next=NULL;
	}
	else
	{
		maux->next=pvivo;
		pvivo=maux;
	}
	totvivo++;
}

void carregaM(int ii, int jj)
{
	TipoCel* maux = (TipoCel*)malloc(sizeof(TipoCel));
	if(maux==NULL)
	{
		apresentaMensagem("Sem espaco na memoria para inclusao de celula morta\n");
		return;
	}
	maux->lin=ii;
	maux->col=jj;
	if(totmorto==0)
	{
		pmorto=maux;
		pmorto->next=NULL;
	}
	else
	{
		maux->next=pmorto;
		pmorto=maux;
	}
	totmorto++;
}

void carregaProV(int ii, int jj)
{
	TipoCel* maux = (TipoCel*)malloc(sizeof(TipoCel));
	if(maux==NULL)
	{
		apresentaMensagem("Sem espaco na memoria para inclusao de celula viva da proxima geracao\n");
		return;
	}
	maux->lin=ii;
	maux->col=jj;
	if(totvivoprox==0)
	{
		pvivoprox=maux;
		pvivoprox->next=NULL;
	}
	else
	{
		maux->next=pvivoprox;
		pvivoprox=maux;
	}
	totvivoprox++;


	for(int i = 1; i<=dim; i++)
		for(int j = 1; j<=dim; j++)
			matriz[i][j] = '.';
			
	maux = pvivoprox;
	while(totvivoprox>0)
	{
		matriz[maux->lin][maux->col]='O';
		pvivoprox=maux->next;
		printf("\n");  //trocar por free(maux); depois
		maux = pvivoprox;
		totvivoprox--;
	}	
}

void ContaMortosVivos()      //funcao que verifica quais celulas sao mortas vizinhas
{
	TipoCel *mauxant, *maux;

	int i,j,m,c;
	
	for(i = 1; i<=dim; i++)                   
		for(j = 1; j<=dim; j++)
			for(int l = (i-1); l <=(i+1); l++)
				for(int c = (j-1); c <=(j+1); c++)
					if ((l != 0) && (l != (dim + 1)))
						if ((c != 0) && (c != (dim + 1)))
							if((matriz[i][j] == 'O') && (matriz[l][c] != 'O'))
								matriz[l][c] = '+';


	for(i = 1; i<=dim; i++)                   
		for(j = 1; j<=dim; j++)
			if(matriz[i][j]=='+')
				carregaM(i,j);
					
}

void ContaVivosAtuais()         //funcao que verifica quais celulas estao vivas
{
	for(int i = 1; i<=dim; i++)                   

		for(int j = 1; j<=dim; j++)
			if(matriz[i][j]=='O')
				carregaVivo(i,j);
}

void LimpalistaMortos()       //funcao que limpa a lista dos mortos-vizinhos
{
	TipoCel *maux,*maux2;

	if(totmorto>0)
	{
		maux = pmorto;
		while(maux->next!=NULL)
		{
		maux2 = maux->next;
		printf("\n");  //trocar por free(maux); depois
		maux = maux2;
		}
		printf("\n");  //trocar por free(maux); depois
		pmorto = NULL;
		totmorto=0;
	}
	
}

void LimpalistaVivos()       //funcao que limpa a lista dos vivos atuais
{
	TipoCel *maux,*maux2;

	if(totvivo>0)
	{
		maux = pvivo;
	while(maux->next!=NULL)
	{
		maux2 = maux->next;
		printf("\n");  //trocar por free(maux); depois
		maux = maux2;
	}
	printf("\n");  //trocar por free(maux); depois
	pvivo=NULL;
	totvivo=0;
	}
	
}

void Mostravivo()
{
	int c=0;

	TipoCel *maux;
	maux=pvivo;
	if(totvivo>0)
	{
		printf("Celulas vivas: ");
		while(maux->next!=NULL)
		{
			printf("(%d,%d)  ",maux->lin,maux->col);
			maux=maux->next;
			c++;
			if(c%10==0)
				printf("\n\t\t\t ");
			
		}
		printf("(%d,%d)\n",maux->lin,maux->col);
	}
	printf("\n");
}

void Mostramorto()        //funcao que apresenta na tela a lista de mortos-vizinhos
{
	int c=0;

	TipoCel *maux;
	maux=pmorto;
	if(totmorto>0)
	{
		printf("Celulas mortas-vizinhas: ");
		while(maux->next!=NULL)
		{
			printf("(%d,%d)  ",maux->lin,maux->col);
			maux=maux->next;
			c++;
			if(c%10==0)
				printf("\n\t\t\t ");
		}
		printf("(%d,%d)  ",maux->lin,maux->col);
	}
	printf("\n\n");
}*/
