class Solution {
  public:
    void constructLPS(string &pat, vector<int> &lps){
        int n=pat.size();
        int len=0;
        int i=1;
        while(i<n){
            if(pat[i]==pat[len]){
                lps[i]=++len;
                i++;
            } else if(len!=0){
                len=lps[len-1];
            } else {
                lps[i]=0;
                i++;
            }
        }
    }
    vector<int> search(string &pat, string &txt) {
        // code here
        int n=pat.size();
        vector<int> lps(n,0);
        constructLPS(pat,lps);
        vector<int> res;
        int i=0, j=0;
        while(i<txt.size()){
            if(pat[j]==txt[i]){
                i++;
                j++;
                if (j == n) {
                    res.push_back(i - j);
                    j = lps[j - 1];
                }
            } else {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return res;
    }
};
