double findMaxAverage(int* nums, int numsSize, int k) {
    double avg = -99999.99;
    int begin = 0;
    int sum = 0;
    for (int i = 0; i < k; ++i)
    {
        sum += nums[i];
    }
    while (begin + k <= numsSize)
    {
        if (begin > 0)
        {
            sum = sum - nums[begin - 1] + nums[begin + k - 1];
        }
        double tmp_avg = (double)sum / k;
        if (tmp_avg > avg)
        {
            avg = tmp_avg;
        }
        begin ++;
    }
    return avg;
}
