#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 4> arr;
    for (int i = 0; i < 4; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    swap(arr[1], arr[2]);

    for (int i = 0; i < 4; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}
