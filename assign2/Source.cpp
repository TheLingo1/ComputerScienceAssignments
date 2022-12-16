#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
	if (argc >= 2) {
        int intConvert;
        intConvert = strtol(argv[1], &argv[argc], 10);
        cout << setw(27) << left << "The integer in hexadecimal " << "form is: " << hex << intConvert << endl;
        cout << setw(27) << left << "The integer in octal " << "form is: " << oct << intConvert << endl;
        cout << setw(27) << left << "The integer in decimal " << "form is: " << dec << intConvert << endl;
	}
	int intShift = 4;
	cout << setw(23) << left << "the integer multiplied " << setw(16) << left << "by 4 with right " << "shift " << "binary operator is: " << (intShift << 2) << endl;
	cout << setw(23) << left << "the integer divided " << setw(16) << left << "by 4 with left " << "shift " << "binary operator is: " << (intShift >> 2) << endl;
	EXIT_SUCCESS;
}
