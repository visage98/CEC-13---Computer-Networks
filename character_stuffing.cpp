#include<iostream>
#include<cstring>

using namespace std;

int main(){

    string input;
    string output="";
    cout<<"Enter input string :";
    cin>>input;

    output+="(DLE STX)"  ;

    for(int i=0;i<input.length();i++)
    {
        if(input[i]=='D' && input[i+1]=='L'&& input[i+2]=='E')
        {
            output+="(DLE)(DLE)";
            i+=2;
        }
        else
        {
            output+=input[i];
        }
    }
    output+="(DLE ETX)";
    cout<<"Output string is : "<<endl<<output;


    return 0;
}
