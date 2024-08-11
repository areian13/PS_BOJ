#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int pre = INT_MAX;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int choco;
        cin >> choco;

        result += (pre < choco);
        pre = choco;
    }
    cout << result << '\n';
}