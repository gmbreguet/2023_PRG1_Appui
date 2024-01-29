#include <iostream>
#include <string>
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

int main() {

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


