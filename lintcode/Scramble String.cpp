class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        // Write your code here
        int a[26], b[26];
		memset(a, 0, sizeof(a));
		memset(b,0,sizeof(b));

		for (int i = 0; i <s1.size(); i++)
		{
			a[s1[i] - 97]++;
			b[s2[i] - 97]++;
		}

		for (int i = 0; i < 26; i++)
		{
			if (a[i] != b[i])
				return false;
		}
		return true;
    }
};