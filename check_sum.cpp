#include<iostream>

using namespace std;

int main()
{
    int a[10][8];
    int n=2;
    int co[10];
    cout<<"Enter bit stream ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>a[i][j];
        }
    }

    int c=0;
    for(int j=7;j>=0;j--)
    {
        if(a[0][j]==1 && a[1][j]==1)
        {
            if(c==1)
                {a[n][j]=1;c=1;}
            else if(c==0)
                {a[n][j]=0;c=1;}
        }
        else if(a[0][j]==0 && a[1][j]==0)
        {
            if(c==1)
                {a[n][j]=1;c=0;}
            else if(c==0)
                {a[n][j]=0;c=0;}
        }
        else if((a[0][j]==0 && a[1][j]==1) || (a[0][j]==1 && a[1][j]==0))
        {

            if(c==1)
                {a[n][j]=0;c=1;}
            else if(c==0)
                {a[n][j]=1;c=0;}
        }
    }cout<<endl;
    cout<<"Check Sum generated is : ";
    for(int j=0;j<8;j++)
    {
        cout<<a[n][j];
    }

    cout<<endl;
    cout<<"It's complement is : ";

    for(int j=0;j<8;j++)
    {
        if(a[n][j]==1)
        {
            co[j]=0;
        }
        else
        {
            co[j]=1;
        }
        cout<<co[j];
    }
    cout<<endl;
    cout<<"\nSENDER SIDE:\nMessage sent is :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    for(int j=0;j<8;j++)
    {
        cout<<co[j];
    }

    cout<<"\nRECEIVER SIDE : "<<endl;
    int b[10][8];
    cout<<"Enter bit stream ";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>b[i][j];
        }
    }
    c=0;
    for(int j=7;j>=0;j--)
    {
        if((b[0][j]==1 && b[1][j]==1 && b[2][j]==1) )
        {
             if(c==1)
                {b[3][j]=0;c=1;}
            else if(c==0)
                {b[3][j]=1;c=1;}
        }
        if((b[0][j]==1 && b[1][j]==0 && b[2][j]==1) ||(b[0][j]==0 && b[1][j]==1 && b[2][j]==1)||(b[0][j]==1 && b[1][j]==1 && b[2][j]==0))
        {
            if(c==1)
                {b[3][j]=1;c=1;}
            else if(c==0)
                {b[3][j]=0;c=1;}
        }
        else if(b[0][j]==0 && b[1][j]==0 && b[2][j]==0)
        {
            if(c==1)
                {b[3][j]=1;c=0;}
            else if(c==0)
                {b[3][j]=0;c=0;}
        }
        else if((b[0][j]==0 && b[1][j]==0 && b[2][j]==1) || (b[0][j]==0 && b[1][j]==1 && b[2][j]==0) || (b[0][j]==1 && b[1][j]==0 && b[2][j]==0))
        {

            if(c==1)
                {b[3][j]=0;c=1;}
            else if(c==0)
                {b[3][j]=1;c=0;}
        }
    }
    cout<<"\nThe Sum of sent data bytes comes out to be : ";
    for(int j=0;j<8;j++)
    {
        cout<<b[3][j];
    }
    cout<<"\nIt's complement is : ";
    for(int j=0;j<8;j++)
    {
        if(b[3][j]==1)
        {
            co[j]=0;
        }
        else
        {
            co[j]=1;
        }
        cout<<co[j];
    }
    cout<<endl;
    int i;
    for(i=0;i<8;i++)
    {
        if(co[i]==0)
            continue;
        else
            cout<<"Error in transmission as complement of sum of received data bytes is not equal to 0.";
    }
    if(i==8)
        cout<<"Successful transmission as complement of sum of received data bytes is equal to 0.";
    return 0;
}
