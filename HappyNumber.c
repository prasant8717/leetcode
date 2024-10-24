bool isHappy(int n){
    int temp = 0;
    while (n)
    {
        char a = (n % 10);
        n /= 10;
        temp += ((int)a * (int)a);
        if (n == 0)
        {
            if ((temp == 1) || (temp == 7))
            {
                return true;
            }
            else if (temp < 10)
                return false;
            n = temp;
            temp = 0;
        }
    }
    return false;
}
