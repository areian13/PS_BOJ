#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 9'999

int CountRandom(int n)
{
    
    array<bool, MAX + 1> isVisited = { false, };
    isVisited[n] = true;
    int result = 1;
    while (true)
    {
        n = (n % 1'000) / 10;
        n *= n;

        if (isVisited[n])
            return result;
        
        result++;
        isVisited[n] = true;
    }
    return -1;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = CountRandom(n);
    cout << result << '\n';
}