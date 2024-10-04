#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

struct TpAluno
{
    char Nome[30], RA[13];
};

struct TpDisci
{
    char Descr[30];

    int CodDisc;
};

struct TpNota
{
    char RA[13];

    int CodDisc;

    float Nota;
};

void Adicionar(TpAluno AuxNomes, int &TLA,TpDisci AuxDisci, int &TLD,TpNota AuxNotas, int &TLN)
{
    int i=0;

    strcpy(AuxNomes[i].Nome,"Joao");
    strcpy(AuxNomes[i].RA,"26.24.1121-1");

    AuxDisci[i].CodDisc = 100;
    strcpy(AuxDisci[i].Descr,"ATP 2");

    strcpy(AuxNotas[i].RA,"26.24.1121-1");
    AuxNotas[i].CodDisc = 100;
    AuxNotas[i].Nota = 8;

    i++;

    strcpy(AuxNomes[i].Nome,"Maria");
    strcpy(AuxNomes[i].RA,"26.28.1921-1");

    AuxDisci[i].CodDisc = 99;
    strcpy(AuxDisci[i].Descr,"ATP 1");

    strcpy(AuxNotas[i].RA,"26.28.1921-1");
    AuxNotas[i].CodDisc = 99;
    AuxNotas[i].Nota = 8;

    TLA=i;
    TLD=i;
    TLN=i;
}

int main()
{
    int TLA=0,TLD=0,TLN=0;

    Adicionar();
}