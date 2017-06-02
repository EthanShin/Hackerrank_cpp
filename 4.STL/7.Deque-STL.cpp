#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k) {
	deque<int> mydeque;
	int maximum = 0, position = -1;

	for (int i = 0; i < n; i++) {
		mydeque.push_back(arr[i]);

		if (arr[i] >= maximum) {
			maximum = arr[i];
			if (i < k - 1) {
				position = i;
			}
			else {
				position = k - 1;
			}
		}

		if (mydeque.size() == k) {
			cout << maximum << " ";
			mydeque.pop_front();
			position--;
			if (position == -1) {
				maximum = 0;
				for (int j = 0; j < mydeque.size(); j++) {
					if (mydeque[j] >= maximum) {
						maximum = mydeque.at(j);
						position = j;
					}
				}
			}
		}
	}
	cout << endl;
}

int main() {

	int t;
	cin >> t;
	while (t>0) {
		int n, k;
		cin >> n >> k;
		int i;
		int arr[n];
		for (i = 0; i<n; i++)
			cin >> arr[i];
		printKMax(arr, n, k);
		t--;
	}
	return 0;
}