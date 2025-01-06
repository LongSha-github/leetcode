### 1769. Minimum Number of Operations to Move All Balls to Each Box

本題可以理解為每一個有 1 的地方距離回傳答案中每個 index 的絕對值距離和。

首先針對回傳中答案中每一個 index 拆解為左右兩部分，左半部分的 1 最終都須移動到 index ，距離則是所需的操作次數，所以可以建立一個 prefix sum 去知道每個 index 左側所有的 1 移動到 index 時需要操作多少次，做法很簡單只要暫時紀錄目前有多少個 1 需要同時移動，以及目前累積的操作總數，遍歷一次就能更新完 prefix sum。

右側也是同理，接著就是在遍歷一次把同樣 index 的左右 prefix sum 相加就是答案了。