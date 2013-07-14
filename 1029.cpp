#include <iostream>
#include <vector>
using namespace std;

int main() {
	int len1, len2;
	cin >> len1;
	vector<int> s1(len1);
	for(vector<int>::iterator it = s1.begin(); it != s1.end(); it++)
		scanf("%d", it);

	cin >> len2;
	vector<int> s2(len2);
	for(vector<int>::iterator it = s2.begin(); it != s2.end(); it++)
		scanf("%d", it);

	int mid = (len1 + len2 - 1)/2;

	vector<int>::iterator p1 = s1.begin();
	vector<int>::iterator p2 = s2.begin();
	int index = -1;
	bool flag;	//the last add is p1(true), p2(false)
	int result;
	while(p1 != s1.end() && p2 != s2.end() && index != mid) {
		if(*p1 < *p2) {
			p1++;
			flag = true;
		}
		else {
			p2++;
			flag = false;
		}
		index++;
	}
	if(index == mid) {
		if(flag)
			result = *(--p1);
		else
			result = *(--p2);
	}
	else if(p1 == s1.end()) {
		while(index != mid) {
			p2++;
			index++;
		}
		result = *(--p2);
	}
	else {
		while(index != mid) {
			p1++;
			index++;
		}
		result = *(--p1);
	}

	printf("%d\n", result);

	return 0;
}