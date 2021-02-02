#include <iostream>
using namespace std;
typedef long long ll;
const int ST = 1 << 17;
ll N, arr[101010], seg[ST * 2], ans[ST * 2];

void build() {
	for (int i = ST; i < ST + N; i++) {
		seg[i] = 1;
	}
	for (int i = ST - 1; i > 0; i--) {
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
}

void update(ll node, ll i, ll val) {
	while (1) {
		if (val == 0) {
			while (1) {
				if (node >= ST) {
					ans[node] = i;
					seg[node] = -1;
					for (int k = node / 2; k >= 1; k /= 2) {
						seg[k]--;
					}
					return;
				}
				if (seg[node * 2] >= 1) node *= 2;
				else node = node * 2 + 1;
			}
		}
		if (seg[2 * node] > val) update(2 * node, i, val);
		else update(2 * node + 1, i, val - seg[2 * node]);
		return;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	build();
	for (int i = 1; i <= N; i++) {
		update(1, i, arr[i]);
	}
	for (int i = ST; i < ST + N; i++) {
		cout << ans[i] << '\n';
	}
}