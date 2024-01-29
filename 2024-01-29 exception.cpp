#include <iostream>
#include <string>

using namespace std;

int main() {

   try {
      string msg = "appui";
      cout << msg.substr(2, 3);
      throw exception();
   }
   catch(out_of_range& e) {
      cout << "out_of_range ...";
   }
   catch(exception& e) {
      cout << "problème ...";
   }

}

