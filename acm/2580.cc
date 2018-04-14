#include <cstdio>
#include <cstdlib>
// 20150774 김태우
int map[9][9];
bool chk(int x, int y)
{
	bool cnt[10]{};
	for (int i = 0; i < 9; ++i)
		// row
		if (map[x][i] == 0) continue;
		else if (!cnt[map[x][i]]) cnt[map[x][i]] = 1;
		else return false;

		for (int i = 0; i < 10; ++i) cnt[i] = 0;

		// col
		for (int i = 0; i < 9; ++i)
			if (map[i][y] == 0) continue;
			else if (!cnt[map[i][y]]) cnt[map[i][y]] = 1;
			else return false;

			for (int i = 0; i < 10; ++i) cnt[i] = 0;

		// part (3/3 총 9 개 구역)
		int xx = x / 3 * 3;
		int yy = y / 3 * 3;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (map[xx + i][yy + j] == 0) continue;
				else if (!cnt[map[xx + i][yy + j]]) cnt[map[xx + i][yy + j]] = 1;
				else return false;

		return true;
}
void solve()
{
	int x, y;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			if (map[i][j] == 0) { x = i, y = j; goto BT; }

	//printMap();
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j) printf("%d ", map[i][j]);
		puts("");
	}
	exit(0);

	BT:
	for (int num = 1; num <= 9; ++num)
	{
		map[x][y] = num;
		if (chk(x, y)) solve();
		//bt
		map[x][y] = 0;
	}
}
int main()
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			scanf("%d", map[i] + j);
	solve();
	return 0;
}