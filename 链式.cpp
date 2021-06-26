#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node//�ṹ��  
{
    char data;
    struct Node *LChild;
    struct Node *RChild;
} BiTNode,*BiTree;
    
void InitList(BiTree *l)//��ʼ��
{
	*l= (BiTree)malloc(sizeof(BiTNode));
    (*l)->LChild = NULL;
    (*l)->RChild = NULL;
}
    
void CreateBiTree(BiTree *bt) //���򴴽������� 
{
    char ch;
    ch = getchar();
    if (ch == ' ') *bt = NULL;
    else
    {
    	*bt = (BiTree)malloc(sizeof(BiTNode));
    	(*bt)->data = ch;
    	CreateBiTree(&((*bt)->LChild));
    	CreateBiTree(&((*bt)->RChild));
    }
}

void caculateLeafNum(BiTree *l,int sum)
{
	int leafNum;
	if((*l) ==NULL)
		return ;
	if((*l)->LChild ==NULL&&(*l)->RChild ==NULL)
	{
		(leafNum)++;
	}
	caculateLeafNum(&((*l)->LChild),sum);
	caculateLeafNum(&((*l)->RChild),sum);
}

int main(){
	static int sum=0;
	BiTree *l;
	BiTree bt;
	printf("%c",caculateLeafNum(&BiTree *l,sum));
}
