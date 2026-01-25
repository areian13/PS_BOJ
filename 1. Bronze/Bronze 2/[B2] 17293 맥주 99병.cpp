#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = n; i >= 2; i--)
    {
        printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
        printf("Take one down and pass it around, %d %s of beer on the wall.\n\n", i - 1, (i == 2 ? "bottle" : "bottles"));
    }

    printf("1 bottle of beer on the wall, 1 bottle of beer.\n");
    printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");

    printf("No more bottles of beer on the wall, no more bottles of beer.\n");
    printf("Go to the store and buy some more, %d %s of beer on the wall.", n, (n == 1 ? "bottle" : "bottles"));
}