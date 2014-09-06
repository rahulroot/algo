#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct 
{
  int index;
  const char *suff;
}suffix;

bool match(const char *pat, const char *txt, int *suffArr, int n)
{
  int m = strlen(pat);
  int l = 0, r = n-1;
  while (l <= r)
  {
    int mid = l + (r - l)/2;
    int res = strncmp(pat, txt+suffArr[mid], m);
    if (res == 0)
       return true;
    if (res < 0)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return false;
}

int cmp(suffix a, suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

int* suffix_array(const char *txt)
{
  int n = strlen(txt);
  suffix *suffixes = new suffix[n];
  for (int i = 0; i < n; i++)
  {
    suffixes[i].index = i;
    suffixes[i].suff = (txt+i);
  }
  sort(suffixes, suffixes+n, cmp);

  int *suffixArr = new int[n];
  for (int i = 0; i < n; i++)
     suffixArr[i] = suffixes[i].index;

  delete [] suffixes;
  return  suffixArr;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int test;
  cin >> test;
  cin.ignore();
  while(test--)
  {
    string txt;
    getline(cin, txt);
    int *arr = suffix_array(txt.c_str());
    int qery;
    cin >> qery;
    while(qery--)
    {
      string q;
      cin >> q;
      cin.ignore();
      if(match(q.c_str(), txt.c_str(), arr, txt.size()))
        cout <<"y"<<endl;
      else
        cout <<"n"<<endl;
      q.clear();
    }
    delete [] arr;
  }
  return 0;
}
