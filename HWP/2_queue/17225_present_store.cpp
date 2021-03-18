#include <iostream>
#include <queue>
using namespace std;
int A, B, N;
struct cmp { // pair�� �� �ϱ� ���� cmp
	bool operator()(pair<int, char> a, pair<int, char> b) {
		if (a.first > b.first) return true; // ���� ���� 1 
		else if (a.first < b.first) return false;
		else {
			if (a.second >= b.second) return true; // B���� �켱 ���� 
			else if (a.second < b.second) return false;
		}
	}
};
int main() {
	scanf("%d %d %d", &A, &B, &N);
	int t, m;
	char c;
	priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
	vector<int> ans_b, ans_r;
	int end_t_b = 0, end_t_r = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%d %c %d", &t, &c, &m);

		if (c == 'B') {
			t = end_t_b < t ? t : end_t_b; // �Է� �ð��� ���� �۾��� ������ �ð��߿� ���� �ð��� ���۽ð����� 
			for (int j = 0; j < m; j++) {
				pq.push(make_pair((t), c)); // ���� �ð���, �� push 
				t += A; // ���� ���� �ð� 
			}
			end_t_b = t; // ������ �ð� ���� 
		}
		else {
			t = end_t_r < t ? t : end_t_r;
			for (int j = 0; j < m; j++) {
				pq.push(make_pair((t), c));
				t += B;
			}
			end_t_r = t;
		}
	}

	int i = 1;
	while (!pq.empty()) {
		pair<int, char> top = pq.top();
		pq.pop();
		if (top.second == 'B') {
			ans_b.push_back(i++);
		}
		else {
			ans_r.push_back(i++);
		}
	}
	printf("%d\n", ans_b.size());
	for (int i = 0; i < ans_b.size(); ++i) {
		printf("%d ", ans_b[i]);
	}
	puts("");

	printf("%d\n", ans_r.size());
	for (int i = 0; i < ans_r.size(); ++i) {
		printf("%d ", ans_r[i]);
	}
	puts("");

	return 0;
}