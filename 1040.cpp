#include <iostream>
#include <vector>
#include <string>
using namespace std;

char input[1001];
vector<int> table[256];

int substring(char c, int index) {
	int result = 1;

	for(vector<int>::iterator it = table[c].end() - 1; *it != index; it--) {
		int end = (*it) - 1;
		int start = index + 1;
		int len = 2;
		bool flag =true;

		for( ;end > start; end--, start++) {
			if(input[start] == input[end]) 
				len += 2;
			else  {
				flag = false;
				break;			
			}
		}

		if(flag) {
			if(end == start)
				len++;

			if(len > result)
				result = len;
		}
	}

	return result;
}

int main() {
	int maxLen = 1;

	cin.getline(input, 1001);

	for(int i = 0; input[i] != '\0'; i++) {
		table[(int)input[i]].push_back(i);
	}

	for(int i = 0; input[i] != '\0'; i++) {
		int len = substring(input[i], i);
		if(len > maxLen)
			maxLen = len;
	}

	cout << maxLen;

	return 0;
}