bool isPalindrome(int x) {
    if (x < 0)
    {
        return false;        
    }
    int digits[10];
    int num = x;
    int idx = 0;
    while(num != 0)
    {
        digits[idx] = num % 10;
        num = num / 10;
        idx ++;
    }
    for (int i = 0; i < idx / 2; ++i)
    {
        if (digits[i] != digits[idx - i - 1])
        {
            return false;
        }
    }
    return true;
}
