#include <iostream>
#include <algorithm> //sort
#include <cmath>; //pow
using namespace std;
int N, M;
long long sum, ans = 0;
long long arr[101010];

int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long p; //2^64 저장
	p = pow(2, 64);

	cin >> M >> N;
	sum = -M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	} 
	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		long long temp = min(arr[i], sum / (N - i));
		sum -= temp;
		ans += temp * temp;
		ans %= p;
	}
	cout << ans;
	return 0;
}