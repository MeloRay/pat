#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const string& left, const string& right) {
	string::const_iterator pl, pr;
	pl = left.begin();
	pr = right.begin();

	while(pl != left.end() && pr != right.end()) {
		if(*pl != *pr)
			return *pl < *pr;
		pl++;
		pr++;
	}

	if(pl == left.end()) {
		if(pr == right.end())
			return true;
		else
			return cmp(left, string(pr, right.end()));
	}
	else
		return cmp(string(pl, left.end()), right);
}

int main() {
	int num;
	vector<string> normal, zero, merge;

	cin >> num;
	normal.reserve(num);
	zero.reserve(num);
	merge.reserve(num - 1);

	for(int i = 0; i < num; i++) {
		string tmp;
		cin >> tmp;
		if(tmp[0] == '0')
			zero.push_back(tmp);
		else
			normal.push_back(tmp);
	}

	vector<string>::const_iterator minZero, minNormal, min;
	int flag = 0;
	bool leadZero = false;

	if(normal.size()) {
		minNormal = normal.begin();
		for(vector<string>::iterator it = normal.begin() + 1; it != normal.end(); it++) {
			if(!cmp(*minNormal, *it))
				minNormal = it;
		}
	}
	else 
		flag = 1;

	if(zero.size()) {
		minZero = zero.begin();
		for(vector<string>::iterator it = zero.begin() + 1; it != zero.end(); it++) {
			if(!cmp(*minZero, *it))
				minZero = it;
		}
	}
	else
		flag = 2;


	switch(flag) {
	case 0:
		if(cmp(string((*minZero).begin() + 1, (*minZero).end()), *minNormal)) {
			min = minZero;
			leadZero = true;
		}
		else
			min = minNormal;

		break;
	case 1:
		min = minZero;
		leadZero = true;
		break;
	case 2:
		min = minNormal;
		break;

	}

	if(leadZero) {
		for(vector<string>::iterator it = zero.begin(); it != zero.end(); it++) 
			if(it != min)
				merge.push_back(*it);

		for(vector<string>::iterator it = normal.begin(); it != normal.end(); it++)
			merge.push_back(*it);
	}
	else {
		for(vector<string>::iterator it = zero.begin(); it != zero.end(); it++) 
			merge.push_back(*it);

		for(vector<string>::iterator it = normal.begin(); it != normal.end(); it++)
			if(it != min)
				merge.push_back(*it);
	}

	sort(merge.begin(), merge.end(), cmp);

	bool ignore = false;
	for(string::const_iterator it = (*min).begin(); it != (*min).end(); it++) {
		if(ignore)
			cout << *it;
		else
			if(*it != '0') {
				ignore = true;
				cout << *it;
			}
	}


	for(vector<string>::iterator it = merge.begin(); it != merge.end(); it++) {
		if(ignore)
			cout << *it;
		else
			for(string::iterator p = (*it).begin(); p != (*it).end(); p++) 
				if(ignore)
					cout << *p;
				else
				if(*p != '0') {
					ignore = true;
					cout << *p;
				}
	}

	if(!ignore)
		cout << '0';

	return 0;
}