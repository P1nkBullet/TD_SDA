#include <stdio.h>
#include <limits.h> // Pour INT_MAX

// Dimensions de la matrice de test
#define N 3 // nombre de lignes
#define M 3 // nombre de colonnes

/*
 * Fonction qui calcule le MiniMax d'une matrice :
 * le minimum des maximums de chaque ligne.
 */
int miniMax(int matrice[N][M]) {
    int min_des_max = INT_MAX; // On initialise au plus grand entier possible

    // 1. On parcourt chaque ligne
    for (int i = 0; i < N; i++) {
        // 2. Pour chaque ligne, on trouve son maximum
        int max_de_la_ligne = matrice[i][0];
        for (int j = 1; j < M; j++) {
            if (matrice[i][j] > max_de_la_ligne) {
                max_de_la_ligne = matrice[i][j];
            }
        }

        // 3. On met à jour le minimum des maximums
        if (max_de_la_ligne < min_des_max) {
            min_des_max = max_de_la_ligne;
        }
    }

    return min_des_max;
}

/*
 * Complexité :
 * - On a deux boucles imbriquées.
 * - La boucle externe (sur les lignes) s'exécute N fois.
 * - La boucle interne (sur les colonnes) s'exécute M fois pour chaque ligne.
 * - Le nombre total d'opérations est proportionnel à N * M.
 * La complexité est donc O(n*m).
 */

// Programme principal de test
int main() {
    int matrice_test[N][M] = {
        {7, 9, 3},  // max = 9
        {5, 2, 8},  // max = 8
        {6, 4, 1}   // max = 6
    };
    // Les maximums sont 9, 8, 6. Le minimum de ces valeurs est 6.

    printf("--- TD2 - EXERCICE 2 : MiniMax d'une matrice ---\n\n");

    printf("Matrice :\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrice_test[i][j]);
        }
        printf("\n");
    }

    int resultat = miniMax(matrice_test);
    printf("\nLa valeur MiniMax de la matrice est : %d\n", resultat);

    return 0;
}