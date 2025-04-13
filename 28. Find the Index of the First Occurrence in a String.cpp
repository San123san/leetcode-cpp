class Solution {
public:
    int strStr(string haystack, string needle) {
        int N = haystack.size();
        int M = needle.size();

        int i, j;

        int p = 0;
        int t = 0;
        int h = 1;
        int d = 256;
        int q = 101;
        
        if (M == 0) return 0;
        if (N < M) return -1;

        for(i = 0; i < M - 1; i++){
            h = (h * d) % q;
        }

        for(i = 0; i < M; i++){
            p = (d * p + needle[i]) % q;
            t = (d * t + haystack[i]) % q;
        }

        for(i = 0; i < N; i++){
            if(p == t){
                for(j = 0; j < M; j++){
                    if(haystack[i + j] != needle[j]){
                        break;
                    }
                }
                if(j == M) return i;
            }

            if(i < N - M){
                t = (d * (t - haystack[i] * h) + haystack[i + M]) % q;
                if(t < 0){
                    t = (t + q);
                }
            }
        }
        return -1;
    }
};
