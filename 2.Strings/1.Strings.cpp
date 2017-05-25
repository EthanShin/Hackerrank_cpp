#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b;
    
    cout << a.length() << " " << b.length() << endl;
    
    c = a + b;
    cout << c << endl;
    
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout << a << " " << b;
    
  
    return 0;
}
