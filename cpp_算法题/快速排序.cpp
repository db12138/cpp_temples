//快排
#include <iostream>
using namespace std;

int A[100];
int partition(int *arr,int start,int end)
{
    int pivot = arr[start];
    int head = start;
    int tail = end;
    while(head < tail)
    {
        while(head < tail && arr[tail] >= pivot)
            tail--;
        if(head<tail)
        {
            arr[head] = arr[tail];
        }
        
        while(head < tail && arr[head] <= pivot)
        {
            head++;
        }
        if(head <tail )
        {
            arr[tail] = arr[head];
        }
    }
    arr[head] = pivot;
    return head;
}
void quicksort(int *arr , int start,int end)
{
    if(start >= end)
        return ;
    
    int pivot_index = partition(arr, start, end);
    quicksort(arr, start, pivot_index-1);
    quicksort(arr, pivot_index+1, end);
    
}
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    
    quicksort(A,0,N-1);
    
    for(int i = 0;i<N;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

