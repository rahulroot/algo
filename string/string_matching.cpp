#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

/*
 * string matching 
 */

bool naive_match(string &txt, string &q)
{
	int slen = txt.size();
	int qlen = q.size();
	bool found = false;
	int s;
	for(s = 0; s <= (slen-qlen); ++s)
	{
		found = true;
		for(int j = 0; j < qlen; ++j)
		{
			if(q[j] != txt[s+j])
			{
				found = false;
				break;
			}
		}
		if(found)
			break;
	}
	cout <<"string match at : " << s  << endl;
	return found;
}

int next[100] = {-1};
void compute_next(string &p)
{
  int plen = p.size();
  next[0] = 0; /* initially next[q] = 0, first character in pattern */
  int k = 0; /* no of char matched so far */
  int q = 1;
  while( q < plen )
  {
    while( k > 0 && p[k] != p[q] ) {
      k = next[k-1];
    }
    if(p[k] == p[q])
      k=k+1;
    next[q] = k;
    q++;
  }
}
bool kmp_match(string &s, string &p)
{
  int slen = s.size();
  int plen = p.size();
  compute_next(p);
  int q = 0; /* no of char matched so far */
  int ind = 0;
  bool found = false;
  while(ind < slen) {
    while(q > 0 && p[q] != s[ind])
      q = next[q-1]; /* if char doesn't match, shift by taking value from next array */
    if(p[q] == s[ind])
      q = q+1; /* if matches, shift by 1 */
    if(q == plen)
    {
      cout <<"Pattern occurs with shift : " << (ind-plen+1) << endl;
      found = true;
      break;
      q = next[q];
    }
    ind++;
  }
  return found;
}  

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	int test;
	infile >> test;
	infile.ignore();

	while(test--)
	{
		string str;
		getline(infile, str);
		int q;
		infile >> q;
		infile.ignore();
		cout <<"new string : "<< str << endl;
		while(q--)
		{
			string que;
			getline(infile, que);
			cout <<"matching : " << que << endl;
			if(kmp_match(str, que))
				cout<<"y"<<endl;
			else
				cout<<"n"<<endl;
			que.clear();
			memset(&next, -1, sizeof(next));
		}
	}

	return 0;
}
