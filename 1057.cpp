#include <stack>
#include <string>
#include <iostream>
using namespace std;

struct Node {
	int num;
	Node* next;
	Node(int num):num(num), next(NULL){}
};

class List {
private:
	Node* head;
	int size;
public:
	List(){head = new Node(-1); size = 0;}

	Node* insert(int num) {
		Node* tmp = head;
		Node* newNode = new Node(num);
		size++;
		for(; tmp->next; tmp = tmp->next) {
			if(tmp->next->num > num) {
				newNode->next = tmp->next;
				tmp->next = newNode;
				return tmp;
			}
		}
		tmp->next = newNode;
		return tmp;
	}

	void del(Node* location) {
		Node* tmp = location->next;
		location->next = location->next->next;
		delete tmp;
		size--;
	}

	int median() {
		int mid = (size + 1)/2;
		Node* tmp = head;
		for(int i = 0; i < mid; i++, tmp = tmp->next);
		return tmp->num;
	}
};

stack<Node*> order;
List list;

void pop() {
	if(order.size()) {
		Node* tmp = order.top();
		cout << tmp->next->num << endl;
		order.pop();
		list.del(tmp);
	}
	else
		cout << "Invalid" << endl;
}

void push() {
	int num;
	cin >> num;
	Node* tmp = list.insert(num);
	order.push(tmp);
}

void peekMedian() {
	if(order.size()) {
		cout << list.median() << endl;
	}
	else
		cout << "Invalid" << endl;
}

int main() {
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		string op;
		cin >> op;
		if(op == "Push")
			push();
		else if(op == "Pop")
			pop();
		else
			peekMedian();
	}

	return 0;
}