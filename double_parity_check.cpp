#include<iostream>
using namespace std;

int main(){
    int a[10][10];
    cout<<"Enter the number of data bytes :";
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    for(int j=0;j<7;j++)
    {
        cin>>a[i][j];
    }
    cout<<"The bit stream has been divided into rows of 7 bits : "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<7;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    int count=0;
    int i=0;int j=0;
    for(i=0;i<m;i++)
    {
        count=0;
        for( j=0;j<7;j++)
        {
            if(a[i][j]==1)
                count++;
        }
        if(count%2!=0)
        {
            a[i][j]=1;
        }
        else
        {
            a[i][j]=0;
        }
    }

    for(j=0;j<7;j++)
    {
        count=0;
        for(i=0;i<m;i++)
        {
            if(a[i][j]==1)
                count++;
        }
        if(count%2!=0)
        {
            a[i][j]=1;
        }
        else
        {
            a[i][j]=0;
        }
    }
    ///diagonal parity
    for(int j=7;j<8;j++)
    {
        count=0;
        for(int i=0;i<m;i++)
        {
            if(a[i][j]==1)
            {
                count++;
            }
        }
        if(count%2!=0)
        {
            a[i][j]=1;
        }
        else
        {
            a[i][j]=0;
        }
    }
    cout<<"The parity generated 2-D array is : "<<endl;
    for(int i=0;i<m+1;i++)
    {
        if(i==m)
        {
          cout<<"- - - - - - - "<<endl;
        }
        for(int j=0;j<8;j++)
        {

            if(j==7)
            {
                cout<<"|"<<a[i][j]<<" ";
            }
            else
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
