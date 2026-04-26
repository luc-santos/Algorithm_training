#include <stdbool.h>

bool isPalindrome(int x)
{
    long new_nb;
    int original;
    int digit;

    if (x < 0)
        return false;

    original = x;
    new_nb = 0;

    while (x != 0)
    {
        digit = x % 10;
        new_nb = new_nb * 10 + digit;
        x /= 10;
    }

    if (new_nb == original)
        return true;
    else
        return false;
}
