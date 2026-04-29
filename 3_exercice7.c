#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Définitions pour la PILE de caractères ---
typedef struct ElementPile {
    char valeur;
    struct ElementPile* suivant;
} ElementPile;
typedef ElementPile* Pile;

void push(Pile* P, char val) {
    ElementPile* nouveau = (ElementPile*)malloc(sizeof(ElementPile));
    nouveau->valeur = val;
    nouveau->suivant = *P;
    *P = nouveau;
}
char pop(Pile* P) {
    if (*P == NULL) return '\0';
    ElementPile* temp = *P;
    char val = temp->valeur;
    *P = temp->suivant;
    free(temp);
    return val;
}

// --- Définitions pour la FILE de caractères ---
typedef struct ElementFile {
    char valeur;
    struct ElementFile* suivant;
} ElementFile;

typedef struct {
    ElementFile* debut;
    ElementFile* fin;
} File;

void initialiserFile(File* F) {
    F->debut = NULL;
    F->fin = NULL;
}

void enfiler(File* F, char val) {
    ElementFile* nouveau = (ElementFile*)malloc(sizeof(ElementFile));
    nouveau->valeur = val;
    nouveau->suivant = NULL;
    if (F->fin == NULL) { // File vide
        F->debut = F->fin = nouveau;
    } else {
        F->fin->suivant = nouveau;
        F->fin = nouveau;
    }
}

char defiler(File* F) {
    if (F->debut == NULL) return '\0';
    ElementFile* temp = F->debut;
    char val = temp->valeur;
    F->debut = temp->suivant;
    if (F->debut == NULL) {
        F->fin = NULL;
    }
    free(temp);
    return val;
}

// --- Fonctions de l'exercice ---

// Stocke un message dans une file
void EcrireMessageDansFile(File* F, const char* message) {
    for (int i = 0; message[i] != '\0'; i++) {
        enfiler(F, message[i]);
    }
}

// Vérifie si le message est un palindrome
int EstPalindrome(const char* message) {
    File F;
    Pile P;
    initialiserFile(&F);
    P = NULL;

    // 1. Mettre tous les caractères dans la file ET dans la pile
    for (int i = 0; message[i] != '\0'; i++) {
        enfiler(&F, message[i]);
        push(&P, message[i]);
    }

    // 2. Comparer les éléments un par un
    // On défile de la file (ordre normal)
    // On dépile de la pile (ordre inverse)
    while (F.debut != NULL) {
        char char_file = defiler(&F);
        char char_pile = pop(&P);
        if (char_file != char_pile) {
            return 0; // Ce n'est pas un palindrome
        }
    }

    return 1; // C'est un palindrome
}


int main() {
    printf("--- TD3 - EXERCICE 7 : Files et Palindromes ---\n\n");
    
    const char* mot1 = "radar";
    const char* mot2 = "bonjour";
    
    printf("Le mot '%s' est-il un palindrome ?\n", mot1);
    if (EstPalindrome(mot1)) {
        printf("Resultat : OUI\n\n");
    } else {
        printf("Resultat : NON\n\n");
    }

    printf("Le mot '%s' est-il un palindrome ?\n", mot2);
    if (EstPalindrome(mot2)) {
        printf("Resultat : OUI\n");
    } else {
        printf("Resultat : NON\n");
    }

    return 0;
}