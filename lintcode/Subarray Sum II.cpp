class Solution {
public:
	/**
	* @param A an integer array
	* @param start an integer
	* @param end an integer
	* @return the number of possible answer
	*/
	int subarraySumII(vector<int>& A, int start, int end) {
		// Write your code here
		int n = A.size();
		int a[2][10000];
		memset(a, 0, sizeof(a));

		int count = 0;
		for (int i = 1; i <= A.size(); i++)
		{
			a[i%2][i] = A[i - 1];
			if (a[i%2][i] >= start && a[i%2][i] <= end)
			{//cout<<i<<" "<<i<<endl;
				count++;
			}
			for (int j = i+1; j <= A.size(); j++)
			{
				a[i%2][j] =a[i%2][j-1]+ A[j-1];

				if (a[i%2][j] >= start && a[i%2][j] <= end)
				{//cout<<i<<" "<<j<<a[i][j]<<endl;
					count++;
				}
			}
		}		
		return count;
	}
};