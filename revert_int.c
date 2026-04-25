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
