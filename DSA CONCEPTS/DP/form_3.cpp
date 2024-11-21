/*form - 3 -> multisequence

qn -> given 2 strings, what will be the longest common subsquence between then 
    s1 => a b x d e f y
    s2 => x b e d e f g 


step - 2 -> 
     dp[i, j] = longest common subsequence of s1[i ... n] and s2[j ... m]

step - transition
        dp[i][j] = dp[i, j + 1]
                    dp[i + 1, j]
                    if(s1[i] == s2[j]) 1 + dp[i + 1][j + 1]
                    */