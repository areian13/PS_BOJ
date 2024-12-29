#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<string, int> cnt;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string card;
        cin >> card;

        cnt[card]++;

        if (cnt[card] > 4)
        {
            result = i + 1;
            break;
        }
    }
    cout << result << '\n';
}