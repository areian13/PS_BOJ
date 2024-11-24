#include <iostream>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<int, bool> hasCard;
    for (int i = 0; i < n; i++)
    {
        int card;
        cin >> card;

        hasCard[card] = true;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int card;
        cin >> card;

        bool result = hasCard[card];
        cout << result << '\n';
    }
}