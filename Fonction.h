    //Variable Globale
    int uniteCourante;
    int uniteCouranteavant ;// Pour la division par zero et la detection de parenthese vide 45/0 ou ()
    int uniteCourantemoins2; //2 caracteres pour la verification de 45/(0)
    char *calu;
    int calunultornot=0;
    int Parenthesefermante=0;
    int ParentheseOuvrante=0;
    int nombreLu=0;
    size_t taille = 0; // Taille initiale du tableau
    //¨Fonction pour recopier l'expression

    //Variable Globale
    void expression(void) {
    terme();
    }
    void terme(void) {
        facteur();
    }
    void facteur(void) {
        if (uniteCourante!='=')
        {
            calu = realloc(calu, (taille + 1) * sizeof(char)); // Réallouer de la mémoire pour augmenter la taille du tableau
            if (calu == NULL) {
                exit(EXIT_FAILURE);
            }
            calu[taille++] = uniteCourante; // Stocker le caractère lu dans la nouvelle case du tableau
        }
        if (Reconnaitre_Nombre(uniteCourante)){
            terminal(uniteCourante);//terminal(2)
        }

        else{
            if (uniteCouranteavant==')'){
                terminal(uniteCourante);
            }
            else{
                if(uniteCourante=='='){
                    printf("Au moins un operateur {+;-;/,*} avec =\n");
                    printf("Mauvaise Expression\n");
                    calunultornot=1;
                    calu=NULL;
                    return;
                }
                terminal(uniteCourante); // terminal(()
            }
        }
    }
        void terminal(int uniteVoulue) {//2
            if (isdigit(uniteVoulue)) {
                int i = 1;
                nombreLu = (uniteCourante - '0'); // Convertir le caractère en nombre entier
               
                uniteCourante=getchar();
                while (isdigit(uniteCourante)) {
                    calu = realloc(calu, (taille + 1) * sizeof(char)); // Réallouer de la mémoire pour augmenter la taille du tableau
                    if (calu == NULL) {
                        exit(EXIT_FAILURE);
                    }
                    calu[taille++] = uniteCourante; // Stocker le caractère lu dans la nouvelle case du tableau
                    nombreLu = nombreLu * 10 + (uniteCourante - '0'); // Ajouter le chiffre à nombreLu
                    uniteCourante = getchar();
                    if (uniteCourante=='.'){
                        printf("Nombre avec des virgules ne sont pas consideres\n Mauvaise Expression\n");
                        return;
                    }
                    i++;
                }
                // 4587587              
                if (uniteCouranteavant=='/' && nombreLu==0){
                    printf("Mauvaise Expression\n");
                    calu=NULL;
                    calunultornot=1;
                    return;
                }
                if (uniteCourante=='\n' || uniteCourante==' '){
                    lire_Utile();
                }


                if (uniteCourante=='='){
                    fin_expression(1,1,0);
                }
                else if(isdigit(uniteCourante)){
                    printf("Mauvaise Expression\n");
                    calunultornot=1;
                    calu=NULL;
                    //p("Il doit y avoir un operateur apres un nombre\n");
                    return;
                }
                else{
                    //p("1,0,0\n");   
                    calu = realloc(calu, (taille + 1) * sizeof(char)); // Réallouer de la mémoire pour augmenter la taille du tableau
                if (calu == NULL) {
                    //p("Erreur d'allocation de mémoire.\n");
                    exit(EXIT_FAILURE);
                }
                calu[taille++] = uniteCourante; // Stocker le caractère lu dans la nouvelle case du tableau                 
                    fin_expression(1,0,0);
                }
            }
            else{
                if (uniteCourante=='('){
                    uniteCourante=getchar();
                    if (uniteCourante=='\n' || uniteCourante==' '){
                        lire_Utile();
                    }
                    fin_expression(0,0,1);
                }

                if (uniteCourante==')'){
                    if (uniteCouranteavant=='('){
                        printf("Mauvaise Expression\n");
                        calunultornot=1;
                        calu=NULL;
                        printf("Parenthese Vide!\n");
                        return;
                    }
                    else{
                        uniteCouranteavant=uniteCourante;
                        fin_expression(0,0,0);
                    } 
                }


                else if (uniteCourante=='='){
                    fin_expression(0,1,0);
                }  


                else if(Reconnaitre_Operateuradditif(uniteCourante) || Reconnaitre_Operateurmultiplicatif(uniteCourante)){
                    fin_expression(1,0,0);                
                }

                else{
                    printf("Mauvaise Expression\n");
                    calu=NULL;
                                        calunultornot=1;
                    printf("Caractere(s) Non autorise!\n");
                    return;
                }

            }
        }
    void erreur(char *message) {
    }

    void fin_expression(bool numberbefore,bool symbole_egal,bool parentheseouvrante) {
        if (symbole_egal){ //..,1,....
            if (ParentheseOuvrante<Parenthesefermante){
                printf("Fin de toute l'expression\n");                    
                printf("Mauvaise Expression Parenthese de fin supérieur\n");
                calunultornot=1;
                calu=NULL;
                return;
            }
            else{
                if (ParentheseOuvrante>=Parenthesefermante){
                    if (Parenthesefermante==ParentheseOuvrante){
                        printf("Fin de toute l'expression\n");                    
                        printf("Bonne Expression!\n");
                        calu = realloc(calu, (taille + 1) * sizeof(char));
                        if (calu == NULL) {
                            exit(EXIT_FAILURE);
                        }
                        calu[taille] = '\0'; // Terminer la chaîne de caractères avec le caractère nul
                        calunultornot=0;
                        return;
                    }
                    else{
                        printf("Fin de toute l'expression\n");
                        if (ParentheseOuvrante >= Parenthesefermante) {
                            if (Parenthesefermante == ParentheseOuvrante) {
                            printf("Bonne Expression\nLa parenthese non fermee a ete ajoute a la fin!\n",ParentheseOuvrante-Parenthesefermante);

                                calu = realloc(calu, (taille + 1) * sizeof(char));
                                // Vérifiez si l'allocation de mémoire a réussi
                                if (calu == NULL) {
                                    exit(EXIT_FAILURE);
                                }
                                calu[taille] = '\0'; // Terminer la chaîne de caractères avec le caractère nul
                                calunultornot=0;
                                return;
                            } else {
                                // Il y a des parenthèses ouvrantes en excès
                                // Ajoutez des parenthèses fermantes pour équilibrer
                                                                printf("Bonne Expression\nLes %d parentheses non fermees ont ete ajoute a la fin!\n",ParentheseOuvrante-Parenthesefermante);
                                while (ParentheseOuvrante > Parenthesefermante) {
                                    calu = realloc(calu, (taille + 1) * sizeof(char));
                                    if (calu == NULL) {
                                        exit(EXIT_FAILURE);
                                    }
                                    calu[taille++] = ')'; // Ajoutez une parenthèse fermante
                                    calunultornot=0;
                                    Parenthesefermante++; // Mettez à jour le nombre de parenthèses fermantes ajoutées
                                }
                                // Ajoutez le caractère nul et quittez la fonction
                                calu = realloc(calu, (taille + 1) * sizeof(char));
                                if (calu == NULL) {
                                    exit(EXIT_FAILURE);
                                }
                                calu[taille] = '\0'; // Terminer la chaîne de caractères avec le caractère nul
                                return;
                            }
                        }
                    } 
                }   
            } 
        }
        else{
            //symboleegal=0
            if (!numberbefore) {//0,0,.. 
                /*Ici c'est la cas ou si on a un dernier caractere different 
                de = et qui n'est pas un nombre*/
                if (uniteCourante == '=') {
                    printf("Fin de toute l'expression\n");                    
                    printf("Mauvaise Expression!\n");
                    calunultornot=1;
                    calu=NULL;
                        return;
                }
                uniteCourante=getchar();
                if (uniteCourante=='\n' || uniteCourante==' '){
                    lire_Utile();
                }
                if (parentheseouvrante){ // 0,0,1
                    ParentheseOuvrante++;
                    facteur(); 
                }
                else{ // 0,0,0
                    if (uniteCouranteavant==')'){
                        Parenthesefermante++;
                        facteur();
                    }


                    else{
                        if(Reconnaitre_Operateuradditif(uniteCourante) || Reconnaitre_Operateurmultiplicatif(uniteCourante)){
                            printf("Fin de toute l'expression\n");                    
                            printf("Mauvaise Expression avec 2 operateurs cote a cote!\n");
                            calunultornot=1;
                            calu=NULL;
                            return;
                        }
                        facteur(); 
                    }
                }
            } 
            else {//1,0
                if (Reconnaitre_Operateuradditif(uniteCourante)) {
                    uniteCouranteavant=uniteCourante;
                    uniteCourante=getchar();
                    if (uniteCourante=='\n' || uniteCourante==' '){
                        lire_Utile();
                    }
                    else if (Reconnaitre_Operateuradditif(uniteCourante)  || Reconnaitre_Operateurmultiplicatif(uniteCourante)){
                        printf("Mauvaise Expression\n");
                        calu=NULL;
                        printf("Au moins 2 operateurs cote a cote\n");
                        calunultornot=1;
                        return ;
                    }
                    else if(Reconnaitre_ParentheseFermante(uniteCourante)){
                     printf("Mauvaise Expression\n");
                        printf("Un nombre ou une parenthese ouvrante est requis pour continuer!\n");   
                        calu=NULL;
                        calunultornot=1;
                        return;
                    }
                    else if(uniteCourante=='='){
                         printf("Mauvaise Expression\n");
                        printf("Operateur + ou - avec =\n");
                        calu=NULL;
                        calunultornot=1;
                        return;
                    }
                    facteur();
                }
                else if (Reconnaitre_Operateurmultiplicatif(uniteCourante)) {
                    if (uniteCourante=='/'){
                        uniteCourantemoins2=uniteCourante;
                    }                    
                    uniteCourante=getchar();
                    if (uniteCourante=='\n' || uniteCourante==' '){
                        lire_Utile();
                    }
                    else if (Reconnaitre_Operateuradditif(uniteCourante)  || Reconnaitre_Operateurmultiplicatif(uniteCourante)){
                                                printf("Au moins 2 operateurs cote a cote\n");

                        calu=NULL;
                                                printf("Mauvaise Expression\n");
calunultornot=1;
                        return;
                    }
                    else if(Reconnaitre_ParentheseFermante(uniteCourante)){
                        printf("Mauvaise Expression\n");
                        calu=NULL;
                        calunultornot=1;
                        printf("Un nombre ou une parenthese ouvrante est requis pour continuer!\n");
                        return;
                    }
                    facteur();
                }

                else if (uniteCourante == '(') {
                    uniteCouranteavant=uniteCourante;
                    ParentheseOuvrante++;
                    uniteCourante=getchar();
                    if (uniteCourante=='\n' || uniteCourante==' '){
                        lire_Utile();
                    }
                    facteur();
                }
                else{
                    Parenthesefermante++;
                    uniteCouranteavant=uniteCourante;
                    uniteCourante=getchar();
                    if (uniteCourante=='\n' || uniteCourante==' '){
                        lire_Utile();
                    }
                    facteur();
                }
            }
        }  
    }

 


void lire_Utile(void) {
    int caractere = getchar();    
    while (isspace(caractere)) {
        caractere = getchar();
    }
    uniteCourante = caractere;
    //   /
}







int Reconnaitre_Nombre(int uniteCourante) {
    if (isdigit(uniteCourante)) {
        return 1; // Si c'est un nombre, retourne 1 (vrai)
    } else {
        return 0; // Si ce n'est pas un nombre, retourne 0 (faux)
    }
}

int Reconnaitre_ParentheseOuvrante(int uniteCourante) {
    if (uniteCourante=='(') {
        return 1; // Si c'est (, retourne 1 (vrai)
    } else {
        return 0; // Si ce n'est (, retourne 0 (faux)
    }
}


int Reconnaitre_ParentheseFermante(int uniteCourante) {
    if (uniteCourante==')') {
        return 1; // Si c'est ), retourne 1 (vrai)
    } else {
        return 0; // Si ce n'est pas ), retourne 0 (faux)
    }
}

int Reconnaitre_Operateuradditif(int uniteCourante) {
    if (uniteCourante=='+' || uniteCourante=='-') {
        return 1; // Si c'est + ou -, retourne 1 (vrai)
    } else {
        return 0; // Si ce n'est pas + ou -, retourne 0 (faux)
    }
}

int Reconnaitre_Operateurmultiplicatif(int uniteCourante) {
    if (uniteCourante=='*' || uniteCourante=='/') {
        return 1; // Si c'est + ou -, retourne 1 (vrai)
    } else {
        return 0; // Si ce n'est pas + ou -, retourne 0 (faux)
    }
}





// Déclaration de la fonction precedence

// Fonctions de la pile
void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == 99;
}

void push(Stack *s, double value) {
    if (!isFull(s)) {
        s->elementpile[++(s->top)] = value;
    } else {
        //p("Expression Trop Longue!\n");
        exit(EXIT_FAILURE);
    }
}
// Définition de la fonction precedence
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // Pour les parenthèses
}

double pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->elementpile[(s->top)--];
    } else {
        //p("Expression Trop Longue!\n");
        exit(EXIT_FAILURE);
    }
}

// Fonction pour évaluer une expression
// Fonction pour évaluer une expression
double evaluateExpressiondgmultiplicatif(char *expression){    
    Stack Pileoperande;
    Stack Pileoperateur;
    initialize(&Pileoperande);
    initialize(&Pileoperateur);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            // Si le caractère est un chiffre, convertissez-le en nombre et empilez-le
            double operand = expression[i] - '0';
            while (isdigit(expression[i + 1])) {
                operand = operand * 10 + (expression[++i] - '0');
            }
            push(&Pileoperande, operand);
        } else if (expression[i] == '(') {
            // Si le caractère est une parenthèse ouvrante, empilez-la
            push(&Pileoperateur, expression[i]);
        } else if (expression[i] == ')') {
            // Si le caractère est une parenthèse fermante, évaluez les opérations à l'intérieur des parenthèses
            while (!isEmpty(&Pileoperateur) && Pileoperateur.elementpile[Pileoperateur.top] != '(') {
                char op = pop(&Pileoperateur);
                double operand2 = pop(&Pileoperande);
                double operand1 = pop(&Pileoperande);
                switch (op) {
                    case '+':
                        push(&Pileoperande, operand1 + operand2);
                        break;
                    case '-':
                        push(&Pileoperande, operand1 - operand2);
                        break;
                    case '*':
                        push(&Pileoperande, operand1 * operand2);
                        break;
                    case '/':
                        if (operand2 == 0) {
                            //p("Error: Division by zero\n");
                            exit(EXIT_FAILURE);
                        }
                        push(&Pileoperande, operand1 / operand2);
                        break;
                }
            }
            pop(&Pileoperateur); // Dépiler la parenthèse ouvrante correspondante
        } else if (expression[i] == '+' || expression[i] == '-') {
            // Si le caractère est un opérateur de plus ou de moins
            // Évaluez toutes les opérations de multiplication et de division stockées dans la pile d'opérateurs
            while (!isEmpty(&Pileoperateur) && (Pileoperateur.elementpile[Pileoperateur.top] == '*' || Pileoperateur.elementpile[Pileoperateur.top] == '/')) {
                char op = pop(&Pileoperateur);
                double operand2 = pop(&Pileoperande);
                double operand1 = pop(&Pileoperande);
                switch (op) {
                    case '*':
                        push(&Pileoperande, operand1 * operand2);
                        break;
                    case '/':
                        if (operand2 == 0) {
                            //p("Error: Division by zero\n");
                            exit(EXIT_FAILURE);
                        }
                        push(&Pileoperande, operand1 / operand2);
                        break;
                }
            }
            push(&Pileoperateur, expression[i]); // Empilez l'opérateur actuel
        } else if (expression[i] == '*' || expression[i] == '/') {
            // Si le caractère est un opérateur de multiplication ou de division, empilez-le
            push(&Pileoperateur, expression[i]);
        }
    }

    // Évaluez toutes les opérations restantes dans la pile d'opérateurs
    while (!isEmpty(&Pileoperateur)) {
        char op = pop(&Pileoperateur);
        double operand2 = pop(&Pileoperande);
        double operand1 = pop(&Pileoperande);
        switch (op) {
            case '+':
                push(&Pileoperande, operand1 + operand2);
                break;
            case '-':
                push(&Pileoperande, operand1 - operand2);
                break;
            case '*':
                push(&Pileoperande, operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0) {
                    //p("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                push(&Pileoperande, operand1 / operand2);
                break;
        }
    }

    // Le résultat final est le seul élément restant dans la pile des opérandes
    return pop(&Pileoperande);
}



/*int main() {
    char expression[] = "3+5*125/7-6+10";
    double result = evaluateExpression(expression);
    //p("Result: %.2f\n", result);
    return 0;
}*/


double evaluateExpression(char *expression) {
    Stack Pileoperande;
    Stack Pileoperateur;
    initialize(&Pileoperande);
    initialize(&Pileoperateur);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            // Si le caractère est un chiffre, convertissez-le en nombre et empilez-le
            double operand = expression[i] - '0';
            while (isdigit(expression[i + 1])) {
                operand = operand * 10 + (expression[++i] - '0');
            }
            push(&Pileoperande, operand);
        } else if (expression[i] == '(') {
            // Si le caractère est une parenthèse ouvrante, empilez-la
            push(&Pileoperateur, expression[i]);
        } else if (expression[i] == ')') {
            // Si le caractère est une parenthèse fermante, évaluez les opérations à l'intérieur des parenthèses
            while (!isEmpty(&Pileoperateur) && Pileoperateur.elementpile[Pileoperateur.top] != '(') {
                char op = pop(&Pileoperateur);
                double operand2 = pop(&Pileoperande);
                double operand1 = pop(&Pileoperande);
                switch (op) {
                    case '+':
                        push(&Pileoperande, operand1 + operand2);
                        break;
                    case '-':
                        push(&Pileoperande, operand1 - operand2);
                        break;
                    case '*':
                        push(&Pileoperande, operand1 * operand2);
                        break;
                    case '/':
                        if (operand2 == 0) {
                            //p("Error: Division by zero\n");
                            exit(EXIT_FAILURE);
                        }
                        push(&Pileoperande, operand1 / operand2);
                        break;
                }
            }
            pop(&Pileoperateur); // Dépiler la parenthèse ouvrante correspondante
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // Si le caractère est un opérateur
            // Évaluer les opérations à droite jusqu'à ce qu'on rencontre un opérateur de priorité inférieure ou égale
            while (!isEmpty(&Pileoperateur) && precedence(expression[i]) <= precedence(Pileoperateur.elementpile[Pileoperateur.top])) {
                char op = pop(&Pileoperateur);
                double operand2 = pop(&Pileoperande);
                double operand1 = pop(&Pileoperande);
                switch (op) {
                    case '+':
                        push(&Pileoperande, operand1 + operand2);
                        break;
                    case '-':
                        push(&Pileoperande, operand1 - operand2);
                        break;
                    case '*':
                        push(&Pileoperande, operand1 * operand2);
                        break;
                    case '/':
                        if (operand2 == 0) {
                            //p("Error: Division by zero\n");
                            exit(EXIT_FAILURE);
                        }
                        push(&Pileoperande, operand1 / operand2);
                        break;
                }
            }
            push(&Pileoperateur, expression[i]); // Empilez l'opérateur actuel
        }
    }

    // Évaluez les opérations restantes dans les piles
    while (!isEmpty(&Pileoperateur)) {
        char op = pop(&Pileoperateur);
        double operand2 = pop(&Pileoperande);
        double operand1 = pop(&Pileoperande);
        switch (op) {
            case '+':
                push(&Pileoperande, operand1 + operand2);
                break;
            case '-':
                push(&Pileoperande, operand1 - operand2);
                break;
            case '*':
                push(&Pileoperande, operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0) {
                    //p("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                push(&Pileoperande, operand1 / operand2);
                break;
        }
    }

    // Le résultat final est le seul élément restant dans la pile des opérandes
    return pop(&Pileoperande);
}