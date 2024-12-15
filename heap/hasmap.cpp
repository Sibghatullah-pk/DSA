#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string,int>m;
    pair<string,int>p=make_pair("ali",3);
    m.insert(p);

    pair<string,int>pair2("live",2);
    m.insert(pair2);

    m["mera"]=1;
    
    cout<<m["mera"]<<endl;
    cout<<m.at("ali")<<endl;
    // cout<<m.at("kjg")<<endl;
    // cout<<m["jkg"]<<endl;
    unordered_map<string,int>::iterator c;
    c=m.begin();

    while(c!=m.end())
    {
        cout<<c->first<<c->second<<endl;
        c++;
    }

    return 0;
}
