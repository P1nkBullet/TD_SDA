#include <stdio.h>
#include <stdlib.h> // Pour la fonction abs()

// Définition de la structure Heure
typedef struct {
    int hh; // heures
    int mm; // minutes
    int ss; // secondes
} Heure;

// 1. Conversion d'une Heure en nombre total de secondes
int HeureVersSecondes(Heure h) {
    return h.hh * 3600 + h.mm * 60 + h.ss;
}

// 2. Conversion d'un nombre de secondes en une Heure
Heure SecondesVersHeure(int total_secondes) {
    Heure h;
    h.hh = total_secondes / 3600;
    total_secondes = total_secondes % 3600;
    h.mm = total_secondes / 60;
    h.ss = total_secondes % 60;
    return h;
}

// 3. Addition de deux Heures
Heure AdditionHeures(Heure h1, Heure h2) {
    int total_secondes = HeureVersSecondes(h1) + HeureVersSecondes(h2);
    return SecondesVersHeure(total_secondes);
}

// 4. Différence (durée) entre deux Heures
Heure DifferenceHeures(Heure h1, Heure h2) {
    // abs() renvoie la valeur absolue, pour que la durée soit toujours positive
    int diff_secondes = abs(HeureVersSecondes(h1) - HeureVersSecondes(h2));
    return SecondesVersHeure(diff_secondes);
}


// Programme principal d'essai pour l'Exercice 2
int main() {
    printf("--- TEST DE L'EXERCICE 2 : STRUCTURES HEURE ---\n\n");

    Heure heure1 = {10, 30, 15};
    Heure heure2 = {2, 45, 50};
    
    printf("Heure 1 : %02d:%02d:%02d\n", heure1.hh, heure1.mm, heure1.ss);
    printf("Heure 2 : %02d:%02d:%02d\n", heure2.hh, heure2.mm, heure2.ss);

    // Test conversion
    int secondes_h1 = HeureVersSecondes(heure1);
    printf("\nTest de conversion : Heure 1 equivaut a %d secondes.\n", secondes_h1);

    // Test addition
    Heure somme = AdditionHeures(heure1, heure2);
    printf("Test d'addition : H1 + H2 = %02d:%02d:%02d\n", somme.hh, somme.mm, somme.ss);

    // Test différence
    Heure difference = DifferenceHeures(heure1, heure2);
    printf("Test de difference : Duree entre H1 et H2 = %02d:%02d:%02d\n", difference.hh, difference.mm, difference.ss);
    
    printf("\n--- FIN DU TEST DE L'EXERCICE 2 ---\n");

    return 0;
}