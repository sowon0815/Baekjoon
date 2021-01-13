#include <stdio.h>

int N;
int arr[130][130];
int count[2];

int check(int x1, int y1, int x2, int y2) {
	//종이 색이 모두 같지 않으면 -1을,
	//모두 같으면 어떤 색인지를 출력(0/1)
	int temp = arr[y1][x1];
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			if (arr[i][j] != temp) return -1;
		}
	}
	return temp;
}

void paper(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		count[arr[y1][x1]]++;
		return;
	}

	if (check(x1, y1, x2, y2) != -1) {
		count[check(x1, y1, x2, y2)]++;
		return;
	}
	else {
		paper(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
		paper((x1+x2)/2+1, y1, x2, (y1 + y2) / 2);
		paper(x1, (y1+y2)/2+1, (x1 + x2) / 2, y2);
		paper((x1+x2)/2+1, (y1 + y2) / 2 + 1, x2, y2);
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	paper(1, 1, N, N);
	printf("%d\n%d\n", count[0], count[1]);
}