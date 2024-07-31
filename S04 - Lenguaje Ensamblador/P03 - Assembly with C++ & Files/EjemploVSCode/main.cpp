#include <iostream>
using namespace std;

extern "C" int sumaASM(int, int);

int main()
{

    cout << "Dame dos numeros para sumarlos: ";
    int a, b, res;
    cin >> a >> b;
    res = sumaASM(a,b);
    cout << "El resultado de la suma es: " << res;

    return 0;
}