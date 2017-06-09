#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshops {
	int start_time;
	int duration;
	int end_time;
};

struct Available_Workshops {
	int n;
	Workshops* ws = new Workshops[n];
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
	map<int, int> check;

	for (int i = 0; i < n; i++) {
		if (check.find(start_time[i]) == check.end() || check.find(start_time[i])->second > duration[i]) {
			check[start_time[i]] = duration[i];
		}
	}

	Available_Workshops* aw = new Available_Workshops;
	aw->n = check.size();

	map<int, int>::iterator iter;
	int i = 0;
	for (iter = check.begin(); iter != check.end(); ++iter) {
		aw->ws[i].start_time = iter->first;
		aw->ws[i].duration = iter->second;
		aw->ws[i].end_time = iter->first + iter->second;
		i++;
	}

	return aw;
}

int CalculateMaxWorkshops(Available_Workshops* aw) {
	int result = 1;

	int current_workshop = 0;
	for (int i = 0; i < aw->n - 1; i++) {
		if (aw->ws[current_workshop].end_time > aw->ws[i + 1].end_time) {
			current_workshop = i + 1;
		}
		else if (aw->ws[current_workshop].end_time <= aw->ws[i + 1].start_time) {
			current_workshop = i + 1;
			result++;
		}
	}
	return result;
}

int main(int argc, char *argv[]) {
	int n; // number of workshops
	cin >> n;
	// create arrays of unknown size n
	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
	return 0;
}