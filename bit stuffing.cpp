#include<iostream>
using namespace std;
int main()
{
    int a[50];
    int b[100];
    int n;
    cout<<"Enter the number of bits : ";
    cin>>n;
    int count=0;
    cout<<"Enter bit stream : ";
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    cout<<endl<<"The bit stuffing algo output is : "<<endl;
    int i=0;
    count=1;
    int flag=0;
    int j=0;
    int k;
    while(i<n)
    {
        if(a[i]==1)
        {
            b[j]=a[i];
            for(k=i+1; a[k]==1 && k<n && count<5; k++)
            {
                j++;
                b[j]=a[k];
                count++;
                if(count==5)
                {
                    j++;
                    b[j]=0;
                    flag++;
                }
                i=k;
            }
        }
        else
        {
            b[j]=a[i];
        }
        i++;
        j++;
    }
    for(int i=0;i<n+flag;i++)
    {
        cout<<b[i];
    }
    return 0;
}
