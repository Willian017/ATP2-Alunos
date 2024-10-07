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

void OrdenacaoNome(TpAluno AuxAlunos[30],int TLA)
{
	int i, j;
	char AuxNome[30];

	for(i=TLA;i>0;i--)
		for(j=0;j<i-1;j++)
			if(strcmp(AuxAlunos[j].Nome,AuxAlunos[j+1].Nome)==1)
			{
				strcpy(AuxNome,AuxAlunos[j].Nome);
				strcpy(AuxAlunos[j].Nome,AuxAlunos[j+1].Nome);
				strcpy(AuxAlunos[j+1].Nome,AuxNome);

				strcpy(AuxNome,AuxAlunos[j].RA);
				strcpy(AuxAlunos[j].RA,AuxAlunos[j+1].RA);
				strcpy(AuxAlunos[j+1].RA,AuxNome);
			}
}

void OrdenacaoDisci(TpDisci AuxDisci[50],int TLD)
{
	int i, j,AuxCod;
	char Descr[30];

	for(i=TLD;i>0;i--)
		for(j=0;j<i-1;j++)
			if(strcmp(AuxDisci[j].Descr,AuxDisci[j+1].Descr)==1)
			{
				strcpy(Descr,AuxDisci[j].Descr);
				strcpy(AuxDisci[j].Descr,AuxDisci[j+1].Descr);
				strcpy(AuxDisci[j+1].Descr,Descr);

				AuxCod=AuxDisci[j].CodDisc;
				AuxDisci[j].CodDisc=AuxDisci[j+1].CodDisc;
				AuxDisci[j+1].CodDisc=AuxCod;
			}
}

void LimparTela(int LI,int LF,int CI,int CF)
{
	int i, j;
	
	for(i=LI;i<=LF;i++)
		for(j=CI;j<=CF;j++)
		{
			gotoxy(j,i);printf(" ");
		}
}

int BuscarAluno(TpAluno AuxAlunos[30],int TLA,char AuxRA[15])
{
	int i=0;

	while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
        i++;

	return i;
}

int BuscarDisciplina(TpDisci AuxDisci[50],int &TLD,int AuxCod)
{
	int i=0;

	while(AuxCod != AuxDisci[i].CodDisc && i<TLD)
        i++;

	return i;
}

int VerificaRA(char AuxRA[15])
{
	int i=0,j;

	if(AuxRA[0]>=48 && AuxRA[0]<=57)
		if(AuxRA[1]>=48 && AuxRA[1]<=57)
			if(AuxRA[2]==46)
				if(AuxRA[3]>=48 && AuxRA[3]<=57)
					if(AuxRA[4]>=48 && AuxRA[4]<=57)
						if(AuxRA[5]==46)
							if(AuxRA[6]>=48 && AuxRA[6]<=57)
								if(AuxRA[7]>=48 && AuxRA[7]<=57)
									if(AuxRA[8]>=48 && AuxRA[8]<=57)
										if(AuxRA[9]>=48 && AuxRA[9]<=57)
											if(AuxRA[10]==45)
												if(AuxRA[11]>=48 && AuxRA[11]<=57)
													i=1;

	return i;

}

void Adicionar(TpAluno AuxAlunos[30], int &TLA,TpDisci AuxDisci[50], int &TLD,TpNota AuxNotas[30], int &TLN)
{
    int i=0,k=0;
    
    char AuxRA[15];
    
    strcpy(AuxRA,"26.24.1121-1");
    k=BuscarAluno(AuxAlunos,TLA,AuxRA);

	if(k==TLA)
	{
		strcpy(AuxAlunos[TLA].Nome,"Willian");
		strcpy(AuxAlunos[TLA].RA,"26.24.1121-1");
		
		TLA++;
		
		strcpy(AuxAlunos[TLA].Nome,"Maria");
		strcpy(AuxAlunos[TLA].RA,"26.24.1296-9");
		
		TLA++;
		
		strcpy(AuxAlunos[TLA].Nome,"Leonardo");
		strcpy(AuxAlunos[TLA].RA,"26.24.1172-5");
		
		TLA++;
		
		strcpy(AuxAlunos[TLA].Nome,"Leandro");
		strcpy(AuxAlunos[TLA].RA,"22.23.1421-1");
		
		TLA++;
		
		strcpy(AuxAlunos[TLA].Nome,"Wagner");
		strcpy(AuxAlunos[TLA].RA,"88.12.3321-7");
		
		TLA++;
		
		AuxDisci[TLD].CodDisc = 100;
		strcpy(AuxDisci[TLD].Descr,"ATP 2");
		
		TLD++;
		
		AuxDisci[TLD].CodDisc = 99;
		strcpy(AuxDisci[TLD].Descr,"ATP 1");
		
		TLD++;
		
		AuxDisci[TLD].CodDisc = 101;
		strcpy(AuxDisci[TLD].Descr,"Ciencia de Dados");
		
		TLD++;
		
		AuxDisci[TLD].CodDisc = 105;
		strcpy(AuxDisci[TLD].Descr,"Estrutura de Dados I");
		
		TLD++;
		
		AuxDisci[TLD].CodDisc = 107;
		strcpy(AuxDisci[TLD].Descr,"Estrutura de Dados II");
		
		TLD++;
		
		strcpy(AuxNotas[TLN].RA,"26.24.1121-1");
		AuxNotas[TLN].CodDisc = 100;
		AuxNotas[TLN].Nota = 8;
		
		TLN++;
		
		strcpy(AuxNotas[TLN].RA,"26.24.1121-1");
		AuxNotas[TLN].CodDisc = 101;
		AuxNotas[TLN].Nota = 7;
		
		TLN++;

		strcpy(AuxNotas[TLN].RA,"26.24.1296-9");
		AuxNotas[TLN].CodDisc = 107;
		AuxNotas[TLN].Nota = 6.3;

		TLN++;
		
		strcpy(AuxNotas[TLN].RA,"26.24.1296-9");
		AuxNotas[TLN].CodDisc = 99;
		AuxNotas[TLN].Nota = 7;

		TLN++;

		strcpy(AuxNotas[TLN].RA,"26.24.1172-5");
		AuxNotas[TLN].CodDisc = 99;
		AuxNotas[TLN].Nota = 5.5;

		TLN++;
		
		strcpy(AuxNotas[TLN].RA,"26.24.1172-5");
		AuxNotas[TLN].CodDisc = 105;
		AuxNotas[TLN].Nota = 10;

		TLN++;

		strcpy(AuxNotas[TLN].RA,"22.23.1421-1");
		AuxNotas[TLN].CodDisc = 107;
		AuxNotas[TLN].Nota = 4;
		
		TLN++;
		
		strcpy(AuxNotas[TLN].RA,"22.23.1421-1");
		AuxNotas[TLN].CodDisc = 100;
		AuxNotas[TLN].Nota = 5;
		
		TLN++;

		strcpy(AuxNotas[TLN].RA,"88.12.3321-7");
		AuxNotas[TLN].CodDisc = 99;
		AuxNotas[TLN].Nota = 8;

		TLN++;

		strcpy(AuxNotas[TLN].RA,"88.12.3321-7");
		AuxNotas[TLN].CodDisc = 101;
		AuxNotas[TLN].Nota = 8;

		TLN++;

		strcpy(AuxNotas[TLN].RA,"88.12.3321-7");
		AuxNotas[TLN].CodDisc = 105;
		AuxNotas[TLN].Nota = 4;

		TLN++;

		strcpy(AuxNotas[TLN].RA,"88.12.3321-7");
		AuxNotas[TLN].CodDisc = 107;
		AuxNotas[TLN].Nota = 5.8;

		TLN++;
	}
}

void CadastroAluno(TpAluno AuxAlunos[30],int &TLA)
{
    char AuxRA[15],AuxNome[30];
    int i=0,x,j=7;

    do
    {
    	LimparTela(2,24,2,79);
    	
    	Moldura(1,1,80,25,1,3);

    	x=38-(strlen("### Cadastro de Aluno ###")/2);
	    gotoxy(x,3);
	    printf("### Cadastro de Aluno ###");
	    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar o cadastro ###");
    	gotoxy(5,j++);
        printf("Digite o RA do Aluno(Ex: 26.24.1121-1): ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12 && VerificaRA(AuxRA)==1)
        {
            i=BuscarAluno(AuxAlunos,TLA,AuxRA);
			
            if(i!=TLA)
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
            	gotoxy(4,13);
                printf("### Nao foi possivel cadastrar esse RA, ele ja esta presente no Sistema ###");
                Sleep(3000);
            }
            else
            {
            	gotoxy(5,j);
                printf("Digite o Nome do Aluno: ");
                fflush(stdin);
                gets(AuxNome);
				
                if(strcmp(AuxNome,"0")==0)
                {
                	LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
	            	x=38-(strlen("### Nome Invalido ###")/2);
            		gotoxy(x,13);
                    printf("### Nome Invalido ###");;
	                Sleep(2000);
            	}
                else
                {    
                	LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
	            	x=38-(strlen("### Cadastro Realizado Com Sucesso ###")/2);
            		gotoxy(x,13);
                    printf("### Cadastro Realizado Com Sucesso ###");;
	                Sleep(3000);
                    strcpy(AuxAlunos[TLA].RA,AuxRA);
                    strcpy(AuxAlunos[TLA].Nome,AuxNome);
                    TLA++;
                }
            }
        }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(2,24,2,79);
			Moldura(1,1,80,25,1,3);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,13);
            printf("### RA Invalido ###");
            Sleep(2000);
        }
		
		j=7;

    } while(strcmp(AuxRA,"0")!=0);
}

void CadastroDisci(TpDisci AuxDisci[50],int &TLD)
{
    char AuxDescr[50];
    int i=0,x,j=7, AuxCod;
    
    do
    {
    	LimparTela(2,24,2,79);
    	Moldura(1,1,80,25,1,3);
	    x=38-(strlen("### Cadastro de Disciplinas ###")/2);
	    gotoxy(x,3);
	    printf("### Cadastro de Disciplinas ###");
	    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar o cadastro ###");
	    
    	gotoxy(5,j++);
        printf("Digite o Codigo da Disciplina: ");
        scanf(" %d",&AuxCod);

        if(AuxCod>0)
        {
            i=BuscarDisciplina(AuxDisci,TLD,AuxCod);
			
			
            if(i!=TLD)
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
            	gotoxy(4,13);
                printf("### Nao foi possivel cadastrar a Disciplina, ela ja esta no Sistema ###");
                Sleep(2000);
            }
            else
            {
            	gotoxy(5,j);
                printf("Digite o Nome da Disciplina: ");
                fflush(stdin);
                gets(AuxDescr);
				
                if(strcmp(AuxDescr,"0")==0)
                {
                	LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
                	x=38-(strlen("### Nome Invalido ###")/2);
            		gotoxy(x,13);
                    printf("### Nome Invalido ###");
                    Sleep(2000);
            	}
                else
                {    
                	LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
	            	x=38-(strlen("### Cadastro Realizado Com Sucesso ###")/2);
            		gotoxy(x,13);
                    printf("### Cadastro Realizado Com Sucesso ###");;
	                Sleep(3000);
                    AuxDisci[TLD].CodDisc=AuxCod;
                    strcpy(AuxDisci[TLD].Descr,AuxDescr);
                    TLD++;
                }
            }
        }
		else if(AuxCod!=0)
		{
			LimparTela(2,24,2,79);
			Moldura(1,1,80,25,1,3);
			x=38-(strlen("### Codigo Invalido ###")/2);
            gotoxy(x,13);
            printf("### Codigo Invalido ###");
            Sleep(2000);
        }
		
		j=7;

    } while(AuxCod!=0);
}

void CadastroNota(TpNota AuxNota[30],int &TLN,TpAluno AuxAlunos[30],int TLA,TpDisci AuxDisci[50],int TLD)
{
    char AuxRA[13],AuxNome[30],AuxDescri[50];
    int i=0,x,j=7, AuxCod;
    float AuxNotas;
    
    do
    {
    	LimparTela(2,24,2,79);
    	Moldura(1,1,80,25,1,3);
	    x=38-(strlen("### Cadastro de Notas ###")/2);
	    gotoxy(x,3);
	    printf("### Cadastro de Notas ###");
	    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar o cadastro ###");
	    
    	gotoxy(5,j++);
        printf("Digite o RA do aluno: ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12 && VerificaRA(AuxRA))
        {

            i=BuscarAluno(AuxAlunos,TLA,AuxRA);	
			
            if(i==TLA)
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
	    		x=38-(strlen("### Esse Aluno nao esta existe ###")/2);
            	gotoxy(x,13);
                printf("### Esse Aluno nao esta existe ###");
                Sleep(2000);
            }
            else
            {
            	strcpy(AuxNome,AuxAlunos[i].Nome);
            	
                do
				{
					LimparTela(8,21,3,78);
					
					j=7;
					    
					gotoxy(5,j++);
				    printf("RA do aluno: %s",AuxRA);
				    gotoxy(5,j++);
				    printf("Nome do aluno: %s",AuxNome);
				    j++;
				    gotoxy(5,j++);
	                printf("Digite o Codigo da Disciplina: ");
	                scanf(" %d",&AuxCod);
		            
		            i=0;
                
	                while(AuxCod!=AuxDisci[i].CodDisc && i<TLD)
	                	i++;
	                
					if(i==TLD && AuxCod>0)	
					{
		                LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
				    	x=38-(strlen("### Essa Disciplina nao esta existe, tente novamente ###")/2);
			           	gotoxy(x,13);
			            printf("### Essa Disciplina nao esta existe, tente novamente ###");
			            Sleep(3000);
			            
			            LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
					    x=38-(strlen("### Cadastro de Notas ###")/2);
					    gotoxy(x,3);
					    printf("### Cadastro de Notas ###");
					    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
					    gotoxy(x,22);
					    printf("### Digite '0' para encerrar o cadastro ###");
					}
					else
					{
						x=0;
						
				        while((AuxCod!=AuxNota[x].CodDisc || strcmp(AuxRA,AuxNota[x].RA)!=0)&& x<TLN)
				        	x++;
					}
									
		        }while(AuxCod>0 && i==TLD);

				
                if(x==TLN && AuxCod>0)
				{    
					
					strcpy(AuxDescri,AuxDisci[i].Descr);
					
                	do
					{
						LimparTela(8,21,3,78);
						
					    j=7;
					    
						gotoxy(5,j++);
				    	printf("RA do aluno: %s",AuxRA);
				    	gotoxy(5,j++);
				    	printf("Nome do aluno: %s",AuxNome);
				    	j++;
				    	gotoxy(5,j++);
	               		printf("Codigo da disciplina: %d",AuxCod);
	               		gotoxy(5,j++);
	               		printf("Nome da disciplina: %s",AuxDescri);
	               		gotoxy(5,++j);
		                printf("Digite a Nota do Aluno: ");
		                scanf(" %f",&AuxNotas);
			            
			            i=0;
		                
						if(AuxNotas<0 || AuxNotas>10)	
						{
			                LimparTela(2,24,2,79);
							Moldura(1,1,80,25,1,3);
					    	x=38-(strlen("### Essa Nota esta fora dos parametros corretos ###")/2);
				           	gotoxy(x,13);
				            printf("### Essa Nota esta fora dos parametros corretos ###");
				            Sleep(3000);
				            
				            LimparTela(2,24,2,79);
							Moldura(1,1,80,25,1,3);
						    x=38-(strlen("### Cadastro de Notas ###")/2);
						    gotoxy(x,3);
						    printf("### Cadastro de Notas ###");
						    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
						    gotoxy(x,22);
						    printf("### Digite '0' para encerrar o cadastro ###");
						}	
		        	}while(AuxNotas<0 || AuxNotas>10);
		        	
		        	LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
	            	x=38-(strlen("### Cadastro Realizado Com Sucesso ###")/2);
            		gotoxy(x,13);
                    printf("### Cadastro Realizado Com Sucesso ###");;
	                Sleep(3000);
		        	strcpy(AuxNota[TLN].RA, AuxRA);
		        	AuxNota[TLN].CodDisc=AuxCod;
		        	AuxNota[TLN].Nota=AuxNotas;
		        	
		        	TLN++;
		    	}
		    	else if(x!=TLN)
		    	{
		    		LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
					x=38-(strlen("### Nota ja cadastrada ###")/2);
		            gotoxy(x,13);
		            printf("### Nota ja cadastrada ###");
		            Sleep(2000);
				}
            }
        }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(2,24,2,79);
			Moldura(1,1,80,25,1,3);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,13);
            printf("### RA Invalido ###");
            Sleep(2000);
        }
        		    
		j=7;


    } while(strcmp(AuxRA,"0")!=0);
}

void AtualizarAluno(TpAluno AuxAlunos[30],int &TLA,TpNota AuxNotas[30],int TLN)
{
	char AuxRA[15],AuxNome[30],menu;
    int i=0,x,j=7;

    do
    {
    	LimparTela(2,24,2,79);
		Moldura(1,1,80,25,1,3);
    	x=38-(strlen("### Atualizar Aluno ###")/2);
	    gotoxy(x,3);
	    printf("### Atualizar Aluno ###");
	    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar a atualizacao ###");
    	gotoxy(5,j++);
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12 && VerificaRA(AuxRA))
        {

        	i=BuscarAluno(AuxAlunos,TLA,AuxRA);

            if(i==TLA)
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
            	x=38-(strlen("### Esse Aluno nao esta cadastrado no sistema ###")/2);
				gotoxy(x,13);
                printf("### Esse Aluno nao esta cadastrado no sistema ###");
                Sleep(3000);
            }
            else
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
	            x=38-(strlen("### Aluno Encontrado ###")/2);
            	gotoxy(x,13);
                printf("### Aluno Encontrado ###");;
	            Sleep(2000);
	            
	            j=7;
	            
	            LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
		    	x=38-(strlen("### Atualizar Aluno ###")/2);
			    gotoxy(x,3);
			    printf("### Atualizar Aluno ###");
			    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
			    gotoxy(x,22);
			    printf("### Digite '0' para encerrar a atualizacao ###");
			    
			    do
			    {
			    	j=7;
			    	LimparTela(8,23,3,78);
				    gotoxy(5,j++);
					printf("RA do aluno: %s",AuxAlunos[i].RA);
					gotoxy(5,j++);
					printf("Nome do aluno: %s",AuxAlunos[i].Nome);
					j++;
					gotoxy(5,j++);
					printf("Deseja: ");
					gotoxy(5,j++);
					printf("[A] Editar o RA");
					gotoxy(5,j++);
					printf("[B] Editar o Nome");
					gotoxy(5,j++);
					printf("[C] Editar o RA e o Nome");
					gotoxy(5,j++);
					printf("[ESC] Sair");
					gotoxy(5,++j);
					printf("Opcao Escolhida: ");
					
					menu=toupper(getch());
				    
				}while(menu!=27 && menu!=66 && menu!=67 && menu!=65);
				    
				    switch(menu)
				    {
				    	case 'A':
				    		do
							{
					    		LimparTela(2,24,2,79);
								Moldura(1,1,80,25,1,3);
						    	x=38-(strlen("### Atualizar Aluno ###")/2);
							    gotoxy(x,3);
							    printf("### Atualizar Aluno ###");
							    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
							    gotoxy(x,22);
							    printf("### Digite '0' para encerrar a atualizacao ###");
							    
							    j=7;
							    
							    gotoxy(5,j++);
								printf("RA Antigo do aluno: %s",AuxAlunos[i].RA);
								gotoxy(5,j++);
								printf("Digite o novo RA: ");
        						scanf(" %s",&AuxRA);
        						
        						if(strlen(AuxRA)==12 && VerificaRA(AuxRA))
        						{

        							x=BuscarAluno(AuxAlunos,TLA,AuxRA);
						                
						            if(x!=TLA)
						            {
						            	LimparTela(2,24,2,79);
										Moldura(1,1,80,25,1,3);
						            	x=38-(strlen("### Esse RA ja esta cadastrado no sistema ###")/2);
						            	gotoxy(x,13);
						                printf("### Esse RA ja esta cadastrado no sistema ###");
						                Sleep(3000);
									}
									else
									{
										x=0;
										
										while(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)!=0 && x<TLN)
						                	x++;
						                	
						               	if(x==TLN)
										{
											LimparTela(2,24,2,79);
											Moldura(1,1,80,25,1,3);
							            	x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
						            		gotoxy(x,13);
						                    printf("### Atualizacao Realizada com Sucesso ###");
						                    strcpy(AuxAlunos[i].RA,AuxRA);
							                Sleep(3000);
										}
										else
										{
											do
											{			
												j=7;	
												LimparTela(2,24,2,79);
												Moldura(1,1,80,25,1,3);
												x=38-(strlen("### Atualizar Aluno ###")/2);
											    gotoxy(x,3);
											    printf("### Atualizar Aluno ###");
											    gotoxy(5,j++);
											    printf("Esse Aluno esta cadastrado na tabela Notas");
											    gotoxy(5,j++);
											    printf("Ao atualiza-lo ira tambem atualizar a tabela de Notas");
											    gotoxy(5,j++);
											    printf("Deseja Atualiza-lo? [S] Sim [N] Nao");
											    gotoxy(5,++j);
											    printf("Opcao Escolhida: ");
											    
											    menu=toupper(getch());
											    
											}while(menu!=83 && menu!=78);
											
											if(menu==83)
											{
												LimparTela(2,24,2,79);
												Moldura(1,1,80,25,1,3);
								            	x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
							            		gotoxy(x,13);
							                    printf("### Atualizacao Realizada com Sucesso ###");
										
												for(x=0;x<TLN;x++)
								                	if(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)==0)
								                		strcpy(AuxNotas[x].RA,AuxRA);
								                	
								                strcpy(AuxAlunos[i].RA,AuxRA);
								                
								                strcpy(AuxRA,"0");
						                	
								                Sleep(3000);
											}
										}
										
										strcpy(AuxRA,"0"); 						          
									}
								} 
							    else if(strcmp(AuxRA,"0")!=0)
								{
									LimparTela(2,24,2,79);
									Moldura(1,1,80,25,1,3);
									x=38-(strlen("### RA Invalido ###")/2);
						            gotoxy(x,13);
						            printf("### RA Invalido ###");
						            Sleep(2000);
						        }
						        
						        	
							}while(strcmp(AuxRA,"0")!=0);
				    	break;
				    	
				    	case 'B':
					    	LimparTela(2,24,2,79);
							Moldura(1,1,80,25,1,3);
						   	x=38-(strlen("### Atualizar Aluno ###")/2);
						    gotoxy(x,3);
						    printf("### Atualizar Aluno ###");
						    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
						    gotoxy(x,22);
						    printf("### Digite '0' para encerrar a atualizacao ###");
						    
							j=7;
							    
							gotoxy(5,j++);
							printf("Nome Antigo do aluno: %s",AuxAlunos[i].Nome);
							gotoxy(5,j++);
							printf("Digite o novo Nome: ");
							fflush(stdin);
        					gets(AuxNome);
        						
        					if(strcmp(AuxNome,"0")!=0)
        					{
								LimparTela(2,24,2,79);
								Moldura(1,1,80,25,1,3);
						        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
					           	gotoxy(x,13);
					            printf("### Atualizacao Realizada com Sucesso ###");
					            strcpy(AuxAlunos[i].Nome,AuxNome);
					            Sleep(3000);
							}
				    	break;
				    	
				    	case 'C':
				    		do
							{
					    		LimparTela(2,24,2,79);
								Moldura(1,1,80,25,1,3);
						    	x=38-(strlen("### Atualizar Aluno ###")/2);
							    gotoxy(x,3);
							    printf("### Atualizar Aluno ###");
							    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
							    gotoxy(x,22);
							    printf("### Digite '0' para encerrar a atualizacao ###");
							    
							    j=7;
							    
							    gotoxy(5,j++);
								printf("RA Antigo do aluno: %s",AuxAlunos[i].RA);
								gotoxy(5,j++);
								printf("Digite o novo RA: ");
        						scanf(" %s",&AuxRA);
        						
        						if(strlen(AuxRA)==12 && VerificaRA(AuxRA))
        						{

									x=BuscarAluno(AuxAlunos,TLA,AuxRA);
						                
						            if(x!=TLA)
						            {
						            	LimparTela(2,24,2,79);
										Moldura(1,1,80,25,1,3);
						            	gotoxy(4,13);
						                printf("### Esse RA ja esta cadastrado no sistema ###");
						                Sleep(3000);
									}
									else
									{
										x=0;
										
										while(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)!=0 && x<TLN)
						                	x++;
						                	
						               	if(x==TLN)
										{
											gotoxy(5,j++);
											printf("Nome Antigo do aluno: %s",AuxAlunos[i].Nome);
											gotoxy(5,j++);
											printf("Digite o novo Nome: ");
											fflush(stdin);
				        					gets(AuxNome);
				        						
				        					if(strcmp(AuxNome,"0")!=0)
				        					{
												LimparTela(2,24,2,79);
												Moldura(1,1,80,25,1,3);
										        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
									           	gotoxy(x,13);
									            printf("### Atualizacao Realizada com Sucesso ###");
									            strcpy(AuxAlunos[i].Nome,AuxNome);
									            strcpy(AuxAlunos[i].RA,AuxRA);
									            Sleep(3000);
											}
										}
										else
										{
											do
											{				
												LimparTela(2,24,2,79);
												Moldura(1,1,80,25,1,3);
												x=38-(strlen("### Atualizar Aluno ###")/2);
											    gotoxy(x,3);
											    printf("### Atualizar Aluno ###");
											    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
											    gotoxy(x,22);
											    printf("### Digite '0' para encerrar a atualizacao ###");
											    j=7;
											    gotoxy(5,j++);
											    printf("Esse Aluno esta cadastrado na tabela Notas");
											    gotoxy(5,j++);
											    printf("Ao atualiza-lo ira tambem atualizar a tabela de Notas");
											    gotoxy(5,j++);
											    printf("Deseja Atualiza-lo? [S] Sim [N] Nao");
											    gotoxy(5,++j);
											    printf("Opcao Escolhida: ");
											    
											    menu=toupper(getch());
											    
											}while(menu!=83 && menu!=78);
											
											if(menu==83)
											{
												LimparTela(2,24,2,79);
												Moldura(1,1,80,25,1,3);
												j=7;
												gotoxy(5,j++);
												printf("RA Antigo do aluno: %s",AuxAlunos[i].RA);
												gotoxy(5,j++);
												printf("Novo RA: %s",AuxRA);
												j++;
												gotoxy(5,j++);
												printf("Nome Antigo do aluno: %s",AuxAlunos[i].Nome);
												gotoxy(5,j++);
												printf("Digite o novo Nome: ");
					        					scanf(" %s",&AuxNome);
					        						
					        					if(strcmp(AuxNome,"0")!=0)
					        					{
													LimparTela(2,24,2,79);
													Moldura(1,1,80,25,1,3);
											        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
										           	gotoxy(x,13);
										            printf("### Atualizacao Realizada com Sucesso ###");
										            
										            for(x=0;x<TLN;x++)
									                	if(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)==0)
									                		strcpy(AuxNotas[x].RA,AuxRA);
									                		
										            strcpy(AuxAlunos[i].Nome,AuxNome);
										            strcpy(AuxAlunos[i].RA,AuxRA);
										            
										            Sleep(3000);
										            
										            
												}
											}
										} 
										strcpy(AuxRA,"0");						          
									}
								} 
							    else if(strcmp(AuxRA,"0")!=0)
								{
									LimparTela(2,24,2,79);
									Moldura(1,1,80,25,1,3);
									x=38-(strlen("### RA Invalido ###")/2);
						            gotoxy(x,13);
						            printf("### RA Invalido ###");
						            Sleep(2000);
						        }
						        
						        
							}while(strcmp(AuxRA,"0")!=0);
				    	break;
					}
					
					strcpy(AuxRA,"1");
            }
        }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(2,24,2,79);
			Moldura(1,1,80,25,1,3);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,13);
            printf("### RA Invalido ###");
            Sleep(2000);
        }
		
		j=7;

    } while(strcmp(AuxRA,"0")!=0);
}

void AtualizarDisci(TpDisci AuxDisci[30],int TLD,TpNota AuxNotas[30],int TLN)
{
	char AuxDescr[100],menu;

    int i=0,x,j=7,AuxCod;

    do
    {
    	LimparTela(2,24,2,79);
		Moldura(1,1,80,25,1,3);
    	x=38-(strlen("### Atualizar Disciplina ###")/2);
	    gotoxy(x,3);
	    printf("### Atualizar Disciplina ###");
	    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar a atualizacao ###");
    	gotoxy(5,j++);
        printf("Digite o Codigo da Disciplina: ");
        scanf("%d",&AuxCod);

        if(AuxCod>0)
        {

            i=BuscarDisciplina(AuxDisci,TLD,AuxCod);
			
            if(i==TLD)
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
            	x=38-(strlen("### Essa Disciplina nao esta cadastrado no sistema ###")/2);
				gotoxy(x,13);
                printf("### Essa Disciplina nao esta cadastrado no sistema ###");
                Sleep(3000);
            }
            else
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
	            x=38-(strlen("### Disciplina Encontrada ###")/2);
            	gotoxy(x,13);
                printf("### Disciplina Encontrada ###");;
	            Sleep(2000);
	            
	            j=7;
	            
	            LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
		    	x=38-(strlen("### Atualizar Disciplina ###")/2);
			    gotoxy(x,3);
			    printf("### Atualizar Disciplina ###");
			    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
			    gotoxy(x,22);
			    printf("### Digite '0' para encerrar a atualizacao ###");
			    
			    do
			    {
			    	j=7;
			    	LimparTela(8,23,3,78);
				    gotoxy(5,j++);
					printf("Codigo da Disciplina: %d",AuxDisci[i].CodDisc);
					gotoxy(5,j++);
					printf("Descricao da Disciplina: %s",AuxDisci[i].Descr);
					j++;
					gotoxy(5,j++);
					printf("Deseja: ");
					gotoxy(5,j++);
					printf("[A] Editar o Codigo");
					gotoxy(5,j++);
					printf("[B] Editar a Descricao");
					gotoxy(5,j++);
					printf("[C] Editar o Codigo e a Descricao");
					gotoxy(5,j++);
					printf("[ESC] Sair");
					gotoxy(5,++j);
					printf("Opcao Escolhida: ");
					
					menu=toupper(getch());
				    
				}while(menu!=27 && menu!=66 && menu!=67 && menu!=65);
				    
				    switch(menu)
				    {
				    	case 'A':
				    		do
							{
					    		LimparTela(2,24,2,79);
								Moldura(1,1,80,25,1,3);
						    	x=38-(strlen("### Atualizar Disciplina ###")/2);
							    gotoxy(x,3);
							    printf("### Atualizar Disciplina ###");
							    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
							    gotoxy(x,22);
							    printf("### Digite '0' para encerrar a atualizacao ###");
							    
							    j=7;
							    
							    gotoxy(5,j++);
								printf("Codigo antigo da Disciplina: %d",AuxDisci[i].CodDisc);
								gotoxy(5,j++);
								printf("Digite o novo Codigo: ");
        						scanf(" %d",&AuxCod);
        						
        						if(AuxCod>0)
        						{
        							x=0;

						            while(AuxCod != AuxDisci[x].CodDisc && x<TLD)
						                x++;
						                
						            if(x!=TLD)
						            {
						            	LimparTela(2,24,2,79);
										Moldura(1,1,80,25,1,3);
						            	x=38-(strlen("### Esse Codigo ja esta cadastrado no sistema ###")/2);
						            	gotoxy(x,13);
						                printf("### Esse Codigo ja esta cadastrado no sistema ###");
						                Sleep(3000);
									}
									else
									{
										x=0;
										
										while(AuxDisci[i].CodDisc != AuxNotas[x].CodDisc && x<TLN)
						                	x++;
						                	
						               	if(x==TLN)
										{
											LimparTela(2,24,2,79);
											Moldura(1,1,80,25,1,3);
							            	x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
						            		gotoxy(x,13);
						                    printf("### Atualizacao Realizada com Sucesso ###");
						                    AuxDisci[i].CodDisc==AuxCod;
							                Sleep(3000);
										}
										else
										{
											do
											{			
												j=7;	
												LimparTela(2,24,2,79);
												Moldura(1,1,80,25,1,3);
												x=38-(strlen("### Atualizar Disciplina ###")/2);
											    gotoxy(x,3);
											    printf("### Atualizar Disciplina ###");
											    gotoxy(5,j++);
											    printf("Essa Disciplina esta cadastrada na tabela Notas");
											    gotoxy(5,j++);
											    printf("Ao atualiza-lo o Codigo tambem atualizara na tabela de Notas");
											    gotoxy(5,j++);
											    printf("Deseja Atualiza-lo? [S] Sim [N] Nao");
											    gotoxy(5,++j);
											    printf("Opcao Escolhida: ");
											    
											    menu=toupper(getch());
											    
											}while(menu!=83 && menu!=78);
											
											if(menu==83)
											{
												LimparTela(2,24,2,79);
												Moldura(1,1,80,25,1,3);
								            	x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
							            		gotoxy(x,13);
							                    printf("### Atualizacao Realizada com Sucesso ###");
										
												for(x=0;x<TLN;x++)
								                	if(AuxDisci[i].CodDisc == AuxNotas[x].CodDisc)
								                		AuxNotas[x].CodDisc=AuxCod;
								                	
								                AuxDisci[i].CodDisc=AuxCod;
								                
											}
										} 
										
										AuxCod=0;						          
	
									}
								} 
							    else if(AuxCod<0)
								{
									LimparTela(2,24,2,79);
									Moldura(1,1,80,25,1,3);
									x=38-(strlen("### Codigo Invalido ###")/2);
						            gotoxy(x,13);
						            printf("### Codigo Invalido ###");
						            Sleep(2000);
						        }
						        
						        
						        	
							}while(AuxCod!=0);
				    	break;
				    	
				    	case 'B':
					    	LimparTela(2,24,2,79);
							Moldura(1,1,80,25,1,3);
						   	x=38-(strlen("### Atualizar Disciplina ###")/2);
						    gotoxy(x,3);
						    printf("### Atualizar Disciplina ###");
						    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
						    gotoxy(x,22);
						    printf("### Digite '0' para encerrar a atualizacao ###");
						    
							j=7;
							    
							gotoxy(5,j++);
							printf("Descricao Antiga da Disciplina: %s",AuxDisci[i].Descr);
							gotoxy(5,j++);
							printf("Digite a nova Descricao: ");
							fflush(stdin);
        					gets(AuxDescr);
        						
        					if(strcmp(AuxDescr,"0")!=0)
        					{
								LimparTela(2,24,2,79);
								Moldura(1,1,80,25,1,3);
						        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
					           	gotoxy(x,13);
					            printf("### Atualizacao Realizada com Sucesso ###");
					            strcpy(AuxDisci[i].Descr,AuxDescr);
					            Sleep(3000);
							}
				    	break;
				    	
				    	case 'C':
				    		do
							{
					    		LimparTela(2,24,2,79);
								Moldura(1,1,80,25,1,3);
						    	x=38-(strlen("### Atualizar Disciplina ###")/2);
							    gotoxy(x,3);
							    printf("### Atualizar Disciplina ###");
							    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
							    gotoxy(x,22);
							    printf("### Digite '0' para encerrar a atualizacao ###");
							    
							    j=7;
							    
							    gotoxy(5,j++);
								printf("Codigo antigo da Disciplina: %d",AuxDisci[i].CodDisc);
								gotoxy(5,j++);
								printf("Digite o novo Codigo: ");
        						scanf(" %d",&AuxCod);
        						
        						if(AuxCod>0)
        						{
        							x=0;

						            while(AuxCod!=AuxDisci[x].CodDisc && x<TLD)
						                x++;
						                
						            if(x!=TLD)
						            {
						            	LimparTela(2,24,2,79);
										Moldura(1,1,80,25,1,3);
						            	gotoxy(4,13);
						                printf("### Esse Codigo ja esta cadastrado no sistema ###");
						                Sleep(3000);
									}
									else
									{
										x=0;
										
										while(AuxDisci[i].CodDisc != AuxNotas[x].CodDisc && x<TLN)
						                	x++;
						                	
						               	if(x==TLN)
										{
											gotoxy(5,j++);
											printf("Descricao Antiga do Disciplina: %s",AuxDisci[i].Descr);
											gotoxy(5,j++);
											printf("Digite o novo Descricao: ");
				        					fflush(stdin);
					        				gets(AuxDescr);
				        						
				        					if(strcmp(AuxDescr,"0")!=0)
				        					{
												LimparTela(2,24,2,79);
												Moldura(1,1,80,25,1,3);
										        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
									           	gotoxy(x,13);
									            printf("### Atualizacao Realizada com Sucesso ###");
									            strcpy(AuxDisci[i].Descr,AuxDescr);
									            AuxDisci[i].CodDisc=AuxCod;
									            Sleep(3000);
											}
										}
										else
										{
											do
											{				
												LimparTela(2,24,2,79);
												Moldura(1,1,80,25,1,3);
												x=38-(strlen("### Atualizar Disciplina ###")/2);
											    gotoxy(x,3);
											    printf("### Atualizar Disciplina ###");
											    j=7;
											    gotoxy(5,j++);
											    printf("Essa Disciplina esta cadastrada na tabela Notas");
											    gotoxy(5,j++);
											    printf("Ao atualiza-lo a Disciplina tambem atualizar a tabela de Notas");
											    gotoxy(5,j++);
											    printf("Deseja Atualiza-lo? [S] Sim [N] Nao");
											    gotoxy(5,++j);
											    printf("Opcao Escolhida: ");
											    
											    menu=toupper(getch());
											    
											}while(menu!=83 && menu!=78);
											
											if(menu==83)
											{
												LimparTela(2,24,2,79);
												Moldura(1,1,80,25,1,3);
												j=7;
												gotoxy(5,j++);
												printf("Codigo antigo da Disciplina: %d",AuxDisci[i].CodDisc);
												gotoxy(5,j++);
												printf("Novo CodDisc: %d",AuxCod);
												j++;
												gotoxy(5,j++);
												printf("Descricao Antigo do aluno: %s",AuxDisci[i].Descr);
												gotoxy(5,j++);
												printf("Digite o novo Descricao: ");
												fflush(stdin);
					        					gets(AuxDescr);
					        						
					        					if(strcmp(AuxDescr,"0")!=0)
					        					{
													LimparTela(2,24,2,79);
													Moldura(1,1,80,25,1,3);
											        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
										           	gotoxy(x,13);
										            printf("### Atualizacao Realizada com Sucesso ###");
										            
										            for(x=0;x<TLN;x++)
									                	if(AuxDisci[i].CodDisc==AuxNotas[x].CodDisc)
									                		AuxNotas[x].CodDisc=AuxCod;
									                		
										            strcpy(AuxDisci[i].Descr,AuxDescr);
										            AuxDisci[i].CodDisc=AuxCod;
										            
										            Sleep(3000);
												}
											}
											AuxCod=0;
										} 						          
									}
								} 
							    else if(AuxCod<0)
								{
									LimparTela(2,24,2,79);
									Moldura(1,1,80,25,1,3);
									x=38-(strlen("### Codigo Invalido ###")/2);
						            gotoxy(x,13);
						            printf("### Codigo Invalido ###");
						            Sleep(2000);
						        }
						        
							}while(AuxCod!=0);
				    	break;
					}

				AuxCod=1;
            }
        }
		else if(AuxCod<0)
		{
			LimparTela(2,24,2,79);
			Moldura(1,1,80,25,1,3);
			x=38-(strlen("### Codigo Invalido ###")/2);
            gotoxy(x,13);
            printf("### Codigo Invalido ###");
            Sleep(2000);
        }
		
		j=7;

    } while(AuxCod!=0);
}

void AtualizarNotas(TpNota AuxNotas[30],int &TLN,TpDisci AuxDisci[30],int TLD,TpAluno AuxAlunos[30],int TLA)
{
	char AuxRA[15],menu;
	
    int i=0,x,j=7,k,AuxCod;
    
    float AuxNota;

    do
    {
    	LimparTela(2,24,2,79);
		Moldura(1,1,80,25,1,3);
    	x=38-(strlen("### Atualizar Notas ###")/2);
	    gotoxy(x,3);
	    printf("### Atualizar Notas ###");
	    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar a atualizacao ###");
    	gotoxy(5,j++);
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);
        
        if(strlen(AuxRA)==12 && VerificaRA(AuxRA))
        {
            i=0;

            while(strcmp(AuxRA,AuxNotas[i].RA)!=0 && i<TLN)
                i++;
			
			
            if(i==TLN)
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
            	x=38-(strlen("### Nao existem Notas desse RA cadastradas no sistema ###")/2);
				gotoxy(x,13);
                printf("### Nao existem Notas desse RA cadastradas no sistema ###");
                Sleep(3000);
            }
            else
            {
		            LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
			        x=38-(strlen("### Aluno Encontrado ###")/2);
		            gotoxy(x,13);
		            printf("### Aluno Encontrado ###");;
			        Sleep(2000);
			            
			        j=7;
			            
			        LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
				   	x=38-(strlen("### Atualizar Notas ###")/2);
					gotoxy(x,3);
					printf("### Atualizar Notas ###");
					x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
					gotoxy(x,22);
					printf("### Digite '0' para encerrar a atualizacao ###");
				    
				do
				{
				    j=7;
				    LimparTela(8,23,3,78);
					gotoxy(5,j++);
					printf("RA do aluno: %s",AuxAlunos[i].RA);
					gotoxy(5,j++);
					printf("Nome do aluno: %s",AuxAlunos[i].Nome);
				
					for(x=0;x<TLN;x++)
						if(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)==0)
						{
							j++;
								
							k=0;
								
							while(AuxDisci[k].CodDisc != AuxNotas[x].CodDisc && k<TLD)
								k++;
							
							gotoxy(5,j);printf("Disciplina: %d",AuxNotas[x].CodDisc);gotoxy(21,j);printf("- %s",AuxDisci[k].Descr);gotoxy(43,j++);printf("Nota: %.1f",AuxNotas[x].Nota);
						}
							
					j++;
					gotoxy(5,21);
					printf("Selecione o Codigo da Nota que deseja atualizar: ");
					scanf(" %d",&AuxCod);
						
					k=0;
								
					while((AuxCod != AuxNotas[k].CodDisc || strcmp(AuxRA,AuxNotas[k].RA))&& k<TLN)
						k++;
						
					if(k!=TLN)
					{
						LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
				        x=38-(strlen("### Nota Encontrada ###")/2);
			            gotoxy(x,13);
			            printf("### Nota Encontrada ###");;
				        Sleep(2000);
				        
				        j=7;
	            
			            LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
				    	x=38-(strlen("### Atualizar Notas ###")/2);
					    gotoxy(x,3);
					    printf("### Atualizar Notas ###");
					    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
					    gotoxy(x,22);
					    printf("### Digite '0' para encerrar a atualizacao ###");
					    
					    do
					    {
					    	j=7;
					    	LimparTela(8,23,3,78);
						    gotoxy(5,j++);
							printf("RA da Nota: %s",AuxNotas[k].RA);
							gotoxy(5,j++);
							printf("Codigo da Disciplina: %d",AuxNotas[k].CodDisc);
							gotoxy(5,j++);
							printf("Nota: %.1f",AuxNotas[k].Nota);
							j++;
							gotoxy(5,j++);
							printf("Deseja: ");
							gotoxy(5,j++);
							printf("[A] Editar o RA");
							gotoxy(5,j++);
							printf("[B] Editar o Codigo");
							gotoxy(5,j++);
							printf("[C] Editar a Nota");
							gotoxy(5,j++);
							printf("[ESC] Sair");
							gotoxy(5,++j);
							printf("Opcao Escolhida: ");
							
							menu=toupper(getch());
						    
						}while(menu!=27 && menu!=66 && menu!=67 && menu!=65);
						    
						switch(menu)
					    {
					    	case 'A':
					    		do
					    		{
					    			j=7;
	            
						            LimparTela(2,24,2,79);
									Moldura(1,1,80,25,1,3);
							    	x=38-(strlen("### Atualizar Notas ###")/2);
								    gotoxy(x,3);
								    printf("### Atualizar Notas ###");
								    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
								    gotoxy(x,22);
								    printf("### Digite '0' para encerrar a atualizacao ###");
								    gotoxy(5,j++);
								    
								    
								    printf("RA Atual da Nota: %s",AuxNotas[k].RA);
								    gotoxy(5,j++);
								    printf("Codigo Atual da Nota: %d",AuxNotas[k].CodDisc);
								    gotoxy(5,j++);
								    printf("Valor Atual da Nota: %.1f",AuxNotas[k].Nota);
								    
								    j++;
								    
								    gotoxy(5,j++);
								    printf("Digite o novo RA da Nota: ");
								    fflush(stdin);
								    gets(AuxRA);
								    
								    if(strlen(AuxRA)==12 && VerificaRA(AuxRA))
								    {
								    	i=0;
								    	
								    	while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
								    		i++;
								    		
								    	if(i==TLA)
										{
											LimparTela(2,24,2,79);
											Moldura(1,1,80,25,1,3);
								           	x=38-(strlen("### Nao existe esse RA no sistema ###")/2);
											gotoxy(x,13);
								            printf("### Nao existe esse RA no sistema ###");
								            Sleep(3000);
										}
										else
										{
											
											LimparTela(2,24,2,79);
											Moldura(1,1,80,25,1,3);
								            x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
							            	gotoxy(x,13);
							                printf("### Atualizacao Realizada com Sucesso ###");
								                	
								            strcpy(AuxNotas[k].RA,AuxRA);
								                
								            strcpy(AuxRA,"0");
						                   
											Sleep(3000);
										}		
									}
								    else if(strcmp(AuxRA,"0")!=0)
								    {
								    	LimparTela(2,24,2,79);
										Moldura(1,1,80,25,1,3);
										x=38-(strlen("### RA Invalido ###")/2);
							            gotoxy(x,13);
							            printf("### RA Invalido ###");
							            Sleep(2000);
									}
								    
								}while(strcmp(AuxRA,"0")!=0);
					    	break;
						    	
					    	case 'B':
					    		do
					    		{
					    			j=7;
	            
						            LimparTela(2,24,2,79);
									Moldura(1,1,80,25,1,3);
							    	x=38-(strlen("### Atualizar Notas ###")/2);
								    gotoxy(x,3);
								    printf("### Atualizar Notas ###");
								    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
								    gotoxy(x,22);
								    printf("### Digite '0' para encerrar a atualizacao ###");
								    gotoxy(5,j++);
								    
								    
								    printf("RA Atual da Nota: %s",AuxNotas[k].RA);
								    gotoxy(5,j++);
								    printf("Codigo Atual da Nota: %d",AuxNotas[k].CodDisc);
								    gotoxy(5,j++);
								    printf("Valor Atual da Nota: %.1f",AuxNotas[k].Nota);
								    
								    j++;
								    
								    gotoxy(5,j++);
								    printf("Digite o novo Codigo da Nota: ");
								    scanf(" %d",&AuxCod);
								    
								    if(AuxCod>0)
								    {
								    	i=0;
								    	
								    	while(AuxCod != AuxDisci[i].CodDisc && i<TLD)
								    		i++;
								    		
								    	if(i==TLD)
										{
											LimparTela(2,24,2,79);
											Moldura(1,1,80,25,1,3);
								           	x=38-(strlen("### Nao existe esse Codigo no sistema ###")/2);
											gotoxy(x,13);
								            printf("### Nao existe esse Codigo no sistema ###");
								            Sleep(3000);
										}
										else
										{
											
											LimparTela(2,24,2,79);
											Moldura(1,1,80,25,1,3);
								            x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
							            	gotoxy(x,13);
							                printf("### Atualizacao Realizada com Sucesso ###");
								                	
								            AuxNotas[k].CodDisc = AuxCod;
								                
								            AuxCod = 0;
						                   
											Sleep(3000);
										}		
									}
								    else if(AuxCod!=0)
								    {
								    	LimparTela(2,24,2,79);
										Moldura(1,1,80,25,1,3);
										x=38-(strlen("### Codigo Invalido ###")/2);
							            gotoxy(x,13);
							            printf("### Codigo Invalido ###");
							            Sleep(2000);
									}
								    
								}while(AuxCod!=0);
						    break;
						    	
						   	case 'C':
						    	do
					    		{
					    			j=7;
	            
						            LimparTela(2,24,2,79);
									Moldura(1,1,80,25,1,3);
							    	x=38-(strlen("### Atualizar Notas ###")/2);
								    gotoxy(x,3);
								    printf("### Atualizar Notas ###");
								    gotoxy(5,j++);
								    
								    
								    printf("RA Atual da Nota: %s",AuxNotas[k].RA);
								    gotoxy(5,j++);
								    printf("Codigo Atual da Nota: %d",AuxNotas[k].CodDisc);
								    gotoxy(5,j++);
								    printf("Valor Atual da Nota: %.1f",AuxNotas[k].Nota);
								    
								    j++;
								    
								    gotoxy(5,j++);
								    printf("Digite a nova Nota: ");
								    scanf(" %f",&AuxNota);
								    
								    if(AuxNota>=0  && AuxNota<=10)
								    {		
										LimparTela(2,24,2,79);
										Moldura(1,1,80,25,1,3);
							            x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
						            	gotoxy(x,13);
						                printf("### Atualizacao Realizada com Sucesso ###");
								                	
							            AuxNotas[k].Nota = AuxNota;
								                
							            AuxCod = 0;
						                   
										Sleep(3000);	
									}
								    else if(AuxNota<0 || AuxNota>10)
								    {
								    	LimparTela(2,24,2,79);
										Moldura(1,1,80,25,1,3);
										x=38-(strlen("### Nota fora dos padroes ###")/2);
							            gotoxy(x,13);
							            printf("### Nota fora dos padroes ###");
							            Sleep(2000);
									}
								    
								}while(AuxCod != 0);
						   	break;
						}
					}
					else if(k==TLN && AuxCod!=0)
					{
						LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
				        x=38-(strlen("### Nota Nao Encontrada ###")/2);
			            gotoxy(x,13);
			            printf("### Nota Nao Encontrada ###");;
				        Sleep(2000);
					}
					
				}while(k==TLN && AuxCod!=0);
			}														
        }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(2,24,2,79);
			Moldura(1,1,80,25,1,3);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,13);
            printf("### RA Invalido ###");
            Sleep(2000);
        }
		
		j=7;

    } while(strcmp(AuxRA,"0")!=0);
}

void ExcluirAlunos(TpAluno AuxAlunos[30],int &TLA,TpNota AuxNotas[30],int &TLN)
{
	char AuxRA[15],AuxNome[30],menu;
    int i=0,x,j=7,k;

    do
    {
    	LimparTela(2,24,2,79);
		Moldura(1,1,80,25,1,3);
    	x=38-(strlen("### Excluir Aluno ###")/2);
	    gotoxy(x,3);
	    printf("### Excluir Aluno ###");
	    x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar a exclusao ###");
    	gotoxy(5,j++);
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12 && VerificaRA(AuxRA))
        {
            i=0;

            while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
                i++;
			
			
            if(i==TLA)
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
            	x=38-(strlen("### Esse Aluno nao esta cadastrado no sistema ###")/2);
				gotoxy(x,13);
                printf("### Esse Aluno nao esta cadastrado no sistema ###");
                Sleep(3000);
            }
            else
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
	            x=38-(strlen("### Aluno Encontrado ###")/2);
            	gotoxy(x,13);
                printf("### Aluno Encontrado ###");;
	            Sleep(2000);
	            
	            j=7;
	            
	            LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
		    	x=38-(strlen("### Excluir Aluno ###")/2);
			    gotoxy(x,3);
			    printf("### Excluir Aluno ###");
			    x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
			    gotoxy(x,22);
			    printf("### Digite '0' para encerrar a exclusao ###");
			    
			    do
			    {
			    	j=7;
			    	LimparTela(8,23,3,78);
				    gotoxy(5,j++);
					printf("RA do aluno: %s",AuxAlunos[i].RA);
					gotoxy(5,j++);
					printf("Nome do aluno: %s",AuxAlunos[i].Nome);
					j++;
					gotoxy(5,++j);
					printf("Deseja Exclui-lo? [S] Sim [N] Nao");
					gotoxy(5,++j);
					printf("Opcao Escolhida: ");
					
					menu=toupper(getch());
				    
				}while(menu!=83 && menu!=78);
				
				x=0;						
										
				while(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)!=0 && x<TLN)
					x++;
						                	
				if(x==TLN && menu==83)
				{
					LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
					x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
					gotoxy(x,13);
					printf("### Exclusao Realizada com Sucesso ###");
					
					for(k=i;k<TLA-1;k++)
					{
						strcpy(AuxAlunos[k].RA,AuxAlunos[k+1].RA);
						strcpy(AuxAlunos[k].Nome,AuxAlunos[k+1].Nome);
					}
					
					TLA--;
					
					Sleep(3000);
				 }
				else if(menu!=78)
				{
					do
					{			
						j=7;	
						LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
						x=38-(strlen("### Atualizar Aluno ###")/2);
						gotoxy(x,3);
						printf("### Atualizar Aluno ###");
						gotoxy(5,j++);
						printf("Esse Aluno esta cadastrado na tabela Notas");
						gotoxy(5,j++);
						printf("Ao Exclui-lo ira tambem ira Exclui-lo na tabela de Notas");
						gotoxy(5,j++);
						printf("Deseja Excluir? [S] Sim [N] Nao");
						gotoxy(5,++j);
						printf("Opcao Escolhida: ");
												    
						menu=toupper(getch());
												    
					}while(menu!=83 && menu!=78);
					
					if(menu==83)
					{
						LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
						x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
						gotoxy(x,13);
						printf("### Exclusao Realizada com Sucesso ###");
						
						x=0;
						
						while(x!=TLN)
						{
							x=0;
							
							while(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)!=0 && x<TLN)
								x++;
								
							if(x!=TLN)
							{
								for(x=i;x<TLN-1;x++)
								{
									strcpy(AuxNotas[x].RA,AuxNotas[x+1].RA);
									AuxNotas[x].CodDisc=AuxNotas[x+1].CodDisc;
									AuxNotas[x].Nota=AuxNotas[x+1].Nota;
								}
								
								TLN--;	
							}
						}
						
						for(x=i;x<TLA-1;x++)
						{
							strcpy(AuxAlunos[x].RA,AuxAlunos[x+1].RA);
							strcpy(AuxAlunos[x].Nome,AuxAlunos[x+1].Nome);
						}
						
						TLA--;
						
						Sleep(3000);
					}
				}
			}														
        }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(2,24,2,79);
			Moldura(1,1,80,25,1,3);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,13);
            printf("### RA Invalido ###");
            Sleep(2000);
        }
		
		j=7;

    } while(strcmp(AuxRA,"0")!=0);
}

void ExcluirDisci(TpDisci AuxDisci[30],int &TLD,TpNota AuxNotas[30],int &TLN)
{
	char AuxDescr[100],menu;
	
    int i=0,x,j=7,k,AuxCod;

    do
    {
    	LimparTela(2,24,2,79);
		Moldura(1,1,80,25,1,3);
    	x=38-(strlen("### Excluir Disciplina ###")/2);
	    gotoxy(x,3);
	    printf("### Excluir Disciplina ###");
	    x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar a exclusao ###");
    	gotoxy(5,j++);
        printf("Digite o Codigo da Disciplina: ");
        scanf(" %d",&AuxCod);

        if(AuxCod>0)
        {
            i=0;

            while(AuxCod != AuxDisci[i].CodDisc && i<TLD)
                i++;
			
			
            if(i==TLD)
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
            	x=38-(strlen("### Essa Disciplina nao esta cadastrado no sistema ###")/2);
				gotoxy(x,13);
                printf("### Essa Disciplina nao esta cadastrado no sistema ###");
                Sleep(3000);
            }
            else
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
	            x=38-(strlen("### Disciplina Encontrada ###")/2);
            	gotoxy(x,13);
                printf("### Disciplina Encontrada ###");;
	            Sleep(2000);
	            
	            j=7;
	            
	            LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
		    	x=38-(strlen("### Excluir Disciplina ###")/2);
			    gotoxy(x,3);
			    printf("### Excluir Disciplina ###");
			    x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
			    gotoxy(x,22);
			    printf("### Digite '0' para encerrar a exclusao ###");
			    
			    do
			    {
			    	j=7;
			    	LimparTela(8,23,3,78);
				    gotoxy(5,j++);
					printf("Codigo da Disciplina: %d",AuxDisci[i].CodDisc);
					gotoxy(5,j++);
					printf("Nome da Disciplina: %s",AuxDisci[i].Descr);
					j++;
					gotoxy(5,++j);
					printf("Deseja Exclui-lo? [S] Sim [N] Nao");
					gotoxy(5,++j);
					printf("Opcao Escolhida: ");
					
					menu=toupper(getch());
				    
				}while(menu!=83 && menu!=78);
				
				x=0;						
										
				while(AuxDisci[i].CodDisc != AuxNotas[x].CodDisc && x<TLN)
					x++;
						                	
				if(x==TLN && menu==83)
				{
					LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
					x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
					gotoxy(x,13);
					printf("### Exclusao Realizada com Sucesso ###");
					
					for(k=i;k<TLD-1;k++)
					{
						AuxDisci[k].CodDisc = AuxDisci[k+1].CodDisc;
						strcpy(AuxDisci[k].Descr,AuxDisci[k+1].Descr);
					}
					
					TLD--;
					
					Sleep(3000);
				 }
				else if(menu!=78)
				{
					do
					{			
						j=7;	
						LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
						x=38-(strlen("### Atualizar Aluno ###")/2);
						gotoxy(x,3);
						printf("### Atualizar Aluno ###");
						gotoxy(5,j++);
						printf("Esse Aluno esta cadastrado na tabela Notas");
						gotoxy(5,j++);
						printf("Ao Exclui-lo ira tambem ira Exclui-lo na tabela de Notas");
						gotoxy(5,j++);
						printf("Deseja Excluir? [S] Sim [N] Nao");
						gotoxy(5,++j);
						printf("Opcao Escolhida: ");
												    
						menu=toupper(getch());
												    
					}while(menu!=83 && menu!=78);
					
					if(menu==83)
					{
						LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
						x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
						gotoxy(x,13);
						printf("### Exclusao Realizada com Sucesso ###");
						x=38-(strlen("### Digite '0' para cancelar a exclusao ###")/2);
					    gotoxy(x,22);
					    printf("### Digite '0' para cancelar a exclusao ###");
						
						x=0;
						
						while(x!=TLN)
						{
							x=0;
							
							while(AuxDisci[i].CodDisc != AuxNotas[x].CodDisc && x<TLN)
								x++;
								
							if(x!=TLN)
							{
								for(x=i;x<TLN-1;x++)
								{
									strcpy(AuxNotas[x].RA,AuxNotas[x+1].RA);
									AuxNotas[x].CodDisc=AuxNotas[x+1].CodDisc;
									AuxNotas[x].Nota=AuxNotas[x+1].Nota;
								}
								
								TLN--;	
							}
						}
						
						for(k=i;k<TLD-1;k++)
						{
							AuxDisci[k].CodDisc = AuxDisci[k+1].CodDisc;
							strcpy(AuxDisci[k].Descr,AuxDisci[k+1].Descr);
						}
						
						TLD--;
						
						Sleep(3000);
					}
				}
				
				AuxCod=1;
			}														
        }
		else if(AuxCod<0)
		{
			LimparTela(2,24,2,79);
			Moldura(1,1,80,25,1,3);
			x=38-(strlen("### Codigo Invalido ###")/2);
            gotoxy(x,13);
            printf("### Codigo Invalido ###");
            Sleep(2000);
        }
		
		j=7;

    } while(AuxCod!=0);
}

void ExcluirNotas(TpNota AuxNotas[30],int &TLN,TpDisci AuxDisci[30],int TLD,TpAluno AuxAlunos[30],int TLA)
{
	char AuxRA[15],menu;
	
    int i=0,x,j=7,k,AuxCod;

    do
    {
    	LimparTela(2,24,2,79);
		Moldura(1,1,80,25,1,3);
    	x=38-(strlen("### Excluir Notas ###")/2);
	    gotoxy(x,3);
	    printf("### Excluir Notas ###");
	    x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar a exclusao ###");
    	gotoxy(5,j++);
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);
        
        if(strlen(AuxRA)==12 && VerificaRA(AuxRA))
        {
            i=0;

            while(strcmp(AuxRA,AuxNotas[i].RA)!=0 && i<TLN)
                i++;
			
			
            if(i==TLA)
            {
            	LimparTela(2,24,2,79);
				Moldura(1,1,80,25,1,3);
            	x=38-(strlen("### Nao existem Notas desse RA cadastradas no sistema ###")/2);
				gotoxy(x,13);
                printf("### Nao existem Notas desse RA cadastradas no sistema ###");
                Sleep(3000);
            }
            else
            {
		            LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
			        x=38-(strlen("### Aluno Encontrado ###")/2);
		            gotoxy(x,13);
		            printf("### Aluno Encontrado ###");;
			        Sleep(2000);
			            
			        j=7;
			            
			        LimparTela(2,24,2,79);
					Moldura(1,1,80,25,1,3);
				   	x=38-(strlen("### Excluir Notas ###")/2);
					gotoxy(x,3);
					printf("### Excluir Notas ###");
					x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
					gotoxy(x,22);
					printf("### Digite '0' para encerrar a exclusao ###");
				    
				do
				{
				    j=7;
				    LimparTela(8,23,3,78);
					gotoxy(5,j++);
					printf("RA do aluno: %s",AuxAlunos[i].RA);
					gotoxy(5,j++);
					printf("Nome do aluno: %s",AuxAlunos[i].Nome);
				
					for(x=0;x<TLN;x++)
						if(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)==0)
						{
							j++;
								
							k=0;
								
							while(AuxDisci[k].CodDisc != AuxNotas[x].CodDisc && k<TLD)
								k++;
								
							gotoxy(5,j);printf("Disciplina: %d",AuxNotas[x].CodDisc);gotoxy(21,j);printf("- %s",AuxDisci[k].Descr);gotoxy(43,j++);printf("Nota: %.1f",AuxNotas[x].Nota);	
						}
							
					j++;
					gotoxy(5,21);
					printf("Selecione o Codigo da Nota que deseja excluir: ");
					scanf(" %d",&AuxCod);
						
					k=0;
								
					while((AuxCod != AuxNotas[k].CodDisc || strcmp(AuxRA,AuxNotas[k].RA))&& k<TLN)
						k++;
						
					if(k!=TLN)
					{
						LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
				        x=38-(strlen("### Nota Encontrado ###")/2);
			            gotoxy(x,13);
			            printf("### Nota Encontrado ###");;
				        Sleep(2000);
					}
					else if(k==TLN && AuxCod!=0)
					{
						LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
				        x=38-(strlen("### Nota Nao Encontrado ###")/2);
			            gotoxy(x,13);
			            printf("### Nota Nao Encontrado ###");;
				        Sleep(2000);
					}
					
				}while(k==TLN && AuxCod!=0);
				
				if(k!=TLN && AuxCod!=0)
				{
					do	
					{	
						j=7;	
						LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
						x=38-(strlen("### Atualizar Aluno ###")/2);
						gotoxy(x,3);
						printf("### Atualizar Aluno ###");	
						gotoxy(5,++j);
						printf("Deseja Exclui-lo? [S] Sim [N] Nao");
						gotoxy(5,++j);
						printf("Opcao Escolhida: ");
						
						menu=toupper(getch());
					    
					}while(menu!=83 && menu!=78);
					
					if(menu==83)
					{
						LimparTela(2,24,2,79);
						Moldura(1,1,80,25,1,3);
						x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
						gotoxy(x,13);
						printf("### Exclusao Realizada com Sucesso ###");
						

						for(x=k;x<TLN-1;x++)
						{
							strcpy(AuxNotas[x].RA,AuxNotas[x+1].RA);
							AuxNotas[x].CodDisc=AuxNotas[x+1].CodDisc;
							AuxNotas[x].Nota=AuxNotas[x+1].Nota;
						}
									
							TLN--;	
					
						Sleep(3000);
				 	}
				}
									                	
				
			}														
        }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(2,24,2,79);
			Moldura(1,1,80,25,1,3);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,13);
            printf("### RA Invalido ###");
            Sleep(2000);
        }
		
		j=7;

    } while(strcmp(AuxRA,"0")!=0);
}

void VisualizarAlunos(TpAluno AuxAlunos[30], int &TLA)
{
    int i,j=10,k,x=0;

    
    LimparTela(2,24,2,79);
	Moldura(1,1,80,25,1,3);
    x=38-(strlen("Visuazilar Alunos")/2);
    gotoxy(x,3);
    printf("Visuazilar Alunos");

    x=38-(strlen("### Nao existe nenhum Aluno cadastrado no sistema ###")/2);
    gotoxy(x,13);
    if(TLA==0)
        printf("### Nao existe nenhum Aluno cadastrado no sistema ###");
    else
    {
	    textcolor(0);
		textbackground(7);
		
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
            
            j++;
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
    
    LimparTela(2,24,2,79);
	Moldura(1,1,80,25,1,3);
    x=38-(strlen("Visuazilar Disciplina")/2);
    gotoxy(x,3);
    printf("Visuazilar Disciplina");

    x=38-(strlen("### Nao existe nenhuma Disciplina cadastrado no sistema ###")/2);
    gotoxy(x,13);
    
    if(TLD==0)
        printf("### Nao existe nenhuma Disciplina cadastrado no sistema ###");
    else
    {
	    textcolor(0);
		textbackground(7);
		
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
    
        for(i=0;i<TLD;i++)
        {
        				
        	if(i%2==1)
        	{
        		textcolor(0);
				textbackground(7);
				
				gotoxy(16,j);
				for(k=16;k<28;k++)
					printf(" ");
				
				gotoxy(29,j);
				for(k=29;k<=59;k++)
					printf(" ");
				
			}
        	else
        	{
        		textcolor(7);
				textbackground(0);
			}
			
            gotoxy(21,j);printf("%d", AuxDisci[i].CodDisc);
            x=44-(strlen(AuxDisci[i].Descr)/2);
            gotoxy(x,j);printf("%s", AuxDisci[i].Descr);
            
            j++;
        }
	}
	
	textcolor(7);
	textbackground(0);
    
    x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
	gotoxy(x,22);
    printf("### Aperte qualquer teclar para sair ###");
	getch();
}

void VisualizarNotas(TpNota AuxNotas[30], int &TLN)
{
    int i,j=10,k,x=0;
    
    LimparTela(2,24,2,79);
	Moldura(1,1,80,25,1,3);
    x=38-(strlen("Visuazilar Notas")/2);
    gotoxy(x,3);
    printf("Visuazilar Notas");

    x=38-(strlen("### Nao existe nenhuma Nota cadastrado no sistema ###")/2);
    gotoxy(x,13);
    
    if(TLN==0)
        printf("### Nao existe nenhuma Nota cadastrado no sistema ###");
    else
    {
	    textcolor(0);
		textbackground(7);

        //x=17;
		
        for(i=16;i<=55;i++)
        {
            gotoxy(i,9);printf(" ");
        }
		
        x=22-(strlen("RA")/2);
        gotoxy(x,9);
		printf("RA");
        gotoxy(29,9);
	    printf("Codigo Disciplina");
	    gotoxy(50,9);
	    printf("Nota");
			
		textcolor(7);
		textbackground(0);
		
        gotoxy(28,9);printf(" ");  
        gotoxy(47,9);printf(" ");  
    
        for(i=0;i<TLN;i++)
        {
			
        	if(i%2==1)
        	{
        		textcolor(0);
				textbackground(7);
				
				gotoxy(29,j);
				for(k=29;k<47;k++)
					printf(" ");
				
				gotoxy(48,j);
				for(k=48;k<56;k++)
					printf(" ");
				
			}
        	else
        	{
        		textcolor(7);
				textbackground(0);
			}
			
            gotoxy(16,j);printf("%s", AuxNotas[i].RA);
            gotoxy(37,j);printf("%d", AuxNotas[i].CodDisc);
            gotoxy(51,j);printf("%.1f", AuxNotas[i].Nota);
            
            j++;
        }
	}
	
	textcolor(7);
	textbackground(0);
    
    x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
	gotoxy(x,22);
    printf("### Aperte qualquer teclar para sair ###");
	getch();
}

void Reprov2(TpNota AuxNotas[50],int TLN,TpAluno AuxAlunos[30],int TLA)
{
	int i,j,k,x=3;
	
	LimparTela(2,24,2,79);
	Moldura(1,1,80,25,1,3);
	gotoxy(5,x++);			
	printf("Alunos que ficaram com 2 materias ou mais com a media abaixo de 6: ");
	
	
	for(j=0;j<TLA;j++)
	{
		k=0;
		
		for(i=0;i<TLN;i++)
			if(strcmp(AuxAlunos[j].RA,AuxNotas[i].RA)==0)
				if(AuxNotas[i].Nota<6)
					k++;
		if(k>=2)
		{
			x++;
			gotoxy(5,x++);
			printf("RA: %s",AuxAlunos[j].RA);
			gotoxy(5,x++);
			printf("Nome: %s",AuxAlunos[j].Nome);
		}
	}
	
	x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
	gotoxy(x,22);
    printf("### Aperte qualquer teclar para sair ###");
	getch();
		
}

void BuscaInicial(TpAluno AuxAlunos[30],int TLA)
{
	int i, j=7,x;
	
	char busca;
	
	LimparTela(2,24,2,79);
	Moldura(1,1,80,25,1,3);
    x=38-(strlen("Busca por Inicial Aluno")/2);
    gotoxy(x,3);		
	printf("Busca por Inicial Aluno");
	
	gotoxy(5,j++);		
	printf("Digite a Inicial que deseja buscar: ");
	busca=toupper(getch());
		
	for(i=0;i<TLA;i++)
		if(toupper(AuxAlunos[i].Nome[0])==busca)
			{
				if(j==8)
				{
					LimparTela(4,23,3,78);
					j=7;
					gotoxy(5,j++);		
					printf("Alunos que comecam com a Inicial '%c':", busca);
					j++;
				}
					
				gotoxy(5,j++);		
				printf("- %s", AuxAlunos[i].Nome);
			}
	
	if(j==8)
	{
		LimparTela(2,24,2,79);
		x=38-(strlen("Nao tem nenhum aluno com a inicial 'C'")/2);
		gotoxy(x,13);		
		printf("Nao tem nenhum aluno com a inicial '%c'",busca);
		Sleep(3000);
	}
	else
	{
		x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
		gotoxy(x,22);
	    printf("### Aperte qualquer teclar para sair ###");
		getch();
	}	
}

void BuscaPalavra(TpDisci AuxDisci[30],int TLD)
{
	int i, j=7,x;
	
	char busca[100],busca2[100];
	
	LimparTela(2,24,2,79);
	Moldura(1,1,80,25,1,3);
    x=38-(strlen("Busca por Palavra Disciplina")/2);
    gotoxy(x,3);		
	printf("Busca por Palavra Disciplina");
	
	gotoxy(5,j++);		
	printf("Digite a Palavra que deseja buscar: ");
	scanf(" %s",&busca);
	
	for(x=0;x<=strlen(busca);x++)
		busca[x]=toupper(busca[x]);

	for(i=0;i<TLD;i++)
	{
		
		for(x=0;x<=strlen(AuxDisci[i].Descr);x++)
			busca2[x]=toupper(AuxDisci[i].Descr[x]);
		 
		if(strstr(busca2,busca))
			{
				if(j==8)
				{
					LimparTela(4,23,3,78);
					j=7;
					gotoxy(5,j++);		
					printf("Diciplinas que tem a palavra '%s':", busca);
					j++;
				}
					
				gotoxy(5,j++);		
				printf("- %s", AuxDisci[i].Descr);
			}
	}
	
	if(j==8)
	{
		LimparTela(2,24,2,79);
		x=38-(strlen("Nao tem nenhuma disciplina com a palavra 'xxxxxx'")/2);
		gotoxy(x,13);		
		printf("Nao tem nenhuma disciplina com a palavra '%s'",busca);
		Sleep(3000);
	}
	else
	{
		x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
		gotoxy(x,22);
	    printf("### Aperte qualquer teclar para sair ###");
		getch();
	}
	
}

void MediaDisci(TpDisci AuxDisci[30],int TLD,TpNota AuxNotas[50],int TLN)
{
	int i,j,x=3,y;
	float k;
	
	LimparTela(2,24,2,79);
	Moldura(1,1,80,25,1,3);
	gotoxy(5,x++);			
	printf("Materias com a media Abaixo de 6: ");
	
	
	for(j=0;j<TLD;j++)
	{
		y=0;
		k=0;
		
		for(i=0;i<TLN;i++)
			if(AuxDisci[j].CodDisc==AuxNotas[i].CodDisc)
			{
				k+=AuxNotas[i].Nota;
				y++;
			}
		
		k=k/y;
		
		if(k<6 && y>0)
		{	
			x++;
			gotoxy(5,x++);
			printf("Codigo: %d",AuxNotas[j].CodDisc);
			gotoxy(5,x++);
			printf("Derscricao: %s",AuxDisci[j].Descr);
			gotoxy(5,x++);
			printf("Media de Nota: %.1f",k);
		}
	}
	
	x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
	gotoxy(x,22);
    printf("### Aperte qualquer teclar para sair ###");
	getch();
}

void VisualizarDados(TpNota AuxNotas[30],int &TLN,TpAluno AuxAlunos[30],int TLA,TpDisci AuxDisci[50],int TLD)
{
	int i,j=3,k,x,y;

	OrdenacaoNome(AuxAlunos,TLA);

	OrdenacaoDisci(AuxDisci,TLD);
	
	system("cls");
	
	for(i=0;i<TLA;i++)
	{
		gotoxy(5,j++); printf("RA: %s   Nome: %s",AuxAlunos[i].RA,AuxAlunos[i].Nome);

		for(k=0;k<TLN;k++)
			if(strcmp(AuxAlunos[i].RA,AuxNotas[k].RA)==0)
			{
				y=0;
				
				while(AuxNotas[k].CodDisc != AuxDisci[y].CodDisc && y<TLD)
					y++;
					
				if(AuxNotas[k].Nota>=6)
				{
					gotoxy(5,j);printf("Disciplina: %d",AuxDisci[y].CodDisc);gotoxy(21,j);printf("- %s",AuxDisci[y].Descr);gotoxy(43,j++);printf("   Nota: %.1f  Situacao: %s",AuxNotas[k].Nota,"Aprovado");
				}
				else
				{
					gotoxy(5,j);printf("Disciplina: %d",AuxDisci[y].CodDisc);gotoxy(21,j);printf("- %s",AuxDisci[y].Descr);gotoxy(43,j++);printf("   Nota: %.1f  Situacao: %s",AuxNotas[k].Nota,"Reprovado");
				}
			}
		j++;
	}

	j+=2;

	x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);

	gotoxy(x,22);
	
	if(j>22)
		gotoxy(x,j);
		
    printf("### Aperte qualquer teclar para sair ###");

	j++;

	if(j>25)
		Moldura(1,1,80,++j,1,3);
	else
		Moldura(1,1,80,25,1,3);

	getch();
	
}

void Iniciar(int j)
{
	int x=0,i,k;
	char atp[15];
	
    system("cls");
    Moldura(1,1,80,25,1,3);
	fflush(stdin);
	strcpy(atp,"### ATP 2 Alunos ###");
	x=38-(strlen(atp)/2);
    
	if(j==0)
	{
		gotoxy(x,13);

		for(i=0;i<=strlen("### ATP 2 Alunos ###");i++)
		{
			printf("%c",atp[i]);
			Sleep(100);
		}

		Sleep(1000);

		k=x;

		x+=strlen(atp)+3;

		for(i=x;i>=k;i--)
		{
			gotoxy(i,13);
			printf(" ");
			Sleep(50);
		}
	}
	else
	{
		gotoxy(x,13);
		printf("%s",atp);

		Sleep(1000);

		k=x;

		x+=strlen(atp)+3;

		for(i=x;i>=k;i--)
		{
			gotoxy(i,13);
			printf(" ");
			Sleep(100);
		}
	}
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
                i=7;
                LimparTela(2,24,2,79);
                Moldura(1,1,80,25,1,3);
                x=38-(strlen("Menu Cadastrar")/2);
                gotoxy(x,3);
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
						CadastroDisci(AuxDisci,TLD);
                    break;

                    case 'C':
						CadastroNota(AuxNotas,TLN,AuxAlunos,TLA,AuxDisci,TLD);
                    break;
                }
            }while(menu!=27);
        break;

        case 'B':
            do
            {
                i=7;
                LimparTela(2,24,2,79);
                Moldura(1,1,80,25,1,3);
                x=38-(strlen("Menu Atualizar")/2);
                gotoxy(x,3);
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
                        AtualizarAluno(AuxAlunos,TLA,AuxNotas,TLN);
                    break;

                    case 'B':
						AtualizarDisci(AuxDisci,TLD,AuxNotas,TLN);

                    case 'C':
						AtualizarNotas(AuxNotas,TLN,AuxDisci,TLD,AuxAlunos,TLA);
                    break;
                }
            }while(menu!=27);
        break;

        case 'C':
            do
            {
                i=7;
                LimparTela(2,24,2,79);
                Moldura(1,1,80,25,1,3);;
                x=39-(strlen("Menu Excluir")/2);
                gotoxy(x,3);
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
                        ExcluirAlunos(AuxAlunos,TLA,AuxNotas,TLN);
                    break;

                    case 'B':
						ExcluirDisci(AuxDisci,TLD,AuxNotas,TLN);
                    break;

                    case 'C':
						ExcluirNotas(AuxNotas,TLN,AuxDisci,TLD,AuxAlunos,TLA);
                    break;
                }
            }while(menu!=27);
        break;

        case 'D':
            do
            {
                i=7;
                LimparTela(2,24,2,79);
                Moldura(1,1,80,25,1,3);
                x=38-(strlen("Menu Visualizar")/2);
                gotoxy(x,3);
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
						VisualizarDisci(AuxDisci,TLD);
                    break;

                    case 'C':
						VisualizarNotas(AuxNotas,TLN);
                    break;
                }
            }while(menu!=27);
        break;
    }
}

int Menu()
{
    char menu;

    int i,x;
    
    int TLA=0,TLD=0,TLN=0;
    TpAluno AuxAlunos[30];
	TpDisci AuxDisci[50];
	TpNota AuxNotas[30];

    do
    {
    	i=7;
        system("cls");
        Moldura(1,1,80,25,1,3);
        x=38-(strlen("Menu")/2);
        gotoxy(x,3);
        printf("Menu");
        gotoxy(5,i++); printf("[A] Cadastrar");
        gotoxy(5,i++); printf("[B] Atualizar");
        gotoxy(5,i++); printf("[C] Excluir");
        gotoxy(5,i++); printf("[D] Visualizar");
        gotoxy(5,i++); printf("[E] Reprovado em 2 ou mais disciplinas");
        gotoxy(5,i++); printf("[F] Visualizar Alunos por Letras");
        gotoxy(5,i++); printf("[G] Visualizar Disciplinas por Palavras");
        gotoxy(5,i++); printf("[H] Visualizar Disciplinas com media abaixo de 6.0");
        gotoxy(5,i++); printf("[I] Visualizar Todos os Dados");
        gotoxy(5,i++); printf("[J] Registro Automatico");
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
                Reprov2(AuxNotas,TLN,AuxAlunos,TLA);
            break;

            case 'F':
				BuscaInicial(AuxAlunos,TLA);
            break;

            case 'G':
				BuscaPalavra(AuxDisci,TLD);
            break;

            case 'H':
				MediaDisci(AuxDisci,TLD,AuxNotas,TLN);
            break;
            
            case 'I':
				VisualizarDados(AuxNotas,TLN,AuxAlunos,TLA,AuxDisci,TLD);
            break;
            
            case 'J':
				Adicionar(AuxAlunos, TLA,AuxDisci,TLD,AuxNotas,TLN);
            break;
        }
    }while(menu!=27);
}

int main ()
{
	Iniciar(0);
	
	Menu();
	
	Iniciar(28);
}
