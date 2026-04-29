#include <stdio.h>

// On définit une taille pour notre tableau de test
#define N 10

/*
 * Fonction qui recherche l'indice de la PREMIERE occurrence
 * d'un élément minimal dans un tableau.
 */
int indicePremierMinimum(int tableau[], int taille) {
    // On suppose que la taille est au moins 1
    if (taille <= 0) {
        return -1; // Erreur, tableau vide
    }

    int indice_min = 0; // On suppose que le premier élément est le minimum

    // On parcourt le reste du tableau à partir du deuxième élément
    for (int i = 1; i < taille; i++) {
        // Si on trouve un élément STRICTEMENT plus petit,
        // il devient notre nouveau minimum.
        if (tableau[i] < tableau[indice_min]) {
            indice_min = i;
        }
    }
    // En ne mettant pas "<=", on s'assure de toujours garder l'indice
    // de la PREMIERE occurrence en cas d'égalité.

    return indice_min;
}

/*
 * Complexité :
 * - Initialisation de 'indice_min' : 1 opération.
 * - La boucle for s'exécute (taille - 1) fois.
 * - À chaque tour de boucle, on fait : 1 comparaison ('i < taille'), 1 comparaison ('tableau[i] < ...'),
 *   1 incrémentation (`i++`), et potentiellement 1 affectation (`indice_min = i`).
 * Le nombre d'opérations est proportionnel à `taille`.
 * La complexité est donc linéaire : O(n), où n est la taille du tableau.
 */

// Programme principal de test
int main() {
    // L'exemple donné dans l'énoncé
    int tableau_test[N] = {5, 2, 4, 2, 1, 7, 9, 4, 1, 1};
    // L'élément minimal est 1. Sa première occurrence est à l'indice 4.

    printf("--- TD2 - EXERCICE 1 : Indice du premier minimum ---\n\n");
    printf("Tableau : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", tableau_test[i]);
    }
    printf("\n");

    int indice = indicePremierMinimum(tableau_test, N);

    printf("L'element minimal est %d.\n", tableau_test[indice]);
    printf("L'indice de sa premiere occurrence est : %d\n", indice);

    return 0;
}