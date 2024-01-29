#include <iostream>

using namespace std;

class Point {
public:
   Point() {x=0; y=0;}
   Point(double _x, double _y) {x=_x; y=_y;}
   void afficher() { cout << "(" << x << ", " << y << ")";}
   void deplacer(double _dx, double _dy) { x += _dx; y += _dy; }

   double getX() const {return x;};
   double getY() const {return y;};

   double setX(double X) {this->x = x;};
   double setY(double Y) {this->y = y;};


private:
   double x;
   double y;
};

int main() {
   Point centre{};
   centre.afficher();

   Point p{1.2, 2.4};
   p.afficher();
   p.deplacer(0.8, 0.6);
   p.afficher();

   p.setX(5.5);
   p.setY(10.3);
   cout << p.getX() << " -- " << p.getY() << endl;

   int i, j, k;
   i = j = k = 0;
}

