#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, Q;
	vector<int> x;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		x.push_back(temp);
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int y;
		cin >> y;

		int temp = lower_bound(x.begin(), x.end(), y) - x.begin();
		if (x.at(temp) == y) {
			cout << "Yes " << temp + 1 << endl;
		}
		else {
			cout << "No " << temp + 1 << endl;
		}
	}
	return 0;
}