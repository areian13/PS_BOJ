#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Info
{
    string num;
    int cnt;

    bool operator==(const Info& c) const
    {
        return num == c.num && cnt == c.cnt;
    }
};

namespace std
{
    template <>
    struct hash<Info>
    {
        size_t operator() (const Info& info) const
        {
            hash<string> hash_func;

            return hash_func(info.num) ^ info.cnt;
        }
    };
}

int main()
{
    FastIO;

    string n;
    int k;
    cin >> n >> k;

    unordered_map<Info, bool> isVisited;
    isVisited[{ n, 0 }] = true;

    queue<Info> Q;
    Q.push({ n,0 });

    string result = "-1";
    while (!Q.empty())
    {
        string cur = Q.front().num;
        int cnt = Q.front().cnt;
        Q.pop();

        if (cnt == k)
        {
            result = max(result, cur);
            continue;
        }

        for (int i = 0; i < n.size() - 1; i++)
        {
            for (int j = i + 1; j < n.size(); j++)
            {
                if (i == 0 && cur[j] == '0')
                    continue;

                string nxt = cur;
                swap(nxt[i], nxt[j]);

                if (isVisited[{ nxt, cnt + 1 }])
                    continue;

                isVisited[{ nxt, cnt + 1 }] = true;
                Q.push({ nxt,cnt + 1 });
            }
        }
    }
    cout << result << '\n';
}