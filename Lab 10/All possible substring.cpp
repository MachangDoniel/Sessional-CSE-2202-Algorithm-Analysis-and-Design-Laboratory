//All possible substring

#include<bits/stdc++.h>

using namespace std;

#define N 100
#define pb push_back
#define MP make_pair


print(int start,int last,int *a)
{
    for(int i=start;i<=last;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    //cout<<"Hello Chief"<<endl;
    ifstream input("input.txt");
    int n,sum;
    input>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++)
    {
        input>>a[i];
    }

    cout<<"Given Array: ";
    print(0,n-1,a);

    cout<<"Subarray: "<<endl;
    int total,start,end,count;
    total=start=end=count=0;
    vector<vector<int>>v(N);
    map<int,int>mp;
    //v.assign(N,0);
    for(int i=0;i<n;i++)
    {
        total+=a[i];
        v[total].pb(i+1);
        mp[total]++;
        //cout<<"Total: "<<total<<endl;
        if(mp[total-sum])
        {
            for(int j=0;j<v[total-sum].size();j++)
            {
                //cout<<" "<<total<<" "<<total-sum<<endl;
                print(v[total-sum][j],i,a);
                count++;
            }
        }
    }
    cout<<"solution: "<<count<<endl;
}

//10 5
//3 9 -2 4 1 -7 2 6 -5 4
