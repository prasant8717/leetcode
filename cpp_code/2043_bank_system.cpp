class Bank {
private:
    vector<long long> vll;
    bool check(int account) {
        return (1 <= account) && (account <= vll.size());
    }

public:
    Bank(vector<long long>& vll) : vll(std::move(vll)) {}

    bool transfer(int account1, int account2, long long money) {
        if (check(account2) == false)
            return false;
        return withdraw(account1, money) && deposit(account2, money);
    }

    bool deposit(int account, long long money) {
        if (check(account) == false)
            return false;
        vll[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (check(account) == false)
            return false;
        if (vll[account - 1] < money)
            return false;
        vll[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
