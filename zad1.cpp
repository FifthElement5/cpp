#include <iostream>
using namespace std;

class Punkt3d {
    int x, y, z;
    public:

};

int get()
{
    int n;
    cout << "podaj cyfre" << endl;
    cin >> n;
    return n;
}
int main()
{
    int x = get();
    int y = get();
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}
