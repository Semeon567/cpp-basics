#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>

#define N  8

using namespace std;

void PrintArray(int a[N][N]) {
	cout << "Array: " << endl;
	cout << string(5 * N, '-') << endl;
	for (int i = 0; i < N; i++) {
		cout << "|";
		for (int j = 0; j < N; j++) {
			cout << setw(3) << a[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << string(5 * N, '-') << endl << endl;
}

void FileRead(int a[N][N]) {
	ifstream fin("file.txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fin >> a[i][j];
		}
	}
	fin.close();
}

void RandomRead(int a[N][N]) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[N][N] = int(pow(-1, rand() % 2))*(rand() % 10); //[-9..9]
		}
	}
}

void FindSubZeroInRows(int a[N][N], bool r[]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] < 0) {
				r[i] = true;
				break;
			}
		}
	}
}

void SumRow(int a[N][N], bool r[]) {
	bool have_result = false;
	for (int i = 0; i < N; i++)
	{
		if (r[i]) {
			have_result = true;
			cout << "Sum in " << i << " row = ";
			int result = 0;
			for (int j = 0; j < N; j++)
			{
				result += a[i][j];
			}
			cout << result;
			cout << "\n";
		}
	}
	if (!have_result)
		cout << "Error: in array no elements sub zero :(";
}

void Findk(int a[N][N], bool k[]) {
	bool equal;
	for (int i = 0; i < N; i++)
	{
		equal = true;
		for (int j = 0; j < N; j++)
		{
			if (!(a[i][j] == a[j][i])) {
				equal = false;
				break;
			}
		}
		if (equal)
			k[i] = true;
	}
}

void Printk(bool k[]) {
	bool have_result = false;
	cout << "k = ";
	for (int i = 0; i < N; i++)
	{
		if (k[i])
			cout << i << ", ";
	}
	cout << "\n\n";
}

int main() {
	int a[N][N];
	bool Rows[N];
	bool k[N];
	for (int i = 0; i < N; i++)
	{
		Rows[i] = false;
		k[i] = false;
	}
	FileRead(a);
	PrintArray(a);

	Findk(a, k);
	Printk(k);

	FindSubZeroInRows(a, Rows);
	SumRow(a, Rows);
	return 0;
}
