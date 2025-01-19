# 6. Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/
## Problem Description

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this:

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

```cpp
string convert(string s, int numRows);
```
## Example 1:
```
Input:
s = "PAYPALISHIRING", numRows = 3

Output:
"PAHNAPLSIIGYIR"
```

## Example 2:
```
Input:
s = "PAYPALISHIRING", numRows = 4

Output:
"PINALSIGYAHRPI"

Explanation:

P     I    N  
A   L S  I G  
Y A   H R  
P     I  
```
## Example 3:
```
Input:
s = "A", numRows = 1

Output:
"A"
```

## Constraints:
- 1 <= s.length <= 1000
- s consists of English letters (lower-case and upper-case), ',' and '.'.
- 1 <= numRows <= 1000


---

## 解法

透過 `count` 紀錄現在正在寫入的 row ，並且透過 `direct` 決定需要加或減，不同的 `direct` 會去確認是否到達邊界，若抵達則必須修改 `count` 並改變 `direct`。

要注意邊界條件，當 `numRows` 為 1 時必須直接返回 `s`。

