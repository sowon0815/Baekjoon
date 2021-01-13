#include <iostream>
#include <vector>
using namespace std;

int N;
int dp[10101][2], visited[10101], peo[10101];
vector<int> graph[10101];

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}

void dfs(int n) {
	for (int i = 0; i < graph[n].size(); i++) {
		if (visited[graph[n][i]] == 0) {
			visited[graph[n][i]] = 1;
			dfs(graph[n][i]);
			dp[n][1] += dp[graph[n][i]][0];
			dp[n][0] += max(dp[graph[n][i]][0], dp[graph[n][i]][1]);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		cin >> peo[i];
		dp[i][1] = peo[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	visited[1] = 1;
	dfs(1);
	printf("%d\n", max(dp[1][0], dp[1][1]));
}