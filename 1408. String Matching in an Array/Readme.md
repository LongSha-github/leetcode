# 1408. String Matching in an Array
https://leetcode.com/problems/string-matching-in-an-array/description/

## 問題描述
Given an array of strings `words`, return all strings in `words` that are a substring of another word. You can return the answer in any order.

A **substring** is a contiguous sequence of characters within a string.

---

## 範例
### 範例 1:
**Input:**  
`words = ["mass","as","hero","superhero"]`  
**Output:**  
`["as","hero"]`  
**Explanation:**  
- `"as"` is a substring of `"mass"`.  
- `"hero"` is a substring of `"superhero"`.  
Both `["as","hero"]` and `["hero","as"]` are valid answers.

---

### 範例 2:
**Input:**  
`words = ["leetcode","et","code"]`  
**Output:**  
`["et","code"]`  
**Explanation:**  
- `"et"` is a substring of `"leetcode"`.  
- `"code"` is a substring of `"leetcode"`.

---

### 範例 3:
**Input:**  
`words = ["blue","green","bu"]`  
**Output:**  
`[]`  
**Explanation:**  
No string in `words` is a substring of another string.

---

## 限制條件
- `1 <= words.length <= 100`  
- `1 <= words[i].length <= 30`  
- `words[i]` consists only of lowercase English letters.  
- All strings in `words` are unique.  

---

## 解法

直接透過迴圈兩兩進去 check 是否為子字串， check 前先保證 i index 所指的 string 比較長，接著 check 是的話用 set 裝最後再改成 vector 回傳