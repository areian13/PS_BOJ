#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Info
{
    int num;
    char player;

    friend bool operator<(const Info& a, const Info& b)
    {
        return a.num < b.num;
    }
};

int main()
{
    FastIO;

    int p;
    cin >> p;

    vector<Info> cards;
    for (int i = 0; i < p; i++)
    {
        int c;
        cin >> c;

        for (int j = 0; j < c; j++)
        {
            int n;
            cin >> n;

            cards.push_back({ n,(char)('A' + i) });
        }
    }
    sort(cards.begin(), cards.end());

    string result = "";
    for (Info& card : cards)
        result += card.player;
    cout << result << '\n';
}