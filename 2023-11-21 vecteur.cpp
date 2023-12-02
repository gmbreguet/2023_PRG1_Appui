//
// Created by Guy-Michel Breguet on 21.11.23.
//

#include "2023-11-21_vecteur.h"
#include <iostream>

using namespace std;

string vector_to_string(const std::vector<int>& v) {
   string resultat = "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         resultat += ", ";
      resultat += to_string(v.at(i));
   }
   resultat += "]";

   return resultat;
}

void afficher_vecteur(const std::vector<int>& v) {
   cout << vector_to_string(v);
}