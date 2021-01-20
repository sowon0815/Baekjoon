#include <iostream>
#include <queue>
using namespace std;
typedef struct val {
	int num;
	double score;
}val;
struct compare {
	bool operator()(val a, val b) {
		return a.score < b.score;
	}
};
int N, M, K;
int visited[101];
double ans = 0;
priority_queue<val, vector<val>, compare> arr; //내림차순 우선순위 큐
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	val temp;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp.num >> temp.score;
			arr.push(temp);
		}
	}
	while (K) {
		temp = arr.top();
		arr.pop();
		if (visited[temp.num] == 0) {
			visited[temp.num] = 1;
			ans += temp.score;
			K--;
		}
	}
	printf("%.1f", ans);
}