#include <stdio.h>
int N;
int ans[7000][7000];
void star(int y, int x, int op, int n) {
	if (n == N) {
		ans[y][x] = op;
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int temp = 1;
			if (i == 1 && j == 1) 	temp = 0;
			star(3 * y + i, 3 * x + j, op*temp, n * 3);
		}
	}
}

int main(void) {
	scanf("%d", &N);
	star(0, 0, 1, 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ans[i][j] == 1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}