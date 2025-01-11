# 1422. Maximum Score After Splitting a String
https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/

## 問題描述
Given a string `s` of zeros and ones, return the **maximum score** after splitting the string into two non-empty substrings (i.e., left substring and right substring).  

The **score** after splitting a string is defined as:  
- The number of zeros in the left substring plus the number of ones in the right substring.

---

## 範例
### 範例 1:
**Input:**  
`s = "011101"`  
**Output:**  
`5`  
**Explanation:**  
All possible ways of splitting `s` into two non-empty substrings are:  
- `left = "0"`, `right = "11101"`, score = `1 + 4 = 5`  
- `left = "01"`, `right = "1101"`, score = `1 + 3 = 4`  
- `left = "011"`, `right = "101"`, score = `1 + 2 = 3`  
- `left = "0111"`, `right = "01"`, score = `1 + 1 = 2`  
- `left = "01110"`, `right = "1"`, score = `2 + 1 = 3`  

The maximum score is `5`.  

---

### 範例 2:
**Input:**  
`s = "00111"`  
**Output:**  
`5`  
**Explanation:**  
When `left = "00"` and `right = "111"`, the maximum score is `2 + 3 = 5`.

---

### 範例 3:
**Input:**  
`s = "1111"`  
**Output:**  
`3`  
**Explanation:**  
The best split is `left = "111"`, `right = "1"`, score = `0 + 3 = 3`.

---

## 限制條件
- `2 <= s.length <= 500`  
- The string `s` consists of characters `'0'` and `'1'` only.  

---

## 解法

本題可以去想像你去一刀切並把左邊的0總數加上右邊的1總數，可能的組合根據你切的位置從左至右滑動取最大就是結果了。

那要注意本題不能有空的 substrings，另外這種有累積性相關的題目大概率會想到 Prefix Sum ，因為我們會去求從左邊往右過程中，每個 index上所累積 0 的總和，以及從右往左過程中，每個 index 上所累積 1 的總和。

最後透過滑動切割的位置去取最大的結果。