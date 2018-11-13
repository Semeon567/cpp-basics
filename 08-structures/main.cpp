#include <iostream>
#include <string>
#include <iomanip>

#define N 8 //Trains

using namespace std;

struct TRAIN
{
	string destination;
	string number;
	string departure_time;
};

bool isNumber(char h) {
	if (h >= '0'&& h <= '9')
		return true;
	else
		return false;
}

bool isTime(string s) {
	for (int i = 0; i < s.length(); i++)
	{
		if (!((s[i] >= '0'&& s[i] <= '9') || (s[i] = ':')))
			return false;
	}
	return true;
}

void InputTrain(TRAIN t[]) {
	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << ". Train \n";
		cout << "Enter Train destination(e.g. NewYork): ";
		cin >> t[i].destination;
		cout << "Enter number of the train(e.g. 28): ";
		cin >> t[i].number;
	repeat:
		cout << "Enter departure time(e.g. 12:15 ): ";
		cin >> t[i].departure_time;
		if (!isTime(t[i].departure_time))
		{
			cout << "Invalid time. Use format hh:mm !\n";
			goto repeat;
		}
		cout << endl;
	}
}

void SortTrain(TRAIN t[]) {
	for (int i = 0; i < N - 1; i++)
	{
		if (t[i].destination.compare(t[i + 1].destination) > 0) {
			swap(t[i], t[i + 1]);
		}
	}
}

void PrintTrain(TRAIN t[]) {
	cout << string(41, '-') << endl;
	cout << "| Number | destination - departure time |\n";
	cout << string(41, '-') << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(8) << t[i].number;
		cout << "|" << setw(9) << t[i].destination;
		cout << setw(6) << "-" << t[i].departure_time << setw(11) << "|\n";
		cout << string(41, '-') << endl;
	}
}

bool isAfter(string t1, string t2) {
	if (t1.compare(t2) > 0) {
		return true;
	}
	return false;
}

void PrintTimeAfter(TRAIN t[]) {
	string select;
	cout << "Select time: ";
	cin >> select;
	cout << "Trains starting after this time:\n";
	bool result = false;
	for (int i = 0; i < N; i++)
	{
		if (isAfter(t[i].departure_time, select)) {
			result = true;
			cout << string(41, '-') << endl;
			cout << "| Number | destination - departure time |\n";
			cout << string(41, '-') << endl;
			cout << "|" << setw(8) << t[i].number;
			cout << "|" << setw(9) << t[i].destination;
			cout << setw(6) << "-" << t[i].departure_time << setw(11) << "\n";
			cout << string(41, '-') << endl;
		}
	}
	if (!result)
		cout << "No one train after this time!";
}

int main() {
	TRAIN t[N];
	InputTrain(t);
	PrintTrain(t);
	SortTrain(t);
	PrintTrain(t);
	PrintTimeAfter(t);
	return 0;
}