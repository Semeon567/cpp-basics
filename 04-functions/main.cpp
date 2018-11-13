#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void PrintTableHead() {
	cout << string(74, '-') << endl;
	cout << "|         x         ";
	cout << "|  arcctg(x) (mine) ";
	cout << "| arcctg(x) (cmath) ";
	cout << "| iterations |\n";
	cout << string(74, '-') << endl;
}

double ComputeSeries(double x, double eps, int &n, const int kMaxIters) {
	n = 1;
	const double PI = 3.141592653589793238463;
	double nth_term = PI;
	double my_exp = nth_term;
	while (abs(nth_term) > eps) {
		nth_term = pow(-1, n + 1)*pow(x, 2 * x + 1) / (2 * n + 1);
		my_exp += nth_term;
		n++;
		if (n > kMaxIters) break;
	}
	return my_exp;
}

void PrintTableRow(double x, double func, int n, const int kMaxIters) {
	cout << "|" << setw(13) << x << setw(7) << "|" << setw(14);
	if (n <= kMaxIters)
		cout << func << setw(6) << "|";
	else
		cout << " limit is exceeded |";
	cout << setw(14) << 1 / static_cast<double>(atan(x)) << setw(6) << "|";
	cout << setw(7) << n << setw(7) << "|\n";
}

int main() {
	const int kMaxIters = 1000;

	double xn, xk, dx, eps;
	cout << "Enter xn -> ";
	cin >> xn;
	cout << "Enter xk (xk >= xn) -> ";
	cin >> xk;
	cout << "Enter dx (dx > 0) -> ";
	cin >> dx;
	cout << "Enter eps (eps > 0) -> ";
	cin >> eps;

	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (eps <= 0) {
		cout << "\nInvalid eps. Must be: eps > 0.\n";
	}
	else if (xn > xk) {
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else {
		PrintTableHead();

		cout << fixed;
		cout.precision(6);

		for (; xn <= xk; xn += dx) {
			int n;
			double my_exp = ComputeSeries(xn, eps, n, kMaxIters);
			PrintTableRow(xn, my_exp, n, kMaxIters);
		}
		cout << string(74, '-');
	}

	return 0;
}