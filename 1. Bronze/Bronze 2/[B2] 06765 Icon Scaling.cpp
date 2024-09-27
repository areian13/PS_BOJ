#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<string> icon =
    {
        "*x*",
        " xx",
        "* *"
    };

    int n;
    cin >> n;

    for (int i = 0; i < n * 3; i++)
    {
        for (int j = 0; j < n * 3; j++)
            cout << icon[i / n][j / n];
        cout << '\n';
    }
}