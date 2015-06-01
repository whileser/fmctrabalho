#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct {
    char Mat[];
    char Nome[];
} calculo;

typedef struct{
char row[];
char posi[];
}midi;

int main() {

    FILE *ARQ1, *ARQ2, *ARQ3;
    midi f1;
    midi f2;
    midi f3;
    //int Igual, Igualfinal;

    if ((ARQ1 = fopen("The_Moody_Blues_-_Go_Now.mid", "rb")) == NULL)//abri arquivo 1
    {
        printf("\n\n Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    if ((ARQ2 = fopen("Aha_-_Hunting_High_And_Low.mid", "rb")) == NULL)///abri arquivo 2
    {
        printf("\n\n Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    if ((ARQ3 = fopen("John_Mellencamp_-_Small_Town.mid", "rb")) == NULL)///abri arquivo 3
    {
        printf("\n\n Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    fread(&f1, sizeof (midi), 1, ARQ1); //le o arquivo 1
    fread(&f2, sizeof (midi), 1, ARQ2); //le o arquivo 2
    fread(&f3, sizeof (midi), 1, ARQ3); //le o arquivo 3


for(int i = 0; i <=100; i++){
    printf("%d", f1.row[i]);

}
printf("\n\n\n");

for(int i = 0; i <=100; i++){
    printf("%d", f2.row[i]);

}

printf("\n\n\n");
for(int i = 0; i <=100; i++){
    printf("%d", f3.row[i]);

}

    fclose(ARQ1);
    fclose(ARQ2);
    fclose(ARQ3);
    //getch();
    return 0;
}

