class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        if (k <= numOnes)
            sum = k;
        else if (k <= numOnes + numZeros)
            sum = numOnes;
        else
            sum = numOnes - (k - numOnes - numZeros); 
        return sum;
    }
};
