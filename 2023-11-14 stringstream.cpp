#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

int main() {

   std::stringstream ss;
   ss << 100 << ' ' << 200;

   int foo,bar;
   ss >> foo >> bar;

   std::cout << "foo: " << foo << '\n';
   std::cout << "bar: " << bar << '\n';

   cout << endl;

   string mot;

   stringstream sstr;
//   sstr.ignore(numeric_limits<streamsize>::max());

   sstr.str("UN DEUX TROIS QUATRE");
   cout << sstr.str() << endl;

   cout << "1ere fois" << endl;
   while(getline(sstr, mot, ' '))
      cout << "|" << mot << "|" << endl;
   cout << endl;

   sstr.str("CINQ SIX SEPT");
   cout << sstr.str() << endl;

   cout << "2eme fois" << endl;
   while(getline(sstr, mot, ' '))
      cout << "|" << mot << "|" << endl;
   cout << endl;

   return EXIT_SUCCESS;
}
