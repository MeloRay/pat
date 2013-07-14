#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class Person {
	public:
		int weight;
		vector<int> relation;

		Person():weight(0){}
};

class Gang {
	private:
		int index;
		int size;
		string out;
	public:
		Gang(int index, int size): index(index), size(size){ turn();}
		void turn() {
			int tmp, value;

			tmp = index;
			value = tmp /(26*26);
			tmp -= value*26*26;
			out.push_back('A' + value);
			value = tmp / 26;
			tmp -= value*26;
			out.push_back('A' + value);
			out.push_back('A' + tmp);
		}
		
		friend ostream& operator<<(ostream& out, const Gang& g) {
			out << g.out << " " << g.size << endl;
			return out;
		}

		friend bool operator< (const Gang& g1, const Gang& g2) {
			return g1.index < g2.index;
		}
};

vector<int> visited(17575, 0);
vector<Person> people(17575);
vector<Gang> result;
int N, K;	//number,  threthold;

inline int turn(string& name) {
	return (name[2] - 'A') + (name[1] - 'A')*26 + (name[0] - 'A')*26*26;
}

void bfs(int index) {
	queue<int> q;
	int max_v= people[index].weight;	//max value;
	int max_i = index;	//max value's index;
	int sum = max_v; //total weight;
	int size = 0;

	q.push(index);
	visited[index] = 1;

	while(!q.empty()) {
		int front = q.front();
		visited[front] = 1;
		for(vector<int>::iterator it = people[front].relation.begin(); it != people[front].relation.end(); it++) {
			int tindex = *it;
			if(visited[tindex] == 0) {
				q.push(tindex);
				visited[tindex] = 1;
				sum += people[tindex].weight;
				if(people[tindex].weight > max_v) {
					max_i = tindex;
					max_v = people[max_i].weight;
				}
			}
		}
		q.pop();
		size++;
	}

	if(sum > 2*K && size > 2) {
		result.push_back(Gang(max_i, size));
	}
}

int main() {
	cin >> N >> K;
	vector<int> input;
	input.reserve(2*K);

	while(N--) {
		string na1, na2;
		int weight;
		cin >> na1 >> na2 >> weight;
		int index1 = turn(na1);
		int index2 = turn(na2);

		input.push_back(index1);
		input.push_back(index2);
		people[index1].weight += weight;
		people[index2].weight += weight;
		people[index1].relation.push_back(index2);
		people[index2].relation.push_back(index1);
	}

	for(vector<int>::iterator it = input.begin(); it != input.end(); it++) {
		int index = *it;
		if(visited[*it] == 0) {
			bfs(index);
		}
	}
	
	sort(result.begin(), result.end());

	cout << result.size() << endl;
	for(vector<Gang>::iterator it = result.begin(); it != result.end(); it++)
		cout << *it;
	
	return 0;
}

