// Prototype.h

void expression(void);
void fin_expression(bool numberbefore, bool symbole_egal, bool parentheseouvrante);
void terme(void);
void fin_terme(void);
void facteur(void);
void terminal(int uniteVoulue);
void erreur(char *message);
void lire_Utile(void);
int Reconnaitre_ParentheseOuvrante(int uniteCourante);
int Reconnaitre_Nombre(int uniteCourante);
int Reconnaitre_ParentheseFermante(int uniteCourante);
int Reconnaitre_Operateurmultiplicatif(int uniteCourante);
int Reconnaitre_Operateuradditif(int uniteCourante);
// Structure de la pile
typedef struct {
    int top;
    double elementpile[100];
} Stack;

// Fonctions de la pile
void initialize(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, double value);
double pop(Stack *s);

// Fonction pour évaluer une expression
double evaluateExpression(char *expression);
double evaluateExpressiondgmultiplicatif(char *expression);

// Fonction pour vérifier la priorité des opérateurs
int precedence(char op);
#include "Fonction.h"
