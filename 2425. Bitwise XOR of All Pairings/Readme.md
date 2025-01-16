# 2425. Bitwise XOR of All Pairings
https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/
## Problem Description

You are given two 0-indexed arrays, `nums1` and `nums2`, consisting of non-negative integers. There exists another array, `nums3`, which contains the bitwise XOR of all pairings of integers between `nums1` and `nums2` (every integer in `nums1` is paired with every integer in `nums2` exactly once).

Return the bitwise XOR of all integers in `nums3`.

---

## Examples

### Example 1:
**Input:**  
`nums1 = [2,1,3]`, `nums2 = [10,2,5,0]`  
**Output:**  
`13`  
**Explanation:**  
A possible `nums3` array is:  
`[2^10, 2^2, 2^5, 2^0, 1^10, 1^2, 1^5, 1^0, 3^10, 3^2, 3^5, 3^0]` = `[8, 0, 7, 2, 11, 3, 4, 1, 9, 1, 6, 3]`.  
The bitwise XOR of all numbers in `nums3` is `13`.  

---

### Example 2:
**Input:**  
`nums1 = [1,2]`, `nums2 = [3,4]`  
**Output:**  
`0`  
**Explanation:**  
A possible `nums3` array is:  
`[1^3, 1^4, 2^3, 2^4]` = `[2, 5, 1, 6]`.  
The bitwise XOR of all numbers in `nums3` is `0`.  

---

## Constraints
- `1 <= nums1.length, nums2.length <= 10^5`
- `0 <= nums1[i], nums2[j] <= 10^9`

---

## 解法
XOR 有一個很重要的特性就是 x^x = 0，偶數次運算會是 0 。

透過觀察可以發現，當 `nums2` 是偶數時，`nums1` 中所有數字都會 XOR 運算偶數次，這代表會是 0 ，而當 `nums2` 是奇數時 `nums1` 中所有的數字都 XOR 運算一次，就會是他們對 `nums3` 的貢獻。

反過來看同理，計算出 `nums2` 對 `nums3` 的貢獻後將兩個貢獻 XOR 就是最終貢獻。
