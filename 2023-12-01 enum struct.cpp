#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <utility>

using namespace std;

enum class Menu { FILE,    EDIT,    VIEW,    QUIT};
array      MENU {"FILE"s, "EDIT"s, "VIEW"s, "QUIT"s};

// sans enum class, pas possible d'avoir 2x ROSE
enum class couleur {ROUGE,       ROSE, VERT};
enum class fleur   {MARGUERITTE, ROSE, FOUGERE};

ostream& operator<< (ostream& os, Menu menu) {
   cout << MENU[size_t(menu)];
   return os;
}

struct Date {
   int jour;
   int mois;
   int annee;
};

struct Personne {
   string   nom;
   string   prenom;
   Date     date;
   unsigned age;
};


Personne plus1an(Personne p) {
   ++p.age;
   return p;
}

Personne plus1an(const Personne& p) {
   return {p.nom, p.prenom, p.date, p.age + 1};
}

Personne plus1an(Personne& p) {
   ++p.age;
}

ostream& operator<< (ostream& os, const Date& d) {
   return os << d.jour << "." << d.mois << "." << d.annee;
}

ostream& operator<< (ostream& os, const Personne& p) {
   cout << "nom     : " << p.nom    << endl;
   cout << "prenom  : " << p.prenom << endl;
   cout << "date    : " << p.date   << endl;
   cout << "age     : " << p.age    << endl;
   return os;
}

template <typename T, int taille>
void listerCarnetAdresse(const array<T, taille>& carnet) {
//void listerCarnetAdresse(const array<Personne, 2>& carnet) {
   for (const Personne& p : carnet)
      cout << p << endl;
}

int main() {

   Personne toto = {"Toto"s, "Jean"s, Date{01, 12, 2023}, 23};
   cout << toto;

   int saisie;

   array carnetAdresse {toto, Personne{"nom", "prenom", {1, 2, 2003}, 19}};

   listerCarnetAdresse<Personne, carnetAdresse.size()>(carnetAdresse);

   cout << "initiales : " << carnetAdresse[0].nom[0] << carnetAdresse[0].prenom[0] << endl;
   cout << "initiales : " << carnetAdresse[1].nom[0] << carnetAdresse[1].prenom[0] << endl;

   cout << Menu::EDIT << endl;

   do {
      cout << "votre choix : ";
      cin  >> saisie;
      Menu menu = Menu(saisie);

      cout << menu;

      switch(menu) {
         case Menu::FILE : cout << "file"; break;
         case Menu::EDIT : cout << "edit"; break;
         case Menu::VIEW : cout << "view"; break;
         case Menu::QUIT : cout << "quit"; return EXIT_SUCCESS;
      }

   } while (true);
}
