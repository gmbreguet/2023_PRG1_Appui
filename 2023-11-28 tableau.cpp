#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <span>

using namespace std;

void afficher(const vector<int>& v) {
//   cout << "taille   : " << v.size()      << endl;
//   cout << "capacite : " << v.capacity()  << endl;
//   cout << "data     : " << v.data()      << endl;
//   cout << "valeurs  : ";
   cout << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if(i) cout << ", ";
      cout << v[i];
   }
   cout << "]" << endl;
}

using Ligne = vector<int>;

void afficher(const array<Ligne, 10>& a) {

   for (const Ligne& l : a)
      afficher(l);


//   cout << "[";
//   for (size_t i=0; i<a.size(); ++i) {
//      if(i) cout << ", ";
//      afficher(a[i]);
//   }
//   cout << "]";
}

int main() {

   /* vector ou array?

   - vector
      - taille variable
      - complexité spatiale (mémoire)
         - 3 * 8B (structure)
         - capacité

    - array
      - taille fixe (à la compilation)
      - complexité spatiale (mémoire)
         - taille uniquement

   */

   vector<int> v;
   v.reserve(6);
   for (size_t i=0; i<10; ++i) {
      v.push_back(i);
      if(i==4)
         v.shrink_to_fit();
      cout << v.size() << "\t\t" << v.capacity()  << "\t\t" << v.data() << endl;
   }
   cout << endl;

   vector<int> v2;
   v2.reserve(5);
   afficher(v2);
   cout << endl;

   vector<int>    v3(10);
   array<int, 10> a3;

   array<Ligne, 10> triangle;
   size_t i=0;
   for (Ligne& l : triangle) {
      l.resize(++i);
      l.assign(i, 0);
   }

   afficher(triangle);

}
