#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <utility>

using namespace std;

// option no 1
template <typename T, T n>
bool estMultipleDe(const T& e) {
   return e % n == 0;
}

// option no 2
template <typename T>
struct EstMultipleDe {
   const T& n;
   bool operator() (const T& e) {
      cout << "foncteur";
      return e % n == 0;
   }
};

void afficher(int e) { cout << e << " ";}

void parcours(vector<int>& v, void(*fct)(int e)) {
   for (size_t i=0; i<v.size(); ++i)
      fct(v[i]);
}

template <typename T, typename Fct>
void parcours(vector<T>& v, Fct fct) {
   for (size_t i=0; i<v.size(); ++i)
      fct(v[i]);
}

int main() {

//   int valeur;
//   cout << "saisie : ";
//   if (cin >> valeur)
//      cout << "ok" << endl;
//   else
//      cout << "ko" << endl;

   vector v {1, 2, 3, 4, 5, 6, 7, 8, 9};

   cout << count(v.begin(), v.end(), 5) << endl;

   // 1ere option - predicate générique (paramètre générique connu à la compilation)
   // /!\ est obligatoire un ~int et n'est connu à la compilation
   cout << count_if(v.begin(), v.end(), estMultipleDe<int, 3>) << endl;
//   cout << count_if(v.begin(), v.end(), estMultipleDe<double, 3>) << endl;
   cout << endl;

   // 2ème option
   EstMultipleDe<int>{3}(2) ? true : false;
   cout << endl;

   // en C
   parcours(v, afficher);
}