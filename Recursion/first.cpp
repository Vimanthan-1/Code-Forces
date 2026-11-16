#include <iostream>

int func(int i, int n, int tot)
{
    if (i > n)
    {
        return tot;
    }
    else
    {

        tot += i;

        return func(i + 1, n, tot);
    }
}
int main()
{
    int n;
    std::cin >> n;

    std::cout << func(1, n, 0);
}