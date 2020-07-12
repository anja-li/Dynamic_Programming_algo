// Time Complexity: O(N*W).
// As redundant calculations of states are avoided.
// Auxiliary Space: O(N*W).
// The use of 2D array data structure for storing intermediate states-:


#include<iostream>
 int wt[100];
    int val[100];
    int n;
    int W;
    int Max_profit;
    int t[1000][1000];


using namespace std;


int knapsack(int wt[],int val[],int n,int W,int t[][1000]){
    if(n==0|| W==0)
       return 0;
    if(t[n][W]!=-1)
        return t[n][W];  
    else if (wt[n-1]<=W)
    {   
        t[n-1][W]=max(val[n-1]+knapsack(wt,val,n-1,W-wt[n-1],t),knapsack(wt,val,n-1,W,t));
        return t[n-1][W];
        }
    else
    {    t[n-1][W]=knapsack(wt,val,n-1,W,t);
        return t[n-1][W];
    }
    
       
}


int main(){

   
    cout<<"Enter the no of Items:"<<endl;
    cin>>n;
    cout<<"ENTER THE WEIGHT ARRAY: "<<endl;
    for (int i = 0; i < n; i++)
    {
       cin>>wt[i];

    }
    cout<<"ENTER THE VALUE ARRAY: "<<endl;
    for (int i = 0; i < n; i++)
    {
       cin>>val[i];

    }
    
    cout<<"Enter the maximum capacity"<<endl;
    cin>>W;
    
    for (int i = 0; i < n+1; i++) 
        for (int j = 0; j < W + 1; j++) 
            t[i][j] = -1; 
    Max_profit=knapsack(wt,val,n,W,t);
    cout<<" The Maximum profit is:"<<Max_profit;
    
    
}
