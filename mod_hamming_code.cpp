#include<bits/stdc++.h>
using namespace std;
int main() {
int data[8];
cout<<"Enter the bits of the data\n";
cin>>data[2]>>data[4]>>data[5]>>data[6];
data[0]=data[2]^data[4]^data[6];
data[1]=data[2]^data[5]^data[6];
data[3]=data[4]^data[5]^data[6];
data[7]=data[0]^data[1]^data[2]^data[3]^data[4]^data[5]^data[6];
cout<<"The sent data is as follows\n";
for(int i=0;i<8;i++)
cout<<data[i];
cout<<'\n';
cout<<"Do you want to introduce error?(1/0)\n"; int choice;
cin>>choice;
while(choice){
cout<<"Enter index\n";
int index;
cin>>index;
data[index]=1-data[index];
cout<<"Do you want to introduce error?(1/0)\n"; cin>>choice;
}
int c1,c2,c3,c4;
c1=data[0]^data[2]^data[4]^data[6];
c2=data[1]^data[2]^data[5]^data[6];
c3=data[3]^data[4]^data[5]^data[6];
c4=data[7]^data[0]^data[1]^data[2]^data[3]^data[4]^data[5]^data[6];
if(c1==0&&c2==0&&c3==0&&c4==0)
cout<<"No error\n";
else if((c1!=0||c2!=0||c3!=0)&&c4!=0)
cout<<"Single bit error\n";
else if((c1!=0||c2!=0||c3!=0)&&c4==0)
cout<<"Double bit error\n";
else
cout<<"The last parity bit is corrupted\n"; return 0;
}
