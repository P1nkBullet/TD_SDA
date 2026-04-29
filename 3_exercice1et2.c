#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// La structure d'un maillon 
typedef struct Maillon {
    int valeur;
    struct Maillon* suivant;
} Maillon;

// La tête de liste est un pointeur vers le premier maillon
typedef Maillon* Liste;

// Fonction pour insérer un élément en tete de liste
// On prend un pointeur sur la liste (**L) pour pouvoir la modifier
void InsererEnTete(Liste* L, int val) {
    // 1. On crée le nouveau maillon
    Maillon* nouveau = (Maillon*)malloc(sizeof(Maillon));
    if (nouveau == NULL) {
        exit(1); // Erreur d'allocation
    }
    
    // 2. On remplit le nouveau maillon
    nouveau->valeur = val;
    
    // 3. Le "suivant" du nouveau est l'ancienne tete de liste
    nouveau->suivant = *L;
    
    // 4. La nouvelle tete de liste devient notre nouveau maillon
    *L = nouveau;
}

// Fonction pour afficher la liste
void AfficherListe(Liste L) {
    Maillon* temp = L;
    while (temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

// EXERCICE 2 : Fonction qui recherche une valeur (retourne 1 si trouvée, 0 sinon)
int RechercherValeur(Liste L, int val_recherchee) {
    Maillon* temp = L;
    while (temp != NULL) {
        if (temp->valeur == val_recherchee) {
            return 1; // Trouvé !
        }
        temp = temp->suivant; // On passe au wagon suivant
    }
    return 0; // Pas trouvé
}

// Programme de test
int main() {
    srand(time(NULL));
    
    // EXERCICE 1 : Créer une liste de 10 éléments aléatoires
    Liste ma_liste = NULL; // Une liste vide au début
    
    printf("--- TD3 - EXERCICE 1 : Création d'une liste ---\n");
    for (int i = 0; i < 10; i++) {
        InsererEnTete(&ma_liste, rand() % 100);
    }
    
    printf("Liste creee : ");
    AfficherListe(ma_liste);
    printf("Complexite de la creation (100 elements) : O(100) -> O(n)\n\n");
    
    // EXERCICE 2 : Tester la recherche
    printf("--- TD3 - EXERCICE 2 : Recherche de valeur ---\n");
    int val = 50;
    printf("Recherche de la valeur %d dans la liste...\n", val);
    
    if (RechercherValeur(ma_liste, val)) {
        printf("Resultat : La valeur %d a ete trouvee.\n", val);
    } else {
        printf("Resultat : La valeur %d n'est pas dans la liste.\n", val);
    }
    printf("Complexite de la recherche (pire cas) : O(n)\n");
    
    return 0;
}