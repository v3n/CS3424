#include "morse_tree.h"

int main(int argc, char const *argv[])
{
	MorseTree t("morse.txt");

	t.to_string();

	return 0;
}