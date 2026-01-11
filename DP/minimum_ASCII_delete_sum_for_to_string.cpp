/* 
  Always give the definition to recursive function
 rec(i, j) = return minimum ASCII sum of deleted character s1[i.....m] and s2[j.....n] to make both string equal 
*/



class Solution {
public:

    vector<int>pSumS1, pSumS2;
    int m, n;

    vector<vector<int>>dp;

    vector<int> prefixSum(string s){

        vector<int>ans(s.length(), 0);

        for(int k=0; k<s.length(); k++){
            if(k == 0){
                ans[k] = s[k];
            }else{
                ans[k] = ans[k-1] + s[k];
            }
        }

        return ans;
    }

    // return minimum ASCII sum of deleted character s1[i.....m] and s2[j.....n] to make both string equal 
    int rec(string &s1,string &s2, int i, int j){
        if(i == m){
            return pSumS2[n-1] -(j > 0 ? pSumS2[j-1] : 0);
        }
        if(j == n){
            return pSumS1[m-1] - (i > 0 ? pSumS1[i-1] : 0);
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return rec(s1, s2, i+1, j+1);
        }

        int delFromS1 = s1[i] + rec(s1, s2, i+1, j);
        int delFromS2 = s2[j] + rec(s1, s2, i, j+1);

        return dp[i][j] =  min(delFromS1, delFromS2);
    }

    int minimumDeleteSum(string s1, string s2) {

        m = s1.length();
        n = s2.length();

        pSumS1 = prefixSum(s1);
        pSumS2 = prefixSum(s2);

        dp.assign(m, vector<int>(n, -1));

        return rec(s1, s2, 0, 0);
    }
};
