int findLengthOfShortestSubarray(int* arr, int arrSize) {
        int l = 0;
        for (int i = 0; i < arrSize - 1; ++ i) {
            if (arr[i + 1] >= arr[i]) {
                l ++;
                continue;
            }
            break;
        }
        int r = arrSize - 1;
        for (int i = arrSize - 1; i > 0; -- i) {
            if (arr[i - 1] <= arr[i]) {
                r --;
                continue;
            }
            break;
        }
        int res = arrSize - l - 1;
        if (res > r)
            res = r;
        int ll = l;
        int rr = arrSize - 1;
        while ((ll >= 0) && (rr >= r) && (rr > ll)) {
            if (arr[ll] <= arr[rr])
                -- rr;
            else
                -- ll;
            if (res > (rr - ll))
                res = rr - ll;
        }
        return res;
}
