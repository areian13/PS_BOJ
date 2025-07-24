#include <iostream>
#include <vector>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Foot
{
	int l = 0, r = 0;

	bool operator==(const Foot& c) const
	{
		return l == c.l && r == c.r;
	}
};

namespace std
{
	template <>
	struct hash<Foot>
	{
		size_t operator()(const Foot& s) const
		{
			size_t h1 = hash<int>()(s.l);
			size_t h2 = hash<int>()(s.r);

			return h1 ^ (h2 << 1);
		}
	};
}

int Dist(int u, int v)
{
	if (u == 0)
		return 2;
	if (u == v)
		return 1;
	if (abs(u - v) == 2)
		return 4;
	return 3;
}

int DP(int cur, Foot foot, vector<unordered_map<Foot, int>>& dp, vector<int>& cmds)
{
	if (cur != 0 && foot.l == foot.r)
		return 10'000'000;
	if (cur == cmds.size())
		return 0;
	if (dp[cur][foot] != 0)
		return dp[cur][foot];

	int l = Dist(foot.l, cmds[cur]);
	int r = Dist(foot.r, cmds[cur]);
	
	return dp[cur][foot] = min(DP(cur + 1, { cmds[cur],foot.r }, dp, cmds) + l, DP(cur + 1, { foot.l,cmds[cur] }, dp, cmds) + r);
}

int main()
{
	FastIO;

	vector<int> cmds;
	while (true)
	{
		int cmd;
		cin>>cmd;

		if (cmd == 0)
			break;

		cmds.push_back(cmd);
	}

	int n = cmds.size();
	vector<unordered_map<Foot, int>> dp(n);

	int result = DP(0, { 0,0 }, dp, cmds);
	cout << result << '\n';
}