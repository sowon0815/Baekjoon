#include <stdio.h>
int N, count[3];
int arr[2200][2200];
int check(int x1, int y1, int x2, int y2) {
	//숫자 모두 같으면 return 1
	//다르면 return 0->9개로 분할
	int temp = arr[y1][x1];
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			if (arr[i][j] != temp) return 10;
		}
	}
	return temp;
}
void paper(int x1, int y1, int x2, int y2, int n) {
	if (x1 == x2) {
		count[arr[y1][x1] + 1]++;
		return;
	}

	if (check(x1, y1, x2, y2) != 10) {
		count[check(x1, y1, x2, y2)+1]++;
		return;
	}
	else {
		paper(x1, y1, x1 + n / 3 - 1, y1 + n / 3 - 1, n / 3);
		paper(x1 + n / 3, y1, x1 + 2 * n / 3 - 1, y1 + n / 3 - 1, n / 3);
		paper(x1 + 2 * n / 3, y1, x2, y1 + n / 3 - 1, n / 3);

		paper(x1, y1 + n / 3, x1 + n / 3 - 1, y1 + 2 * n / 3 - 1, n / 3);
		paper(x1 + n / 3, y1 + n / 3, x1 + 2 * n / 3 - 1, y1 + 2 * n / 3 - 1, n / 3);
		paper(x1 + 2 * n / 3, y1 + n / 3, x2, y1 + 2 * n / 3 - 1, n / 3);

		paper(x1, y1 + 2 * n / 3, x1 + n / 3 - 1, y2, n / 3);
		paper(x1 + n / 3, y1 + 2 * n / 3, x1 + 2 * n / 3 - 1, y2, n / 3);
		paper(x1 + 2 * n / 3, y1 + 2 * n / 3, x2, y2, n / 3);

	}
}
int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	paper(1, 1, N, N, N);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", count[i]);
	}
}