// matrix chain multiplication
int matmul(vec dim, int be, int en, auto& dp) {

	// if one or 0 matrix
	if (be == en || be + 1 == en) return 0;

	if (dp[be][en] != -1) return dp[be][en];

	int best = INT_MAX;

	for (int i = be + 1; i <= en - 1; ++i) {
		int lans = matmul(dim, be, i, dp);
		int rans = matmul(dim, i, en, dp);
		int ans = lans + rans + dim[be] * dim[i] * dim[en];
		best = min(ans, best);
	}
	return dp[be][en] = best;
}



int matmul2(vec dim){
	int n = dim.size();

	mat dp(n, vec(n, 0));

	for(int len = 2; len < n; ++len){

		int en = n - 2;
		int best = INT_MAX;
		for(int be = n - len - 1; be >= 0; --be, --en){

			for(int k = be; k < en; ++k){
				int ans = dp[be][k] + dim[be]*dim[k]*dim[en] + dp[k][en];
				best= min(ans, best);
			}

			dp[be][en] = best;
		}

	}
	printMat(dp);
	return dp[0][n - 1];
}