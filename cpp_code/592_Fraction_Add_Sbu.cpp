class Solution {
public:
    string fractionAddition(string expression) {
        istringstream iss(expression);
        char c;
        int d;
        int n;
        int D = 0;
        int N = 1;
        while (iss >> d >> c >> n) {
            D = D * n + d * N;
            N *= n;
            int t = abs(__gcd(D, N));
            D /= t;
            N /= t;
        }
        return to_string(D) + "/" + to_string(N);
    }
};
