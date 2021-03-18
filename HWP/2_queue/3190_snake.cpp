#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, K, L;
int map[101][101];
int Dir[4][2] = { {-1 ,0}, { 0,1} , {1,0}, {0,-1} }; // ���� �� ������ �Ʒ� �������� 90���� ȸ�� ��� 
class Snake {
public:
	Snake() {
		this->body.push_back(make_pair(this->headx, this->heady)); // ���� �� �ٵ���� 1�� 
	}
	bool move() { // �����̰��� true�̸� ��� ����, false�� ���� ���� 
		int nx = this->headx + Dir[d][0];  // ���� x ��ǥ
		int ny = this->heady + Dir[d][1]; // ���� y ��ǥ 
		for (int i = 0; i < body.size(); ++i) { // ���� x y ��ǥ�� body�� ���� ��� ���� 
			if (nx == body[i].first && ny == body[i].second) return false;
		}
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) { // ���� ���� ��� ���� 
			return false;
		}
		if (map[nx][ny] == 1) { // ��� �� ��� �� �ø���.
			body.push_back(make_pair(nx, ny));
			this->headx = nx;
			this->heady = ny;
			map[nx][ny] = 0;
			return true;
		}
		else { // ����� �ƴ� ��� �Ӹ��� ������ġ�� ���� �������� �� �� �� ��ġ�� ���󰣴� 
			this->body = vector<pair<int, int>>(this->body.begin() + 1, this->body.end());
			body.push_back(make_pair(nx, ny));
			this->headx = nx;
			this->heady = ny;
			return true;
		}
	}
	int headx = 0;
	int heady = 0;
	int d = 1;
	vector<pair<int, int>> body;
};
void PrintSnake(Snake s) { // �α׸� ���� ����Ʈ �ڵ� 
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			bool isBody = false;
			for (int k = 0; k < s.body.size(); ++k) {
				if (s.body[k].first == i && s.body[k].second == j) {
					isBody = true;
					break;
				}
			}
			if (isBody) printf("* ");
			else printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}
int main(int argc, const char* argv[]) {
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		map[x - 1][y - 1] = 1;
	}
	queue<pair<int, char>> q; // q�� �̿��ؼ� ��� ������ �� �� �ֵ��� 
	scanf("%d", &L);
	for (int i = 0; i < L; ++i) {
		int t;
		char c;
		scanf("%d %c", &t, &c);
		q.push(make_pair(t, c)); // �ð�, �������� ť�� Ǫ�� 
	}
	Snake s;
	int time = 0;
	bool result = true;
	while (true) {
		time++;
		result = s.move(); // �����̰� 
		//printf("%d\n", time);
		//PrintSnake(s);
		if (!result) break;		// �����̸� ���� ����
		if (!q.empty()) { // ť�� ������� ���� ��� 
			int timeTurn = q.front().first; // �ð��� �Ǿ����� Ȯ���ϰ� 
			if (time == timeTurn) { // �ð� �� �Ǿ����� 
				if (q.front().second == 'D') { // ���⿡ �°� D 
					s.d += 1;
					if (s.d >= 4) s.d = 0;
				}
				else if (q.front().second == 'L') { // L�� ȸ�� �Ͽ� ���� �Ͽ� ����� �� �ֵ���.
					s.d -= 1;
					if (s.d < 0) s.d = 3;
				}
				q.pop();
			}
		}
	}
	printf("%d\n", time);
	return 0;
}