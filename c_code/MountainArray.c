bool validMountainArray(int* arr, int arrSize){
    if (arrSize < 3)
        return false;
    int i = 0;
    for (; i < arrSize - 2; ++ i)
        if (arr[i] < arr[i + 1])
            continue;
        else
            break;
    int j = arrSize - 1;
    for (; j > 1; -- j)
        if (arr[j] < arr[j - 1])
            continue;
        else
            break;
    bool sts = false;
    if (i == j)
        sts = true;
    return sts;
}
