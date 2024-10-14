#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int BS(int n)
{
    int result = (n % 2 == 1);
    n /= 2;

    int start = 1 - result;
    int end = 50 - result;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        result++;
        if (mid < n)
            start = mid + 1;
        else if (n < mid)
            end = mid - 1;
        else
            return result;
    }
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        int result = BS(n);
        cout << result << '\n';
    }
}