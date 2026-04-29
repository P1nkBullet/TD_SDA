#include <stdio.h>

// 1. Fonction récursive "puissance" simple
long puissance_simple(int a, int i) {
    if (i == 0) {
        return 1;
    }
    return a * puissance_simple(a, i - 1);
}
// Complexité : T(i) = T(i-1) + 1 => O(i) multiplications.

// 2. Fonction récursive "exponentiation rapide"
long puissance_rapide(int a, int i) {
    if (i == 0) {
        return 1;
    }
    if (i % 2 == 0) { // Si i est pair
        long temp = puissance_rapide(a, i / 2);
        return temp * temp;
    } else { // Si i est impair
        return a * puissance_rapide(a, i - 1);
    }
}
// Complexité : T(i) = T(i/2) + 1 => O(log i) multiplications.

// Programme principal de test
int main() {
    int a = 2;
    int i = 10;

    printf("--- TD2 - EXERCICE 3 : Puissance récursive ---\n\n");
    printf("Calcul de %d^%d :\n", a, i);

    long resultat_simple = puissance_simple(a, i);
    printf("Avec la methode simple : %ld\n", resultat_simple);

    long resultat_rapide = puissance_rapide(a, i);
    printf("Avec l'exponentiation rapide : %ld\n", resultat_rapide);

    return 0;
}