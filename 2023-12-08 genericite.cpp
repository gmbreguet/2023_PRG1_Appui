#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <utility>

using namespace std;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
   cout << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if(i) cout << ", ";
      cout << v[i];
   }
   return cout << "]";
}

template <int n, typename T>
void parcourir(vector<T>& v) {
   for (T& e : v)
      e += n;
}

template <typename T, typename Fonction>
void parcourir(vector<T>& v, Fonction fct) {
   for (T& e : v)
      e = fct(e);
}

template <typename T, T n>
T add(const T& t) {
   return t + n;
}

// instanciation explicite
template
int add<int, 2>(const int& t);

int main() {

   vector<int>    vi = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   vector<double> vd = {1, 2, 3, 4, 5, 6, 7, 8, 9};

   cout << vi << endl;
   cout << vd << endl;

   parcourir<2>(vi);
   parcourir<3>(vd);

   cout << vi << endl;
   cout << vd << endl;

   cout << add<int, 2>(3) << endl;
//   cout << add<double, 2.1>(3.2); 77 ne prend que des types ~entiers

   parcourir<int>(vi, add<int, 10>);
   cout << vi << endl;

}