//JV_LPP_Model.cpp
//10/10/2023
//Grupo: LPP
//Larissa Hipolito, Pedro Gabriel, Pedro Carvalho 

#include "JV2_LPP_Model.h"


typedef struct cel
{
 	int lin, col;      //as 2 coordenadas da celula
 	struct cel *next;  //ponteiro (endereço) para a próxima célula
} TipoCel;

TipoCel *aux;
TipoCel *pvivo, *pmorto, *pvivoprox;
int totvivo, totmorto, totvivoprox;


