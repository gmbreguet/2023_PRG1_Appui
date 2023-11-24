#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

using namespace std;

int main() {

   for (int i=0; i<10; ++i) {
      cout << i << " : ";
      for (int j = 0; j < 3; ++j)
         cout << j << " ";
      cout << endl;
   }

   vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};

   for (int e : v)
      cout << ++e << " ";
   cout << endl;
   for (int e : v)
      cout << e << " ";

   //   for (size_t i=0; i<12; ++i)
////      cout << v[i] << " ";
//      cout << v.at(i) << " ";

   cout << endl;
   char     c  = 300; // 'a';
   int8_t   i8 = 255;
   size_t   st = 12;

   cout << (int)c  << endl;
   cout << i8 << endl;
   cout << st << endl;

   return EXIT_SUCCESS;
}
