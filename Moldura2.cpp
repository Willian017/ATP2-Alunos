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

void Adicionar(TpAluno AuxAlunos[30], int &TLA,TpDisci AuxDisci[50], int &TLD,TpNota AuxNotas[30], int &TLN)
{
    int i=0;

    strcpy(AuxAlunos[i].Nome,"Joao");
    strcpy(AuxAlunos[i].RA,"26.24.1121-1");

    AuxDisci[i].CodDisc = 100;
    strcpy(AuxDisci[i].Descr,"ATP 2");

    strcpy(AuxNotas[i].RA,"26.24.1121-1");
    AuxNotas[i].CodDisc = 100;
    AuxNotas[i].Nota = 8;

    i++;

    strcpy(AuxAlunos[i].Nome,"Maria");
    strcpy(AuxAlunos[i].RA,"26.28.1921-1");

    AuxDisci[i].CodDisc = 99;
    strcpy(AuxDisci[i].Descr,"ATP 1");

    strcpy(AuxNotas[i].RA,"26.28.1921-1");
    AuxNotas[i].CodDisc = 99;
    AuxNotas[i].Nota = 8;

    TLA=i+1;
    TLD=i+1;
    TLN=i+1;
}

void CadastroAluno(TpAluno AuxAlunos[30],int &TLA)
{
    char AuxRA[15],AuxNome[30],a;
    int i=0,x,j=9;

    system("cls");
    Moldura(1,1,80,25,1,7);
    Moldura(2,2,79,4,1,3);
    x=38-(strlen("ATP 2 Alunos")/2);
    gotoxy(x,3);
    printf("ATP 2 Alunos");
    Moldura(2,5,79,24,1,3);
    x=38-(strlen("### Cadastro de Aluno ###")/2);
    gotoxy(x,7);
    printf("### Cadastro de Aluno ###");
    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
    gotoxy(x,22);
    printf("### Digite '0' para encerrar o cadastro ###");
    
    do
    {
    	gotoxy(5,j++);
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12)
        {
            i=0;

            while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
                i++;
			
			
            if(i!=TLA)
            {
            	x=38-(strlen("### Nao foi possivel cadastrar esse RA, ele ja esta presente no Sistema ###")/2);
            	j++;
            	gotoxy(x,j);
                printf("### Nao foi possivel cadastrar esse RA, ele ja esta presente no Sistema ###");
            }
            else
            {
            	gotoxy(5,j);
                printf("Digite o Nome do Aluno: ");
                scanf(" %s",&AuxNome);
				
                if(strcmp(AuxNome,"0")==0)
                {
                	j++;
                	x=38-(strlen("### Nome Invalido ###")/2);
            		gotoxy(x,j);
                    printf("### Nome Invalido ###");
            	}
                else
                {    
                    strcpy(AuxAlunos[TLA].RA,AuxRA);
                    strcpy(AuxAlunos[TLA].Nome,AuxNome);
                    TLA++;
                }
            }
        }
		else if(strcmp(AuxRA,"0")!=0)
		{
			j++;
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,j);
            printf("### RA Invalido ###");
        }
        
        j+=2;
        
        if(j>19)
        {
        	x=38-(strlen("### Aperte qualquer teclar para continuar ###")/2);
		    gotoxy(x,22);
		    printf("### Aperte qualquer teclar para continuar ###");
        	getch();
        	
        	system("cls");
		    Moldura(1,1,80,25,1,7);
		    Moldura(2,2,79,4,1,3);
		    x=38-(strlen("ATP 2 Alunos")/2);
		    gotoxy(x,3);
		    printf("ATP 2 Alunos");
		    Moldura(2,5,79,24,1,3);
		    x=38-(strlen("### Cadastro de Aluno ###")/2);
		    gotoxy(x,7);
		    printf("### Cadastro de Aluno ###");
		    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
		    gotoxy(x,22);
		    printf("### Digite '0' para encerrar o cadastro ###");
		    
		    j=9;
		}

    } while(strcmp(AuxRA,"0")!=0);
}

void VisualizarAlunos(TpAluno AuxAlunos[30], int &TLA)
{
    int i,j=10,k,x=0;

    
    system("cls");
    Moldura(1,1,80,25,1,7);
    Moldura(2,2,79,4,1,3);
    x=38-(strlen("ATP 2 Alunos")/2);
    gotoxy(x,3);
    printf("ATP 2 Alunos");
    Moldura(2,5,79,24,1,3);
    x=38-(strlen("Visuazilar Alunos")/2);
    gotoxy(x,7);
    printf("Visuazilar Alunos");

    x=38-(strlen("### Nao existe nenhum Aluno cadastrado no sistema ###")/2);
    gotoxy(x,13);
    if(TLA==0)
        printf("### Nao existe nenhum Aluno cadastrado no sistema ###");
    else
    {
	    textcolor(0);
		textbackground(7);

        //x=17;
		
        for(i=16;i<=59;i++)
        {
            gotoxy(i,9);printf(" ");
        }
		
        x=22-(strlen("RA")/2);
        gotoxy(x,9);
		printf("RA");
        x=44-(strlen("Nome")/2);
        gotoxy(x,9);
	    printf("Nome");
			
		textcolor(7);
		textbackground(0);
		
        gotoxy(28,9);printf(" ");  
    
        for(i=0;i<TLA;i++)
        {
        				
			j+=i;
			
        	if(i%2==1)
        	{
        		textcolor(0);
				textbackground(7);
				
				gotoxy(29,j);
				for(k=29;k<=59;k++)
					printf(" ");
			}
        	else
        	{
        		textcolor(7);
				textbackground(0);
			}
			
			x=44-(strlen(AuxAlunos[i].Nome)/2);
        	
            gotoxy(16,j);printf("%s", AuxAlunos[i].RA);
            gotoxy(x,j);printf("%s", AuxAlunos[i].Nome);
        }
	}
	
	textcolor(7);
	textbackground(0);
    
    x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
	gotoxy(x,22);
    printf("### Aperte qualquer teclar para sair ###");
	getch();
}

void VisualizarDisci(TpDisci AuxDisci[50], int &TLD)
{
    int i,j=10,k,x=0;

    
    system("cls");
    Moldura(1,1,80,25,1,7);
    Moldura(2,2,79,4,1,3);
    x=38-(strlen("ATP 2 Alunos")/2);
    gotoxy(x,3);
    printf("ATP 2 Alunos");
    Moldura(2,5,79,24,1,3);
    x=38-(strlen("Visuazilar Disciplina")/2);
    gotoxy(x,7);
    printf("Visuazilar Disciplina");

    x=38-(strlen("### Nao existe nenhuma Disciplina cadastrado no sistema ###")/2);
    gotoxy(x,13);
    if(TLA==0)
        printf("### Nao existe nenhuma Disciplina cadastrado no sistema ###");
    else
    {
	    textcolor(0);
		textbackground(7);

        //x=17;
		
        for(i=16;i<=59;i++)
        {
            gotoxy(i,9);printf(" ");
        }
		
        x=22-(strlen("Codigo")/2);
        gotoxy(x,9);
		printf("Codigo");
        x=44-(strlen("Descricao")/2);
        gotoxy(x,9);
	    printf("Descricao");
			
		textcolor(7);
		textbackground(0);
		
        gotoxy(28,9);printf(" ");  
    
        for(i=0;i<TLA;i++)
        {
        				
			j+=i;
			
        	if(i%2==1)
        	{
        		textcolor(0);
				textbackground(7);
				
				gotoxy(29,j);
				for(k=29;k<=59;k++)
					printf(" ");
			}
        	else
        	{
        		textcolor(7);
				textbackground(0);
			}
			
			x=44-(strlen(AuxDisci[i].Descr)/2);
        	
            gotoxy(16,j);printf("%s", AuxDisci[i].CodDisc);
            gotoxy(x,j);printf("%s", AuxDisci[i].Descr);
        }
	}
	
	textcolor(7);
	textbackground(0);
    
    x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
	gotoxy(x,22);
    printf("### Aperte qualquer teclar para sair ###");
	getch();
}



void CRUD(char Menu,TpAluno AuxAlunos[30], int &TLA,TpDisci AuxDisci[50], int &TLD,TpNota AuxNotas[30], int &TLN)
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
                        CadastroAluno(AuxAlunos,TLA);
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
                        CadastroAluno(AuxAlunos,TLA);
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
                        CadastroAluno(AuxAlunos,TLA);
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
                        VisualizarAlunos(AuxAlunos,TLA);
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
    TpAluno AuxAlunos[30];
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
                CRUD(menu,AuxAlunos,TLA,AuxDisci,TLD,AuxNotas,TLN);
            break;

            case 'B':
                CRUD(menu,AuxAlunos,TLA,AuxDisci,TLD,AuxNotas,TLN);
            break;

            case 'C':
				CRUD(menu,AuxAlunos,TLA,AuxDisci,TLD,AuxNotas,TLN);
            break;
            
            case 'D':
                CRUD(menu,AuxAlunos,TLA,AuxDisci,TLD,AuxNotas,TLN);
            break;

            case 'E':
                Adicionar(AuxAlunos, TLA,AuxDisci,TLD,AuxNotas,TLN);
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
