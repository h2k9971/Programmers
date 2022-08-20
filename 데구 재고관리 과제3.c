#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CODE_LENGTH 7 //관리번호 길이 정의

// 재고관리를 위한 구조체 정의
// 관리번호, 재고수량
typedef int itemStock;

typedef struct
{
    char itemCode[MAX_CODE_LENGTH];
    itemStock stock;
}item;

//재고관리를 위한 이진트리 노드 구조체 정의
typedef struct treeNode
{
    item key;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

typedef struct treeNode* treePointer;

treePointer iterSearch(treePointer tree, item theitem);

treePointer modifiedSearch(treePointer tree, item theitem);

treePointer search_BST(treePointer curr, item theitem, treePointer* parent);

void inorder(treePointer ptr) // 중위순회 재고확인하기
{
    if(ptr)
    {
        inorder(ptr->left);
        printf("%s %d", ptr->key.itemCode, ptr->key.stock);
        inorder(ptr->right);
    }
}

void insert(treePointer *node, item theitem)
{
    treePointer ptr, temp;
    treeNode* curr;
    ptr=(treePointer)malloc(sizeof(*ptr));
    ptr->key = theitem;
    ptr->left = ptr->right= NULL;
    
    curr = iterSearch(*node, theitem);
    
    if(curr != NULL)
    {
        printf("\n존재하는 상품코드입니다.");
        curr->key.stock = curr->key.stock+ theitem.stock;
        printf("\n상품코드 %s의 재고는 %d개 입니다.\n", curr->key.itemCode, curr->key.stock);
        
        return;
    }
    
    if(!(*node)) // 루트가 널이면 즉 노드가 한개도 없는 경우
        *node=ptr;
    else
    {
        temp = modifiedSearch(*node, theitem);
        
        if(strcmp(theitem.itemCode, temp->key.itemCode) < 0)
        {
            temp->left=ptr;
        }
        else
        {
            temp->right=ptr;
        }
        
    }
}

treePointer iterSearch(treePointer tree, item theitem)
{
    while(tree)
    {
        if(strcmp(theitem.itemCode,tree->key.itemCode) == 0)
        {
            return tree;
        }
        if(strcmp(theitem.itemCode,tree->key.itemCode) < 0)
        {
            tree = tree->left;
            
        }
        else
            tree = tree->right;
    }
    return NULL;
}

treePointer modifiedSearch(treePointer tree, item theitem)
{
    treePointer Parent=NULL;
    while(tree)
    {
        if(strcmp(theitem.itemCode, tree->key.itemCode) == 0)
            return NULL;
        
        if(strcmp(theitem.itemCode, tree->key.itemCode) < 0)
            tree= tree->left;
        else
            tree=tree->right;
    }
    return Parent;
}

void BST_Delete(treePointer* root, item theitem)
{
    treePointer parent, nptr, curr, succ, temp;
    
    nptr = search_BST(*root, theitem, &parent);
    
    temp = iterSearch(*root, theitem);

    if(temp->key.stock > theitem.stock)
    {
        temp->key.stock = temp->key.stock - theitem.stock;
        printf("재고가 %d개 출고 되었습니다. 남은 재고는 %d개 입니다.\n", theitem.stock, temp->key.stock);
        return;
    }
    else
    {
        if(nptr->left && nptr->right)
        {
            succ = nptr->right;
            parent = nptr;
            while(succ->left)
            {
                parent=succ;
                succ=succ->left;
            }
            nptr->key = succ->key;
            nptr =succ;
        }
    
        curr = nptr->left;
        
        if(curr==NULL)
        {
            curr=nptr->right;
        }
        if(parent == NULL)
            *root = curr; // root가 한 개 이하의 자식을 가진경우이다.
        else if(parent->left == nptr)
        {
            parent->left = curr;
        }
        else
        {
            parent->right = curr;
        }
        free(nptr);
    }
}

treePointer search_BST(treePointer curr, item theitem, treePointer* parent)
{
    *parent=NULL;
    while(curr)
    {
        if(strcmp(theitem.itemCode, curr->key.itemCode) == 0)
            return curr;
        
        else if(strcmp(theitem.itemCode, curr->key.itemCode) < 0)
        {
            *parent= curr;
            curr=curr->left;
        }
        else
        {
            *parent = curr;
            curr= curr->right;
        }
    }
    return NULL;
}

int main()
{
    treePointer tree = NULL;
    item theitem;
    treeNode* temp;
    
    int n=0;
    
    while(1)
    {
        printf("*==== SELECT MENU ====*\n");
        printf("       1 : 재고확인      \n");
        printf("       2 :  입고        \n");
        printf("       3 :  출고        \n");
        printf("       4 :  검색        \n");
        printf("       5 :  종료        \n");
        printf("*=====================*\n");
        scanf("%d", &n);
        
        switch(n)
        {
            case 1:
                printf("[전체 재고 출력]\n\n");
                inorder(tree);
                break;
                
            case 2:
                printf("[입고] 관리번호를 입력하세요. :");
                scanf("%s", theitem.itemCode);
                printf("\n[입고] 입고 수량을 입력하세요. :");
                scanf("%d", &theitem.stock);
                printf("\n");
                insert(&tree, theitem);
                break;
                
            case 3:
                printf("[출고] 관리번호를 입력하세요. :");
                scanf("%s", theitem.itemCode);
                temp = iterSearch(tree, theitem);
                if(temp==NULL)
                {
                    printf("없는 관리번호입니다.\n");
                    break;
                }
                printf("상품코드 %s의 재고는 %d개 입니다.\n", temp->key.itemCode, temp->key.stock); // 재고 정보를 출력해준다.
                printf("\n[출고] 출고 수량을 입력하세요 : ");
                scanf("%d", &theitem.stock);
                BST_Delete(&tree, theitem);
                break;
                
            case 4:
                printf("[재고 수량 검색] 관리번호를 입력하세요 :");
                scanf("%s",theitem.itemCode);
                iterSearch(tree, theitem);
                
                if(tree == NULL)
                {
                    printf("상품을 찾을 수 없습니다.\n");
                }
                else
                {
                    printf("상품코드 %s의 재고는 %d개 입니다.\n\n", tree->key.itemCode, tree->key.stock);
                }
                break;
                
            case 5:
                printf("프로그램을 종료합니다");
                exit(1);
        }
    }
    return 0;
}
