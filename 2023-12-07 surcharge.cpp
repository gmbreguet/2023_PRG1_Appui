#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <utility>

using namespace std;

int main() {

   //               0  1  2  3  4  5  6  7  8  *9*
   vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

   cout << "sizeof   : " << sizeof(v)     << endl;
   cout << "taille   : " << v.size()      << endl;
   cout << "capacité : " << v.capacity()  << endl;
   cout << "data     : " << v.data()      << endl;

   size_t n = 1;
   cout << v[n] << " " << v.at(n) << endl;

   char c = 65;
   cout << c << " " << c + 1 << " " << -c << endl;
   cout << int(3.14e400) << endl;
}