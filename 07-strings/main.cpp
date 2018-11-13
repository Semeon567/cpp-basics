#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string s, file_name;

	cout << "Write  file name (default name 'a') -> ";
	cin >> file_name;
	file_name += ".txt";
	ifstream fin(file_name);

	if (!fin.is_open()) {
		cout << "can't open file!" << endl;
		return 1;
	}

	getline(fin, s, '\n');
	s += ' ';
	cout << s << endl << endl;
	int result = 0;
	int series = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] > 'a'&&s[i] < 'z')
			series++;
		if (s[i] == ' ') {
			if (series < 5) {
				result += 1;
			}
			series = 0;
		}

	}
	cout << "words with the letters no more 4: ";
	cout << result << endl;

	fin.close();
	return 0;
}