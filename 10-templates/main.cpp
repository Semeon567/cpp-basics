#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>

#define N  8

using namespace std;

template <class T>
void PrintArray(T a[N][N]) {
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

template <class T>
void FileRead(T a[N][N], string name) {
	ifstream fin(name + ".txt");
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

template <class T>
void RandomRead(T a[N][N]) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[N][N] = static_cast<T>(pow(-1, rand() % 2))*(rand() % 10); //[-9..9]
		}
	}
}

template <class T>
void FindSubZeroInRows(T a[N][N], bool r[]) {
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

template <class T>
void SumRow(T a[N][N], bool r[]) {
	bool have_result = false;
	for (int i = 0; i < N; i++)
	{
		if (r[i]) {
			have_result = true;
			cout << "Sum in " << i << " row = ";
			T result = 0;
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

template <class T>
void Findk(T a[N][N], bool k[]) {
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

template <class TypeArray>
void Start(string name) {
	TypeArray a[N][N];
	bool Rows[N];
	bool k[N];
	for (int i = 0; i < N; i++)
	{
		Rows[i] = false;
		k[i] = false;
	}
	FileRead(a, name);
	PrintArray(a);

	Findk(a, k);
	Printk(k);

	FindSubZeroInRows(a, Rows);
	SumRow(a, Rows);
}

int main() {
reselect:
	cout << "Enter type(1- int, 2- double, 3- float)-> ";
	string select;
	cin >> select;
	if (select < "1" || select > "3")
	{
		cout << "Use only 1 or 2 or 3!\n";
		goto reselect;
	}
	if (select == "1")
		Start<int>("int");
	if (select == "2")
		Start<float>("float");
	if (select == "3")
		Start<double>("double");
	return 0;
}