#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// 1. Définition de la structure Point
typedef struct {
    int x;
    int y;
} Point;

// 2. Fonction pour saisir un point (non utilisée dans le main auto, mais présente pour la consigne)
Point SaisirPoint() {
    Point p;
    printf("Entrez les coordonnées (x y) : ");
    scanf("%d %d", &p.x, &p.y);
    return p;
}

// 3. Fonction pour afficher un point au format (x,y)
void AfficherPoint(Point p) {
    printf("(%d,%d)", p.x, p.y);
}

// 5. Fonction qui calcule la distance d'un point par rapport à l'origine
float DistanceOrigine(Point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

// 6. Fonction qui trie un tableau de points par ordre croissant de distance
void TrierTableauPoints(Point tableau[], int taille) {
    int i, j;
    Point temp;

    for (i = 0; i < taille - 1; i++) {
        for (j = 0; j < taille - i - 1; j++) {
            if (DistanceOrigine(tableau[j]) > DistanceOrigine(tableau[j+1])) {
                temp = tableau[j];
                tableau[j] = tableau[j+1];
                tableau[j+1] = temp;
            }
        }
    }
}

// 7. Programme principal d'essai pour l'Exercice 1
int main() {
    srand(time(NULL)); // Initialisation pour les nombres aléatoires

    printf("--- TEST DE L'EXERCICE 1 : STRUCTURES POINT ---\n\n");

    // 4. Création d'un tableau dynamique de points
    int taille_tableau = 5;
    Point* tableau_points = (Point*) malloc(taille_tableau * sizeof(Point));
    if (tableau_points == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    printf("Tableau de %d points générés aléatoirement :\n", taille_tableau);
    for (int i = 0; i < taille_tableau; i++) {
        tableau_points[i].x = rand() % 20; // x entre 0 et 19
        tableau_points[i].y = rand() % 20; // y entre 0 et 19
        AfficherPoint(tableau_points[i]);
        printf(" -> Distance a l'origine : %.2f\n", DistanceOrigine(tableau_points[i]));
    }

    // Test de la fonction de tri
    TrierTableauPoints(tableau_points, taille_tableau);

    printf("\nTableau trié par distance croissante a l'origine :\n");
    for (int i = 0; i < taille_tableau; i++) {
        AfficherPoint(tableau_points[i]);
        printf(" -> Distance a l'origine : %.2f\n", DistanceOrigine(tableau_points[i]));
    }

    // On n'oublie pas de libérer la mémoire :
    free(tableau_points);
    
    printf("\n--- FIN DU TEST DE L'EXERCICE 1 ---\n");

    return 0;
}