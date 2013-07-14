#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool modify(string& input) {
	string::iterator it;
	bool flag = true;

	for(it = input.begin(); it != input.end(); it++) {
		switch(*it) {
		case '1':
			flag = false;
			*it = '@';
			break;
		case '0':
			flag = false;
			*it = '%';
			break;
		case 'l':
			flag = false;
			*it = 'L';
			break;
		case 'O':
			flag = false;
			*it = 'o';
			break;
		}
	}

	return flag;
}

int main() {
	int num;
	vector<string> name;
	vector<string> passwd;
	vector<int> result;

	cin >> num;
	name.reserve(num);
	passwd.reserve(num);
	result.reserve(num);

	for(int i = 0; i < num; i++) {
		string tname, tpasswd;
		cin >> tname >> tpasswd;
		if(!modify(tpasswd))
			result.push_back(i);

		name.push_back(tname);
		passwd.push_back(tpasswd);
	}

	if(result.size()) {
		cout << result.size() << endl;
		for(vector<int>::iterator it = result.begin(); it != result.end(); it++)
			cout << name[*it] << " " << passwd[*it] <<endl;
	}
	else 
		if(num == 1)
			cout << "There is 1 account and no account is modified" << endl;
		else
			cout << "There are " << num << " accounts and no account is modified" <<endl;

	return 0;

}