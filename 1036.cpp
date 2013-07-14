#include <iostream>
#include <string>
using namespace std;

int main() {
	int boy = 101;
	int girl = -1;
	string gName, gId, bName, bId;
	int num;
	cin >> num;

	while(num--) {
		char sex;
		string name, id;
		int score;
		cin >> name >> sex >>id >> score;
		if(sex == 'M') {
			if(score < boy) {
				bName = name;
				bId = id;
				boy = score;
			}
		}
		else {
			if(score > girl) {
				gName = name;
				gId = id;
				girl = score;
			}
		}
	}
	int flag = true;
	if(girl == -1) {
		flag = false;
		cout << "Absent" << endl;
	}
	else 
		cout << gName << " " << gId << endl;
	
	if(boy == 101) {
		flag = false;
		cout << "Absent" << endl;
	}
	else 
		cout << bName << " " << bId << endl;

	if(flag)
		cout << girl - boy << endl;
	else
		cout << "NA" << endl;

	return 0;
}