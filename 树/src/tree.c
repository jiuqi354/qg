#include <stdio.h>
#include <stdlib.h>
#include "../inc/binary_sort_tree.h"

NodePtr search(NodePtr,ElemType);
NodePtr parentSearch(NodePtr,ElemType);
void Visit(NodePtr);

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr ptr){
    if(!ptr->root){
        printf("树已生成！\n");
        return succeed;
    }
    NodePtr nodePtr1=(NodePtr)malloc(sizeof(Node));
    if(!nodePtr1)
        return failed;
    ptr->root=nodePtr1;
    nodePtr1->value=-1;
    nodePtr1->left=NULL;
    nodePtr1->right=NULL;
    printf("创建成功！\n");
    return succeed;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr ptr, ElemType e){
    NodePtr ptr1=(NodePtr)malloc(sizeof(Node));
    ptr1->left=NULL;
    ptr1->right=NULL;
    ptr1->value=e;
    NodePtr ptr2=ptr->root;
    while (true){
        if(e>ptr2->value){
            if(!ptr2->right){
                ptr2->right=ptr1;
                return succeed;
            }
            ptr2=ptr2->right;
        }
        if(e<ptr2->value){
            if(!ptr2->left){
                ptr2->left=ptr1;
                return succeed;
            }
            ptr2=ptr2->left;
        }
        if(e==ptr2->value){
            printf("数字已存在！\n");
            return failed;}
    }
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr ptr, ElemType e){
    NodePtr nodePtr1=parentSearch(ptr->root,e);
    NodePtr nodePtr2=search(ptr->root,e);
    while (true) {
        if (!nodePtr1)
            return failed;
        if (!nodePtr2->left && !nodePtr2->right) {
            free(nodePtr2);
            return succeed;
        }
        if (!nodePtr2->left) {
            if (nodePtr1->left == nodePtr2) {
                nodePtr1->left = nodePtr2->right;
            }
            if (nodePtr1->right == nodePtr2) {
                nodePtr1->right = nodePtr2->right;
            }
            free(nodePtr2);
            return succeed;
        }
        if (!nodePtr2->right) {
            if (nodePtr1->left == nodePtr2) {
                nodePtr1->left = nodePtr2->left;
            }
            if (nodePtr1->right == nodePtr2) {
                nodePtr1->right = nodePtr2->left;
            }
            free(nodePtr2);
            return succeed;
        }

    }
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr BST, ElemType e){
    if(!search(BST->root,e)){
        printf("数不存在\n");
        return false;}
    return true;
}
/**
 * BST search
 * @param NodePtr ptr
 * @param ElemType the value to search
 * @return ptr
 */
NodePtr search(NodePtr ptr,ElemType e){
     if(!ptr)
         return NULL;
     if(ptr->left->value<e)
         ptr=search(ptr->left,e);
     if(ptr->right->value>e)
         ptr=search(ptr->right,e);
     return ptr;
}
/**
 * BST parentSearch
 * @param NodePtr ptr
 * @param ElemType the value to search the parent node
 * @return parent ptr
 */
 NodePtr parentSearch(NodePtr ptr,ElemType e){
     while(true){
    if(e>ptr->value){
        if(!ptr->right)
            return ptr;
        ptr=ptr->right;
    }
    if(e<ptr->value){
        if(!ptr->left)
            return ptr;
        ptr=ptr->left;
    }
     }
 }

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr ptr, void (*visit)(NodePtr)){
    if(ptr->root==NULL)
        return succeed;


 }


void Visit(NodePtr ptr){
    printf("%d ",ptr->value);
}
/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr ptr, void (*visit)(NodePtr)){

}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr ptr, void (*visit)(NodePtr)){

}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr ptr, void (*visit)(NodePtr)){

}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr ptr, void (*visit)(NodePtr)){

}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr ptr, void (*visit)(NodePtr)){

}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr ptr, void (*visit)(NodePtr)){

}