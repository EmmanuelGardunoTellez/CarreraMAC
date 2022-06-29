#include <stdio.h>
#include <string.h>
#define n 2
struct StrFruits{
   	char name[30];
	int account;
};

struct StrPerson{
   	char name[30];
	char email[30];
};


struct StrInventory{
struct StrFruits Fruit;
struct StrPerson Provider;
};



 
int main( ) {

int i;
struct StrInventory inventory[n];
for (i=0;i<n;i++){
printf("dame la fruta: ");
fflush(stdin);
scanf("%[^\n]%*c",inventory[i].Fruit.name);
printf("dame la cantidad de la fruta: ");
scanf("%i",&inventory[i].Fruit.account);
printf("dame la nombre del provedor : ");
fflush(stdin);
scanf("%[^\n]%*c",inventory[i].Provider.name);
}


for(i=0;i<n;i++){
printf( "\n\nFrutas en el inventario %s\n", inventory[i].Fruit.name);
printf( "Numero de frutas en el inventario %i. Proveedor: %s\n", inventory[i].Fruit.account, inventory[i].Provider.name);
}   return 0;

}
