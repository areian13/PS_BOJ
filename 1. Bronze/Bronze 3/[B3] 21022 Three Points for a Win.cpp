#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;

        result += (a[i] == b ? 1 : (a[i] > b ? 3 : 0));
    }
    cout << result << '\n';
}