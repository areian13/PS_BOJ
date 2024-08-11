#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SpecialCard(int sum, vector<int>& cards)
{
    int n = cards.size();

    for (int i = 0; i < n; i++)
    {
        if (cards[i] == sum - cards[i])
            return i + 1;
    }
    return -1;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> cards(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
        sum += cards[i];
    }

    int result = SpecialCard(sum, cards);
    cout << result << '\n';
}