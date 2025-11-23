// given a 2d array such that arr[i][j] = 1 means ith person knows jth person, the tasks is to find the celebrity. 
// a celebrity is a person who is known to all but doeas not known anyone return the index of the celebrity ,if there is no celebrity return -1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int getcelebrity(vector<vector<int>> arr)
{
    stack<int> s;
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        s.push(i);
        while(s.size()>1)
        {
            int i = s.top();
            s.pop();

            int j = s.top();
            s.pop();

            if(arr[i][j] == 0)
            {
                s.push(i);
            }
            else{
                s.push(j);
            }
        }
    }

    int celeb = s.top();
    for(int i =0;i <n;i++)
    {
        if((i!=celeb) && (arr[i][celeb]==0 || arr[celeb][i]==1))
        {
            return -1;
        }
        return celeb;
    }
}

int main()
{
    vector<vector<int>> arr = { {0,1,0},{0,0,0},{0,1,0}};
    int ans = getcelebrity(arr);

    cout << " celebrity is : " << ans << endl;

    return 0;
}
