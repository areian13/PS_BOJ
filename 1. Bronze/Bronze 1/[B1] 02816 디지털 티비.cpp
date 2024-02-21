#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int kbs1, kbs2;
    for (int i = 0; i < n; i++)
    {
        string channel;
        cin >> channel;

        if (channel == "KBS1")
            kbs1 = i;
        else if (channel == "KBS2")
            kbs2 = i;
    }
    if (kbs1 > kbs2)
        kbs2++;

    string result = "";
    for (int i = 0; i < kbs1; i++)
        result += '1';
    for (int i = 0; i < kbs1; i++)
        result += '4';

    for (int i = 0; i < kbs2; i++)
        result += '1';
    for (int i = 0; i < kbs2 - 1; i++)
        result += '4';

    cout << result << '\n';
}