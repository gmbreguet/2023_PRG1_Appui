#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

   int tab[] = {1, 2, 3, 4, 5};

   int         i     = 12;
   const int   k     = 24;

   const int* ptrInt = &tab[1]; // &i;
   ptrInt = &tab[2];
   *ptrInt = 12;
//   ptrInt            = &k;
//   double* ptrDouble = &i;


   cout << "valeur i       : " <<  i   << endl;
   cout << "adresse i      : " << &i   << endl;

   cout << "valeur ptrInt  : " <<  ptrInt   << endl;
   cout << "adresse ptrInt : " << &ptrInt   << endl;
   cout << "valeur pointee : " << *ptrInt   << endl;

   *ptrInt = 21;

   cout << endl;
   cout << "valeur i       : " <<  i   << endl;
   cout << "adresse i      : " << &i   << endl;

   cout << "valeur ptrInt  : " <<  ptrInt   << endl;
   cout << "adresse ptrInt : " << &ptrInt   << endl;
   cout << "valeur pointee : " << *ptrInt   << endl;

   return EXIT_SUCCESS;
}
