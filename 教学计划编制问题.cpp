#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define N 100
#define M 10010
template<class T>
class Queue
{
public:
    bool IsFull() const;
    bool IsEmpty() const;
    T front();
    void Pop();
    void Push(T &e);
    Queue(int size);
    ~Queue();
private:
    T *base;
    int top,rear
    int maxsize;
};
template<class T>
bool Queue<T>::IsFull() const
{
    return rear == maxsize;
}
template<class T>
bool Queue<T>::IsEmpty() const
{
    return rear == top;
}
template<class T>
Queue<T>::Queue(int size):maxsize(size)
{
    base = new T[maxsize];
    if (base == NULL)
    {
        cout<<"内存分配失败！"<<endl;exit(0);
    }
    top = rear = 0;
}
template<class T>
void Queue<T>::Pop()
{
    top++;
}
template<class T>
void Queue<T>::Push(T &e)
{
    base[rear++] = e;
}
template<class T>
T Queue<T>::front()
{
    return base[top];
}
template<class T>
Queue<T>::~Queue()
{
    delete [] base;
}
 
int InDegree[N],res[N];
int S,C,n,l,num,op,ave,s1,tot;
bool flag;
bool vis[N];
struct node1
{
    char id[4],pre[N][4];
    int cre,k;
}course[N];
int head[N];
struct node
{
    int x,y,next;
}edge[M];
void add(int x,int y)
{
    l++;
    edge[l].x = x;edge[l].y = y;
    edge[l].next = head[x];head[x] = l;
}
 
int TopSort_Queue()
{
    memset(vis,0,sizeof(vis));
    Queue<int> Q(N);
    for (int i=1;i<=n;i++)
        if (InDegree[i] == 0) Q.Push(i);
    while (!Q.IsEmpty())
    {
        int v = Q.front();
        res[++num] = v;
        vis[v] = 1;
        Q.Pop();
        for (int p=head[v];p;p = edge[p].next)
        {
            int u = edge[p].y;
            InDegree[u]--;
            if (InDegree[u] == 0) Q.Push(u);
        }
    }
    for (int i=1;i<=n;i++)
        if (!vis[i]) return 0;
    return 1;
}
 
void solve()
{
    memset(head,0,sizeof(head));
    memset(InDegree,0,sizeof(InDegree));
    l = 0;
    for (int i=1;i<=n;i++)
    {
        for (int j = 1;j<=course[i].k;i++)
        {
            flag = 0;
            for (int i1 = 1;i1<=n;i1++)
                if (!strcmp(course[i1].id, course[i].pre[j]))
                {
                    add(i1,i);
                    InDegree[i]++;
                    flag = 1;
                }
            if (!flag)
            {
                printf("失败！ID不存在！");
                return ;
            }
        }
    }
    int tmp = TopSort_Queue();
    if (!tmp)
    {
        printf("失败！先修课程的关系有错误！\n");
        return ;
    }
    tot = 0;
    s1 = 0;
    for (int i=1;i<=num;i++)
    {
        tot += course[res[i]].cre;
        if (tot > C)
        {
            s1++;
            tot = course[res[i]].cre;
        }
        if (course[res[i]].cre > C)
        {
            printf("失败！课程的学分太大!\n", course[res[i]].id);
            return ;
        }
    }
    if (s1 > S)
    {
        printf("失败！这个问题没有解决办法！学期数太少了！\n");
        return ;
    }
    printf("请输入您想安排课程的方式\n");
    printf("一是每学期平均安排课程\n");
    printf("第二个是在前几个学期尽量安排课程\n");
    printf("输入1或2选择方式和输入0退出\n");
 
    ofstream outFile;
    outFile.open("result.dat", ios::out);
 
    while (~scanf("%d", &op))
    {
        if (op == 1)
        {
            outFile<<"The first way:\n";
            ave = num / S;
            s1 = 0;
            int i = 1;
            while (i<=num)
            {
                s1++;
                int tot = 0;
                int j = i;
                while (j<=num && j-i+1<=ave && tot <= C)
                    tot += course[res[j++]].cre;
                outFile<<"No."<<s1<<" 学期: ";
                for (int k = i;k<j;k++)
                    outFile<<course[res[k]].id<<' ';
                outFile<<endl;
                i = j;
            }
        }
        else if (op == 2)
        {
            outFile<<"The second way:\n";
            s1 = 0;
            int i = 1;
            while (i<=num)
            {
                s1++;
                int tot = 0;
                int j = i;
                while (j<=num && tot <= C)
                    tot += course[res[j++]].cre;
                outFile<<"No."<<s1<<" 学期: ";
                for (int k = i;k<j;k++)
                    outFile<<course[res[k]].id<<' ';
                outFile<<endl;
                i = j;
            }
        }
        else
        {
            printf("Thank you!\n");
            return ;
        }
    }
}
int main()
{
    printf("请输入总学期数、学分限制C和课程数\n");
    printf("S = ");
    scanf("%d", &S);
    printf("C = ");
    scanf("%d", &C);
    printf("N = ");
    scanf("%d", &n);
    printf("请输入其必修课程的ID、学分、编号和ID\n");
    for (int i=1;i<=n;i++)
    {
        scanf("%s %d", course[i].id, &course[i].cre);
        scanf("%d", &course[i].k);
        for (int j=1;j<=course[i].k;j++)
            scanf("%s", course[i].pre[j]);
    }
    solve();
}

