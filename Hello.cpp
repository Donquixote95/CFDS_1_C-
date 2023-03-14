#include <iostream>
#include <string>
// int main(void)
// {
//     std::string myStr;
//     std::cin >> myStr;
//     std::cout<<myStr;
//     return 0;
// }

// int main(void)
// {
//     std::string myStr;
//     getline(std::cin, myStr);
//     std::cout<<myStr;

//     return 0;
// }

// namespace foo {
//     int value() { return 5; }
// }

// namespace bar {
//     const double pi = 3.1416;
//     double value()  {
//         return 2 * pi;
//     }
// }

// int main (){
//     std::cout << foo::value() << '\n';
//     std::cout << bar::value() << '\n';
//     std::cout << bar::pi << '\n';
//     return 0;
// }

// using namespace std;

// namespace first {
//     int x = 5;
//     int y = 10;
// }

// namespace second {
//     double x = 3.1416;
//     double y = 2.7183;
// }

// int main () {
//     {
//     using namespace first;
//     cout << x << '\n';
//     }
//     {
//     using namespace second;
//     cout << y << '\n';
//     }

//     return 0;
// }

// default values in functions
// using namespace std;
// int divide (int a, int b=2){
//     int r;
//     r = a/b;
//     return (r);
// }

// int main (){
//     cout << divide (12) <<'\n';
//     cout << divide (20, 4) << '\n';
//     return 0;
// }

// range-based for loop
#include <iostream>
#include <string>
using namespace std;
int main() {
    string myStr {"Hello!"};
    for (auto c : myStr) {
        cout << "["<< c << "]";
    }
    cout << '\n';
}