int largestAltitude(int* gain, int gainSize) {
    int alt = 0;
    int tmp = 0;
    for (int i = 0; i < gainSize; ++i)
    {
        tmp += gain[i];
        if (tmp > alt)
        {
            alt = tmp;
        }
    }
    return alt;
}
