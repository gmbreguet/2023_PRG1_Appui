#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

   ifstream file_in  ("../2023-11-16 file_in.txt");
   ofstream file_out ("../2023-11-16 file_out.txt");

   streambuf* backup = file_in.rdbuf();
   cout << backup->

   char c;
   string mot;
   string ligne;

   while (file_in >> mot) {
      cout << mot << endl;
      file_out << mot << endl;
   }

   file_in.close();
   file_out.close();

   return EXIT_SUCCESS;
}
