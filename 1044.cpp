#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num, amount;
	int diamonds[100001];
	vector<int> equal;
	vector<int> min;
	bool flag = false;

	scanf("%d%d", &num, & amount);
	equal.reserve(num);
	min.reserve(num);

	diamonds[0] = 0;
	for(int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		diamonds[i + 1] = diamonds[i] + tmp;
	}

	int minLost = 0xefffff;
	int front = 0, first = 0;

	while(diamonds[++front] < amount)
		;

	for(int i = front; i < num + 1; i++) {

		for(int j = first; j <= i; j++) {
			int sum = diamonds[i] - diamonds[j];

			if(diamonds[i] - diamonds[j] == amount) {
				equal.push_back(j + 1);
				equal.push_back(i);
				flag = true;
				first = j;
				break;
			}

			else if(sum > amount) {
				if(flag == false) {
					if(sum < minLost) {
						minLost = sum;
						min.clear();
						min.push_back(j + 1);
						min.push_back(i);
					}
					else if(sum == minLost) {
						min.push_back(j + 1);
						min.push_back(i);
					}
				}	
			}

			else {
				first = j - 1;
				break;
			}

		}
	}

	if(flag) {
		for(vector<int>::iterator it = equal.begin(); it != equal.end(); it += 2) {
			printf("%d-%d\n", *it, *(it+1));
		}
	}
	else {
		for(vector<int>::iterator it = min.begin(); it != min.end(); it += 2)
			printf("%d-%d\n", *it, *(it+1));
	}

	return 0;
}