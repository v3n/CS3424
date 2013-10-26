#include <iostream>
#include <string>

using namespace std;

int main(int args, char **argc) {
	string fname;

	cout << "What is your name?" << endl;
	cin >> fname;

	cout << "Hello, " << fname << endl;

	#ifdef _WIN32
		system("pause");
	#endif
}