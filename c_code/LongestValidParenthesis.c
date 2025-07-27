int longestValidParentheses(char* s) {
    int max = 0;
    int ob = 0;
    int cb = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i ++) {
        if (s[i] == '(') {
            ob ++;
        } else {
            cb ++;
        }
        if (ob == cb) {
            if (max < (cb << 1))
                max = (cb << 1);
        } else if (cb > ob) {
            ob = 0;
            cb = 0;
        }
    }
    ob = 0;
    cb = 0;
    for (int i = len - 1; i >= 0; i --) {
        if (s[i] == '(') {
            ob ++;
        } else if (s[i] == ')') {
            cb ++;
        }
        if (ob == cb) {
            if (max < (ob << 1))
                max = (ob << 1);
        } else if (ob > cb) {
            ob = 0;
            cb = 0;
        }
    }
    return max;
}
