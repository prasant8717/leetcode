int myAtoi(char* s) {
    int ret = 0;
    int len = strlen(s);
    if (len <= 200)
    {
        int sign = 1;
        int val = 0;
        char next;
        for (int i = 0; i < len; ++i) {
            next = s[i];
            if ((next >= '0') && (next <= '9'))
            {
                int tmp = next - 0x30;
                unsigned long long sat = tmp + ((unsigned long long)ret * 10);
                if (sat < 0x80000000)
                {
                    ret = (int)sat;
                }
                else
                {
                    if (sign == -1)
                    {
                        ret = 0x80000000;
                        sign = 1;
                    }
                    else
                    {
                        ret = 0x7FFFFFFF;
                    }
                    break;
                }
                val = 1;
                //printf("\nsat - %x, ret - %d, tmp - %d\n", sat, ret, tmp);
            }
            else if (next == '-')
            {
                if(val == 0)
                {
                    val = 1;
                    sign = -1;
                }
                else
                {
                    break;
                }
            }
            else if (next == '+')
            {
                if(val != 0)
                {
                    break;
                }
                else
                {
                    val = 1;
                }
            }
            else if (next == ' ')
            {
                if (val != 0)
                {
                    break;
                }
            }
            else if (next == '*')
            {
                ;
            }
            else
            {
                break;
            }
        }
        ret = sign * ret;
    }
    //printf("\noutput - %d\n", ret);
    return ret;
}
