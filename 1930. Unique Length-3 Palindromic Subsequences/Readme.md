# 1930. Unique Length-3 Palindromic Subsequences
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
## 問題描述
Given a string `s`, return the number of **unique palindromes** of length three that are a subsequence of `s`.  

- A **palindrome** is a string that reads the same forwards and backwards.  
- A **subsequence** of a string is a new string generated from the original string by deleting some characters (can be none) without changing the relative order of the remaining characters.

### 注意事項
- Multiple ways of obtaining the same subsequence count only once.

---

## 範例
### 範例 1:
**Input:**  
`s = "aabca"`  
**Output:**  
`3`  
**Explanation:**  
The 3 unique palindromic subsequences of length 3 are:  
- `"aba"` (subsequence of `"aabca"`)  
- `"aaa"` (subsequence of `"aabca"`)  
- `"aca"` (subsequence of `"aabca"`)  

---

### 範例 2:
**Input:**  
`s = "adc"`  
**Output:**  
`0`  
**Explanation:**  
There are no palindromic subsequences of length 3 in `"adc"`.

---

### 範例 3:
**Input:**  
`s = "bbcbaba"`  
**Output:**  
`4`  
**Explanation:**  
The 4 unique palindromic subsequences of length 3 are:  
- `"bbb"` (subsequence of `"bbcbaba"`)  
- `"bcb"` (subsequence of `"bbcbaba"`)  
- `"bab"` (subsequence of `"bbcbaba"`)  
- `"aba"` (subsequence of `"bbcbaba"`)  

---

## 限制條件
- `3 <= s.length <= 10^5`  
- `s` consists of only lowercase English letters.  
---

## 解法

本題是在找長度為三的回文，依照這個要求可想到當我中間 index 不管是什麼字只要他的前後有一組相同的字就能生成回文。

故我們可以針對前後相同的字先下手，找到最左的 a 與最右的 a ，在這左右之間依序遍歷，用 set 的資料型態去存中間的值並把他加入到答案中。

接再找最左的 b 與最右的 b ，重複去執行剛才的方法就是答案。