// Problem#: 16214
// Submission#: 4084624
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;

int a[101];
int b[101];

//判断是否排序完成
bool haveSort(int *a,int size)
{
    for(int i = 0;i < size-1;i++)
    {
        if(a[i]>a[i+1])
            return false;
    }
    return true;
}

//判断进行排序后序列是否有改变
bool change(int *a,int *b,int size)
{
    for(int i = 0;i < size;i++)
    {
        if(a[i] != b[i])
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;

    for(int i = 0;i < n;i++)
        cin>>a[i];

    //输出原始数据
    for(int i = 0;i < n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    if(haveSort(a,n))
        return 0;
    else
    {
        //插入排序
        for(int i = 1;i < n;i++)
        {
            for(int i = 0;i < n;i++)
                b[i] = a[i];            
            
            int temp = a[i];
            int j = i-1;

            while(j>=0 && temp < a[j])
                a[j+1]=a[j],j--;
            a[j+1]=temp;
                    
            //每次插入排序后输出
            if(change(a,b,n))
            {
                for(int i = 0;i < n;i++)
                    cout<<a[i]<<" ";
                cout<<endl;
            }
            
            //判断是否已经排好序，若排好则停止
            if(haveSort(a,n))
                return 0;
        }
    }

    return 0;
}                                 