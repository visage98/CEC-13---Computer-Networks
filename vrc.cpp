#include<iostream>
using namespace std;
int main(){

    cout<<"Enter length : ";
    int n;
    cin>>n;
    cout<<"Enter data : " ;
    int a[20];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]==1)
        {
            count++;
        }
    }
    if(count%2==0)
    {
        a[n]=0;
        cout<<"Parity bit is : "<<0<<endl;
    }
    else
    {
        a[n]=1;
        cout<<"Parity bit is : "<<1<<endl;
    }

    cout<<"Sent data is : ";
    for(int i=0;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl<<"RECEIVER SIDE : "<<endl;
    count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            count++;
        }
    }
    if(count%2==0)
    {
        cout<<"Sent correctly!";
    }
    else
    {
        cout<<"Sent incorrectly!";
    }
    cout<<endl<<"RECEIVED data is : ";
    for(int i=0;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
