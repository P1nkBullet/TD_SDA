#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct Maillon {
    int valeur;
    struct Maillon* suivant;
} Maillon;

typedef Maillon* Liste;

void InsererEnTete(Liste* L, int val) {
    Maillon* nouveau = (Maillon*)malloc(sizeof(Maillon));
    nouveau->valeur = val;
    nouveau->suivant = *L;
    *L = nouveau;
}

void AfficherListe(Liste L) {
    Maillon* temp = L;
    while (temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

// Supprimer le maillon avec la valeur minimale
void SupprimerMinimum(Liste* L) {
    if (*L == NULL) return; // Liste vide, rien à faire

    Maillon *courant = *L, *precedent = NULL;
    Maillon *min_maillon = *L, *precedent_min = NULL;
    int min_valeur = (*L)->valeur;

    // 1. Trouver le maillon minimum et son précédent
    while (courant != NULL) {
        if (courant->valeur < min_valeur) {
            min_valeur = courant->valeur;
            min_maillon = courant;
            precedent_min = precedent;
        }
        precedent = courant;
        courant = courant->suivant;
    }

    // 2. Supprimer le maillon minimum
    if (precedent_min == NULL) { // Le minimum est en tête de liste
        *L = min_maillon->suivant;
    } else { // Le minimum est au milieu ou à la fin
        precedent_min->suivant = min_maillon->suivant;
    }
    
    free(min_maillon); // Libérer la mémoire du maillon supprimé
}

// Programme de test
int main() {
    srand(time(NULL));
    Liste ma_liste = NULL;
    for (int i = 0; i < 10; i++) {
        InsererEnTete(&ma_liste, rand() % 100);
    }

    printf("--- TD3 - EXERCICE 3 : Suppression du minimum ---\n");
    printf("Liste avant suppression : ");
    AfficherListe(ma_liste);

    SupprimerMinimum(&ma_liste);

    printf("Liste apres suppression du minimum : ");
    AfficherListe(ma_liste);
    printf("Complexite : Recherche du min (O(n)) + Suppression (O(1)) = O(n)\n");
    
    return 0;
}