#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning(disable:4996)

struct Person {
	int order;
	int age;
	string name;
};
bool cmp(const Person &p1, const Person &p2) {
	if (p1.age == p2.age) {
		return p1.order < p2.order;
	}
	else
		return p1.age < p2.age;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<Person> v(N);
	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> v[i].age >> v[i].name;
		v[i].order = i;
	}
	sort(v.begin(), v.end(),cmp);
	for (Person p : v)
		cout << p.age << ' '<< p.name << '\n';

	return 0;
}