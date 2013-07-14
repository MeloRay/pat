#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, L;

	cin >> N >> M;

	vector<int> table(N + 1, 0);

	for(int i = 0; i < M; i++) {
		int color;
		cin >> color;
		table[color] = i + 1;
	}

	cin >> L;

	vector<int> stripe;
	stripe.reserve(L);

	for(int i = 0; i < L; i++) {
		int color;
		cin >> color;
		if(table[color])
			stripe.push_back(table[color]);
	}
	
	vector<int> cnt(stripe.size(), 1);
	int max = 0;
	
	for(int i = 0; i < stripe.size(); i++) {
		for(int j = 0; j < i; j++) {
			if(stripe[i] >= stripe[j] && cnt[i] < cnt[j] + 1)
				cnt[i] = cnt[j] + 1;
		}
		if(max < cnt[i])
			max = cnt[i];
	}

	cout << max << endl;

	return 0;
}
