#include<bits/stdc++.h>
using namespace std;
struct trie
{
    trie* node[26];
    int count;
    trie()
    {
        for(int i=0;i<26;i++)
        {
            node[i]=NULL;
        }
        count=0;
    }
};
void build(string s, trie* root)
{
    for(int i=0;i<s.length();i++)
    {
        if(!root->node[s[i]-'a'])
        root->node[s[i]-'a']=new trie();
        root=root->node[s[i]-'a'];
        root->count++;
    }
}
string find(string s, trie* root)
{
    string t;
    for(int i=0;i<s.length();i++)
    {
        t.push_back(s[i]);
        root=root->node[s[i]-'a'];
        if(root->count==1)
            return t;
    }
}
vector<string> Solution::prefix(vector<string> &a) 
{
    vector<string> v;
    trie* root = new trie();
    for(int i=0;i<a.size();i++)
    {
        build(a[i],root);
    }
    for(int i=0;i<a.size();i++)
    {
        v.push_back(find(a[i],root));
    }
    return v;
}