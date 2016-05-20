#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void print(string &s)
{
  cout << s <<' ';
}
int main()

{
    set<string> dict;
    dict.insert("12");
    dict.insert("123");
    dict.insert("234");
    dict.insert("12345");
    dict.insert("456");
    dict.insert("1234");
    dict.insert("567");
    dict.insert("123342");
    dict.insert("42");
    dict.insert("245436564");
    dict.insert("12334");

    string str = "123456712334245436564";

    int size = str.size();
    vector<int> dp(size+1, -1);
    dp[0] = 0;
    vector<string > res(size+1);
    for(int i = 0; i < size; ++i)
    {
        if(dp[i] != -1)
        {
            for(int j = i+1; j <= size; ++j)
            {
                const int len = j-i;
                string substr = str.substr(i, len);
                if(dict.find(substr) != dict.end())
                {
        cout <<"Found in dic : " << substr <<" at i : " << i <<  endl;
                    string space = i?" ":"";
                    res[i+len] = res[i] + space + substr;
        for_each(res.begin(), res.end(), print);
                    dp[i+len] = dp[i]+1;
                }
            }
        }
    }
    cout << *dp.rbegin() << endl;
    cout << *res.rbegin() << endl;

    return 0;
}
