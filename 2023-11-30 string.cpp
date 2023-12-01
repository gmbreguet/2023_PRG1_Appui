#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <span>

using namespace std;


void afficher(span<const int> s) {
   for (int i : s)
      cout << i << " ";
   cout << endl;
}

//void afficher(const vector<int>& v) {
//   for (int i : v)
//      cout << i << " ";
//   cout << endl;
//}

//void afficher(const array<int, 5>& v) {
//   for (int i : v)
//      cout << i << " ";
//   cout << endl;
//}

int main() {

   // constante litérale
   const char* chaine = "chat";
//   chaine[1] = 'H';      // pas possible

   cout << (void*)"chat"   << endl;
   cout << (void*)"chat"   << endl;
   cout << (void*)chaine   << endl;

   char testTaille[] = "Hello";
   cout << "testTaille : " << sizeof(testTaille) << endl;

   //              01234567890123456789
   char tab[] = "chat et souris";
   tab[0] = 'C';
//   tab[4] = '\0';
   cout << tab             << endl;
   cout << "tab[14] : " <<(int)tab[14] << endl;
   tab[14] = 'a';
   cout << "tab[14] : " <<(int)tab[14] << endl;
   cout << (void*)tab      << endl;
   cout << tab             << endl;

   cout << endl;
   cout << "string" << endl;
   string str = "chat et souris";
   str[0] = 'C';
   str[4] = '\0';
   cout << str << endl;
   cout << "taille      : " << str.size()       << endl;
   cout << "capacite    : " << str.capacity()   << endl;
   cout << "data        : " << (void*)str.data()<< endl;

   str += str;
   cout << "taille      : " << str.size()       << endl;
   cout << "capacite    : " << str.capacity()   << endl;
   cout << "data        : " << (void*)str.data()<< endl;


   string str1 = "HEIG-VD";
   string str2 = "PRG1-Appui";

   string& CstStrRef = str1;
   CstStrRef = str2;

   string_view strView     = str1;
   strView     = str2;

   cout << strView.at(2);

   cout << endl << endl;

   vector v  {1, 2, 3, 4, 5, 6};
   array  a  {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   span s(v);
   s = a;

   s[1] = 12;

   afficher (v);
   afficher (a);
   afficher (t);

   cout << size_t(-1) << endl;
   cout << v[6]    << endl;
   cout << v.at(6) << endl;
}
