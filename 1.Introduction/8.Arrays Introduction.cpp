#include <iostream>
using namespace std;

int main() {
    int index = 0;
    cin >> index;
    
    int *number = new int[index];
    for(int i = 0; i < index; i++) cin >> number[i];
   
    for(int i = index - 1; i >= 0; i--) cout << number[i] << " ";
    
    delete[] number;
    
    return 0;
}