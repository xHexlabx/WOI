#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str1, str2 ;
    cin>>str1>>str2;

//Reverse them
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

//Getting size for final result, just to avoid dynamic size
    int ans_size = str1.size() + str2.size();

//Declaring array to store final result
    int ans[ans_size]= {0};

//Multiplying
//In a reverse manner, just to avoid reversing strings explicitly
    for(int i=0; i<str1.size(); i++)
    {
        for(int j=0; j<str2.size(); j++)
        {
            //Convert array elements (char -> int)
            int p = (int)(str1[i]) - '0';
            int q = (int)(str2[j]) - '0';

            //Excerpt from Shravan's answer above
            ans[i+j]+=p*q;
            ans[i+j+1]=ans[i+j+1]+ans[i+j]/10;
            ans[i+j]%=10;
        }
    }

//Declare array to store string form of final answer
    string s="";

    for(auto i=0; i<ans_size; ++i)
        s += to_string(ans[i]);

    reverse(s.begin(), s.end() );

//If last element is 0, it should be skipped
    if(s[0] =='0')
    {
        string ss(s,1,s.size()-1);
        s=ss;
    }

//Final answer
    cout<< s;

    return 0;
}