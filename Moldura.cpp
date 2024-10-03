#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <windows.h>

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

int main ()
{
	int i=9;
	Moldura(1,1,80,25,1,7);
	Moldura(2,2,79,4,1,3);
	gotoxy(33,3);
	printf("ATP 2 Alunos");
	Moldura(2,5,79,24,1,3);
	gotoxy(37,7);
	printf("Menu");
	gotoxy(5,i++); printf("[A] Cadastro de Alunos");gotoxy(45,i); printf("[I] Excluir Notas");
	gotoxy(5,i++); printf("[B] Cadastro de Disciplinas");gotoxy(45,i); printf("[J] Visualizar Alunos");
	gotoxy(5,i++); printf("[C] Cadastro de Notas");gotoxy(45,i); printf("[K] Visualizar Disciplina");
	gotoxy(5,i++); printf("[D] Atualizar Alunos");gotoxy(45,i); printf("[L] Visualizar Notas");
	gotoxy(5,i++); printf("[E] Atualizar Disciplinas");gotoxy(45,i); printf("[M] Reprovado em 2 ou mais disciplinas");
	gotoxy(5,i++); printf("[F] Atualizar Notas");gotoxy(45,i); printf("[N] Visualizar Alunos por Letras");
	gotoxy(5,i++); printf("[G] Excluir Alunos");gotoxy(45,i); printf("[O] Visualizar Disciplinas com media abaixo de 6.0");
	gotoxy(5,i++); printf("[H] Excluir Disciplinas");gotoxy(45,i); printf("[P] Visualizar Todosa os Dados");
	gotoxy(5,i++); printf("[ESC] Sair\n");
    gotoxy(5,i+=2); printf("Opcao desejada: ");
}
