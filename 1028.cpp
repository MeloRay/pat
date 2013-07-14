#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
	private:
		int id;
		string name;
		int score;
	public:
		Student(int id, string name, int score):
			id(id), name(name), score(score){}
		int getId() const {return id;}
		string getName() const {return name;}
		int getScore() const {return score;}

		friend ostream& operator<<(ostream& out, const Student& stu) {
			out << setfill('0') << setw(6) << stu.id << " " 
				<< stu.name << " " << stu.score << endl;
			return out;
		}
};

bool cmp1(const Student& s1, const Student& s2) {
	return s1.getId() < s2.getId();
}

bool cmp2(const Student& s1, const Student& s2) {
	int tmp = s1.getName().compare(s2.getName());
	if(tmp == 0)
		return s1.getId() < s2.getId();
	else
		return tmp < 0;
}

bool cmp3(const Student& s1, const Student& s2) {
	if(s1.getScore() == s2.getScore())
		return s1.getId() < s2.getId();
	else
		return s1.getScore() < s2.getScore();
}

int main() {
	ios::sync_with_stdio(false);
	vector<Student> students;
	int number, flag;

	cin >> number >> flag;
	students.reserve(number);

	for(int i = 0; i < number; i++) {
		int id, score;
		string name;
		cin >> id >> name >> score;
		students.push_back(Student(id, name, score));
	}

	switch(flag) {
		case 1:
			sort(students.begin(), students.end(), cmp1);
			break;
		case 2:
			sort(students.begin(), students.end(), cmp2);
			break;
		case 3:
			sort(students.begin(), students.end(), cmp3);
			break;
	}

	for(vector<Student>::iterator it = students.begin(); it != students.end(); it++) 
		cout << *it;

	return 0;
}