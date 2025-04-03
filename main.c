    #include <stdio.h>
    #include <ctype.h>
    #include <stdarg.h> // Inclure l'en-tête pour les fonctions variadiques
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "Prototype.h"
int main(int argc, char const *argv[]) {
    
    printf("A toi : ");
    lire_Utile();
    while (uniteCourante!='.'){
        if (calunultornot){
            printf("A toi : ");
        }
        else{
            if (uniteCourante=='*' || uniteCourante=='/'){
                printf("Mauvaise Expression\n");
                printf("Debut de caractere{*,/} Interdit\n");
                printf("A toi : ");
            }
            else{
                expression();
                double caluconversion = evaluateExpression(calu);
                printf("Priorite Gauche a Droite de meme priorite\n");
                printf("Sa valeur est: %.2f\n", caluconversion);
                double caluconversion2=evaluateExpressiondgmultiplicatif(calu);
                printf("Priorite Droite a Gauche de meme priorite\n");
                printf("Sa valeur est: %.2f\n", caluconversion2);
                Parenthesefermante = 0;
                ParentheseOuvrante = 0;
                nombreLu = 0;
                taille = 0;
                free(calu);
                calu=NULL;
                printf("A toi : ");
            }
        }
        lire_Utile();
    } 
    printf("Au revoir...");
    return 0;
}