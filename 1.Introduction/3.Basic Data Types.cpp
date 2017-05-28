#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a;
    long b;
    long long c;
    char d;
    float e;
    double f;
    
    cin >> a >> b >> c >> d >> e >> f;
    cout << setprecision(9) << a << endl << b << endl << c << endl << d << endl << e << endl << f << endl;
    return 0;
}
