#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void AddTen(int page, int ten, array<int, 10>& result)
{
    while (page > 0)
    {
        result[page % 10] += ten;
        page /= 10;
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int start = 1, end = n;
    int ten = 1;

    array<int, 10> result = { 0, };
    while (start <= end)
    {
        while (end % 10 != 9 && start <= end)
        {
            AddTen(end, ten, result);
            end--;
        }

        if (start > end)
            break;

        while (start % 10 != 0 && start <= end)
        {
            AddTen(start, ten, result);
            start++;
        }

        start /= 10;
        end /= 10;

        for (int i = 0; i < 10; i++)
            result[i] += (end - start + 1) * ten;

        ten *= 10;
    }

    for (int i = 0; i < 10; i++)
        cout << result[i] << ' ';
    cout << '\n';
}