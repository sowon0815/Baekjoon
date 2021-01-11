#include <stdio.h>
int N;
char arr[70][70];
int check(int x1, int y1, int x2, int y2) {
	//사각형 안에 든 숫자가 모두 같으면 1, 다르면 0을 리턴
	char a = arr[y1][x1];
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			if (arr[i][j] != a) return 0;
		}
	}
	return 1;
}

void printAns(int x1, int y1, int x2, int y2) {
	if (check(x1, y1, x2, y2) == 1) {
		printf("%c", arr[y1][x1]);
		return;
	}
	else {
		printf("(");
		printAns(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
		printAns((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2);
		printAns(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2);
		printAns((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2);
		printf(")");
	}

}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}
	printAns(0, 0, N - 1, N - 1);
}