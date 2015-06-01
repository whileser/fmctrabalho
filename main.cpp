#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

typedef struct {
    char Mat[];
    char Nome[];
} calculo;

typedef struct{
char row[];
char posi[];
}midi;

// tirar o MDC de dois números inteiros.
// retorna o Mínimo Divisor Comum (MDC)
// caso retorne '1', os números são primos entre si.
int euclidesMDC(int a, int b){
    if(a > 0){
        return euclidesMDC(b % a, a);
    } else {
      return b;
    }
}

// checar se números são primos entre si dois a dois.
// recebe um vetor de numeros para serem testados (numbers[]) e um tamanho do vetor (lines)
// retorna 1 se todos os numeros do vetor forem coprimos entre si. 0 se existem 2 ou mais que não são coprimos.
int Coprimes(int numbers[], int lines){
    bool coprime = true;
    int counter = 0;
    while(coprime && counter < lines-1){
        coprime = false;
        for(int next = counter + 1; next < lines; next++){
            if(euclidesMDC(numbers[counter], numbers[next]) == 1) // usa a função euclidesMDC() para tirar o MDC
                coprime = true;
        }
        counter++;
    }
    if(coprime)
        return 1;
    return 0;
}

// Recebe um inteiro e retorna a sua função totiente
long int getPhi(int number){
    long int phi = 0;
    for(int index = 0; index < number; index++){
        if(euclidesMDC(index, number) == 1)
            phi++;
    }
    return phi;
}

// Calcula a solução para um sistema de congruências usando TEOREMA CHINES DOS RESTOS

/* 
 * Recebe 2 vetores:
 * -> um é o vetor dos coeficientes da congruencia (números aos quais x é congruente);
 * -> outro é o vetor dos módulos de x;
 * recebe também o tamanho dos vetores (length)
 */
long long int calculateX(int coefficients[], int modules[], int length){
    long long int mod = 1; // Base to product
    long long int result = 0;
    for(int index = 0; index < length; index++){
        mod *= modules[index];
    }
    // Chinese Remainder Theorem
    // (x = a1*x1 + a2*x2 + ... + an * xn) mod (x1*x2*...*xn)
    for(int index = 0; index < length; index++){
        result += coefficients[index] * (pow(double (mod / modules[index]), getPhi(modules[index]))); // usa math.h e getPhi()
    }
    return result % mod;
}

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

