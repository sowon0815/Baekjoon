#include <iostream>

using namespace std;
int N, M, K;
int ans = 0, sum = 0;
//간선이 있는 경우 graph[][]=weight
//방문한 노드에서 최소거리로 연결되는 것이 minimum-없으면 0
int visited[1010], graph[1010][1010], minimum[1010];

int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int temp, a, b;
	int idx, idxMin = 10001;
	cin >> N >> M >> K;
	sum = K;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		visited[temp] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> temp;
		graph[a][b] = temp;
		graph[b][a] = temp;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] != 0 && visited[j] == 0) {
					if (minimum[j] == 0) minimum[j] = graph[i][j];
					else minimum[j] = min(minimum[j], graph[i][j]);
				}
			}
		}
	}
	while (sum < N) {
		idxMin = 10001;
		for (int i = 1; i <= N; i++) {
			if (minimum[i] != 0 && minimum[i] < idxMin) {
				idx = i;
				idxMin = minimum[i];
			}
		}
		visited[idx] = 1; sum++; ans += idxMin;
		minimum[idx] = 0;
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0 && graph[idx][i] != 0) {
				if (minimum[i] == 0) minimum[i] = graph[idx][i];
				else minimum[i] = min(minimum[i], graph[idx][i]);
			}
		}
	}
	cout << ans;
}