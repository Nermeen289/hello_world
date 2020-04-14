#include <iostream>
#include <set>
using namespace std;
set<string>str;
set<string> ::iterator it;

void recprmute(string sofar,string rest)

{

    if(rest=="")
     str.insert(sofar);
    else
    {
         for (int i = 0; i < rest.length(); i++)
        {
           string next = sofar + rest[i];
           string remaining = rest.substr(0, i)+ rest.substr(i+1);
              recprmute(next, remaining);
        }
    }


}
    void ListPermutations(string s){

        recprmute("",s);
        cout<<"Output"<<endl;
        for(it=str.begin();it!=str.end();it++)
            cout<<*it<<" ";
}

int main()
{

    string s;
    cout<<"Input:"<<endl;
    cin>>s;
    ListPermutations(s);


 return 0;
}
