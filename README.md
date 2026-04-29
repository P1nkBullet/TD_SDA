
## TD1 : Les structures
*   **Utilisation des structures** : Elles permettent de regrouper des données de types différents sous un même nom. C'est une abstraction qui facilite la manipulation d'objets complexes (comme un point ou une heure) dans le code.
*   **Tableaux statiques vs dynamiques** : 
    *   Les tableaux statiques ont une taille fixée à la compilation. La mémoire est allouée automatiquement sur la pile (*stack*).
    *   Les tableaux dynamiques sont alloués durant l'exécution via `malloc`. La mémoire est prise sur le tas (*heap*), ce qui permet d'adapter la taille au besoin réel de l'utilisateur.
*   **Passage par valeur vs adresse** :
    *   Passer une structure par valeur crée une copie complète en mémoire.
    *   Passer une structure par adresse (pointeur) évite la copie, économise la mémoire et permet à la fonction d'agir directement sur les données originales.

## TD2 : Complexité et Récursivité
*   **Exercice 1 (Recherche de min)** : La complexité est en O(n). L'algorithme parcourt le tableau une seule fois, effectuant un nombre d'opérations proportionnel à la taille n du tableau.
*   **Exercice 2 (MiniMax matrice)** : La complexité est en O(n*m). Il faut parcourir chaque ligne (n) et chaque colonne (m) pour trouver le maximum local de chaque ligne, puis le minimum de ces maximums.
*   **Exercice 3 (Puissance)** : 
    *   La fonction récursive classique est en O(n), car elle effectue n appels pour calculer la puissance.
    *   L'exponentiation rapide est en O(ln n), car à chaque étape, on réduit l'exposant de moitié, ce qui diminue drastiquement le nombre d'opérations.
*   **Exercice 4 (Fonctions récursives)** :
    *   `rec1` calcule $2^n$ avec une complexité linéaire O(n).
    *   `rec2` effectue un nombre d'additions qui double à chaque appel, menant à une complexité exponentielle O(2^n).

## TD3 : Listes, Piles et Files
*   **Complexité des listes** :
    *   L'insertion en tête de liste est en O(1), car elle ne dépend pas du nombre d'éléments.
    *   La recherche d'une valeur ou la suppression d'un élément (comme le minimum) est en O(n), car dans le pire des cas, il faut examiner chaque nœud de la liste.
*   **Définitions clés** :
    *   **Pile (Stack)** : Structure LIFO (*Last In, First Out*). Le dernier élément entré est le premier sorti. Utile pour les algorithmes récursifs ou les annulations (*undo*).
    *   **File (Queue)** : Structure FIFO (*First In, First Out*). Le premier entré est le premier sorti. Indispensable pour la gestion de tâches en attente.
    *   **Palindrome** : Pour détecter un palindrome, on peut enfiler tous les caractères dans une file et les empiler dans une pile. En vidant les deux, on compare l'ordre original (file) avec l'ordre inversé (pile). S'ils correspondent, le mot est un palindrome.
