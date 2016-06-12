class Solution {
public:
	/**
	* @param A an integer array
	* @param k an integer
	* @return an integer
	*/
	int postOffice(vector<int>& A, int k) {

		int dp[50][600];//记录最短距离，最终需要的值，第一维是邮局
		int s[600][600];//决策变量
		int w[600][600];//两个村庄之间的距离

		memset(dp, 0, sizeof(dp));
		memset(w, 0, sizeof(w));
		memset(s, 0, sizeof(s));
		int n = A.size();
	//	cout << n<<" ";
		// for(int i=0;i<n;i++)  printf("%d",A[i]);
		//冒泡排序
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j<n; j++)
				if (A[j]<A[i])
				{
					int temp = A[j];
					A[j] = A[i];
					A[i] = temp;
				}
		}

// 		for (int i = 0; i < n; i++)
// 			cout << A[i]<<"  ";
// 		cout << endl;

		//w的初始化
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				w[i][j] = w[i][j - 1] + abs(A[j - 1] - A[i - 1]);
			}
		}

		//s[1]的初始化
		for (int i = 1; i <= n; i++)
		{
			s[i][i] = i - 1;//由s[i][j]记录使用前i-1个邮局的村庄数
			int k2 = (1 + i) / 2;
			dp[1][i] = w[k2][i]-w[k2][1-1];
		}

		//只有当村庄数>邮局数（k）才需要进行吐下操作
		if (n > k){
			for (int i = 2; i <= k; i++)
			{
				int  temp,k2;
				dp[i][n]= 1000000;
				int j = n;
				for (int k1 = s[i - 1][j]; k1 <= n; k1++)
				{
					k2 = (k1 + 1 + n) / 2;
					temp = dp[i - 1][k1] + (w[k2][n]-w[k2][k1]);
					if (temp < dp[i][j]){
						dp[i][j] = temp;
						s[i][j] = k1;
					}
				}
				for (j--; j>i; j--)
				{
					dp[i][j] = 1000000;
					for (int k1 = s[i - 1][j]; k1 <= s[i][j+1]; k1++)
					{
						k2 = (k1 + 1 + j) / 2;
						temp = dp[i - 1][k1] + (w[k2][j] - w[k2][k1]);
						if (temp < dp[i][j]){
							dp[i][j] = temp;
							s[i][j] = k1;
						}
					}
				}
			}
		}

		return dp[k][n];
	}
};
