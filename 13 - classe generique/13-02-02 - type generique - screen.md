# Type générique - screen

Déclarer les types de données permettant de définir un écran et sa résolution.

Un écran est composé de `width` x `height` `pixel`, chacun composé des trois couleurs `R` `G` `B`.<br>
Les couleurs peuvent être codées sur 8, 16 ou 32 bits. 

| Screen   | Definition  | Depth   |
|----------|-------------|--------:|
| HD       | 1280 x 720  |  8 bits |
| Full HD  | 1920 x 1080 | 16 bits |
| UHD 4K   | 3840 x 2160 | 32 bits |
| UHD 8K   | 7680 x 4320 | 32 bits |

Sur ces bases, déclarer des variables utilisant ces différents types et ajouter le code afin d'afficher les détails d'un écran comme suit.

~~~cpp
(1280 x 720) / 8bits
(1920 x 1080) / 16bits
(3840 x 2160) / 32bits
(7680 x 4320) / 32bits
~~~

🤔 Combien de mémoire faut-il pour ces structures ?

<details>
<summary>Solution - mémoire</summary>

| Screen  | Definition  | Colors | Depth | Bits          | Bytes       | MB    |
|---------|-------------|:------:|:-----:|--------------:|------------:|------:|
| HD      | 1280 x 720  |   3    |   8   |    22'118'400 |   2'764'800 |   2.8 |
| Full HD | 1920 x 1080 |   3    |  16   |    99'532'800 |  12'441'600 |  12.4 |
| UHD 4K  | 3840 x 2160 |   3    |  32   |   796'262'400 |  99'532'800 |  99.5 |
| UHD 8K  | 7680 x 4320 |   3    |  32   | 3'185'049'600 | 398'131'200 | 398.1 |

⚠️ Ces éléments sont **trop gros (~400MB contigu en mémoire)** pour être sur la pile, plusieurs solutions.

### Dimentionnement de la pile d'exécution
Sur les systèmes Unix/Linux, les commandes telles que `ulimit` permet de voir ou d'ajuster la taille de la pile d'exécution pour un processus : `ulimit -s`

Certains compilateurs peuvent donner des informations sur la taille de la pile d'exécution allouée par défaut.<br>
Par exemple, avec GCC, vous pouvez utiliser l'option `-Wstack-usage=n` pour obtenir un avertissement sur l'utilisation de la pile : `g++ -Wstack-usage=1024 -o main main.cpp`

### Alternatives

1. Utiliser `static` à la déclaration des variables pour que celles-ci sont placées sur le `heap` (tas) comme ce serait le cas pour les parties `data` d'un vecteur qui sont eux réservés dynamiquement.

2. Utiliser des `vector<T>` ce qui implique que le dimentionnement se fait au moment de la déclaration de la variable et non sur le type. Les parties `data` d'un vecteur qui sont eux réservés dynamiquement, donc sur le `heap`.

3. Répartir les données en plusieurs zones avec plusieurs `vector<T>` ou une structure que le fait intrinsèquement, ie une `deque<T>` qui sera vu en ASD.

</details>

<details>
<summary> Solution no 1 - array</summary>

~~~cpp
#include <iostream>
#include <array>
#include <cstdint>

using namespace std;

//------------------------------------------------------------
template <typename T>
struct Pixel {
   T R;
   T G;
   T B;
};

//------------------------------------------------------------
template <typename T, size_t width>
using Line = array<Pixel<T>, width>;

//------------------------------------------------------------
template <typename T, size_t width, size_t height>
using Screen = array< Line<T, width>, height>;

//------------------------------------------------------------
using HD      = Screen<uint8_t,  1280,  720>;
using Full_HD = Screen<uint16_t, 1920, 1080>;
using UHD_4k  = Screen<uint32_t, 3840, 2160>;
using UHD_8k  = Screen<uint32_t, 7680, 4320>;

//------------------------------------------------------------
template <typename T, size_t width, size_t height>
ostream& operator<< (ostream& os, const Screen<T, width, height>& s);

//------------------------------------------------------------
int main() {
   static HD      screen_HD;
   static Full_HD screen_Full_HD;
   static UHD_4k  screen_UHD_4k;
   static UHD_8k  screen_UHD_8k;

   cout << screen_HD       << endl;
   cout << screen_Full_HD  << endl;
   cout << screen_UHD_4k   << endl;
   cout << screen_UHD_8k   << endl;
}

//------------------------------------------------------------
template <typename T, size_t width, size_t height>
ostream& operator<< (ostream& os, const Screen<T, width, height>& s) {
   if(s.empty()) return os;
   os << "(" << s[0].size() << " x " << s.size() << ") / "
      << sizeof(T) * 8 << "bits";
   return os;
}
~~~

</details>

<details>
<summary>Solution no 2 - vector</summary>

🤔 Cette solution est certes meilleurs, mais elle implique jusqu'à 400MB contigu en mémoire ce qui sera difficile voire impossible pour l'OS

~~~cpp
#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

//------------------------------------------------------------
template <typename T>
struct Pixel {
   T R;
   T G;
   T B;
};

//------------------------------------------------------------
template <typename T>
using Line = vector<Pixel<T>>;

//------------------------------------------------------------
template <typename T>
using Screen = vector<Line<T>>;

//------------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const Screen<T>& s);

//------------------------------------------------------------
int main() {
   Screen<uint8_t>  screen_HD     (1280, Line<uint8_t> ( 720));
   Screen<uint16_t> screen_Full_HD(1920, Line<uint16_t>(1080));
   Screen<uint32_t> screen_UHD_4k (3840, Line<uint32_t>(2160));
   Screen<uint32_t> screen_UHD_8k (7680, Line<uint32_t>(4320));

   cout << screen_HD       << endl;
   cout << screen_Full_HD  << endl;
   cout << screen_UHD_4k   << endl;
   cout << screen_UHD_8k   << endl;
}

//------------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const Screen<T>& s) {
   if(s.empty()) return os;
   os << "(" << s[0].size() << " x " << s.size() << ") / "
      << sizeof(T) * 8 << "bits";
   return os;
}
~~~

</details>

<details>
<summary>Solution no 3 - deque</summary>

🤔 Avec une [deque](https://cplusplus.com/reference/deque/deque/), les données sont réparties en plusieurs chunks (sera étudiées en ASD).

~~~cpp
#include <iostream>
#include <deque>
#include <cstdint>

using namespace std;

//------------------------------------------------------------
template <typename T>
struct Pixel {
   T R;
   T G;
   T B;
};

//------------------------------------------------------------
template <typename T>
using Line = deque<Pixel<T>>;

//------------------------------------------------------------
template <typename T>
using Screen = deque<Line<T>>;

//------------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const Screen<T>& s);

//------------------------------------------------------------
int main() {
   Screen<uint8_t>  screen_HD     (1280, Line<uint8_t> ( 720));
   Screen<uint16_t> screen_Full_HD(1920, Line<uint16_t>(1080));
   Screen<uint32_t> screen_UHD_4k (3840, Line<uint32_t>(2160));
   Screen<uint32_t> screen_UHD_8k (7680, Line<uint32_t>(4320));

   cout << screen_HD       << endl;
   cout << screen_Full_HD  << endl;
   cout << screen_UHD_4k   << endl;
   cout << screen_UHD_8k   << endl;
}

//------------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const Screen<T>& s) {
   if(s.empty()) return os;
   os << "(" << s[0].size() << " x " << s.size() << ") / "
      << sizeof(T) * 8 << "bits";
   return os;
}
~~~

</details>