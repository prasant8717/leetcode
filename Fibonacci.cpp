class Solution {
public:
    int fib(int n) {
        //if (n == 0)
        //    return 0;
        //if (n == 1)
        //    return 1;
        //return fib(n -1) + fib(n - 2);
        int n0 = 0;
        int n1 = 1;
        int n2 = 0;
        for (int i = 0; i < n + 1; ++ i) {
            if (i == 0)
                n2 = n0;
            else if (i == 1)
                n2 = n1;
            else {
                n2 = n1 + n0;
                n0 = n1;
                n1 = n2;
            }
        }
        return n2;
    }
};
