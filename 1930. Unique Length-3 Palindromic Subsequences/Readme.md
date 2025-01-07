### 1930. Unique Length-3 Palindromic Subsequences
本題是在找長度為三的回文，依照這個要求可想到當我中間 index 不管是什麼字只要他的前後有一組相同的字就能生成回文。

故我們可以針對前後相同的字先下手，找到最左的 a 與最右的 a ，在這左右之間依序遍歷，用 set 的資料型態去存中間的值並把他加入到答案中。

接再找最左的 b 與最右的 b ，重複去執行剛才的方法就是答案。