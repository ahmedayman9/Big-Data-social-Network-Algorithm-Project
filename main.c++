#include <bits/stdc++.h>
using namespace std;
map<string,int> cx;
vector<pair<int,string>> v;
set<pair<string,string>> Dup;
int main()
{
      int i,x;
        ifstream fin("twitter.csv");
      string str;

      // o (mlg(m))
      while(getline(fin,str)) //   o(m)  parent
        {
            string id1,id2;
            for(i = 0; str[i] != ',' ;i++) id1.push_back(str[i]);   //   O(size id1)
            ++i;
            for(; i < str.size() ;i++) id2.push_back(str[i]);   // O(size id1)

            Dup.insert({id1,id2});  //o(lgm) parent

        }

        // o(mlg(n))
        for (auto n : Dup){    // o(m)
                cx[n.second]++; //o (lgn)  child
        }

        // o(n) child
        for(auto u:cx)  // O(n)
        {
            v.push_back({u.second,u.first});
        }


        sort(v.begin(),v.end());     // o(nlgn) child
        reverse(v.begin(),v.end()); // o(n)  child


   for (i =0 ;i<5 ; ++i ){
        cout << "Top Influencer ID is " << "  " << v[i].second << "  " <<"No.of Followers  is " << "    " << v[i].first <<endl<< endl;
    }

}

