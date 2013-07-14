#include <iostream>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int head1, head2, num;
	map<int, int> nodes;
	set<int> record;
	cin >> head1 >> head2 >> num;

	for(int i = 0; i < num; i++) {
		int addr, next;
		char data;
		cin >> addr >> data >> next;
		nodes.insert(pair<int, int>(addr, next));
	}

	int n1 = head1;
	int n2 = head2;
	int oldsize;
	int result = -1;
	while(n1 != -1 && n2 != -1) {
		//map<int, int>::iterator p1, p2;
		if(n1 != -1) {
			oldsize = record.size();
			record.insert(n1);
			if(oldsize == record.size()) {
				result = n1;
				break;
			}
			n1 = nodes.find(n1)->second;
			//n1 = p1->second;
		}

		if(n2 != -1) {
			oldsize = record.size();
			record.insert(n2);
			if(oldsize == record.size()) {
				result = n2;
				break;
			}
			n2 = nodes.find(n2)->second;
			//n2 = p2->second;
		}		
	}
	if(result == -1)
		cout << -1 << endl;
	else 
		cout << setfill('0') << setw(5) << result << endl;

	return 0;
}