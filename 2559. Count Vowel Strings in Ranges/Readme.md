# 2559. Count Vowel Strings in Ranges
https://leetcode.com/problems/count-vowel-strings-in-ranges/description/
## 問題描述
You are given a 0-indexed array of strings `words` and a 2D array of integers `queries`.

Each query `queries[i] = [li, ri]` asks us to find the number of strings present in the range `li` to `ri` (both inclusive) of `words` that **start and end with a vowel**.  

Return an array `ans` of size `queries.length`, where `ans[i]` is the answer to the `i-th` query.  

**Note:** The vowel letters are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

---

## 範例
### 範例 1:
**Input:**  
`words = ["aba","bcb","ece","aa","e"]`  
`queries = [[0,2],[1,4],[1,1]]`  
**Output:**  
`[2,3,0]`  
**Explanation:**  
The strings starting and ending with a vowel are `"aba"`, `"ece"`, `"aa"` and `"e"`.  
- Query `[0,2]` counts `"aba"` and `"ece"`, so the result is `2`.  
- Query `[1,4]` counts `"ece"`, `"aa"`, and `"e"`, so the result is `3`.  
- Query `[1,1]` has no valid strings, so the result is `0`.  

---

### 範例 2:
**Input:**  
`words = ["a","e","i"]`  
`queries = [[0,2],[0,1],[2,2]]`  
**Output:**  
`[3,2,1]`  
**Explanation:**  
Every string satisfies the conditions:  
- Query `[0,2]` counts all strings, so the result is `3`.  
- Query `[0,1]` counts `"a"` and `"e"`, so the result is `2`.  
- Query `[2,2]` counts `"i"`, so the result is `1`.  

---

## 限制條件
- `1 <= words.length <= 10^5`  
- `1 <= words[i].length <= 40`  
- `words[i]` consists only of lowercase English letters.  
- `sum(words[i].length) <= 3 * 10^5`  
- `1 <= queries.length <= 10^5`  
- `0 <= li <= ri < words.length`  

---

## 解法
此題非常明顯求累積量的題目，並且又是針對某個區間 queries[i] = [li, ri] 去找出 words 中滿足特定條件的總量。
直接使用 prefix 的思路就完事。