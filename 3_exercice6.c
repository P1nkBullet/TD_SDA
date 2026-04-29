#include <stdio.h>
#include <stdlib.h>

// La structure d'un élément de la pile est la même qu'un maillon de liste
typedef struct ElementPile {
    int valeur;
    struct ElementPile* suivant;
} ElementPile;

// Une Pile est un pointeur vers le sommet
typedef ElementPile* Pile;

// Fonction pour empiler (push)
void push(Pile* P, int val) {
    ElementPile* nouveau = (ElementPile*)malloc(sizeof(ElementPile));
    nouveau->valeur = val;
    nouveau->suivant = *P;
    *P = nouveau;
}

// Fonction pour dépiler (pop)
int pop(Pile* P) {
    if (*P == NULL) {
        printf("Erreur : la pile est vide.\n");
        return -1; // Valeur d'erreur
    }
    ElementPile* temp = *P;
    int valeur_retournee = temp->valeur;
    *P = temp->suivant;
    free(temp);
    return valeur_retournee;
}

void AfficherPile(Pile P) {
    ElementPile* temp = P;
    printf("Sommet -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

// La procédure PairImpair de l'exercice
void PairImpair(Pile* P1) {
    Pile P2 = NULL; // Pairs
    Pile P3 = NULL; // Impairs

    // 1. Vider P1 et trier dans P2 et P3
    while (*P1 != NULL) {
        int val = pop(P1);
        if (val % 2 == 0) {
            push(&P2, val);
        } else {
            push(&P3, val);
        }
    }

    // 2. Vider P3 (impairs) dans P1 (qui sera notre pile finale)
    while (P3 != NULL) {
        push(P1, pop(&P3));
    }
    
    // 3. Vider P2 (pairs) dans P1. Les pairs arrivent au sommet, donc "en dessous" des impairs.
    while (P2 != NULL) {
        push(P1, pop(&P2));
    }
}

int main() {
    Pile P1 = NULL;
    for (int i = 1; i <= 10; i++) {
        push(&P1, i);
    }
    
    printf("--- TD3 - EXERCICE 6 : Piles ---\n");
    printf("Pile P1 initiale : ");
    AfficherPile(P1);

    PairImpair(&P1);

    printf("Pile P1 apres PairImpair (pairs en dessous des impairs) : \n");
    AfficherPile(P1);

    return 0;
}