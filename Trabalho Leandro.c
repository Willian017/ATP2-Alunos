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

void Excluir(tpAluno auxAl[tf], int &TLa)
{
	char exclusao[13];
	int TLa=0,i,j;
	
	printf("Digite o RA que deseja excluir:\n");
	scanf("%s",&exclusao);
	
	for(i=0;i<TLa;i++){
		if(strcmp(auxAl[i].RA,exclusao)==0){
		printf("Aluno encontrado! O que deseja fazer?\n");
		printf("(A) Excluir Aluno:\n");
		printf("(B) Excluir Disciplina:\n");
		printf("(C) Excluir Nota:\n");
		scanf("%c",&opcao);
		
		if(opcao== 'a'){
		for(j=i;j<TLa-1;i++){
			auxAl[i]=auxAl[j+1];
			}
					TLa--;
		printf("Aluno com o RA %d excluído!\n",exclusao);
			}
		}else if(opcao=='b'){
			char excludis[30];
			int k,l;
			printf("Digite a Disciplina que deseja excluir:\n");
			scanf("%s\n",&excludis);
			
			for(k=0;k<auxAl[i].Descr;k++){
				if(strcmp(auxAl[i].Descr[k].cod,excludis)==0 ||
				strcmp(auxAl[i].Descr[k].nome,excludis)==0)
				
				for(l=k;l<auxAl[i].Descr-1;l++){
					auxAl[i].Descr[l]=auxAl[i].Descr[l+1];
				}
				auxAl[i].Descr--;
				printf("Disciplina Excluída!\n");
			}
		}else if(opcao=='c'){
			char exclunota[30];
			
			printf("Digite o nome ou o codigo de uma disciplina para excluir nota;\n");
			scanf("%s",&exclunota);
			
			int k;
			for(k=0;k<auxAl[i].Descr;k++){
				if(strcmp(auxAl[i].Descr[k].cod,exclunota)==0 ||
				strcmp(auxAl[i].Descr[k].nome,exclunota)==0)
				
				aluno[i].Descr[k].nota=0;
				printf("Nota da Disciplina %s Excluída!\n",esclunota);
			}
		}
		printf("Disciplina não encontrada!\n");
		return;
	}else{
		printf("Opção Invalida!\n");
		return;
	}
}

void VisualizarAlunos(TpAluno AuxAlunos, int &TLA)
{
    int i;

    system("cls");

    if(TLA==0)
        printf("### Nao existe nenhum Aluno cadastrado no sistema ###");
    else
        for(i=0;i<TLA;i++)
        {
            printf("Nome: %s\n", AuxAlunos[i].Nome);
            printf("RA: %s\n\n", AuxAlunos[i].RA);
        }
    
    getch();
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
