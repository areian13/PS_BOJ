#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Info
{
    int score, idx, rank;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Info> info(n);
    for (int i = 0; i < n; i++)
    {
        int score;
        cin >> score;

        info[i] = { score, i };
    }
    sort(info.begin(), info.end(), [](Info& a, Info& b) { return a.score < b.score; });
    for (int i = 0; i < n; i++)
        info[i].rank = (i > 0 && info[i].score == info[i - 1].score ? info[i - 1].rank : i + 1);
    sort(info.begin(), info.end(), [](Info& a, Info& b) { return a.idx < b.idx; });
    for (int i = 0; i < n; i++)
        cout << info[i].rank << '\n';
}