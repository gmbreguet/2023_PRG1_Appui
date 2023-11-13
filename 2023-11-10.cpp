#include <iostream>
#include <string>

using namespace std;


void f(int param) {
   ++param;
   cout << param;
}

void g(const int& param) {
   cout << param;
}

void h(int i) {
   cout << i << " ";
   if (i)         // condition
      h(i-1);     // appel récursif
   // param => condition d'arrêt
}

void afficher( string& str) {
   cout << str << endl;
}


int main() {

   const string str("coucou");
   afficher(str);
   afficher("couou");

   h(5);

   short i = 2;
   g(i);
   cout << i << endl;

   return EXIT_SUCCESS;
}
