#include <iostream>
#include <vector>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Sum(vector<int>& stick)
{
    return accumulate(stick.begin(), stick.end(), 0);
}

int main()
{
    FastIO;

    int x;
    cin >> x;

    int result = 1;
    vector<int> stick = { 64 };
    while (Sum(stick) > x)
    {
        stick.back() /= 2;
        if (Sum(stick) < x)
        {
            stick.push_back(stick.back());
            result++;
        }
    }
    cout << result << '\n';
}