#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int table[256];
	char s1[10001];

	memset(table, 0, 256*sizeof(int));
	cin.getline(s1, 10001);

	char c;
	while((c = getchar()) != '\n') {
		table[(int)c] = 1;
	}

	for(int i = 0; s1[i] != '\0'; i++) {
		if(table[s1[i]] == 0)
			printf("%c", s1[i]);
	}

	return 0;
}