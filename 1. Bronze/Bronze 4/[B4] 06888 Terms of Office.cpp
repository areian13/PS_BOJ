#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;


    int start, end;
    cin >> start >> end;

    for (int result = start; result <= end; result += 60)
        printf("All positions change in year %d\n", result);
}