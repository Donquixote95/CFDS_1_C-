#include <iostream>
#include <new>

using namespace std;

class Triangle {
    double sideA;
    double sideB;
    double sideC;
public:
    dobule area();
    double perimeter();
};

int main(void)
{
    Triangle t1(2.0, 2.0, 3.0);
    Triangle *t2;

    t2 = new Triangle(4.2, 7.8, 10.2);
    
    double p1;

    p1 = t1.perimeter();
}

double Trinagle::perimeter()
{
    return sideA + sideB + sideC;
}

double Triangle::area()
{
    double s = perimeter() / 2;

    //Heron's Formula
    retrun sqrt(s*(s - sideA) * (s-sideB) * (s - sideC));
}
// int main(){
//     int i, n;
//     int * p;

//     cout << "How many numbers would you like to type?" ;
//     cin >> i;

//     p = new (nothrow) int[i];

//     if (p == nullptr)
//         cout << "Error: memory could not be allocated";
//     else {
//         for (n = 0; n < i; n++){
//             cout << "Enter number: ";
//             cin >> p[n];
//         }
//         cout << "You have entered: ";
//         for (n=0; n < i; n++)
//             cout << p[n] << ", ";
//         delete[] p;
//     }

//     return 0;
// }