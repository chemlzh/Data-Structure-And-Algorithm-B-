#### 第六周编程解析 ####

**T1**：说起哈夫曼树，就想到贪心算法，就想到每次将值最小的两个节点合并，就想到用优先队列（小根堆）将最小的两个数取出来……OIer的想象力唯有在这一层如此跃进。（逃）
此题不需要显式建立哈夫曼树，只需要将所有节点扔进小根堆，每次取出最小的两个数，合并后加到ans中，然后将合并后的数重新扔回小根堆，可以证明，这个操作与哈夫曼树的显式建立是一致的，因此最终得到的ans即为最小外部路径长度总和。C++ STL有优先队列的实现（在\<queue\>中），但默认为大根堆，还需要结合\<functional\>的greater\<long\>，才能变成小根堆，具体的定义为priority_queue\<long, vector\<long\>, greater\<long\> \> t。
