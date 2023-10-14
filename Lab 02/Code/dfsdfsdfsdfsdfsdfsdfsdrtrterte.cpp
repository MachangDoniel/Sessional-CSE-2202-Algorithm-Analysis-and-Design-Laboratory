#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        long long x;
        int sum=0;
        cin>>x;
        if(x<11)cout<<"NO"<<endl;
        else if(x%11==0||x%111==0) cout<<"YES"<<endl;
        else
        {

            for(int k=1; k<x/111;)
            {
                if((x-k*111)%11==0)
                {
                    cout<<"YES"<<endl;
                    sum++;
                    break;
                }
                else
                {
                    k++;
                }
            }
            if(sum==0)cout<<"NO"<<endl;
        }
    }

}

