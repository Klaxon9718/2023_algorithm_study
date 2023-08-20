//https://school.programmers.co.kr/learn/courses/30/lessons/131704
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st;
    int idx=0;
    for(int i=0;i<order.size();i++)
    {
        st.push(i+1);
        while(!st.empty())
        {
            if(st.top()==order[idx])
            {
                st.pop();
                idx++;
                answer++;
                
            }
            else break;
        }
    }
    return answer;
}