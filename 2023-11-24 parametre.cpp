#include <iostream>
#include <string>

using namespace std;

// par valeur => aucun changement pour l'appelant
void f (int p) {
   cout << p << " ";
   p = 12;
   cout << p << " ";
}

// par référence => changement direct pour l'appelant
void g (int& p) {
   cout << p << " ";
   p = 12;
   cout << p << " ";
}

// par adresse => changement direct pour l'appelant
void h (int* ptr) {
   cout << *ptr << " ";
   *ptr = 12;
   cout << *ptr << " ";
}

void afficher(const string& s) {
   cout << s << endl;
}

void initialEnMajuscule(string& s) {
//   for (size_t i=0; i<s.size(); ++i)
   for (char& c : s)
      c = toupper(c);

int main() {

   int i = 2;
   cout << i << " ";
   f(i);
   cout << i << " ";
   cout << endl;

   i = 2;
   cout << i << " ";
   g(i);
   cout << i << " ";
   cout << endl;

   i = 2;
   cout << i << " ";
   h(&i);
   cout << i << " ";
   cout << endl;


   // pointeurs
   int valeur = 12;
   int* ptr   = &valeur;

   cout << "valeur                  : " <<   valeur   << endl;
   cout << "adresse de valeur       : " <<  &valeur   << endl;

   cout << "ptr                     : " <<   ptr      << endl;
   cout << "adresse de ptr          : " <<  &ptr      << endl;
   cout << "valeur pointee par ptr  : " <<  *ptr      << endl;

   // référence
   double d = 3.14;
   double& refD = d;
   refD = 7.8;

   cout << "d                       : " <<   d        << endl;
   cout << "adresse de d            : " <<  &d        << endl;

   cout << "refD                    : " <<   refD     << endl;
   cout << "adresse de refD         : " <<  &refD     << endl;

   const string hello = "hello"s;
   afficher(hello);

   string ecole = "heig-vd";
   initialEnMajuscule(ecole);
   afficher(ecole);

}
