# 1400. Construct K Palindrome Strings
https://leetcode.com/problems/construct-k-palindrome-strings/description/

## 問題描述
Given a string `s` and an integer `k`, return `true` if you can use all the characters in `s` to construct `k` palindrome strings, or `false` otherwise.

---

## 範例
### 範例 1:
**Input:**  
`s = "annabelle"`, `k = 2`  
**Output:**  
`true`  
**Explanation:**  
You can construct two palindromes using all characters in `s`.  
Some possible constructions:  
- `"anna"` + `"elble"`  
- `"anbna"` + `"elle"`  
- `"anellena"` + `"b"`

---

### 範例 2:
**Input:**  
`s = "leetcode"`, `k = 3`  
**Output:**  
`false`  
**Explanation:**  
It is impossible to construct 3 palindromes using all the characters of `s`.

---

### 範例 3:
**Input:**  
`s = "true"`, `k = 4`  
**Output:**  
`true`  
**Explanation:**  
The only possible solution is to put each character in a separate string.

---

## 限制條件
- `1 <= s.length <= 10^5`  
- `s` consists of lowercase English letters.  
- `1 <= k <= 10^5`  


---

## 解法
本題可以先從奇偶回文下手，當所有字母都是偶數時，只要`s`的大小比`k`小，`1~k`組回文都必定能組出來。

而當有奇數字母數量出現時，只有1個倒是沒什麼差，當出現2個時，最少必須是2組回文，因為2個奇數不能待在同一組，會無法形成回文。

照這思路，可推導出`s`中奇數字母的數量限制了回文組數的下限，只要不大於`k`基本上都能組出來。
