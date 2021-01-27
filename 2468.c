#include <stdio.h>
int N;
int arr[101][101], check[101][101];
int min = 101, max = 0;
int count = 0, ans = 0;
void dfs(int a, int b) {
	if (check[a][b] == -1) return;
	check[a][b] = -1;
	if (a - 1 >= 0) dfs(a - 1, b);
	if (a + 1 < N) dfs(a + 1, b);
	if (b - 1 >= 0)dfs(a, b - 1);
	if (b + 1 < N)dfs(a, b + 1);
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] < min) min = arr[i][j];
			if (arr[i][j] > max)max = arr[i][j];
		}
	}
	for (int i = min - 1; i <= max; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (arr[j][k] <= i) check[j][k] = -1;
				else check[j][k] = 0;
			}
		}
		count = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (check[j][k] != -1) {
					count++;
					dfs(j, k);
				}
			}
		}
		if (count > ans) ans = count;
	}

	printf("%d\n", ans);
}