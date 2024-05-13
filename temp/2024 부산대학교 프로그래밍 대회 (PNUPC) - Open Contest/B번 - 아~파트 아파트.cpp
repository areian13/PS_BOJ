#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Hand
{
    int i, f;

    friend bool operator<(const Hand& a, const Hand& b)
    {
        return a.f < b.f;
    }
};

int DrinkingMan(int n, vector<Hand>& hands)
{
    int m = hands.size();
    sort(hands.begin(), hands.end());

    queue<Hand> Q;
    for (int i = 0; i < m; i++)
        Q.push(hands[i]);

    int result = -1;
    for (int i = 0; i < n; i++)
    {
        Hand hand = Q.front();
        Q.pop();

        result = hand.i;

        Q.push(hand);
    }
    return result + 1;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Hand> hands(m * 2);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        hands[i * 2 + 0] = { i,l };
        hands[i * 2 + 1] = { i,r };
    }

    int result = DrinkingMan(n, hands);
    cout << result << '\n';
}