#include <stdio.h>

#define TF 50
struct Alunos
{
    char Nome[30], RA[15];
}Al;

struct Disciplinas
{
    char Nome[50];

    int Codigo;
}Dis;

struct Notas
{
    char Nome_Aluno[30];

    int Codigo_Disciplina;

    float Nota;
}Not;

void CadastroAluno(Alunos AuxAlunos,int &TL)
{
    char AuxCad,j=0;

    system("cls");
    printf("### Cadastro de Aluno ###\n\n");
    do
    {
        printf("Digite o Nome do Aluno: ");
        printf("Digite o RA do Aluno: ");
    
        if(TL>0)
            for(i=0;i<TL;i++)
                if(strcmp(AuxCad,AuxAlunos[i].RA)==0)
                {
                    i=TL;
                    printf("\n### Nao foi possivel cadastrar esse RA, ele ja esta presente no Sistema\n");
                }
        


    } while (AuxCad != '');
}

void ExcluirAluno(Alunos Al[TF], int &TL)
{
    char AuxNome[30];

    printf("Digite o Nome do aluno para Excluir:\n");
    scanf("%s\n",AuxNome);
    
    for(i=0;i<TL;i++)
    {
        if (stricmp(Al[i].Nome,AuxNome)=0)
        {
            for(j=i;j<TL-1;j++)
            {
                Al[j]=Al[j+1];
            }
            return TL-1;
        }
    }
    return TL;
           
    if(TL==TF)
    {
        printf("%s nÃ£o existente no sistema!\n");
    }
}

void ExcluirDisciplina(Disciplinas Dis[TF], int &TL)
{
    int AuxDis
    printf("Digite a Disciplina para Excluir:\n");
    scanf("%d\n",AuxDis);

    for(i=0;i<TL;i++){
        if(AuxDis==Disciplinas[i].Codigo)[
            for(j=i;j<TL-1;j++){
                Dis[j]=Dis[j+1];
            }
            return TL-1;
        ]
    }
    return TL;

    if(TL==TF){
        printf("%d nÃ£o estÃ¡ contido no Sistema!\n",AuxDis);
    }
}


void Menu()
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
    printf("[O] Visualizar Disciplinas com medias abaixo de 6.0\n");
    printf("[P] Visualizar Todos os Dados\n");
    printf("[ESC] Sair\n");
}

int main()
{

}
