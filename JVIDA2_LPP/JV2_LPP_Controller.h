//JV_LPP_Controller.h
//10/10/2023
//Grupo: LPP
//Larissa Hipolito, Pedro Gabriel, Pedro Carvalho 


void mostrarmatriz();
void LimpaTela();
void menuprincipal();
int escolhamatriz();
void LimparBuffer();
void tamanhomatriz();
void addcelula();
void criamatriz();
void matrizgg();
void limpamesa();
void mostrarvizinhos();
void escondevizinha();
void atualizamatriz();
void criamatrizaux();
void aplicaregra();
int contavizinho(int p, int g);
void mauxrecebeprincipal();
void principalrecebemaux();
void geracao();
void limparMatriz();

void alocamem();
void carregaVivo(int ii, int jj);
void carregaMorto(int ii, int jj);
void carregaProV(int ii, int jj);
void carregaMortosViz();
void atualizaViz();
void excluiLVivo(int ii, int jj);
void liberaLista(TipoCel *maux, int tot);
void iniciaListas();
void salvarGeracoesEmArquivo();
void carregarGeracoesDeArquivo();
int ContarVizinhosVivos(int linha, int coluna);



