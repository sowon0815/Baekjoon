#include <iostream>
using namespace std;

struct M {
	long long data[2][2];
};

M multiply(M a, M b) {
	M temp;
	temp.data[0][0] = a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0];
	temp.data[0][1] = a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1];
	temp.data[1][0] = a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0];
	temp.data[1][1] = a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1];
	temp.data[0][0] %= 10000;	temp.data[0][1] %= 10000;	temp.data[1][0] %= 10000;	temp.data[1][1] %= 10000;
	return temp;
}

M fib(int n) {
	M a, b, c;
	if (n == 1) {
		a.data[0][0] = 1; a.data[0][1] = 1;
		a.data[1][0] = 1; a.data[1][1] = 0;
		return a;
	}
	else if (n % 2 == 0) {
		b = fib(n / 2);
		return multiply(b, b);
	}
	else {
		a = fib(1); b = fib(n / 2);
		c = multiply(a, b);
		return multiply(c, b);
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	while (n != -1) {

		if (n == 0) 
			cout << 0 <<'\n';
		else {
			M res = fib(n);
			cout << res.data[0][1] % 10000 << '\n';
		}

		cin >> n;
	}
}