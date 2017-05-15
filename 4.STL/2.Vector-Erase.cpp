#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int N, x, a, b;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		v.push_back(number);
	}

	cin >> x;
	v.erase(v.begin() + x - 1);
	cin >> a >> b;
	v.erase(v.begin() + a - 1, v.begin() + b - 1);

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}

	return 0;
}
