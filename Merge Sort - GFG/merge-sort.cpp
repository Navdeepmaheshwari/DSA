//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int len1=m-l+1,len2=r-m;
         
         int left[len1],right[len2]; //create 2 arrays
         int k=l;
         for(int i=0;i<len1;i++){
             left[i]=arr[l+i];
         }
         for(int i=0;i<len2;i++){
             right[i]=arr[m+1+i];
         }
         
         int i=0,j=0;
         k=l;
         while(i<len1&&j<len2){
             
             if(left[i]<=right[j]){
                 arr[k++]=left[i++];
             }else{
                 arr[k++]=right[j++];
             }
         }
         
         while(i<len1){
             arr[k++]=left[i++];
         }
         
          while(j<len2){
             arr[k++]=right[j++];
         }
         
    }
    
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(r>l){
            
            int mid=l+(r-l)/2;
            
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends