#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <utility>

using namespace std;

template <typename T>
struct Coord {
   T x;
   T y;
};

template <typename T>
bool operator< (const Coord<T>& lhs, const Coord<T>& rhs) {
   return lhs.x * lhs.x + lhs.y * lhs.y
        < rhs.x * rhs.x + rhs.y * rhs.y;
}

class Personne {
public :
   Personne (const string& s, int age) : nom(s), age(age) {}
   bool operator< (const Personne& p) const {return this->age < p.age; }
private:
   string nom;
   int age;
};

template <typename T>
struct MultipleDe {
   const T& n;
   bool operator() (const T& e) { return e % n == 0; };
};

int main() {

   int a = 12, b = 21;
   cout << (a < b) << endl;

   Coord<int> point1 {1, 2};
   Coord<int> point2 {3, 4};
   cout << (point1 < point2) << endl;

   vector v1 {1, 2, 3, 4, 5};
   vector v2 {5, 4, 3, 2, 1};

   cout << (v1 < v2) << endl;
   cout << operator<(v1, v2) << endl;

   Personne pers1("toto, "s, 20);
   Personne pers2("tati, "s, 18);
   cout << pers1.operator<(pers2) << endl;

   cout <<  (pers1 < pers2) << endl;

   // foncteur
   // trouver le premier multiple de "2" dans le vecteur
   vector<int> v {1, 4, 2, 3, 2, 3, 4, 2, 6, 7, 2};

   vector<int>::iterator it = v.begin();
   while( (it = find_if(it, v.end(), MultipleDe<int>{2})) != v.end()) {
      cout << distance(v.begin(), it) << " ";
      ++it;
   };
   cout << endl;

   // opérateur d'affectation

   int valeur = 12;
   cout << ((valeur+=1)+= 1) << endl;

   cout << (++valeur)++ << endl; // ++valeur retourne
   cout << ++(++valeur) << endl; // ... une référence

   cout << (valeur++)++ << endl; // valeur ++ retourne
   cout << ++(valeur++) << endl; // ... une copie

}