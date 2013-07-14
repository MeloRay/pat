#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void output(string& input) {
	int length = input.size();
	int row = (length + 2)/3;
	int col = length + 2 - 2*row;
	
	for(int i = 0; i < row - 1; i++)
		cout << input[i] << setw(col - 2) << " " << input[length - 1 - i] << endl;
	for(int i = 0; i < col; i++) 
		cout << input[row + i - 1];
	cout << endl;
}

int main() {
	string input;
	cin >> input;

	output(input);
	return 0;
}