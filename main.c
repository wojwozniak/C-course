#include <stdio.h>
#include <stdlib.h>

int main() {
    char cur;
    char prev;
    int i=0;
    while(1) {
        if(i!=0) {
            prev = cur;
            printf("\n");
        }
        i++;
        printf("Podaj znak: ");
        // Trzeba tak zrobi� �eby spacja dzia�a�a, trzeba da� CTRL + Z (sam enter powoduje niesko�czon� p�tl�)
        scanf("%[^\n]s", &cur);
        //printf(" %c", cur);
        int curint = (int)cur;
        int prevint = (int)prev;
        if(curint==32 || curint == 9) {
            if(prevint!=32 && prevint!=9) {
                printf(" ");
            }
            continue;
        }
        if(curint == 10) {
            printf("\n");
            continue;
        }
        if(curint > 32 && curint <=126) {
            if(curint >=97 && curint <=122) {
                curint+=3;
                if(curint>122) {
                    curint-= 26;
                }
            }
            printf("%c", curint);
            continue;
        }
    }
}
