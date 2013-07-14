#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

class Station {
public:
	double _price;
	double _dist;
	double _essential;
	double _put;

	Station(double dist, double price) {
		_dist = dist;
		_price = price;
		_essential = 0;
		_put = 0;
		
	}

	friend bool operator<(const Station& left, const Station& right) {
		return left._dist < right._dist;
	}
};

double Dist, Davg, Cap, Max;
int N;

vector<Station> stations;

double set() {
	double sum = 0, left = 0, result = 0;
	for(int index = 0; index < N && sum != Dist; index++) {
		Station& pos = stations[index];
		double optm = pos._essential;
		int flag = 0;

		for(int i = index + 1; i < N; i++) {
			if(stations[i]._price <= pos._price) {
				flag = 1;
				break;
			}

			optm += stations[i]._essential;
			if(optm > Max) {
				flag = 2;
				break;
			}
		}
		switch(flag) {
		case 0:
			pos._put = Dist - sum;
			break;
		case 1:
			if(left < optm)
				pos._put = optm - left;
			break;
		case 2:
			pos._put = Max - left;
		}

		sum += pos._put;
		left = left + pos._put - pos._essential;
		result += (pos._put / Davg) * pos._price;
	}

	return result;
}

int main() {
	cin >> Cap >> Dist >> Davg >> N;
	Max = Cap * Davg;
	stations.reserve(N);

	for(int i = 0; i < N; i++) {
		double tmpPrice, tmpDist;
		cin >> tmpPrice >> tmpDist;
		stations.push_back(Station(tmpDist, tmpPrice));
	}

	sort(stations.begin(), stations.end());

	if(stations[0]._dist != 0) {
		cout << "The maximum travel distance = 0.00" << endl;
		return 0;
	}

	for(int i = 0; i < N - 1; i++) {
		stations[i]._essential = stations[i + 1]._dist - stations[i]._dist;
		if(stations[i]._essential > Max) {
			cout << "The maximum travel distance = " << setiosflags(ios::fixed) << setprecision(2) << stations[i]._dist + Max <<endl;
			return 0;
		}
	}

	stations[N - 1]._essential = Dist - stations[N - 1]._dist;
	if(stations[N - 1]._essential > Max) {
		cout << "The maximum travel distance = " << setiosflags(ios::fixed) << setprecision(2) << stations[N - 1]._dist + Max <<endl;
		return 0;
	}

	double result;
	result = set();
	cout << setiosflags(ios::fixed) << setprecision(2) << result <<endl;

	return 0;
}