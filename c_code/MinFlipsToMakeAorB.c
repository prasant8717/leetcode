int minFlips(int a, int b, int c){
    int cnt = 0;
    for(int i = 0; i < 32; ++i)
    {
        int c_bit = (c >> i);
        int a_bit = (a >> i);
        int b_bit = (b >> i);
        if((c_bit & 1) != ((a_bit & 1) | (b_bit & 1)))
        {
            cnt ++;
            if (((a_bit & 1) == (b_bit & 1)) && ((a_bit & 1) == 1))
            {
                cnt ++;
            }
        }
        else
        {
            if ((a_bit == 0) && (b_bit == 0) && (c_bit == 0))
            {
                break;
            }
        }
    }
    return cnt;
}
