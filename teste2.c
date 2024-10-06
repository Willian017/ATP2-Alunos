void AtualizaCodDiscluno(TpDisci AuxDisci[30],int TLD,TpNota AuxNotas[30],int TLN)
{
	char AuxDescr[30],menu;

    int i=0,x,j=9,AuxCod;

    do
    {
    	LimparTela(6,23,3,78);
    	x=38-(strlen("### Atualizar Disciplina ###")/2);
	    gotoxy(x,7);
	    printf("### Atualizar Disciplina ###");
	    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
	    gotoxy(x,22);
	    printf("### Digite '0' para encerrar a atualizacao ###");
    	gotoxy(5,j++);
        printf("Digite o Codigo da Disciplina: ");
        scanf("%d",&AuxCod);

        if(AuxCod>0)
        {
            i=0;

            while(AuxCod!=AuxDisci[i].CodDisc && i<TLD)
                i++;
			
			
            if(i==TLD)
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
		    	x=38-(strlen("### Atualizar Disciplina ###")/2);
			    gotoxy(x,7);
			    printf("### Atualizar Disciplina ###");
			    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
			    gotoxy(x,22);
			    printf("### Digite '0' para encerrar a atualizacao ###");
			    
			    do
			    {
			    	j=9;
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
					    		LimparTela(6,23,3,78);
						    	x=38-(strlen("### Atualizar Disciplina ###")/2);
							    gotoxy(x,7);
							    printf("### Atualizar Disciplina ###");
							    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
							    gotoxy(x,22);
							    printf("### Digite '0' para encerrar a atualizacao ###");
							    
							    j=9;
							    
							    gotoxy(5,j++);
								printf("Codigo antigo da Disciplina: %s",AuxDisci[i].CodDisc);
								gotoxy(5,j++);
								printf("Digite o novo Codigo: ");
        						scanf(" %s",&AuxCod);
        						
        						if(strlen(AuxCod)==12)
        						{
        							x=0;

						            while(AuxCod==AuxDisci[x].CodDisc && x<TLD)
						                x++;
						                
						            if(x!=TLD)
						            {
						            	LimparTela(6,23,3,78);
						            	x=38-(strlen("### Esse Codigo ja esta cadastrado no sistema ###")/2);
						            	gotoxy(x,14);
						                printf("### Esse Codigo ja esta cadastrado no sistema ###");
						                sleep(3);
									}
									else
									{
										x=0;
										
										while(AuxDisci[i].CodDisc==AuxNotas[x].CodDisc && x<TLN)
						                	x++;
						                	
						               	if(x==TLN)
										{
											LimparTela(6,23,3,78);
							            	x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
						            		gotoxy(x,14);
						                    printf("### Atualizacao Realizada com Sucesso ###");
						                    strcpy(AuxDisci[i].CodDisc,AuxCod);
							                sleep(3);
										}
										else
										{
											do
											{			
												j=9;	
												LimparTela(6,23,3,78);
												x=38-(strlen("### Atualizar Disciplina ###")/2);
											    gotoxy(x,7);
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
												LimparTela(6,23,3,78);
								            	x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
							            		gotoxy(x,14);
							                    printf("### Atualizacao Realizada com Sucesso ###");
										
												for(x=0;x<TLN;x++)
								                	if(AuxDisci[i].CodDisc==AuxNotas[x].CodDisc)
								                		AuxNotas[x].CodDisc=AuxCod;
								                	
								                strcpy(AuxDisci[i].CodDisc,AuxCod);
								                
								                strcpy(AuxCod,"-1");
						                	
								                sleep(3);
											}
										} 						          
									}
								} 
							    else if(strcmp(AuxCod,"0")!=0)
								{
									LimparTela(6,23,3,78);
									x=38-(strlen("### CodDisc Invalido ###")/2);
						            gotoxy(x,14);
						            printf("### CodDisc Invalido ###");
						            sleep(2);
						        }
						        
						        if(strcmp(AuxCod,"0")==0)
						        	strcpy(AuxCod,"00");
						        	
							}while(strcmp(AuxCod,"00")!=0);
				    	break;
				    	
				    	case 'B':
					    	LimparTela(6,23,3,78);
						   	x=38-(strlen("### Atualizar Disciplina ###")/2);
						    gotoxy(x,7);
						    printf("### Atualizar Disciplina ###");
						    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
						    gotoxy(x,22);
						    printf("### Digite '0' para encerrar a atualizacao ###");
						    
							j=9;
							    
							gotoxy(5,j++);
							printf("Descr Antigo do aluno: %s",AuxDisci[i].Descr);
							gotoxy(5,j++);
							printf("Digite o novo Descr: ");
        					scanf(" %s",&AuxDescr);
        						
        					if(strcmp(AuxDescr,"0")!=0)
        					{
								LimparTela(6,23,3,78);
						        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
					           	gotoxy(x,14);
					            printf("### Atualizacao Realizada com Sucesso ###");
					            strcpy(AuxDisci[i].Descr,AuxDescr);
					            sleep(3);
							}
				    	break;
				    	
				    	case 'C':
				    		do
							{
					    		LimparTela(6,23,3,78);
						    	x=38-(strlen("### Atualizar Disciplina ###")/2);
							    gotoxy(x,7);
							    printf("### Atualizar Disciplina ###");
							    x=38-(strlen("### Digite '0' para encerrar a atualizacao ###")/2);
							    gotoxy(x,22);
							    printf("### Digite '0' para encerrar a atualizacao ###");
							    
							    j=9;
							    
							    gotoxy(5,j++);
								printf("Codigo antigo da Disciplina: %s",AuxDisci[i].CodDisc);
								gotoxy(5,j++);
								printf("Digite o novo Codigo: ");
        						scanf(" %s",&AuxCod);
        						
        						if(strlen(AuxCod)==12)
        						{
        							x=0;

						            while(strcmp(AuxCod,AuxDisci[x].CodDisc)!=0 && x<TLD)
						                x++;
						                
						            if(x!=TLD)
						            {
						            	LimparTela(6,23,3,78);
						            	gotoxy(4,14);
						                printf("### Esse Codigo ja esta cadastrado no sistema ###");
						                sleep(3);
									}
									else
									{
										x=0;
										
										while(strcmp(AuxDisci[i].CodDisc,AuxNotas[x].CodDisc)!=0 && x<TLN)
						                	x++;
						                	
						               	if(x==TLN)
										{
											gotoxy(5,j++);
											printf("Descr Antigo do aluno: %s",AuxDisci[i].Descr);
											gotoxy(5,j++);
											printf("Digite o novo Descr: ");
				        					scanf(" %s",&AuxDescr);
				        						
				        					if(strcmp(AuxDescr,"0")!=0)
				        					{
												LimparTela(6,23,3,78);
										        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
									           	gotoxy(x,14);
									            printf("### Atualizacao Realizada com Sucesso ###");
									            strcpy(AuxDisci[i].Descr,AuxDescr);
									            strcpy(AuxDisci[i].CodDisc,AuxCod);
									            sleep(3);
											}
										}
										else
										{
											do
											{				
												LimparTela(6,23,3,78);
												x=38-(strlen("### Atualizar Disciplina ###")/2);
											    gotoxy(x,7);
											    printf("### Atualizar Disciplina ###");
											    j=9;
											    gotoxy(5,j++);
											    printf("Essa Disciplina esta cadastrada na tabela Notas");
											    gotoxy(5,j++);
											    printf("Ao atualiza-lo o Codigo tambem atualizar a tabela de Notas");
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
												printf("Codigo antigo da Disciplina: %s",AuxDisci[i].CodDisc);
												gotoxy(5,j++);
												printf("Novo CodDisc: %s",AuxCod);
												j++;
												gotoxy(5,j++);
												printf("Descr Antigo do aluno: %s",AuxDisci[i].Descr);
												gotoxy(5,j++);
												printf("Digite o novo Descr: ");
					        					scanf(" %s",&AuxDescr);
					        						
					        					if(strcmp(AuxDescr,"0")!=0)
					        					{
													LimparTela(6,23,3,78);
											        x=38-(strlen("### Atualizacao Realizada com Sucesso ###")/2);
										           	gotoxy(x,14);
										            printf("### Atualizacao Realizada com Sucesso ###");
										            
										            for(x=0;x<TLN;x++)
									                	if(strcmp(AuxDisci[i].CodDisc,AuxNotas[x].CodDisc)==0)
									                		strcpy(AuxNotas[x].CodDisc,AuxCod);
									                		
										            strcpy(AuxDisci[i].Descr,AuxDescr);
										            strcpy(AuxDisci[i].CodDisc,AuxCod);
										            
										            sleep(3);
										            
										            strcpy(AuxCod,"0");
												}
											}
										} 						          
									}
								} 
							    else if(strcmp(AuxCod,"0")!=0)
								{
									LimparTela(6,23,3,78);
									x=38-(strlen("### CodDisc Invalido ###")/2);
						            gotoxy(x,14);
						            printf("### CodDisc Invalido ###");
						            sleep(2);
						        }
						        
						        if(strcmp(AuxCod,"0")==0)
						        	strcpy(AuxCod,"00");
						        
							}while(strcmp(AuxCod,"00")!=0);
				    	break;
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

    } while(AuxCod<0);
}