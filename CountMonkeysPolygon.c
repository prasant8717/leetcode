int monkeyMove(int n) {
    long long result = 1;
    long long mod = 1e9 + 7;
    long long tmp = n;
    long long power = 2;
    while(tmp > 0)
    {
        if (tmp & 1)
        {
            result = (result * power) % mod;
        }
        power = (power * power) % mod;
        tmp = tmp >> 1;
    }
    return (result - 2 + mod) % mod;
}
