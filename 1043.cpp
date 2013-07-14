#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
	bool isVisited;
	Node(int key): key(key) {
		left = NULL;
		right = NULL;
		isVisited = false;
	}
};

vector<int> pre;
vector<Node*> result;
int nodeCount = 0;
bool isMirror = false;
Node* root = NULL;
int num;

Node* insert(vector<int>::iterator bottom, vector<int>::iterator upper) {
	Node* parent = new Node(*bottom);
	vector<int>::iterator bound;
	bool noRight = false;

	if(bottom == upper)
		return parent;

	if(isMirror) {
		for(bound = bottom + 1; bound < upper; bound++) {
			if(*bound < *bottom) {
				break;
			}
		}
		if(*bound >= *bottom)
			noRight = true;
	}
	else {
		for(bound = bottom + 1; bound < upper; bound++) {
			if(*bound >= *bottom)
				break;
		}
		if(*bound < *bottom) 
			noRight = true;
	}

	if(bottom + 1 != bound || noRight)
		if(noRight)
			parent->left = insert(bottom + 1, upper);
		else
			parent->left = insert(bottom + 1, bound - 1);

	if(!noRight)
		parent->right = insert(bound, upper);

	return parent;
}

int find(int key) {
	Node* pos = root;

	if(!isMirror) {
		while(pos) {
			if(pos->key == key) {
				if(pos->isVisited == false) {
					pos->isVisited = true;
					return 1;
				}
				else
					pos = pos->right;
			}
			else if(pos->key > key)
				pos = pos->left;
			else 
				pos = pos->right;
		}
	}
	else {
		while(pos) {
			if(pos->key == key) {
				if(pos->isVisited == false) {
					pos->isVisited = true;
					return 1;
				}
				else
					pos = pos->left;
			}
			else if(pos->key > key)
				pos = pos->right;
			else 
				pos = pos->left;
		}
	}
	return 0;
}

void record(Node* node) {
	result.push_back(node);

	if(node->right)
		record(node->right);
	if(node->left)
		record(node->left);
}

void print() {

	record(root);

	for(vector<Node*>::iterator it = result.end() - 1; it != result.begin(); it--) {
		cout << (*it)->key << ' ';
	}

	cout << result.front()->key;
}

int main() {
	bool isBST = true;
	

	cin >> num;

	result.reserve(num);
	pre.reserve(num);

	for(int i = 0; i < num; i++) {
		int tmp;
		cin >> tmp;
		pre.push_back(tmp);
	}

	root = insert(pre.begin(), pre.end() - 1);
	
	for(vector<int>::iterator it = pre.begin(); it != pre.end(); it++) {
		if(find(*it) == 0) {
			isMirror = true;
			break;
		}
	}

	if(isMirror) {
		root = insert(pre.begin(), pre.end() - 1);

		for(vector<int>::iterator it = pre.begin(); it != pre.end(); it++) {
			if(find(*it) == 0) {
				isBST = false;
				break;
			}
		}
	}

	if(isBST) {
		cout << "YES" << endl;
		print();
	}
	else
		cout << "NO";
	return 0;
}