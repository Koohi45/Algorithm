#include <iostream>
#include <vector>

using namespace std;

int maxSushi(vector<int>& s, int n, int d, int k, int c)
{
	//구간마다 먹은 초밥 개수 저장할 배열
	vector<int> count_eat(d + 1, 0);

	//슬라이딩 윈도우 첫 시작 초기화
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (count_eat[s[i]] == 0)
			cnt++;
		count_eat[s[i]]++;
	}
	//쿠폰
	if (count_eat[c]++ == 0)
		cnt++;


	//슬라이딩 윈도우 이동
	int ans = cnt;
	for (int i = 1; i < n; i++) {
		//윈도우 이동 전 초밥 제거
		count_eat[s[i - 1]]--;	
		if (count_eat[s[i - 1]] == 0)
			cnt--;
		
		//윈도우 영역에 들어온 초밥
		if (count_eat[s[(i + k - 1) % n]] == 0)
			cnt++;
		count_eat[s[(i + k - 1) % n]]++;

		ans = max(cnt, ans);
	}

	return ans;
}

int main()
{
	int n, d, k, c;
	vector<int> sushi;

	cin >> n >> d >> k >> c;
	sushi.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> sushi[i];

	cout << maxSushi(sushi, n, d, k, c) << '\n';
}
