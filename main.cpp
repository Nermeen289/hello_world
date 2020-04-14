#include <iostream>
#include  <vector>
#include <bits/c++io.h>
#include <algorithm>
using namespace std;

class BigDicimal
{
public:
    vector<int>finall;
    vector<int>degitt;
    int carri=0;///this for carry number
    int sizee=0;///this for carry size
    int sum=0;///this for sum
    int diff;///this for differance
    int bow;///this is for bowrow
    string s1;/// this input
    int size();
    BigDicimal(string str);
    BigDicimal(int deci);
    BigDicimal operator=(BigDicimal b);
    BigDicimal operator+(BigDicimal obj1 );
    BigDicimal operator-(BigDicimal obj1 );
    friend ostream& operator << (ostream& out, BigDicimal b);


};

BigDicimal::BigDicimal(string str)
{
    int degit=0;
    s1=str;
    if(s1[0]=='-')
    {

         degitt.push_back(degit);
        for(int i=1; i<str.length(); i++)
        {

            degit=(s1[i]-'0');
         degitt.push_back(degit);


        }

    }
    else
    {
        for(int i=0; i<str.length(); i++)
        {
            degit=s1[i]-'0';
            degitt.push_back(degit);
        }
    }

    sizee=degitt.size();
}

BigDicimal::BigDicimal(int deci)
{


}
ostream& operator<<(ostream& out, BigDicimal b)
{
    out<<b.s1;
    for(int i=0; i<b.size(); i++)
        out<<b.finall[i];
    return out;
}
BigDicimal BigDicimal::operator+(BigDicimal  obj1)
{
    BigDicimal obj(0);

    if(sizee>obj1.sizee)
    {

        int n=sizee-obj1.sizee;
        for(int i=0; i<n; i++)
            obj1.degitt.insert(obj1.degitt.begin(),0);
        for( int i=degitt.size(); i>=0; i--)
        {
            sum=(obj1.degitt[i])+(degitt[i]);
            if(sum>=10)
            {
                degitt[i-1]++ ;
                carri = 1 ;
            }
            if(carri==1)
            {
                obj.finall.push_back(sum-10) ;
                carri = 0 ;
            }
            else
            {

                obj.finall.push_back(sum) ;
            }
        }


        reverse(obj.finall.begin(), obj.finall.end());

    }

    else if(obj1.sizee>sizee)
    {
        int n=obj1.sizee-sizee;

        for(int i=0; i<n; i++)
            degitt.insert(degitt.begin(),0);

        for( int i=obj1.degitt.size(); i>=0; i--)
        {
            sum=(obj1.degitt[i])+(degitt[i]);
            if(sum>=10)
            {
               obj1.degitt[i-1]++ ;
                carri = 1 ;
            }
            if(carri==1)
            {
                obj.finall.push_back(sum-10) ;
                carri = 0 ;
            }
            else
            {

                obj.finall.push_back(sum) ;
            }


        }
        reverse(obj.finall.begin(), obj.finall.end());
    }
    else

    {



        for( int i=sizee; i>=0; i--)
        {
            sum=(obj1.degitt[i])+(degitt[i]);
            if(sum>=10)
            {
                degitt[i-1]++ ;
                carri = 1 ;
            }
            if(carri==1)
            {
                obj.finall.push_back(sum-10) ;
                carri = 0 ;
            }
            else
            {

                obj.finall.push_back(sum) ;
            }


        }
        reverse(obj.finall.begin(), obj.finall.end());
    }

    return obj;


}

BigDicimal BigDicimal::operator-(BigDicimal  obj1)
{

    BigDicimal obj(0);
    if(sizee>obj1.sizee)
    {
        int n=sizee-obj1.sizee;
        for(int i=0; i<n; i++)
            obj1.degitt.insert(obj1.degitt.begin(),0);

        for(int i=degitt.size(); i>=0; i--)
        {
            diff=(degitt[i])-(obj1.degitt[i]);
            if(diff<0)
            {
                degitt[i-1]--;
                bow=1;

            }
            if(bow==1)
            {
                obj.finall.push_back(diff+10);
                bow=0;
            }
            else
            {
                obj.finall.push_back(diff);
            }


        }
    }
    else if(sizee<obj1.sizee)
    {
        int n=obj1.sizee-sizee;
        for(int i=0; i<n; i++)
            degitt.insert(degitt.begin(),0);
        for(int i=obj1.degitt.size(); i>=0; i--)
        {
            diff=(obj1.degitt[i])-(degitt[i]);
            if(diff<0)
            {
                obj1.degitt[i-1]--;
                bow=1;

            }
            if(bow==1)
            {
                obj.finall.push_back(diff+10);
                bow=0;
            }
            else
            {
                obj.finall.push_back(diff);
            }

        }

    }

    else
    {
        bool flage=0;
          for(int i=0;i<degitt.size();i++)
        {
            if(degitt[i]>obj1.degitt[i])
                flage=1;
            else
               flage=0;

        }
          if(flage==0)
            {
                for(int i=obj1.degitt.size(); i>=0; i--)
            {
                diff=(obj1.degitt[i])-(degitt[i]);
                if(diff<0)
            {
                obj1.degitt[i-1]--;
                bow=1;

            }
            if(bow==1)
            {
                obj.finall.push_back(diff+10);
                bow=0;
            }
            else
            {
                obj.finall.push_back(diff);
            }

            }
            }
            else
            {
                for(int i=degitt.size(); i>=0; i--)
            {
                diff=(obj1.degitt[i])-(degitt[i]);
                if(diff<0)
            {
                 degitt[i-1]--;
                bow=1;

            }
            if(bow==1)
            {
                obj.finall.push_back(diff+10);
                bow=0;
            }
            else
            {
                obj.finall.push_back(diff);
            }

            }
            }


        }


 reverse(obj.finall.begin(), obj.finall.end());

 return obj;

}

BigDicimal::size()
{

    return finall.size();

}

int main()
{
    BigDicimal num("-1157");
    BigDicimal num1("-11454");
    BigDicimal num2 =num1-num;
    cout<<"num1"<<" = "<<num<<endl;
    cout<<"num2"<<" = "<<num1<<endl;
    cout<<"num3"<<" = "<<num2<<endl;
    cout<<"real diff"<<" = "<<-1157+11454<<endl;


    return 0;
}
