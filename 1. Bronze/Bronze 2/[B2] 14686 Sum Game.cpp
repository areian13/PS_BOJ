#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int sumA = 0, sumB = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        sumA += a[i];
        sumB += b[i];

        if (sumA == sumB)
            result = i + 1;
    }
    cout << result << '\n';
}