#include<stdio.h>
#define n 10
struct date
{
char Loc[50];
int month;
int day;
int year;
};
struct ParYImpar
{
	int p, i;
};

struct Alfa
{
	int MA;
	int mi;
};
struct NumYLetras
{
		
};

void main()
{
	struct ParYImpar Number[n];
	struct Alfa AL[27];
	int r, i;
	char ora[50];
	for(r=1;r<n;r++)
	{
		Number[r].p=(2*r);
		Number[r].i=(2*r)-1;
	}
	for(r=1;r<n;r++){
		printf("%i, ",Number[r].i);
	}
	printf("\n");
	for(r=1;r<n;r++){
		printf("%i, ",Number[r].p);
	}
	printf("\n");
	for(r=1;r<27;r++)
	{
		AL[r].MA=64+r;
		AL[r].mi=96+r;
	}
	printf("\n");
 	for(r=1;r<27;r++){
		printf("%c			%c\n",AL[r].MA, AL[r].mi);
		
	}
	
	printf("Como te gusta que te llamen (sin espacios)? ");
	scanf("%[^\n]", ora);

	
}
	
