#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string DeadMan(int k)
{
    if (k % 15 == 0)
        return "DeadMan";
    if (k % 3 == 0)
        return "Dead";
    if (k % 5 == 0)
        return "Man";
    return to_string(k);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string result = DeadMan(i);
        cout << result << '\n';
    }
}