#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string b1, k1, b2, k2;
    cin >> n >> b1 >> k1 >> b2 >> k2;

    string result = "";
    bool isBB84 = true;
    for (int i = 0; i < n; i++)
    {
        if (b1[i] != b2[i])
            continue;

        if (k1[i] == k2[i])
            result += k1[i];
        else
        {
            isBB84 = false;
            break;
        }
    }

    if (!isBB84)
        cout << "htg!" << '\n';
    else
        cout << result << '\n';
}