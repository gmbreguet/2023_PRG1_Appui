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

   stringstream sstr("UN DEUX TROIS QUATRE");
   sstr.ignore(numeric_limits<streamsize>::max());

   sstr << "CINQ SIX SEPT";

   cout << "1ere fois" << endl;
   while(getline(sstr, mot, ' '))
      cout << "|" << mot << "|" << endl;
   cout << endl;

   cout << "2eme fois" << endl;
   while(getline(sstr, mot, ' '))
      cout << "|" << mot << "|" << endl;
   cout << endl;

   return EXIT_SUCCESS;
}
