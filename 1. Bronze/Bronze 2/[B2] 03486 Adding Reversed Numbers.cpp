#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int RevSumNum(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string sum = to_string(stoi(a) + stoi(b));
    reverse(sum.begin(), sum.end());

    int result = stoi(sum);
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string a, b;
        cin >> a >> b;

        int result = RevSumNum(a, b);
        cout << result << '\n';
    }
}