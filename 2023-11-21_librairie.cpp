#include <cstdlib>
#include "2023-11-21_vecteur.h"

using namespace std;

int main() {

   vector<int> vect = {1, 2, 3, 4, 5, 6};
   string test = vector_to_string(vect);
   afficher_vecteur(vect);

   return EXIT_SUCCESS;
}
