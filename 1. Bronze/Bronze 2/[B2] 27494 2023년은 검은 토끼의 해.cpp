#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool Is2023(string n)
{
    string n2023 = "2023";
    for (int i = 0, idx = 0; i < n.size(); i++)
    {
        if (n[i] == n2023[idx])
            idx++;
        if (idx == 4)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    while (n >= 2023)
    {
        result += Is2023(to_string(n));
        n--;
    }
    cout << result << '\n';
}