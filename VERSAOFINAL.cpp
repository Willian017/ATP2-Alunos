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

void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF)
{
	int i;
	
	textcolor(CorT);
	textbackground(CorF);
	gotoxy(CI,LI); printf("%c",201);
	gotoxy(CF,LI); printf("%c",187);
	gotoxy(CI,LF); printf("%c",200);
	gotoxy(CF,LF); printf("%c",188);
	for(i=CI+1; i<CF; i++)
	{
		gotoxy(i,LI); printf("%c",205);
		gotoxy(i,LF); printf("%c",205);
	}
	for(i=LI+1; i<LF; i++)
	{
		gotoxy(CI,i); printf("%c",186);
		gotoxy(CF,i); printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}

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


void VisualizarAlunos(TpAluno AuxAlunos[30], int &TLA)
{
    int i,j=0,k,x=0;

    system("cls");

    if(TLA==0)
        printf("### Nao existe nenhum Aluno cadastrado no sistema ###");
    else
    {
	    textcolor(0);
		textbackground(7);
		
        for(i=1;i<=43;i++)
        {
            gotoxy(i,1);printf(" ");
        }
		
        x=7-(strlen("RA")/2);
        gotoxy(x,1);
		printf("RA");
        x=28-(strlen("Nome")/2);
        gotoxy(x,1);
	    printf("Nome");
			
		textcolor(7);
		textbackground(0);
			
		gotoxy(13,1);printf(" ");
        gotoxy(13,2);printf(" ");
        gotoxy(13,3);printf(" ");	    
    
        for(i=0;i<TLA;i++)
        {
        				
			j=i+2;
			
        	if(i%2==1)
        	{
        		textcolor(0);
				textbackground(7);
				
				gotoxy(14,j);
				for(k=14;k<=43;k++)
					printf(" ");
			}
        	else
        	{
        		textcolor(7);
				textbackground(0);
			}
			
			x=28-(strlen(AuxAlunos[i].Nome)/2);
        	
            gotoxy(1,j);printf("%s", AuxAlunos[i].RA);
            gotoxy(x,j);printf("%s", AuxAlunos[i].Nome);
        }
	}
	
	textcolor(7);
	textbackground(0);
    
    getch();
}

void CRUD(char Menu,TpAluno AuxNomes[30], int &TLA,TpDisci AuxDisci[50], int &TLD,TpNota AuxNotas[30], int &TLN)
{
    int i,x;

    char menu;

    switch(Menu)
    {
        case 'A':
            do
            {
                i=9;
                system("cls");
                Moldura(1,1,80,25,1,7);
                Moldura(2,2,79,4,1,3);
                gotoxy(33,3);
                printf("ATP 2 Alunos");
                Moldura(2,5,79,24,1,3);
                x=38-(strlen("Menu Cadastrar")/2);
                gotoxy(x,7);
                printf("Menu Cadastrar");
                gotoxy(5,i++); printf("[A] Cadastrar Alunos");
                gotoxy(5,i++); printf("[B] Cadastrar Disciplinas");
                gotoxy(5,i++); printf("[C] Cadastrar Notas");
                gotoxy(5,i++); printf("[ESC] Sair\n");
                gotoxy(5,i+=2); printf("Opcao desejada: ");

                menu = toupper(getch());

                switch(menu)
                {
                    case 'A':
                        CadastroAluno(AuxNomes,TLA);
                    break;

                    case 'B':

                    break;

                    case 'C':

                    break;
                }
            }while(menu!=27);
        break;

        case 'B':
            do
            {
                i=9;
                system("cls");
                Moldura(1,1,80,25,1,7);
                Moldura(2,2,79,4,1,3);
                gotoxy(33,3);
                printf("ATP 2 Alunos");
                Moldura(2,5,79,24,1,3);
                x=38-(strlen("Menu Atualizar")/2);
                gotoxy(x,7);
                printf("Menu Atualizar");
                gotoxy(5,i++); printf("[A] Atualizar Alunos");
                gotoxy(5,i++); printf("[B] Atualizar Disciplinas");
                gotoxy(5,i++); printf("[C] Atualizar Notas");
                gotoxy(5,i++); printf("[ESC] Sair\n");
                gotoxy(5,i+=2); printf("Opcao desejada: ");

                menu = toupper(getch());

                switch(menu)
                {
                    case 'A':
                        CadastroAluno(AuxNomes,TLA);
                    break;

                    case 'B':

                    break;

                    case 'C':

                    break;
                }
            }while(menu!=27);
        break;

        case 'C':
            do
            {
                i=9;
                system("cls");
                Moldura(1,1,80,25,1,7);
                Moldura(2,2,79,4,1,3);
                gotoxy(33,3);
                printf("ATP 2 Alunos");
                Moldura(2,5,79,24,1,3);
                x=39-(strlen("Menu Excluir")/2);
                gotoxy(x,7);
                printf("Menu Excluir");
                gotoxy(5,i++); printf("[A] Excluir Alunos");
                gotoxy(5,i++); printf("[B] Excluir Disciplinas");
                gotoxy(5,i++); printf("[C] Excluir Notas");
                gotoxy(5,i++); printf("[ESC] Sair\n");
                gotoxy(5,i+=2); printf("Opcao desejada: ");

                menu = toupper(getch());

                switch(menu)
                {
                    case 'A':
                        CadastroAluno(AuxNomes,TLA);
                    break;

                    case 'B':

                    break;

                    case 'C':

                    break;
                }
            }while(menu!=27);
        break;

        case 'D':
            do
            {
                i=9;
                system("cls");
                Moldura(1,1,80,25,1,7);
                Moldura(2,2,79,4,1,3);
                gotoxy(33,3);
                printf("ATP 2 Alunos");
                Moldura(2,5,79,24,1,3);
                x=38-(strlen("Menu Visualizar")/2);
                gotoxy(x,7);
                printf("Menu Visualizar");
                gotoxy(5,i++); printf("[A] Visualizar Alunos");
                gotoxy(5,i++); printf("[B] Visualizar Disciplinas");
                gotoxy(5,i++); printf("[C] Visualizar Notas");
                gotoxy(5,i++); printf("[ESC] Sair\n");
                gotoxy(5,i+=2); printf("Opcao desejada: ");

                menu = toupper(getch());

                switch(menu)
                {
                    case 'A':
                        VisualizarAlunos(AuxNomes,TLA);
                    break;

                    case 'B':

                    break;

                    case 'C':

                    break;
                }
            }while(menu!=27);
        break;
    }
}

void Menu()
{
    char menu;

    int i,x;
    
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
        x=38-(strlen("ATP 2 Alunos")/2);
        gotoxy(x,3);
        printf("ATP 2 Alunos");
        Moldura(2,5,79,24,1,3);
        x=38-(strlen("Menu")/2);
        gotoxy(x,7);
        printf("Menu");
        gotoxy(5,i++); printf("[A] Cadastrar");
        gotoxy(5,i++); printf("[B] Atualizar");
        gotoxy(5,i++); printf("[C] Excluir");
        gotoxy(5,i++); printf("[D] Visualizar");
        gotoxy(5,i++); printf("[E] Reprovado em 2 ou mais disciplinas");
        gotoxy(5,i++); printf("[F] Visualizar Alunos por Letras");
        gotoxy(5,i++); printf("[G] Visualizar Disciplinas com media abaixo de 6.0");
        gotoxy(5,i++); printf("[H] Visualizar Todos os Dados");
        gotoxy(5,i++); printf("[ESC] Sair\n");
        gotoxy(5,i+=2); printf("Opcao desejada: ");

        menu = toupper(getch());

        switch(menu)
        {
            case 'A':
                CRUD(menu,AuxNomes,TLA,AuxDisci,TLD,AuxNotas,TLN);
            break;

            case 'B':
                CRUD(menu,AuxNomes,TLA,AuxDisci,TLD,AuxNotas,TLN);
            break;

            case 'C':
				CRUD(menu,AuxNomes,TLA,AuxDisci,TLD,AuxNotas,TLN);
            break;
            
            case 'D':
                CRUD(menu,AuxNomes,TLA,AuxDisci,TLD,AuxNotas,TLN);
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

int main ()
{
	Menu();
}
