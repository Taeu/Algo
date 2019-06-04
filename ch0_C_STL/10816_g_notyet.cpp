#include <set>
#include <iostream>
using namespace std;
# pragma warning (disable : 4996)


int main() {
	multiset<int> s;
	int N;
	scanf("%d", &N);
	for(int i =0;i<N; i++){
		int num;
		scanf("%d", &num);
		s.insert(num);
	}
	scanf("%d", &N);
	for(int i =0;i<N;i++){
		int num;
		scanf("%d", &num);
		printf("%d ",s.count(num));
	}
	return 0;
}

/// https://jaimemin.tistory.com/993
