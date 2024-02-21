#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 10

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        array<int, SIZE> arr;

        for (int i = 0; i < SIZE; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end(), greater<int>());

        cout << arr[2] << '\n';
    }
}