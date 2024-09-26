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

void CadastroAluno(TpAluno AuxAlunos,int &TLA)
{
    char AuxRA,AuxNome,decisao;
    int i=0;

    system("cls");
    printf("### Cadastro de Aluno ###\n\n");
    do
    {
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12)
        {
            if(TLA>0)
            {
                i=0;

                while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
                    i++;

                if(i!=TLA)
                    printf("\n### Nao foi possivel cadastrar esse RA, ele ja esta presente no Sistema\n");
                else
                {
                    printf("\nDigite o Nome do Aluno: ");
                    scanf(" %s",&AuxNome);

                    while(strcmp(AuxNome,"/0")==0)
                    {  
                        printf("### Nome Invalido ###");
                        printf("\nDeseja cancelar esse cadastro? [S]-Sim [N]-Nao\n");
                        printf("Opcao desejada: ");
                        decisao = toupper(getch());

                        if(a==21)
                        {
                            printf("\nDigite o Nome do Aluno: ");
                            scanf(" %s",&AuxNome);
                        }
                        else
                            strcpy(AuxNome,"SIM");
                    }

                    if(stricmp(AuxNome,"SIM")!=0)
                    {    
                        strcpy(AuxAlunos[TLA].RA,AuxRA);
                        strcpy(AuxAlunos[TLA].Nome,AuxNome);
                        TLA++;
                    }
                }
            }
            else
            {
                printf("\nDigite o Nome do Aluno: ");
                scanf(" %s",&AuxNome);

                while(strcmp(AuxNome,"/0")==0)
                {  
                    printf("### Nome Invalido ###");
                    printf("\nDeseja cancelar esse cadastro? [S]-Sim [N]-Nao\n");
                    printf("Opcao desejada: ");
                    if(a==21)
                    {
                        printf("\nDigite o Nome do Aluno: ");
                        scanf(" %s",&AuxNome);
                    }
                    else
                        strcpy(AuxNome,"SIM");
                }

                if(stricmp(AuxNome,"SIM")!=0)
                {    
                    strcpy(AuxAlunos[TLA].RA,AuxRA);
                    strcpy(AuxAlunos[TLA].Nome,AuxNome);
                    TLA++;
                }
            }
        }
        
        if(strcmp(AuxRA,"/0")!=0)
            printf("### RA Invalido ###");

    } while(strcmp(AuxRA,"/0")!=0);
}

void CadastroNota(TpNota AuxNotas,TpAluno AuxAlunos,TpDisci AuxDisci,int TLA,int TLD, int &TLN)
{
    char AuxRA[13];
    int AuxCodDisc, i=0;
    float Notas;
    do
    {
        system("cls");
        printf("### Cadastro Notas ###\n\n");
        printf("Digite o RA do Aluno: ");
        AuxRA = getche();

        while(strcmp(AuxRA,AuxAlunos.RA[i]) != 0 && i<TL)
        {
            i++;
        }

        if(strcmp(AuxRA,AuxAlunos.RA[i]) != 0)
            printf("\n### RA nao cadastrado, tente novamente ###\n");
    }while();

}

void Menu()
{
    char menu;

    do
    {
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

        switch(menu)
        {
            case A:
                CadastroAluno();
            break;

            case B:
                CadastroDisciplina();
            break;

            case C:
                CadastroNota();
            break;
            
            case D:

            break;

            case E:

            break;

            case F:

            break;

            case G:

            break;

            case H:

            break;

            case I:

            break;

            case J:

            break;

            case K:

            break;

            case L:

            break;

            case M:

            break;

            case N:

            break;

            case O:

            break;

            case P:

            break;
        }

    }while(menu!=27);
}

int main()
{
    int TLA=0, TLD=0, TLN=0;
    
    Menu(); 
}