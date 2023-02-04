
#include <stdio.h>
#include <stdlib.h>

//Creating a structure and using typedef for future ease in typing //

typedef struct bst* ptrtobst;
typedef struct bst {
    int data;
    ptrtobst lchild;
    ptrtobst rchild;
    }bst;

//initialising the root node//
ptrtobst root = NULL;


//inserting any element in the bst//
ptrtobst insert(int element, ptrtobst node){
    ptrtobst temp;
    if(node == NULL)
        {
            temp = (ptrtobst) malloc(sizeof(bst));
            temp->data = element;
            temp->lchild = NULL;
            temp->rchild = NULL;
                if(root == NULL)
                    root = temp;
                return temp;
                }


                else if(element < node->data)
                {
                node->lchild = insert(element, node->lchild);
                return node;
                }
                else if(element > node->data)
                {
                node->rchild = insert(element, node->rchild);
                return node;
                }
            else
            {
            printf("Duplicate Element found while inserting!\n");
            return NULL;
        }
    }


//inorder traversal//

void inorder(ptrtobst node)
{
    if(node == NULL)
        return;
        inorder(node->lchild);
        printf("%d ",node->data);
        inorder(node->rchild);
    }



//preorder traversal//

void preorder(ptrtobst node)
{
        if(node == NULL)
        return;
        printf("%d ",node->data);
        preorder(node->lchild);
        preorder(node->rchild);
    }


//postorder traversal//

void postorder(ptrtobst node)
{
        if(node == NULL)
        return;
        postorder(node->lchild);
        postorder(node->rchild);
        printf("%d ",node->data);
    }



//key search function//

int search(int key,ptrtobst node){
    if(node==NULL){
    printf("Key not found!!\n");
    return 0;
    }
    else{
    if(key == node->data){
        printf("Key found!");
        return 1;
    }
    else if(key>node->data)
        search(key,node->rchild);
    else if(key<node->data)
        search(key,node->lchild);
    }
}



int main(){
    int ele;
    int key;
    int ch ;

    printf("Enter no of elements in BST: \n");
    scanf("%d", &ch);
    int i = 0;
    while(i<ch){
    printf("Enter Element to Insert in the BST: \n");
    scanf("%d", &ele);
    insert(ele, root);
    i++;
    }

        printf("\nInorder: \n");
        inorder(root);

        printf("\nPreorder: \n");
        preorder(root);
       
        printf("\nPostorder: \n");
        postorder(root);

        printf("\nEnter the Element to be Searched in the BST: \n");
        scanf("%d", &key);
        if (search(key,root)==0)
        {
            insert(key,root);
        }


        printf("\nInorder: \n");
        inorder(root);

        printf("\nPreorder: \n");
        preorder(root);
       
        printf("\nPostorder: \n");
        postorder(root);


}

