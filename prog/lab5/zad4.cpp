#include <iostream>

using namespace std;

class X {
    int i;
    float j;
    public:
    int fun(int i, float j) {return i;};
};

int fun(int i, float j) {return i;};


X A;
int i;
int j;
int main(){

 A.X::fun(2,5.1);
}
