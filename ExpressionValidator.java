import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ExpressionValidator {

    // Expression régulière pour un nombre
    public static String regexNombre() {
        return "[0-9]{1,}"; // \\d correspond à un chiffre, \\. correspond à un point littéral
    }

    // Expression régulière pour un facteur (nombre ou parenthèses)
    public static String regexFacteur() {
        return regexNombre() + "|\\(([^()]+)\\)"; // Un nombre ou une expression entre parenthèses
    }

    // Expression régulière pour un terme (facteurs avec multiplication ou division)
    public static String regexTerme() {
        return regexFacteur() + "(\\s*[\\*/]\\s*" + regexFacteur() + ")*"; // Facteurs reliés par * ou /
    }

    // Expression régulière pour une expression (termes avec addition ou soustraction)
    public static String regexExpression() {
        return regexTerme() + "(\\s*[\\+\\-]\\s*" + regexTerme() + ")*"; // Termes reliés par + ou -
    }

    // Vérifier la validité de l'expression
    public static boolean finExpressionVerification(String expression) {
        String regexExpression = "^" + regexExpression() + "$"; // L'expression doit correspondre à toute la ligne
        Pattern pattern = Pattern.compile(regexExpression);
        Matcher matcher = pattern.matcher(expression);
        if (matcher.matches()) {
            System.out.println("Expression Valide : " + expression);
            return true;
        } else {
            System.out.println("Expression Invalide : " + expression);
            return false;
        }
    }

    public static void main(String[] args) {
        // Exemples d'utilisation :
        String expression1 = "3+5*125/7-6+10";
        String expression2 = "(47*8)*58-8";
        String expression3 = "2++7";
        String expression4 = "3+5*125/7-6+10=";
        String expression5 = "+3+5*125/7-6+10=";

        finExpressionVerification(expression1);
        finExpressionVerification(expression2);
        finExpressionVerification(expression3);
        finExpressionVerification(expression4);
        finExpressionVerification(expression5);
    }
}

/*
 * 
 * Séquences d'échappement courantes
\\s :

Correspond à n'importe quel caractère d'espacement (espace, tabulation, nouvelle ligne, retour chariot, etc.).
Exemple : "\\s+" correspond à un ou plusieurs espaces.
\\d :

Correspond à n'importe quel chiffre (équivalent à [0-9]).
Exemple : "\\d+" correspond à un ou plusieurs chiffres.
\\w :

Correspond à n'importe quel caractère de mot (lettres, chiffres, et underscore _, équivalent à [a-zA-Z0-9_]).
Exemple : "\\w+" correspond à un ou plusieurs caractères de mot.
\\S :

Correspond à n'importe quel caractère qui n'est pas un espace.
Exemple : "\\S+" correspond à une séquence de caractères non espacés.
\\D :

Correspond à n'importe quel caractère qui n'est pas un chiffre.
Exemple : "\\D+" correspond à une séquence de caractères non numériques.
\\W :

Correspond à n'importe quel caractère qui n'est pas un caractère de mot.
Exemple : "\\W+" correspond à une séquence de caractères non alphanumériques.
\\b :

Correspond à une limite de mot (la position entre un caractère de mot et un caractère non mot).
Exemple : "\\bword\\b" correspond exactement au mot "word".
\\B :

Correspond à une position qui n'est pas une limite de mot.
Exemple : "\\Bword\\B" ne correspond à "word" que s'il est entouré de caractères de mot.
 */
