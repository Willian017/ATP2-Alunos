#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define tf 30;

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

void CadastroAluno(TpAluno AuxAlunos[30],int &TLA)
{
    char AuxRA,AuxNome,decisao;
    int Veri=0,i=0;

    system("cls");
    printf("### Cadastro de Aluno ###\n\n");
    do
    {
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12 && Veri==1)
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

                while(strcmp(AuxNome,"/0")!=0)
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

void Excluir(TpAluno auxAl[30], int &TLa, TpDisci auxDisci[30], TpNota auxNota[30], int &TLD, int &TLN)
{
    char exclusao[13], opcao;
    int i, j;

    printf("Digite o RA que deseja excluir:\n");
    scanf("%s", exclusao);
    
    // Vai fazer a busca pelo RA do Aluno
    for (i = 0; i < TLa; i++) {
        if (strcmp(auxAl[i].RA, exclusao) == 0) { //Vai fazer a comparação para encontrar "== 0 se for verdade "
            printf("Aluno encontrado! O que deseja fazer?\n");//Achou 
            printf("(A) Excluir Aluno\n"); //opção dado para excluir aluno diretamente
            printf("(B) Excluir Disciplina\n"); //opcao dada para excluir disciplina
            printf("(C) Excluir Nota\n"); //opcao dada para excluir nota
            scanf(" %c", &opcao); //digita a opcao desejada ,a,b,c
            opcao = toupper(opcao); //funcao dada para digitar independente maiusculo ou minusculo

            // Excluir Aluno
            if (opcao == 'A') {
                for (j = i; j < TLa - 1; j++) { //busca para aluno, "j=i pois é o indici a ser excluído , j=tla-1 pois ira percorrer até o penultimo item"
                    auxAl[j] = auxAl[j + 1]; // Desloca os alunos para "apagar" o aluno
                }
                TLa--; // Reduz a quantidade de alunos
                printf("Aluno com o RA %s excluído!\n", excluir);
            }

            // Excluir Disciplina
            else if (opcao == 'B') {
                int codDisc, k;
                printf("Digite o código da disciplina que deseja excluir:\n");
                scanf("%d", &codDisc);

                for (k = 0; k < TLD; k++) {
                    if (auxDisci[k].CodDisc == codDisc) { //se a disciplina no vetor for igual a disciplina digitada
                        for (j = k; j < TLD - 1; j++) { //descoloca o vetor excluindo a disciplina encontrada
                            auxDisci[j] = auxDisci[j + 1]; // Desloca as disciplinas
                        }
                        TLD--; //vetor diminui de tamanho
                        printf("Disciplina com código %d excluída!\n", codDisc);
                    }
                }
                printf("Disciplina não encontrada!\n");
            }

            // Excluir Nota
            else if (opcao == 'C') {
                int codDisc, k;
                printf("Digite o código da disciplina para excluir a nota:\n");
                scanf("%d", &codDisc);

                for (k = 0; k < TLN; k++) { //vetor notas
                    if (strcmp(auxNota[k].RA, exclusao) == 0 && auxNota[k].CodDisc == codDisc) { //compara se a variavel presente no auxNota é a mesma presente na exclusao, compara se a variavel presente em auxNota é a mesma presente em codDisc
                        auxNota[k].Nota = 0.0; // se ambas forem verdadeiras zera a nota presente
                        printf("Nota da disciplina %d excluída!\n", codDisc);
                    }
                }
                printf("Nota não encontrada!\n"); //se for falso exibe a mensagem
            } else {
                printf("Opção inválida!\n"); //se digitar algo sem ser a,b,c , exibe a mensagem
            }
            return;
        }
    }

    printf("Aluno com RA %s não encontrado!\n", exclusao); //se digitar um RA inexistente exibe a mensagem
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
        printf("[P] Visualizar Todosa os Dados\n");
        printf("[ESC] Sair\n");
        printf("Opcao desejada: ");

        menu = toupper(getch());

        switch(menu)
        {
            case A:
                CadastroAluno(TpAluno Auxalunos,TLA);
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
