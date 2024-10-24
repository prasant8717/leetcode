bool canArrange(int* arr, int arrSize, int k) {
    int *ocr = (int *)malloc(sizeof(int) * k);
    bool sts = true;
    for (int i = 0; i < k; ++i)
    {
        ocr[i] = 0;
    }
    for (int i = 0; i < arrSize; ++i)
    {
        int rem = arr[i] % k;
        if (rem < 0)
        {
            rem = k + rem;
        }
        if (ocr[(k - rem) % k] != 0)
        {
            ocr[(k - rem) % k] --;
        }
        else
        {
            ocr[rem] ++;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        if (ocr[i] != 0)
        {
            sts = false;
            break;
        }
    }
    free(ocr);
    return sts;    
}
