//Knapsack

#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>iteminfo(1000);
int profit_array[100][100]={0};
int trac_array[100][100]={0};
void select_item(int n,int k)
{
    int selected_item=trac_array[n][k];
    if(n==0||k<=0)
        return;
    else if(n==selected_item)
    {
        select_item(--n,k-iteminfo[selected_item].second);
    }
    else
    {
        selected_item=0;
        select_item(--n,k);
    }
    if(selected_item)
        cout<<"Selected Item: "<<selected_item<<endl;
}
int main()
{
    int i,j,knapsack,nitem,profit,weight,index=1;
    cin>>nitem>>knapsack;
    for(i=0;i<nitem;i++)
    {
        cin>>profit>>weight;
        iteminfo[index++]=make_pair(profit,weight);
    }
    for(i=1;i<=nitem;i++)
    {
        cout<<"profit: "<<iteminfo[i].first<<" weight: "<<iteminfo[i].second<<endl;
    }
    for(i=1;i<=nitem;i++)
    {
        for(j=1;j<=knapsack;j++)
        {
            pair<int,int>frnt=iteminfo[i];
            if(frnt.second>j)
            {
                profit_array[i][j]=profit_array[i-1][j];
                trac_array[i][j]=trac_array[i-1][j];
            }
            else
            {
                int pre_profit=profit_array[i-1][j];
                int new_profit=frnt.first+profit_array[i-1][j-frnt.second];
                if(pre_profit>new_profit)
                {
                    profit_array[i][j]=profit_array[i-1][j];
                    trac_array[i][j]=trac_array[i-1][j];
                }
                else
                {
                    profit_array[i][j]=new_profit;
                    trac_array[i][j]=i;                }
            }
        }
    }
    for(i=0;i<=nitem;i++)
    {
        for(j=0;j<=knapsack;j++)
        {
            cout<<profit_array[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=0;i<=nitem;i++)
    {
        for(j=0;j<=knapsack;j++)
        {
            cout<<trac_array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Maximum Profit: "<<profit_array[nitem][knapsack]<<endl;;
    select_item(nitem,knapsack);
}
