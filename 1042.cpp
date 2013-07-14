#include <iostream>
using namespace std;

int main() {
	int tmp1[55], tmp2[55];
	int sh[55];
	int num;
	int *before = tmp1, *after = tmp2;
	int *result = NULL;

	cin >> num;

	for(int i = 1; i < 55; i++) {
		int pos;
		cin >> pos;
		sh[i] = pos;
		before[i] = i;
	}

	for(int i = 0; i < num; i++) {
		for(int j = 1; j < 55; j++) {
			after[sh[j]] = before[j];
		}
		result = after;
		after = before;
		before = result;
	}

	for(int i = 1; i < 55; i++) {
		int flag, off;
		flag = result[i]/13;
		off = result[i] % 13;
		if(off == 0) {
			flag--;
			off = 13;
		}

		switch(flag) {
		case 0:
			cout << 'S';
			break;
		case 1:
			cout << 'H';
			break;
		case 2:
			cout << 'C';
			break;
		case 3:
			cout << 'D';
			break;
		case 4:
			cout << 'J';
			break;			
		}

		cout << off;
		
		if(i != 54)
			cout << ' ';
	}

	return 0;
}