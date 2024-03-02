#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int ExerciseTime(int N, int m, int M, int T, int R)
{
    if (M - m < T)
        return -1;

    int result = 0;
    int X = m;
    while (N > 0)
    {
        result++;
        if (X + T <= M)
        {
            X += T;
            N--;
        }
        else
            X = max(m, X - R);
    }
    return result;
}

int main()
{
    FastIO;

    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;

    int result = ExerciseTime(N, m, M, T, R);
    cout << result << '\n';
}