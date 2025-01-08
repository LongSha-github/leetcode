# 2381. Shifting Letters II
https://leetcode.com/problems/shifting-letters-ii/description/

## 問題描述
You are given a string `s` of lowercase English letters and a 2D integer array `shifts` where `shifts[i] = [starti, endi, directioni]`.  

For every `i`, shift the characters in `s` from the index `starti` to the index `endi` (inclusive):  
- **Forward** if `directioni = 1`  
- **Backward** if `directioni = 0`  

**Shifting** a character forward means replacing it with the next letter in the alphabet (wrapping around so that `'z'` becomes `'a'`).   
Similarly, shifting a character backward means replacing it with the previous letter (wrapping around so that `'a'` becomes `'z'`).  

Return the final string after all such shifts to `s` are applied.

---

## 範例
### 範例 1:
**Input:**  
`s = "abc"`  
`shifts = [[0,1,0],[1,2,1],[0,2,1]]`  
**Output:**  
`"ace"`  
**Explanation:**  
1. Shift characters from index `0` to `1` backward. Now `s = "zac"`.  
2. Shift characters from index `1` to `2` forward. Now `s = "zbd"`.  
3. Shift characters from index `0` to `2` forward. Now `s = "ace"`.  

---

### 範例 2:
**Input:**  
`s = "dztz"`  
`shifts = [[0,0,0],[1,1,1]]`  
**Output:**  
`"catz"`  
**Explanation:**  
1. Shift characters from index `0` to `0` backward. Now `s = "cztz"`.  
2. Shift characters from index `1` to `1` forward. Now `s = "catz"`.  

---

## 限制條件
- `1 <= s.length, shifts.length <= 5 * 10^4`  
- `shifts[i].length == 3`  
- `0 <= starti <= endi < s.length`  
- `0 <= directioni <= 1`  
- `s` consists of lowercase English letters.  


---

## 解法
這題很直觀的作法就是先建立一個 vector 遍歷 shifts 中的區間去紀錄每個 index 需要位移的量，但問題是使用 for 迴圈去做 +1 or -1 所要付出的代價非常高。

這裡就要用到差分的概念去減少計算消耗，最後要小心若 shift 是負數時要 +26 轉為正的。