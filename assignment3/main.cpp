#include "morse_tree.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Creating MorseTree object" << endl;
	MorseTree t("morse.txt");

	cout << "Testing decoding of string: ";
	if(t.decode("..-. --- .-.   .- ... --. .- .-. -.. .-.-.- ").compare("F O R   A S G A R D . ")) {
		std::cout << t.decode("..-. --- .-.   .- ... --. .- .-. -.. .-.-.- ") << endl << "\t Success." << endl;
	} else {
		cout << "Failure." << endl;
	}

	std::cout << t.encode("For Asgard.") << std::endl;

	cout << "Testing encoding of string: ";
	if(t.decode("For Asgard.").compare("..-. --- .-.   .- ... --. .- .-. -.. .-.-.- ")) {
		std::cout << t.encode("For Asgard.") << endl << "\t Success." << endl;
	} else {
		cout << "Failure." << endl;
	}
	return 0;
}