#include <iostream>
#include <queue>
using namespace std;
typedef struct {
	int start;
	int finish;
}time;
struct compare {
	bool operator()(time a, time b) {
		return a.start > b.start;
	}
};
struct compare2 {
	bool operator()(int a, int b) {
		return a > b;
	}
};
int N;
priority_queue<time, vector<time>, compare> pq;
priority_queue<int, vector<int>, compare2> e;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	time temp;
	int ans = 1, t;//t는 시간 temp
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp.start >> temp.finish;
		pq.push(temp);
	}
	e.push(0);
	for (int i = 0; i < N; i++) {
		temp = pq.top(); pq.pop();
		t = e.top();
		if (temp.start >= t) {
			e.pop();
			e.push(temp.finish);
		}
		else {
			ans++;
			e.push(temp.finish);
		}
	}
	cout << ans << '\n';
}