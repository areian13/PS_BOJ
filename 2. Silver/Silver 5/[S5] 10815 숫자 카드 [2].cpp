#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool HasCard(int card, vector<int>& cards)
{
    int start = 0, end = cards.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (cards[mid] == card)
            return true;
        if (cards[mid] < card)
            start = mid + 1;
        else if (cards[mid] > card)
            end = mid - 1;
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++)
        cin >> cards[i];

    sort(cards.begin(), cards.end());

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int card;
        cin >> card;

        bool result = HasCard(card, cards);
        cout << result << '\n';
    }
}