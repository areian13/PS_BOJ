#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Cand
{
    int idx;
    int score = 0;
    array<int, 4> cnt = { 0, };

    friend bool operator<(const Cand& a, const Cand& b)
    {
        if (a.score != b.score)
            return a.score < b.score;
        if (a.cnt[3] != b.cnt[3])
            return a.cnt[3] < b.cnt[3];
        return a.cnt[2] < b.cnt[2];
    }

    friend bool operator==(const Cand& a, const Cand& b)
    {
        return a.score == b.score && a.cnt == b.cnt;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<Cand, 3> cand;
    for (int i = 0; i < 3; i++)
        cand[i].idx = i + 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int s;
            cin >> s;

            cand[j].score += s;
            cand[j].cnt[s]++;
        }
    }
    sort(cand.begin(), cand.end());

    array<int, 2> result = { cand[1] == cand[2] ? 0 : cand[2].idx, cand[2].score };
    cout << result[0] << ' ' << result[1] << '\n';
}