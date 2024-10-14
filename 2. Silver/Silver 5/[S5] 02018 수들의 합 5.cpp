#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 1;

    int left = 1, right = 1;
    int sum = 0;
    while (left <= right && right <= n)
    {
        if (sum < n)
        {
            sum += right;
            right++;
        }
        else
        {
            if (sum == n)
                result++;
            sum -= left;
            left++;
        }
    }
    cout << result << '\n';
}