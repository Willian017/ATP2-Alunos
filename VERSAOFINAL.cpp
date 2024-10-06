#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <unistd.h>

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

void LimparTela(int CI,int CF,int LI,int LF)
{
	int i, j;
	
	for(i=CI;i<=CF;i++)
		for(j=LI;j<=LF;j++)
		{
			gotoxy(j,i);printf(" ");
		}
}

void Adicionar(TpAluno AuxAlunos[30], int &TLA,TpDisci AuxDisci[50], int &TLD,TpNota AuxNotas[30], int &TLN)
{
    int i=0;

	strcpy(AuxAlunos[TLA].Nome,"Joao");
	strcpy(AuxAlunos[TLA].RA,"26.24.1121-1");
	
	AuxDisci[TLD].CodDisc = 100;
	strcpy(AuxDisci[TLD].Descr,"ATP 2");
	
	strcpy(AuxNotas[TLN].RA,"26.24.1121-1");
	AuxNotas[TLN].CodDisc = 100;
	AuxNotas[TLN].Nota = 8;
	
	TLA++;
	TLD++;
	TLN++;
	
	strcpy(AuxAlunos[TLA].Nome,"Maria");
	strcpy(AuxAlunos[TLA].RA,"26.28.1921-1");
	
	AuxDisci[TLD].CodDisc = 99;
	strcpy(AuxDisci[TLD].Descr,"ATP 1");
	
	strcpy(AuxNotas[TLN].RA,"26.28.1921-1");
	AuxNotas[TLN].CodDisc = 99;
	AuxNotas[TLN].Nota = 2;
	
	TLA++;
	TLD++;
	TLN++;

	    
	strcpy(AuxNotas[TLN].RA,"26.28.1921-1");
	AuxNotas[TLN].CodDisc = 100;
	AuxNotas[TLN].Nota = 3;
	
	TLN++;
}

void CadastroAluno(TpAluno AuxAlunos[30],int &TLA)
{
    char AuxRA[15],AuxNome[30];
    int i=0,x,j=9;

    do
    {
    	LimparTela(6,23,3,78);
    	
    	x=38-(strlen("### Cadastro de Aluno ###")/2);
	    gotoxy(x,7);
	    printf("### Cadastro de Aluno ###");
	    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar o cadastro ###");
    	gotoxy(5,j++);
        printf("Digite o RA do Aluno(Ex: 26.24.1121-1): ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12)
        {
            i=0;

            while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
                i++;
			
			
            if(i!=TLA)
            {
            	LimparTela(6,23,3,78);
            	gotoxy(4,14);
                printf("### Nao foi possivel cadastrar esse RA, ele ja esta presente no Sistema ###");
                sleep(3);
            }
            else
            {
            	gotoxy(5,j);
                printf("Digite o Nome do Aluno: ");
                fflush(stdin);
                gets(AuxNome);
				
                if(strcmp(AuxNome,"0")==0)
                {
                	LimparTela(6,23,3,78);
	            	x=38-(strlen("### Nome Invalido ###")/2);
            		gotoxy(x,14);
                    printf("### Nome Invalido ###");;
	                sleep(2);
            	}
                else
                {    
                	LimparTela(6,23,3,78);
	            	x=38-(strlen("### Cadastro Realizado Com Sucesso ###")/2);
            		gotoxy(x,14);
                    printf("### Cadastro Realizado Com Sucesso ###");;
	                sleep(3);
                    strcpy(AuxAlunos[TLA].RA,AuxRA);
                    strcpy(AuxAlunos[TLA].Nome,AuxNome);
                    TLA++;
                }
            }
        }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(6,23,3,78);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,14);
            printf("### RA Invalido ###");
            sleep(2);
        }
		
		j=9;

    } while(strcmp(AuxRA,"0")!=0);
}

void CadastroDisci(TpDisci AuxDisci[50],int &TLD)
{
    char AuxDescr[50];
    int i=0,x,j=9, AuxCod;
    
    do
    {
    	LimparTela(6,23,3,78);
	    x=38-(strlen("### Cadastro de Disciplinas ###")/2);
	    gotoxy(x,7);
	    printf("### Cadastro de Disciplinas ###");
	    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar o cadastro ###");
	    
    	gotoxy(5,j++);
        printf("Digite o Codigo da Disciplina: ");
        scanf(" %d",&AuxCod);

        if(AuxCod>0)
        {
            i=0;

            while(AuxCod != AuxDisci[i].CodDisc && i<TLD)
                i++;
			
			
            if(i!=TLD)
            {
            	LimparTela(6,23,3,78);
            	gotoxy(4,14);
                printf("### Nao foi possivel cadastrar a Disciplina, ela ja esta no Sistema ###");
                sleep(2);
            }
            else
            {
            	gotoxy(5,j);
                printf("Digite o Nome da Disciplina: ");
                fflush(stdin);
                gets(AuxDescr);
				
                if(strcmp(AuxDescr,"0")==0)
                {
                	LimparTela(6,23,3,78);
                	x=38-(strlen("### Nome Invalido ###")/2);
            		gotoxy(x,14);
                    printf("### Nome Invalido ###");
                    sleep(2);
            	}
                else
                {    
                	LimparTela(6,23,3,78);
	            	x=38-(strlen("### Cadastro Realizado Com Sucesso ###")/2);
            		gotoxy(x,14);
                    printf("### Cadastro Realizado Com Sucesso ###");;
	                sleep(3);
                    AuxDisci[TLD].CodDisc=AuxCod;
                    strcpy(AuxDisci[TLD].Descr,AuxDescr);
                    TLD++;
                }
            }
        }
		else if(AuxCod!=0)
		{
			LimparTela(6,23,3,78);
			x=38-(strlen("### Codigo Invalido ###")/2);
            gotoxy(x,14);
            printf("### Codigo Invalido ###");
            sleep(2);
        }
		
		j=9;

    } while(AuxCod!=0);
}

void CadastroNota(TpNota AuxNota[30],int &TLN,TpAluno AuxAlunos[30],int TLA,TpDisci AuxDisci[50],int TLD)
{
    char AuxRA[13],AuxNome[30],AuxDescri[50];
    int i=0,x,j=9, AuxCod;
    float AuxNotas;
    
    do
    {
    	LimparTela(6,23,3,78);
	    x=38-(strlen("### Cadastro de Notas ###")/2);
	    gotoxy(x,7);
	    printf("### Cadastro de Notas ###");
	    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar o cadastro ###");
	    
    	gotoxy(5,j++);
        printf("Digite o RA do aluno: ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12)
        {
            i=0;

            while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
                i++;
			
			
            if(i==TLA)
            {
            	LimparTela(6,23,3,78);
	    		x=38-(strlen("### Esse Aluno nao esta existe ###")/2);
            	gotoxy(x,14);
                printf("### Esse Aluno nao esta existe ###");
                sleep(2);
            }
            else
            {
            	strcpy(AuxNome,AuxAlunos[i].Nome);
            	
                do
				{
					LimparTela(8,21,3,78);
					
					j=9;
					    
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
		                LimparTela(6,23,3,78);
				    	x=38-(strlen("### Essa Disciplina nao esta existe, tente novamente ###")/2);
			           	gotoxy(x,14);
			            printf("### Essa Disciplina nao esta existe, tente novamente ###");
			            sleep(3);
			            
			            LimparTela(6,23,3,78);
					    x=38-(strlen("### Cadastro de Notas ###")/2);
					    gotoxy(x,7);
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
						
					    j=9;
					    
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
			                LimparTela(6,23,3,78);
					    	x=38-(strlen("### Essa Nota esta fora dos parametros corretos ###")/2);
				           	gotoxy(x,14);
				            printf("### Essa Nota esta fora dos parametros corretos ###");
				            sleep(3);
				            
				            LimparTela(6,23,3,78);
						    x=38-(strlen("### Cadastro de Notas ###")/2);
						    gotoxy(x,7);
						    printf("### Cadastro de Notas ###");
						    x=38-(strlen("### Digite '0' para encerrar o cadastro ###")/2);
						    gotoxy(x,22);
						    printf("### Digite '0' para encerrar o cadastro ###");
						}	
		        	}while(AuxNotas<0 || AuxNotas>10);
		        	
		        	LimparTela(6,23,3,78);
	            	x=38-(strlen("### Cadastro Realizado Com Sucesso ###")/2);
            		gotoxy(x,14);
                    printf("### Cadastro Realizado Com Sucesso ###");;
	                sleep(3);
		        	strcpy(AuxNota[TLN].RA, AuxRA);
		        	AuxNota[TLN].CodDisc=AuxCod;
		        	AuxNota[TLN].Nota=AuxNotas;
		        	
		        	TLN++;
		    	}
		    	else if(x!=TLN)
		    	{
		    		LimparTela(6,23,3,78);
					x=38-(strlen("### Nota ja cadastrada ###")/2);
		            gotoxy(x,14);
		            printf("### Nota ja cadastrada ###");
		            sleep(2);
				}
            }
        }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(6,23,3,78);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,14);
            printf("### RA Invalido ###");
            sleep(2);
        }
        		    
		j=9;


    } while(strcmp(AuxRA,"0")!=0);
}

void AtualizarAluno(TpAluno AuxAlunos[30],int &TLA,TpNota AuxNotas[30],int TLN)
{
	char AuxRA[15],AuxNome[30],menu;
    int i=0,x,j=9;

    do
    {
    	LimparTela(6,23,3,78);
    	x=38-(strlen("### Atualizar Aluno ###")/2);
	    gotoxy(x,7);
	    printf("### Atualizar Aluno ###");
	    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar a atualizacao ###");
    	gotoxy(5,j++);
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12)
        {
            i=0;

            while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
                i++;
			
			
            if(i==TLA)
            {
            	LimparTela(6,23,3,78);
            	x=38-(strlen("### Esse Aluno nao esta cadastrado no sistema ###")/2);
				gotoxy(x,14);
                printf("### Esse Aluno nao esta cadastrado no sistema ###");
                sleep(3);
            }
            else
            {
            	LimparTela(6,23,3,78);
	            x=38-(strlen("### Aluno Encontrado ###")/2);
            	gotoxy(x,14);
                printf("### Aluno Encontrado ###");;
	            sleep(2);
	            
	            j=9;
	            
	            LimparTela(6,23,3,78);
		    	x=38-(strlen("### Atualizar Aluno ###")/2);
			    gotoxy(x,7);
			    printf("### Atualizar Aluno ###");
			    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
			    gotoxy(x,22);
			    printf("### Digite '0' para encerrar a atualizacao ###");
			    
			    do
			    {
			    	j=9;
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
					    		LimparTela(6,23,3,78);
						    	x=38-(strlen("### Atualizar Aluno ###")/2);
							    gotoxy(x,7);
							    printf("### Atualizar Aluno ###");
							    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
							    gotoxy(x,22);
							    printf("### Digite '0' para encerrar a atualizacao ###");
							    
							    j=9;
							    
							    gotoxy(5,j++);
								printf("RA Antigo do aluno: %s",AuxAlunos[i].RA);
								gotoxy(5,j++);
								printf("Digite o novo RA: ");
        						scanf(" %s",&AuxRA);
        						
        						if(strlen(AuxRA)==12)
        						{
        							x=0;

						            while(strcmp(AuxRA,AuxAlunos[x].RA)!=0 && x<TLA)
						                x++;
						                
						            if(x!=TLA)
						            {
						            	LimparTela(6,23,3,78);
						            	x=38-(strlen("### Esse RA ja esta cadastrado no sistema ###")/2);
						            	gotoxy(x,14);
						                printf("### Esse RA ja esta cadastrado no sistema ###");
						                sleep(3);
									}
									else
									{
										x=0;
										
										while(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)!=0 && x<TLN)
						                	x++;
						                	
						               	if(x==TLN)
										{
											LimparTela(6,23,3,78);
							            	x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
						            		gotoxy(x,14);
						                    printf("### Atualizacao Realizada com Sucesso ###");
						                    strcpy(AuxAlunos[i].RA,AuxRA);
							                sleep(3);
										}
										else
										{
											do
											{			
												j=9;	
												LimparTela(6,23,3,78);
												x=38-(strlen("### Atualizar Aluno ###")/2);
											    gotoxy(x,7);
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
												LimparTela(6,23,3,78);
								            	x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
							            		gotoxy(x,14);
							                    printf("### Atualizacao Realizada com Sucesso ###");
										
												for(x=0;x<TLN;x++)
								                	if(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)==0)
								                		strcpy(AuxNotas[x].RA,AuxRA);
								                	
								                strcpy(AuxAlunos[i].RA,AuxRA);
								                
								                strcpy(AuxRA,"0");
						                	
								                sleep(3);
											}
										} 						          
									}
								} 
							    else if(strcmp(AuxRA,"0")!=0)
								{
									LimparTela(6,23,3,78);
									x=38-(strlen("### RA Invalido ###")/2);
						            gotoxy(x,14);
						            printf("### RA Invalido ###");
						            sleep(2);
						        }
						        
						        if(strcmp(AuxRA,"0")==0)
						        	strcpy(AuxRA,"00");
						        	
							}while(strcmp(AuxRA,"00")!=0);
				    	break;
				    	
				    	case 'B':
					    	LimparTela(6,23,3,78);
						   	x=38-(strlen("### Atualizar Aluno ###")/2);
						    gotoxy(x,7);
						    printf("### Atualizar Aluno ###");
						    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
						    gotoxy(x,22);
						    printf("### Digite '0' para encerrar a atualizacao ###");
						    
							j=9;
							    
							gotoxy(5,j++);
							printf("Nome Antigo do aluno: %s",AuxAlunos[i].Nome);
							gotoxy(5,j++);
							printf("Digite o novo Nome: ");
							fflush(stdin);
        					gets(AuxNome);
        						
        					if(strcmp(AuxNome,"0")!=0)
        					{
								LimparTela(6,23,3,78);
						        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
					           	gotoxy(x,14);
					            printf("### Atualizacao Realizada com Sucesso ###");
					            strcpy(AuxAlunos[i].Nome,AuxNome);
					            sleep(3);
							}
				    	break;
				    	
				    	case 'C':
				    		do
							{
					    		LimparTela(6,23,3,78);
						    	x=38-(strlen("### Atualizar Aluno ###")/2);
							    gotoxy(x,7);
							    printf("### Atualizar Aluno ###");
							    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
							    gotoxy(x,22);
							    printf("### Digite '0' para encerrar a atualizacao ###");
							    
							    j=9;
							    
							    gotoxy(5,j++);
								printf("RA Antigo do aluno: %s",AuxAlunos[i].RA);
								gotoxy(5,j++);
								printf("Digite o novo RA: ");
        						scanf(" %s",&AuxRA);
        						
        						if(strlen(AuxRA)==12)
        						{
        							x=0;

						            while(strcmp(AuxRA,AuxAlunos[x].RA)!=0 && x<TLA)
						                x++;
						                
						            if(x!=TLA)
						            {
						            	LimparTela(6,23,3,78);
						            	gotoxy(4,14);
						                printf("### Esse RA ja esta cadastrado no sistema ###");
						                sleep(3);
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
												LimparTela(6,23,3,78);
										        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
									           	gotoxy(x,14);
									            printf("### Atualizacao Realizada com Sucesso ###");
									            strcpy(AuxAlunos[i].Nome,AuxNome);
									            strcpy(AuxAlunos[i].RA,AuxRA);
									            sleep(3);
											}
										}
										else
										{
											do
											{				
												LimparTela(6,23,3,78);
												x=38-(strlen("### Atualizar Aluno ###")/2);
											    gotoxy(x,7);
											    printf("### Atualizar Aluno ###");
											    j=9;
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
												LimparTela(6,23,3,78);
												j=9;
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
													LimparTela(6,23,3,78);
											        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
										           	gotoxy(x,14);
										            printf("### Atualizacao Realizada com Sucesso ###");
										            
										            for(x=0;x<TLN;x++)
									                	if(strcmp(AuxAlunos[i].RA,AuxNotas[x].RA)==0)
									                		strcpy(AuxNotas[x].RA,AuxRA);
									                		
										            strcpy(AuxAlunos[i].Nome,AuxNome);
										            strcpy(AuxAlunos[i].RA,AuxRA);
										            
										            sleep(3);
										            
										            strcpy(AuxRA,"0");
												}
											}
										} 						          
									}
								} 
							    else if(strcmp(AuxRA,"0")!=0)
								{
									LimparTela(6,23,3,78);
									x=38-(strlen("### RA Invalido ###")/2);
						            gotoxy(x,14);
						            printf("### RA Invalido ###");
						            sleep(2);
						        }
						        
						        if(strcmp(AuxRA,"0")==0)
						        	strcpy(AuxRA,"00");
						        
							}while(strcmp(AuxRA,"00")!=0);
				    	break;
					}
            }
        }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(6,23,3,78);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,14);
            printf("### RA Invalido ###");
            sleep(2);
        }
		
		j=9;

    } while(strcmp(AuxRA,"0")!=0);
}

void ExcluirAlunos(TpAluno AuxAlunos[30],int &TLA,TpNota AuxNotas[30],int &TLN)
{
	char AuxRA[15],AuxNome[30],menu;
    int i=0,x,j=9,k;

    do
    {
    	LimparTela(6,23,3,78);
    	x=38-(strlen("### Excluir Aluno ###")/2);
	    gotoxy(x,7);
	    printf("### Excluir Aluno ###");
	    x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar a exclusao ###");
    	gotoxy(5,j++);
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);

        if(strlen(AuxRA)==12)
        {
            i=0;

            while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
                i++;
			
			
            if(i==TLA)
            {
            	LimparTela(6,23,3,78);
            	x=38-(strlen("### Esse Aluno nao esta cadastrado no sistema ###")/2);
				gotoxy(x,14);
                printf("### Esse Aluno nao esta cadastrado no sistema ###");
                sleep(3);
            }
            else
            {
            	LimparTela(6,23,3,78);
	            x=38-(strlen("### Aluno Encontrado ###")/2);
            	gotoxy(x,14);
                printf("### Aluno Encontrado ###");;
	            sleep(2);
	            
	            j=9;
	            
	            LimparTela(6,23,3,78);
		    	x=38-(strlen("### Excluir Aluno ###")/2);
			    gotoxy(x,7);
			    printf("### Excluir Aluno ###");
			    x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
			    gotoxy(x,22);
			    printf("### Digite '0' para encerrar a exclusao ###");
			    
			    do
			    {
			    	j=9;
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
						                	
				if(x==TLN)
				{
					LimparTela(6,23,3,78);
					x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
					gotoxy(x,14);
					printf("### Exclusao Realizada com Sucesso ###");
					
					for(k=i;k<TLA-1;k++)
					{
						strcpy(AuxAlunos[k].RA,AuxAlunos[k+1].RA);
						strcpy(AuxAlunos[k].Nome,AuxAlunos[k+1].Nome);
					}
					
					TLA--;
					
					sleep(3);
				 }
				else
					do
					{			
						j=9;	
						LimparTela(6,23,3,78);
						x=38-(strlen("### Atualizar Aluno ###")/2);
						gotoxy(x,7);
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
						LimparTela(6,23,3,78);
						x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
						gotoxy(x,14);
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
						
						sleep(3);
					}
				}														
            }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(6,23,3,78);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,14);
            printf("### RA Invalido ###");
            sleep(2);
        }
		
		j=9;

    } while(strcmp(AuxRA,"0")!=0);
}

void ExcluirDisci(TpDisci AuxDisci[30],int &TLD,TpNota AuxNotas[30],int &TLN)
{
	char AuxDescr[100],menu;
	
    int i=0,x,j=9,k,AuxCod;

    do
    {
    	LimparTela(6,23,3,78);
    	x=38-(strlen("### Excluir Disciplina ###")/2);
	    gotoxy(x,7);
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
            	LimparTela(6,23,3,78);
            	x=38-(strlen("### Essa Disciplina nao esta cadastrado no sistema ###")/2);
				gotoxy(x,14);
                printf("### Essa Disciplina nao esta cadastrado no sistema ###");
                sleep(3);
            }
            else
            {
            	LimparTela(6,23,3,78);
	            x=38-(strlen("### Disciplina Encontrada ###")/2);
            	gotoxy(x,14);
                printf("### Disciplina Encontrada ###");;
	            sleep(2);
	            
	            j=9;
	            
	            LimparTela(6,23,3,78);
		    	x=38-(strlen("### Excluir Disciplina ###")/2);
			    gotoxy(x,7);
			    printf("### Excluir Disciplina ###");
			    x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
			    gotoxy(x,22);
			    printf("### Digite '0' para encerrar a exclusao ###");
			    
			    do
			    {
			    	j=9;
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
						                	
				if(x==TLN)
				{
					LimparTela(6,23,3,78);
					x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
					gotoxy(x,14);
					printf("### Exclusao Realizada com Sucesso ###");
					
					for(k=i;k<TLD-1;k++)
					{
						AuxDisci[k].CodDisc = AuxDisci[k+1].CodDisc;
						strcpy(AuxDisci[k].Descr,AuxDisci[k+1].Descr);
					}
					
					TLD--;
					
					sleep(3);
				 }
				else
					do
					{			
						j=9;	
						LimparTela(6,23,3,78);
						x=38-(strlen("### Atualizar Aluno ###")/2);
						gotoxy(x,7);
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
						LimparTela(6,23,3,78);
						x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
						gotoxy(x,14);
						printf("### Exclusao Realizada com Sucesso ###");
						
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
						
						sleep(3);
					}
				}														
            }
		else if(AuxCod<0)
		{
			LimparTela(6,23,3,78);
			x=38-(strlen("### Codigo Invalido ###")/2);
            gotoxy(x,14);
            printf("### Codigo Invalido ###");
            sleep(2);
        }
		
		j=9;

    } while(AuxCod==0);
}

void ExcluirNots(TpNota AuxNotas[30],int &TLN)
{
	char AuxRA[15],menu;
	
    int i=0,x,j=9,k,AuxCod;

    do
    {
    	LimparTela(6,23,3,78);
    	x=38-(strlen("### Excluir Notas ###")/2);
	    gotoxy(x,7);
	    printf("### Excluir Notas ###");
	    x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar a exclusao ###");
    	gotoxy(5,j++);
        printf("Digite o RA do Aluno: ");
        scanf(" %s",&AuxRA);
        
        if(strlen(AuxRA)==12)
        {
            i=0;

            while(strcmp(AuxRA,AuxAlunos[i].RA)!=0 && i<TLA)
                i++;
			
			
            if(i==TLA)
            {
            	LimparTela(6,23,3,78);
            	x=38-(strlen("### Esse Aluno nao esta cadastrado no sistema ###")/2);
				gotoxy(x,14);
                printf("### Esse Aluno nao esta cadastrado no sistema ###");
                sleep(3);
            }
            else
            {
            	LimparTela(6,23,3,78);
	            x=38-(strlen("### Aluno Encontrado ###")/2);
            	gotoxy(x,14);
                printf("### Aluno Encontrado ###");;
	            sleep(2);
	            
	            j=9;
	            
	            LimparTela(6,23,3,78);
		    	x=38-(strlen("### Excluir Aluno ###")/2);
			    gotoxy(x,7);
			    printf("### Excluir Aluno ###");
			    x=38-(strlen("### Digite '0' para encerrar a exclusao ###")/2);
			    gotoxy(x,22);
			    printf("### Digite '0' para encerrar a exclusao ###");
			    
			    do
			    {
			    	j=9;
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
						                	
				if(x==TLN)
				{
					LimparTela(6,23,3,78);
					x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
					gotoxy(x,14);
					printf("### Exclusao Realizada com Sucesso ###");
					
					for(k=i;k<TLA-1;k++)
					{
						strcpy(AuxAlunos[k].RA,AuxAlunos[k+1].RA);
						strcpy(AuxAlunos[k].Nome,AuxAlunos[k+1].Nome);
					}
					
					TLA--;
					
					sleep(3);
				 }
				else
					do
					{			
						j=9;	
						LimparTela(6,23,3,78);
						x=38-(strlen("### Atualizar Aluno ###")/2);
						gotoxy(x,7);
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
						LimparTela(6,23,3,78);
						x=38-(strlen("### Exclusao Realizada com Sucesso ###")/2);
						gotoxy(x,14);
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
						
						sleep(3);
					}
				}														
            }
		else if(strcmp(AuxRA,"0")!=0)
		{
			LimparTela(6,23,3,78);
			x=38-(strlen("### RA Invalido ###")/2);
            gotoxy(x,14);
            printf("### RA Invalido ###");
            sleep(2);
        }
		
		j=9;

    } while(strcmp(AuxRA,"0")!=0);
}

void VisualizarAlunos(TpAluno AuxAlunos[30], int &TLA)
{
    int i,j=10,k,x=0;

    
    LimparTela(6,23,3,78);
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
    
    LimparTela(6,23,3,78);
    x=38-(strlen("Visuazilar Disciplina")/2);
    gotoxy(x,7);
    printf("Visuazilar Disciplina");

    x=38-(strlen("### Nao existe nenhuma Disciplina cadastrado no sistema ###")/2);
    gotoxy(x,13);
    
    if(TLD==0)
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
			
			
        	x=22-(strlen(AuxDisci[i].Descr)/2);
            gotoxy(x,j);printf("%d", AuxDisci[i].CodDisc);
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
    
    LimparTela(6,23,3,78);
    x=38-(strlen("Visuazilar Notas")/2);
    gotoxy(x,7);
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
	int i,j,k,x=7;
	
	LimparTela(6,23,3,78);
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
	int i, j=9,x;
	
	char busca;
	
	LimparTela(6,23,3,78);
    x=38-(strlen("Busca por Inicial Aluno")/2);
    gotoxy(x,7);		
	printf("Busca por Inicial Aluno");
	
	gotoxy(5,j++);		
	printf("Digite a Inicial que deseja buscar: ");
	busca=toupper(getch());
		
	for(i=0;i<TLA;i++)
		if(toupper(AuxAlunos[i].Nome[0])==busca)
			{
				if(j==10)
				{
					LimparTela(9,23,3,78);
					j=9;
					gotoxy(5,j++);		
					printf("Alunos que comecam com a Inicial '%c':", busca);
					j++;
				}
					
				gotoxy(5,j++);		
				printf("- %s", AuxAlunos[i].Nome);
			}
	
	if(j==10)
	{
		LimparTela(9,23,3,78);
		x=38-(strlen("Nao tem nenhum aluno com a inicial 'C'")/2);
		gotoxy(x,14);		
		printf("Nao tem nenhum aluno com a inicial '%c'",busca);
		sleep(3);
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
	int i, j=9,x;
	
	char busca[100],busca2[100];
	
	LimparTela(6,23,3,78);
    x=38-(strlen("Busca por Palavra Disciplina")/2);
    gotoxy(x,7);		
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
				if(j==10)
				{
					LimparTela(9,23,3,78);
					j=9;
					gotoxy(5,j++);		
					printf("Diciplinas que tem a palavra '%s':", busca);
					j++;
				}
					
				gotoxy(5,j++);		
				printf("- %s", AuxDisci[i].Descr);
			}
	}
	
	if(j==10)
	{
		LimparTela(9,23,3,78);
		x=38-(strlen("Nao tem nenhuma disciplina com a palavra 'xxxxxx'")/2);
		gotoxy(x,14);		
		printf("Nao tem nenhuma disciplina com a palavra '%s'",busca);
		sleep(3);
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
	int i,j,x=7,y;
	float k;
	
	LimparTela(6,23,3,78);
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
		}
	}
	
	x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
	gotoxy(x,22);
    printf("### Aperte qualquer teclar para sair ###");
	getch();
}

void VisualizarDados(TpNota AuxNotas[30],int &TLN,TpAluno AuxAlunos[30],int TLA,TpDisci AuxDisci[50],int TLD)
{
	int i,j=7,k,x,y;
	
	LimparTela(6,23,3,78);
	
	for(i=0;i<TLA;i++)
	{
		gotoxy(5,j++); printf("RA: %s   Nome: %s",AuxAlunos[i].RA,AuxAlunos[i].Nome);
		

		for(k=0;k<TLN;k++)
			if(strcmp(AuxAlunos[i].RA,AuxNotas[k].RA)==0)
			{
				y=0;
				
				while(AuxNotas[k].CodDisc != AuxDisci[y].CodDisc && y<TLD)
					y++;
				if(AuxNotas[k].Nota>6)
				{
					gotoxy(5,j);printf("Disciplina: %d - %s",AuxDisci[y].CodDisc,AuxDisci[y].Descr);gotoxy(5,j++);printf("Nota: %.1f  Situacao: %s",AuxNotas[k].Nota,"Aprovado");
				}
				else
				{
					gotoxy(5,j);printf("Disciplina: %d - %s",AuxDisci[y].CodDisc,AuxDisci[y].Descr);gotoxy(43,j++);printf("Nota: %.1f  Situacao: %s",AuxNotas[k].Nota,"Reprovado");
				}
			}
		j++;
	}
	
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
                LimparTela(6,23,3,78);
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
                i=9;
                LimparTela(6,23,3,78);
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
                        AtualizarAluno(AuxAlunos,TLA,AuxNotas,TLN);
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
                LimparTela(6,23,3,78);
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
                        ExcluirAlunos(AuxAlunos,TLA,AuxNotas,TLN);
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
                LimparTela(6,23,3,78);
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
	Menu();
}
