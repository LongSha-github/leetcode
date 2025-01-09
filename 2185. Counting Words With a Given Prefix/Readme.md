# 2185. Counting Words With a Given Prefix
https://leetcode.com/problems/counting-words-with-a-given-prefix/description/
## 問題描述
You are given an array of strings `words` and a string `pref`.  

Return the number of strings in `words` that contain `pref` as a prefix.  

A **prefix** of a string `s` is any leading contiguous substring of `s`.

---

## 範例
### 範例 1:
**Input:**  
`words = ["pay","attention","practice","attend"]`  
`pref = "at"`  
**Output:**  
`2`  
**Explanation:**  
The 2 strings that contain `"at"` as a prefix are:  
- `"attention"`  
- `"attend"`.  

---

### 範例 2:
**Input:**  
`words = ["leetcode","win","loops","success"]`  
`pref = "code"`  
**Output:**  
`0`  
**Explanation:**  
There are no strings that contain `"code"` as a prefix.  

---

## 限制條件
- `1 <= words.length <= 100`  
- `1 <= words[i].length, pref.length <= 100`  
- `words[i]` and `pref` consist of lowercase English letters.  


---

## 解法
簡單利用 for 迴圈將子字串與` pref `做比較，須注意字的長度再做比較。
