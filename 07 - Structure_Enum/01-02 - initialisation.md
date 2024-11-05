# struct - déclaration
Soient les `struct` ci-dessous.

~~~cpp
struct Coord {
   int x, y, z;
};

struct Cercle {
   int   rayon;
   Coord centre;
};
~~~

Que valent les déclarations proposées ?

1. `Cercle cercle = {1, {2, 3, 4}};`
   - rayon = 1
      - x = 2
      - y = 3
      - x = 4
2. `Cercle cercle = {1};`
   - rayon = 1
      - x = 0
      - y = 0
      - x = 0
3. `Cercle cercle = {};`
   - rayon = 0
      - x = 0
      - y = 0
      - x = 0
4. `Cercle cercle = {1, {2, 3}};`
   - rayon = 1
      - x = 2
      - y = 3
      - x = 0
5. `Cercle cercle = {1, 2, 3, 4};`
   - rayon = 1
      - x = 2
      - y = 3
      - x = 4
6. `Coord  coord  = {x=1, y=2, z=3};`  
    erreur de syntax
7. `Coord  coord  = {.x=1, .y=2, .z=3};`
   - x = 1
   - y = 2
   - x = 3
8. `Coord  coord  = {.x=1,       .z=3};`
   - x = 1
   - y = 0
   - x = 3
9. `Coord  coord;`
   - x = ?
   - y = ?
   - x = ?

<details>































<summary>Solutions</summary>

| no |  R  |  X  |  Y  |  Z  | Commentaire                                         |
|--- |---  |---  |---  |---  |---                                                  |
| 1  | 1   | 2   | 3   | 4   | l'agégat est complet                                |
| 2  | 1   | 0   | 0   | 0   | seul le rayon est renseigné, le reste à `0`         |
| 3  | 0   | 0   | 0   | 0   | l'agrégat est vide, donc tout est à `0`             |
| 4  | 1   | 2   | 3   | 0   | manque la valeur de Z, => à `0`                     |
| 5  | 1   | 2   | 3   | 4   | tout est renseigné en séquence                      |
| 6  | X   | X   | X   | X   | erreur de syntaxe, manque les `.`  exemple : `.x=1` |
| 7  | n/a | 1   | 2   | 3   | tout est renseigné par nom                          |
| 8  | n/a | 1   | 0   | 3   | la valeur manquante est déterminée et vaut `0`      |
| 9  | n/a | ?   | ?   | ?   | les valeurs sont indéterminées.                     |

</details>
