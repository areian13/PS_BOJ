#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int t;
        cin >> t;

        sum += t;
    }

    bool result = sum + 300 <= 1'800;
    if (result)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}