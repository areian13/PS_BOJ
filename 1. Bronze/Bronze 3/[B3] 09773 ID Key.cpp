#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string card;
        cin >> card;

        int n = card.size();
        int result = 0;
        for (int i = 0; i < n; i++)
            result += (card[i] - '0');
        result += stoi(card.substr(10, 3)) * 10;

        if (result < 1000)
            result += 1000;
        result %= 10'000;
        printf("%04d\n", result);
    }
}