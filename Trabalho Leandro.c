#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

struct TpAluno
{
    char Nome[30], RA[13];
}

struct TpDisci
{
    char Descr[30];

    int CodDisc;
}

struct TpNota
{
    char RA[13];

    int CodDisc;

    float Nota;
}

void CadastroAluno(TpAluno AuxAlunos,int &TL)
{
    char AuxRA,AuxNome,j=0;

    system("cls");
    printf("### Cadastro de Aluno ###\n\n");
    do
    {
        printf("Digite o RA do Aluno: ");
        getch(AuxRA);
        if(TL>0)
            for(i=0;i<TL;i++)
                if(strcmp(AuxCRA,AuxAlunos[i].RA)==0)
                {
                    i=TL;
                    printf("\n### Nao foi possivel cadastrar esse RA, ele ja esta presente no Sistema\n");
                }
        else
            if(strlen(AuxCad)==12)
            {
                strcpy(AuxAlunos.Nome[TL],AuxCad);
                printf("Digite o Nome do Aluno: ");
                getch(Auxcad);
            }
        // printf("Digite o Nome do Aluno: ");
        // getch(Auxcad);
    
        
        


    } while (AuxCad != '');
}

void Menu()
{
    char menu;

    system("cls");
    printf("### Selecione uma Opcao ###\n\n");
    printf("[A] Cadastro de Alunos\n");
    printf("[B] Cadastro de Disciplinas\n");
    printf("[C] Cadastro de Notas\n");
    printf("[D] Atualizar Alunos\n");
    printf("[E] Atualizar Disciplinas\n");
    printf("[F] Atualizar Notas\n");
    printf("[G] Excluir Alunos\n");
    printf("[H] Excluir Disciplinas\n");
    printf("[I] Excluir Notas\n");
    printf("[J] Visualizar Alunos\n");
    printf("[K] Visualizar Disciplina\n");
    printf("[L] Visualizar Notas\n");
    printf("[M] Reprovado em 2 ou mais disciplinas\n");
    printf("[N] Visualizar Alunos por Letra\n");
    printf("[O] Visualizar Disciplinas com media abaixo de 6.0\n");
    printf("[P] Visualizar Todos os Dados\n");
    printf("[ESC] Sair\n");
    printf("Opcao desejada: ");

    menu = toupper(getch());
}

int main()
{

}