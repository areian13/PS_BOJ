#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
    }

    string cmd;
    cin >> cmd;
    reverse(cmd.begin(), cmd.end());

    cout << cmd << '\n';
}