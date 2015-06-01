#include<stdio.h>
#include<conio.h>
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
}mid;

int main() {

    FILE *ARQ1, *ARQ2, *ARQ3;
    calculo f1;
    calculo f2;
    calculo f3;
    int Igual, Igualfinal;

    if ((ARQ1 = fopen("teste2.mid", "rb")) == NULL)//abri arquivo 1
    {
        printf("\n\n Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    if ((ARQ2 = fopen("teste1.mid", "rb")) == NULL)///abri arquivo 2
    {
        printf("\n\n Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    if ((ARQ3 = fopen("ave_maria_gounod.mid", "rb")) == NULL)///abri arquivo 3
    {
        printf("\n\n Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    fread(&f1, sizeof (calculo), 1, ARQ1); //le o arquivo 1
    fread(&f2, sizeof (calculo), 1, ARQ2); //le o arquivo 2
    fread(&f3, sizeof (calculo), 1, ARQ3); //le o arquivo 3


for(int i = 0; i <=100; i++){
    printf("%d", f1.Mat[i]);

}
printf("\n\n\n");

for(int i = 0; i <=100; i++){
    printf("%d", f2.Mat[i]);

}

printf("\n\n\n");
for(int i = 0; i <=100; i++){
    printf("%d", f3.Mat[i]);

}

    fclose(ARQ1);
    fclose(ARQ2);
    fclose(ARQ3);
    getch();
    return 0;
}

