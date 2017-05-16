#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    
    int capacity;
    cin >> capacity;
    vector<int>v;
    
    for (int i = 0; i < capacity; i++) {
        int number;
        cin >> number;
        v.push_back(number);
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < capacity; i++) {
        cout << v.at(i) << " ";
    }
    
    return 0;
}
