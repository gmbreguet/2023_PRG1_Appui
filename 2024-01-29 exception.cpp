#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Trace {
   friend ostream& operator<< (ostream& os, const Trace& t) {
      return os << t.data;
   }

public:
   Trace()           : data(0)          { cout << "C0(" << data << ") ";   }

   Trace(int data)   : data(data)       { cout << "Ci(" << data << ") ";   }

   Trace(const Trace& other)            { this->data = other.data;
      cout << "CC(" << data << ") ";   }

   ~Trace()                             { cout << "D("  << data << ") ";   }

   Trace& operator=(const Trace& other) { this->data = other.data;
      cout << "=C("  << data << ") ";
      return *this;                    }
private:
   int data;
};

class Op {
public:
   Op(int a=0) : a(a) {}
   auto operator<=> (const Op& op) const { return this->a <=> op.a; }
private:
   int a;
};

//-----------------------------------------------------------------------------
template <typename T>
class C;

template <typename T>
ostream& operator<< (ostream& os, const C<T>& c);

template <typename T>
class C {
//   friend C operator+ (const C& c, int i) { return C(c.valeur + i); }   // c + 2
   friend C operator+ (int i, const C& c) { return C(c.valeur + i); }   // 2 + c

   friend ostream& operator<< <>(ostream& os, const C<T>& c) {return os << c.valeur; };

public:
   C() : valeur{0} {};
   C(int i) : valeur(i) {};
   bool getTrouve1()   const      { return trouve; }
   static bool getTrouve2() { return trouve; }

   C operator+ (int i) { return C(this->valeur + i); }      // c + 2
                                                            // 2 + c

private:
   T valeur;
   static bool trouve;
};

template <typename T>
bool C<T>::trouve = false;

//-----------------------------------------------------------------------------
void f(int i) {

   if (i > 0) {
      cout << i << " "; // descente
      f(i/3);
      cout << i << " "; // entre deux
      f(i/2);
      cout << i << " "; // montée
   }
}


//-----------------------------------------------------------------------------

int main() {

   f(6);
   return EXIT_SUCCESS;


   stringstream flux("ceci est le contenu");

   char car;
   while(flux >> car)
      cout << car;

   cout << flux.str();

   return EXIT_SUCCESS;

   C<int> c;
   cout << c.getTrouve1();
   cout << c.getTrouve2();
   cout << endl;

// cout << C::getTrouve1();
   cout << C<int>::getTrouve2();
   cout << endl;

   cout << c << endl;
   return EXIT_SUCCESS;

   //
//
//   Op a1(1);
//   Op a2(2);
//
//   cout << (a1 <  a2) << endl;
//   cout << (a1 == a2) << endl;
//   cout << (a1 >  a2) << endl;
//
//   cout << (a1 <=>  a2 <  0) << endl;
//   cout << (a1 <=>  a2 == 0) << endl;
//   cout << (a1 <=>  a2 >  0) << endl;

   Trace trace1;
   cout << endl;

   Trace trace2(2);
   cout << endl;

   Trace trace3(trace2);
   cout << endl;

   Trace trace4 = trace2;
   cout << endl;

   trace4 = trace2;
   cout << endl;

   vector<Trace> v1(3);
   cout << endl;

   vector<Trace> v2(3, trace1);
   cout << endl;

   vector<Trace> v3(3, Trace(3));
   cout << endl;

   vector<Trace> v4(3, 4);
   cout << endl;

   return EXIT_SUCCESS;


   string s1("chaine",  4);      // string (const char* s, size_t n);
   // => "chai"

   string s2("string"s, 1, 4);   // string (const string& str, size_t pos, size_t len = npos);
   // => "trin"

   string test = "appui 2024";
   cout << test << endl;
   test.erase(2, 3);
   cout << test << endl;

   remove(test.begin()+1, test.begin()+4, ' ');
   cout << test << endl;

   string test2("12343");
   cout << test2 << endl;
   remove(test2.begin(), test2.end(), '2');
   cout << test2 << endl;


}


