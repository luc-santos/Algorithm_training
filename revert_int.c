/*
** Reverses the digits of an integer.
** Extracts digits using modulo and builds the reversed number.
** Checks for overflow before multiplying and adding digits.
** Returns 0 if the reversed number exceeds int limits.
**
** Example:
** x = 123 → 321
** x = -123 → -321
*/

int reverse(int x)
{
    int new_nb;
    int last_digit;

    new_nb = 0;
    while (x != 0)
    {
        if (new_nb > 2147483647 / 10 || (new_nb == 2147483647 / 10 && last_digit > 7))
            return 0;
        if (new_nb < -2147483648 / 10 || (new_nb == -2147483648 / 10 && last_digit < -8))
            return 0;
        last_digit = x % 10;
        new_nb = (new_nb * 10) + last_digit;
        x = x / 10;
    }
        return (new_nb);
}
