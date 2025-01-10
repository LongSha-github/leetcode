
# 916. Word Subsets
https://leetcode.com/problems/word-subsets/description/

## 問題描述
You are given two string arrays `words1` and `words2`.  

A string `b` is a **subset** of string `a` if every letter in `b` occurs in `a`, including multiplicity.  
- For example, `"wrr"` is a subset of `"warrior"` but is not a subset of `"world"`.  

A string `a` from `words1` is **universal** if for every string `b` in `words2`, `b` is a subset of `a`.  

Return an array of all the universal strings in `words1`. You may return the answer in any order.

---

## 範例
### 範例 1:
**Input:**  
`words1 = ["amazon","apple","facebook","google","leetcode"]`  
`words2 = ["e","o"]`  
**Output:**  
`["facebook","google","leetcode"]`  

---

### 範例 2:
**Input:**  
`words1 = ["amazon","apple","facebook","google","leetcode"]`  
`words2 = ["l","e"]`  
**Output:**  
`["apple","google","leetcode"]`  

---

## 限制條件
- `1 <= words1.length, words2.length <= 10^4`  
- `1 <= words1[i].length, words2[i].length <= 10`  
- `words1[i]` and `words2[i]` consist only of lowercase English letters.  
- All the strings of `words1` are unique.  

---

## 解法
本題是在找出`words1`中那些字串可以讓`words2`中所有的字串都成為他的子集。

很明顯可以用 hash 去做，但是我們不可能用 2 層 for 去遍歷`words1`與 `words2`判斷子集，非常低效。

注意到必須要`words2`都是子集才滿足條件，故只需要針對每個字母去找出`words2`中的每個字串中所需的最大數量，就能去代表滿足整個`words2`都是子集的條件。
