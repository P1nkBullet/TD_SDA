#include <stdio.h>
#include <stdlib.h>

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

// EXERCICE 5 : Fonction de destruction
void DetruireListe(Liste* L) {
    Maillon* courant = *L;
    Maillon* suivant;

    while (courant != NULL) {
        suivant = courant->suivant; // On sauvegarde l'adresse du prochain
        free(courant);              // On détruit le maillon actuel
        courant = suivant;          // On passe au suivant
    }

    *L = NULL; // Important: la liste est maintenant vide
}

// Programme de test
int main() {
    Liste ma_liste = NULL;
    for (int i = 0; i < 10; i++) {
        InsererEnTete(&ma_liste, i);
    }
    
    printf("--- TD3 - EXERCICE 5 : Destruction d'une liste ---\n");
    printf("Liste avant destruction : ");
    AfficherListe(ma_liste);

    DetruireListe(&ma_liste);

    printf("Liste apres destruction : ");
    AfficherListe(ma_liste); // Devrait afficher "NULL"

    if (ma_liste == NULL) {
        printf("La liste a bien ete detruite.\n");
    }

    return 0;
}