# 2429. Minimize XOR
https://leetcode.com/problems/minimize-xor/description/
## Problem Description

Given two positive integers `num1` and `num2`, find the positive integer `x` such that:
1. `x` has the same number of set bits (1's in binary representation) as `num2`.
2. The value `x XOR num1` is minimal.

Note:
- XOR is the bitwise XOR operation.
- The number of set bits of an integer is the number of 1's in its binary representation.

Return the integer `x`. The test cases are generated such that `x` is uniquely determined.

---

## Examples

### Example 1:
**Input:**  
`num1 = 3`, `num2 = 5`  
**Output:**  
`3`  
**Explanation:**  
- Binary representations:  
  `num1 = 0011`, `num2 = 0101`  
- The integer `3` has the same number of set bits as `num2` (both have 2 set bits).  
- `3 XOR 3 = 0`, which is minimal.  

---

### Example 2:
**Input:**  
`num1 = 1`, `num2 = 12`  
**Output:**  
`3`  
**Explanation:**  
- Binary representations:  
  `num1 = 0001`, `num2 = 1100`  
- The integer `3` (`0011` in binary) has the same number of set bits as `num2` (both have 2 set bits).  
- `3 XOR 1 = 2`, which is minimal.  

---

## Constraints
- `1 <= num1, num2 <= 10^9`


---

## 解法
題目就是在考 bit 操作，當 `num1` 與 `num2` 數量相等時，直接返回 num1。

當 `num1` 數量比 `num2` 多時可以知道必然會有消不完的 1 ，但是我必需使 盡量多的 1 是在較大位數與 `num1` XOR , 故我們可以從右側把消不完的部分去除就能得到`x`。

當 `num1` 數量比 `num2` 少時代表需填充多餘的1，我們會從右邊開始填充，畢竟這樣 XOR 之後會比較小。 
