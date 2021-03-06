#### 第八周编程解析 ####
**T1**：本题要求根据二叉树的先序遍历和中序遍历，来输出二叉树的后序遍历。此题不需要显式建立二叉树，而是采用递归分治的方法。对于长度为n的先序遍历（记为pre[0..n-1]），其第一个元素即为根节点，接下来我们在中序遍历（记为mid[0..n-1]）中找到根节点（设位置为i），则左子树为mid[0..i-1]（相应的先序遍历为pre[1..i]），右子树为mid[i+1,n-1]（相应的先序遍历为pre[i+1..n-1]），然后递归输出的顺序为printPostOrder(posPre+1,posMid,i)→printPostOrder(posPre+i+1,posMid+i+1,n-i-1)→printf("%ld",pre[0])，其中posPre为子树的先序遍历起始位置，posMid为子树的中序遍历起始位置。

**T2**：本题要求将输入的数据插入到一棵二叉搜索树中（如果插入的元素已经在二叉搜索树中，则不需再次插入），然后输出该二叉搜索树的先序遍历。典型的模板题。首先我们明确这棵二叉搜索树的插入操作：如果二叉搜索树为空，则直接将根节点\*root设置为新节点；如果二叉搜索树非空，则用指针\*tempNode表示当前比较的节点（初始时指向\*root），用\*fatherNode表示比较节点的父节点。如果\*tempNode->element等于待插入元素，则不需插入，直接返回；如果\*tempNode->element小于待插入元素，则根据二叉搜索树的性质“任何比根节点大的元素均在右子树中”，\*tempNode应指向右子树；如果\*tempNode->element大于待插入元素，则根据二叉搜索树的性质“任何比根节点小的元素均在左子树中”，\*tempNode应指向左子树。这样查找必然会遇到两种情况：要么遇到相等元素而提前退出，要么最终遇到空节点（nullptr），此时\*fatherNode即为插入位置的父节点，再根据二叉搜索树的性质，将新节点插入到\*fatherNode的左（或右）儿子处。接下来先序遍历便可以用递归实现，这里不再赘述。

