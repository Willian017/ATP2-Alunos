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
    char AuxRA[15],AuxNome[30],a;
    int i=0;

    system("cls");
    printf("### Cadastro de Aluno ###\n\n");
    do
    {
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12)
        {
            i=0;

            while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
                i++;

            if(i!=TLA)
                printf("\n### Nao foi possivel cadastrar esse RA, ele ja esta presente no Sistema\n");
            else
            {
                printf("Digite o Nome do Aluno: ");
                scanf(" %s",&AuxNome);

                if(strcmp(AuxNome,"0")==0)
                    printf("\n### Nome Invalido ###\n\n");
                else
                {    
                    strcpy(AuxAlunos[TLA].RA,AuxRA);
                    strcpy(AuxAlunos[TLA].Nome,AuxNome);
                    TLA++;
                }
            }
        }
		else if(strcmp(AuxRA,"0")!=0)
            printf("\n### RA Invalido ###\n\n");

    } while(strcmp(AuxRA,"0")!=0);
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

void VisualizarAlunos(TpAluno AuxAlunos[30], int &TLA)
{
    int i;

    system("cls");

    if(TLA==0)
        printf("### Nao existe nenhum Aluno cadastrado no sistema ###");
    else
        for(i=0;i<TLA;i++)
        {
            printf("RA: %s\n", AuxAlunos[i].RA);
            printf("Nome: %s\n\n", AuxAlunos[i].Nome);
        }
    
    getch();
}

void VisualizarDisci(TpDisci AuxDisci[50], int &TLD)
{
    int i;

    system("cls");

    if(TLD==0)
        printf("### Nao existe nenhuma Disciplina cadastrado no sistema ###");
    else
        for(i=0;i<TLD;i++)
        {
            printf("Codigo: %d\n", AuxDisci[i].CodDisc);
            printf("Disciplina: %s\n\n", AuxDisci[i].Descr);
        }
    
    getch();
}

void VisualizarNotas(TpNota AuxNotas[30], int &TLN)
{
    int i;

    system("cls");

    if(TLN==0)
        printf("### Nao existe nenhum Nota cadastrado no sistema ###");
    else
        for(i=0;i<TLN;i++)
        {
            printf("RA: %s\n", AuxNotas[i].RA);
            printf("Codigo da Disciplina: %d\n", AuxNotas[i].CodDisc);
            printf("Nota: %.1f\n\n", AuxNotas[i].Nota);
        }
    
    getch();
}

void Reprovado2mais(TpNota AuxNotas,TpAuluno AuxAlunos, int &TLN, int &TLA)
{
    int i,j,k;

    system("cls");

    if(TLN==0)
        printf("### Nenhum aluno esta com 2 reprovas ou ###");
    else
        for(j=0;j<TLA;j++)
        {
            k=0;

            for(i=0;i<TLN;i++)
                if(strcmp(AuxNotas[i].RA,AuxAlunos[j].RA)==0 && AuxNotas[i].Nota < 6)
                    k++;

            if(k>=2)
            {
                printf("RA: %s\n", AuxAlunos[j].RA);
                printf("Nome: %s\n\n", AuxAlunos[j].Nome);
            }
        }
    
    getch();
}

void Menu()
{
    char menu;

    int i;
    
    int TLA=0,TLD=0,TLN=0;
    TpAluno AuxNomes[30];
	TpDisci AuxDisci[50];
	TpNota AuxNotas[30];

    do
    {
    	i=9;
        system("cls");
        Moldura(1,1,80,25,1,7);
        Moldura(2,2,79,4,1,3);
        gotoxy(33,3);
        printf("ATP 2 Alunos");
        Moldura(2,5,79,24,1,3);
        gotoxy(37,7);
        printf("Menu");
        gotoxy(5,i++); printf("[A] Cadastrar");gotoxy(45,i);
        gotoxy(5,i++); printf("[B] Atualizar");gotoxy(45,i);
        gotoxy(5,i++); printf("[C] Excluir");gotoxy(45,i);
        gotoxy(5,i++); printf("[D] Visualizar");gotoxy(45,i);
        gotoxy(5,i++); printf("[E] Reprovado em 2 ou mais disciplinas");
        gotoxy(5,i++); printf("[F] Visualizar Alunos por Letras");
        gotoxy(5,i++); printf("[G] Visualizar Disciplinas com media abaixo de 6.0");
        gotoxy(5,i++); printf("[H] Visualizar Todosa os Dados");
        gotoxy(5,i++); printf("[ESC] Sair\n");
        gotoxy(5,i+=2); printf("Opcao desejada: ");

        menu = toupper(getch());

        switch(menu)
        {
            case 'A':
                Adicionar(AuxNomes, TLA,AuxDisci,TLD,AuxNotas,TLN);
            break;

            case 'B':
                VisualizarAlunos(AuxNomes,TLA);
            break;

            case 'C':

            break;
            
            case 'D':

            break;

            case 'E':

            break;

            case 'F':

            break;

            case 'G':

            break;

            case 'H':

            break;
        }
    }while(menu!=27);
}

int main()
{
    Menu(); 
}
