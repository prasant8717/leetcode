/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
	int begin = 1;
    int end = n;
    if (guess(n) == 0)
    {
        return n;
    }
    while (begin < end)
    {
        int mid = begin;
        int del = (end - begin);
        mid += (del / 2);
        int ret = guess(mid);
        if (ret == -1)
        {
            end = mid;
        }
        else if (ret == 1)
        {
            begin = mid;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
