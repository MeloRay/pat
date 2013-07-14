#include <iostream>
#include <vector>
using namespace std;

struct Adjacent {
	int city;
	int dist;
	int cost;
	Adjacent(int city, int distance, int cost):
		city(city), dist(distance), cost(cost){}

	friend ostream& operator<<(ostream& out, const Adjacent tmp) {
		out << "city: " << tmp.city << ", dist: " << tmp.dist << ", cost: " << tmp.cost << endl;
		return out;
	}
};

class Map {
private:
	int num;
	int start;
	int dest;
	vector<vector<Adjacent>> roads;
	vector<int> path;
	vector<int> visited; 
	int dist;
	int cost;
public:
	Map(int num, int roadNum, int start, int dest):
		num(num), 
		start(start), 
		dest(dest),	
		roads(vector<vector<Adjacent>>(num)),
		visited(vector<int>(num, 0)){
			dist = 1000;
			cost = 1000;
			while(roadNum--) {
				int city1, city2, tdist, tcost;
				cin >> city1 >> city2 >> tdist >> tcost;
				roads[city1].push_back(Adjacent(city2, tdist, tcost));
				roads[city2].push_back(Adjacent(city1, tdist, tcost));
			}
		}
	void find() {
		visited[start] = 1;
		for(vector<Adjacent>::iterator it = roads[start].begin(); it != roads[start].end(); it++) {
			vector<int> tpath;
			tpath.push_back(start);
			//cout << *it;
			dfs(it->city, it->dist, it->cost, tpath);
		}
	}

	void dfs(int tcity, int tdist, int tcost, vector<int> tpath) {
		tpath.push_back(tcity);
		if(tcity == dest) {
			//cout << "find: " << tcity << " " << tdist << " " << tcost << endl;
			if(tdist == dist) {
				if(tcost < cost) {
					cost = tcost;
					path = tpath;
				}
			}
			else if(tdist < dist) {
				dist = tdist;
				cost = tcost;
				path = tpath;
			}
		}
		else {
			visited[tcity] = 1;
			for(vector<Adjacent>::iterator it = roads[tcity].begin(); it != roads[tcity].end(); it++) {
				if(visited[it->city] == 0)
					if(tdist + it->dist <= dist) {
						//cout << *it;
						dfs(it->city, tdist + it->dist, tcost + it->cost, tpath);
				}
			}
			visited[tcity] = 0;
		}
	}

	friend ostream& operator<<(ostream& out, const Map& map) {
		for(vector<int>::const_iterator it = map.path.begin(); it != map.path.end(); it++)
			out << *it << ' ';
		out << map.dist << ' ' << map.cost;
		return out;
	}

};

int main() {
	int num, roadNum, start, dest;
	cin >> num >> roadNum >> start >> dest;
	Map map(num, roadNum, start, dest);
	map.find();
	
	cout << map << endl;

	return 0;
}