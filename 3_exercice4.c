#include <stdio.h>
#include <stdlib.h>

typedef struct Maillon {
    int valeur;
    struct Maillon* suivant;
} Maillon;

typedef Maillon* Liste;

// Fonction pour ajouter un élément en FIN de liste (utile pour construire les listes A et B)
void InsererEnFin(Liste* L, int val) {
    Maillon* nouveau = (Maillon*)malloc(sizeof(Maillon));
    nouveau->valeur = val;
    nouveau->suivant = NULL;

    if (*L == NULL) {
        *L = nouveau;
    } else {
        Maillon* temp = *L;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }
}

void AfficherListe(Liste L) {
    Maillon* temp = L;
    while (temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

// EXERCICE 4 : Fonction de fusion
Liste FusionAlternance(Liste A, Liste B) {
    if (A == NULL) return B;
    if (B == NULL) return A;

    Liste C = A; // La nouvelle liste commence par le premier élément de A
    Maillon* courantA = A;
    Maillon* courantB = B;

    while (courantA != NULL && courantB != NULL) {
        Maillon* tempA = courantA->suivant; // On sauvegarde le reste de A
        Maillon* tempB = courantB->suivant; // On sauvegarde le reste de B

        courantA->suivant = courantB; // On accroche B1 après A1

        if (tempA != NULL) {
            courantB->suivant = tempA; // On accroche A2 après B1
        }
        
        courantA = tempA; // On avance dans A
        courantB = tempB; // On avance dans B
    }
    
    return C;
}

// Programme de test
int main() {
    Liste listeA = NULL;
    Liste listeB = NULL;

    // Remplissage de la liste A (ex: 5 éléments)
    for (int i = 1; i <= 5; i++) {
        InsererEnFin(&listeA, i * 10); // 10, 20, 30, 40, 50
    }

    // Remplissage de la liste B (ex: 3 éléments)
    for (int i = 1; i <= 3; i++) {
        InsererEnFin(&listeB, i); // 1, 2, 3
    }
    
    printf("--- TD3 - EXERCICE 4 : Fusion de deux listes ---\n");
    printf("Liste A : ");
    AfficherListe(listeA);
    printf("Liste B : ");
    AfficherListe(listeB);

    Liste listeC = FusionAlternance(listeA, listeB);

    printf("\nListe fusionnee C : ");
    AfficherListe(listeC);

    return 0;
}