#include <iostream>
#include <queue>
using namespace std;

//자료형 long long
struct compare {
	bool operator()(long long a, long long b) {
		return a > b;
	}
};

int n, m;
priority_queue<long long, vector<long long>, compare> arr;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long temp;
	long long a, b;
	long long sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push(temp);
	}
	for (int i = 0; i < m; i++) {
		a = arr.top(); arr.pop();
		b = arr.top(); arr.pop();
		arr.push(a + b);
		arr.push(a + b);
	}
	for (int i = 0; i < n; i++) {
		temp = arr.top(); arr.pop();
		sum += temp;
	}
	cout << sum << '\n';
}