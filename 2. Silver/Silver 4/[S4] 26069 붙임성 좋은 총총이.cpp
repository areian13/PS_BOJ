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

    unordered_map<string, bool> isDancing;
    isDancing["ChongChong"] = true;

    int result = 1;
    while (n--)
    {
        string a, b;
        cin >> a >> b;

        if (isDancing[a] || isDancing[b])
        {
            result += !isDancing[a];
            result += !isDancing[b];

            isDancing[a] = isDancing[b] = true;
        }
    }
    cout << result << '\n';
}