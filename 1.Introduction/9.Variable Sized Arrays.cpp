#include<iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int **array = new int*[n];
    for(int a = 0; a < n; a++) {
        int k;
        cin >> k;
        array[a] = new int[k];
        for(int b = 0; b < k; b++) {
            cin >> array[a][b];
        }
    }

    for(int a = 0; a < q; a++) {
        int i, j;
        cin >> i >> j;
        cout << array[i][j] << endl;
    }

    delete[] array;
    return 0;
}