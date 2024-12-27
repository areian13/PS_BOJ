#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string c1, c2;
    cin >> n >> c1 >> c2;

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (c1[i] == 'C' && c2[i] == 'C');
    cout << result << '\n';
}