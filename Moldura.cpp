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
	i=7;
	Moldura(1,1,80,25,1,7);
	Moldura(2,2,79,4,1,3);
	gotoxy(33,3);
	printf("ATP 2 Alunos");
	Moldura(2,5,30,24,1,3);
	gotoxy(3,i++);
	printf("[A] Cad Alunos\n");
	gotoxy(3,i++);
	printf("[A] Cad Alunos\n");
	gotoxy(3,i++);
	printf("[A] Cad Alunos\n");
	gotoxy(3,i++);
	printf("[A] Cad Alunos\n");
	gotoxy(3,i++);
	printf("[A] Cad Alunos\n");
	gotoxy(3,i++);
	printf("[A] Cad Alunos\n");
	printf("\n");
}
