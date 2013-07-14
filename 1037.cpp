#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	vector<int> n_cou, cou, n_pro, pro;
	int nc, np;

	cin >> nc;
	n_cou.reserve(nc);
	cou.reserve(nc);
	for(int i = 0; i < nc; i++) {
		int tmp;
		cin >> tmp;
		if(tmp < 0)
			n_cou.push_back(tmp);
		else
			cou.push_back(tmp);
	}

	cin >> np;
	n_pro.reserve(np);
	pro.reserve(np);
	for(int i = 0; i < np; i++) {
		int tmp;
		cin >> tmp;
		if(tmp < 0)
			n_pro.push_back(tmp);
		else
			pro.push_back(tmp);
	}

	sort(n_cou.begin(), n_cou.end());
	sort(cou.begin(), cou.end(), greater<int>());
	sort(n_pro.begin(), n_pro.end());
	sort(pro.begin(), pro.end(), greater<int>());

	int amount = 0;
	vector<int>::iterator p1, p2;
	for(p1 = cou.begin(), p2 = pro.begin(); p1 != cou.end() && p2 != pro.end(); p1++, p2++) {
		amount += (*p1)*(*p2);
	}
	for(p1 = n_cou.begin(), p2 = n_pro.begin(); p1 != n_cou.end() && p2 != n_pro.end(); p1++, p2++) {
		amount += (*p1)*(*p2);
	}

	cout << amount;
	return 0;
}