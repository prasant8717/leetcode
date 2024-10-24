int numTilings(int n) {
	if (n < 3) {
		return n;
	}
    long long tl[n + 1][3];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            tl[i][j] = 0;
        }
    }
	tl[0][0] = tl[1][0] = 1;
	tl[1][1] = tl[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		tl[i][0] = (tl[i - 1][0] + tl[i - 2][0]
					+ tl[i - 2][1] + tl[i - 2][2]) % ((long long)1000000000 + 7);
		tl[i][1] = (tl[i - 1][0] + tl[i - 1][2]) % ((long long)1000000000 + 7);
		tl[i][2] = (tl[i - 1][0] + tl[i - 1][1]) % ((long long)1000000000 + 7);
	}
	return tl[n][0];    
}
