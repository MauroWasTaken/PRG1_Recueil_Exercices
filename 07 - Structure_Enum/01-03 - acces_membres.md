# struct - accès aux membres
Soient les déclarations ci-dessous.

~~~cpp
struct Coord {
   int x, y, z;
};

struct Cercle {
   int   rayon;
   Coord centre;
};

const Coord origine = {0, 0, 0};
Cercle cercle = {1, {2, 3, 4}};
Cercle* ptr = &cercle;
~~~

Les instructions sont-elles correctes ?

1. `cout << cercle.rayon;`
- oui
2. `cout << cercle->rayon;`
- non
3. `cout << *(&cercle).rayon;`
- non
4. `cercle.centre = origine;`
- oui
5. `ptr.rayon = 2;`
- non
6. `*ptr.rayon = 2;`
- non
7. `cercle.centre.x = 2;`
- oui (c'est une copie en wr)
8. `ptr.centre.x = 2;`
- non
9. `Coord coord1 = cercle.centre;`
- oui
10. `Coord coord2 = ptr->centre;`
- oui























<details>
<summary>Solutions</summary>

| no | Réponse   | Commentaire                                                                                                         |
|--- |---        |---                                                                                                                  |
| 1  | correct   | affiche le rayon => 1                                                                                               |
| 2  | faux      | remplacer l'opérateur `->` par un `.`                                                                               |
| 3  | faux      | selon la priorité des opérateurs, `.` est fait avant le `*`                                                         |
| 4  | correct   | le membre `centre` est affectée par les valeurs de `origine`                                                        |
| 5  | faux      | `ptr` n'a pas de membre, il faut d'abord le déréférencer</br>`(*ptr).rayon = 2;` ou `ptr->rayon = 2;`               |
| 6  | faux      | l'opérateur `.` est trop prioritaire</br>`(*ptr).rayon = 2;` ou `ptr->rayon = 2;`                                   |
| 7  | correct   | `cercle.centre` pour descendre dans `Coord` puis `.x` pour accéder au membre `x`.                                     |
| 8  | faux      | il faut déréférencer le `ptr`puis descendre dans la structure</br>`(*ptr).centre.x` ou `ptr->centre.x;`               |
| 9  | correct   | `cercle.centre` est utilisée pour initialiser `coord1`                                                               |
| 10 | correct   | `cercle.centre` pointée par `ptr` est utilisée pour initialiser `coord2`                                             |

</details>
