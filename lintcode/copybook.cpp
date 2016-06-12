class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
    int a[3][1005];
	int b[1005][1005];

	int n =pages.size();
	a[1][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		a[1][i] = a[1][i - 1] + pages[i-1];
	}

	for (int i = 1; i <= n; i++){
		b[i][i] = pages[i-1];
		for (int j = i + 1; j <= n; j++){
			b[i][j] = b[i][j-1] + pages[j-1];
		}

	}

	int m=a[1][1];
	for (int i = 2; i <= k; i++)
	{
		int t = 0, f = 0;
		a[i%2][0] = 0;
		a[i%2][1] = m;
		for (int j = 2; j <= n; j++){

			while (t<j){
				if (b[t + 1][j] >= a[(i - 1)%2][t])
					t++;
				else {
					a[i%2][j] = min(b[t][j], a[(i - 1)%2][t]);
					break;
				}
			}

			if (t == j){
				a[i%2][j] = min(b[j][j], a[(i - 1)%2][j]);
			}

		}

	}
	return a[k%2][n];
    }
};
