#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CallTime(int n, int l, int d)
{
    int size = n * (l + 5);
    vector<bool> isSilence(size, false);
    for (int i = 0; i < n; i++)
    {
        int start = i * (l + 5) + l;
        for (int j = 0; j < 5; j++)
            isSilence[start + j] = true;
    }

    int result = 0;
    while (result < size)
    {
        if (isSilence[result])
            break;
        result += d;
    }
    return result;
}

int main()
{
    FastIO;

    int n, l, d;
    cin >> n >> l >> d;

    int result = CallTime(n, l, d);
    cout << result << '\n';
}