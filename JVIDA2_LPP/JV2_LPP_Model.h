//JV_LPP_Model.h
//10/10/2023
//Grupo: LPP
//Larissa Hipolito, Pedro Gabriel, Pedro Carvalho 

int dim; // dimensao escolhida pelo criador
char matriz[60][60];
int g;
char maux[60][60];
int atraso;

#define FALSE 0
#define TRUE 1
#define VIVO 'O'
#define MORTO '.'
#define VIZINHO '+'

bool fviz = FALSE;