#include <iostream>

template <class T> //Type 이름을 T라고 한 것, A라고 해도 되고 다른 것으로 바꿔도 됨. 임의의 타입 T에 대하여, 라는 뜻. 입력이 Type으로 들어온다. generic하게 들어올 값을 열어주는 것.
void mySwap(T &x, T &y){
    T temp = x;
    x = y;
    y = temp;
}

template <class T, int N>
T fixed_multiply (T val){
    retrun val * N;
}

using namespace std;
int main(void) {
    int intA = 10, intB = 20;
    double doubleA = 10.15, doubleB = 20.25;
    char charA = 'a', charB = 'b';
    int* intPtrA = &intA;
    int* intPtrB = &intB;

    cout << fixed_multiply<int, 2>(10) << '\n';
    cout << fixed_multiply<int, 3>(10) << '\n';

    //int swap
    cout << "[Before Swap] A: " << intA
         << "\t B:" << intB <<endl;
    mySwap(intA, intB);
    cout << "[After  Swap] A: " << intA
         << "\t B:" << intB <<endl;

    //double swap
    cout << "[Before Swap] A: " << doubleA << "\t B:" << doubleB <<endl;
    mySwap(doubleA, doubleB);
    cout << "[After  Swap] A: " << doubleA << "\t B:" << doubleB <<endl;

    //char swap
    cout << "[Before Swap] A: " << charA << "\t B:" << charB <<endl;
    mySwap(charA, charB);
    cout << "[After  Swap] A: " << charA << "\t B:" << charB <<endl;

    return 0;
}