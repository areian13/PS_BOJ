#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<char> course(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> course[i];

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (course[i] == course[n]);
    cout << result << '\n';
}