#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<string> scores =
    {
        "ABCDEFGHJLM",
        "ACEFGHILM",
        "ACEFGHILM",
        "ABCEFGHLM",
        "ACEFGHLM",
        "ACEFGHLM",
        "ACEFGHLM",
        "ACEFGHLM",
        "ACEFGHLM",
        "ABCFGHLM"
    };

    int n;
    cin >> n;

    string result = scores[n - 1];
    cout << result.size() << '\n';
    for (char c : result)
        cout << c << ' ';
    cout << '\n';
}