// Source : homework of data structure
// Number : **
// Author : HL
// Date   : 2018-09-14
// Kill   : ***

/********************************************************************************** 
一个栈元素的类型为整数，现在要想将该栈从顶到底按从小到大的
顺序排列，只允许申请一个栈，除此之外，可以申请额外的变量，
但是不能申请额外的数据结构，如何完成排序 
用例:    
   输入： 3 4 6 2 5 7  
   输出： 2 3 4 5 6 7 
**********************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s1, s2;
    int a, b;
    cin >> a;
    s1.push(a);
    while (cin.get() != '\n') {
        cin >> a;
        s1.push(a);
    }
    int numberOfS1 = (int)s1.size(), step = 1;

    while (step < numberOfS1) {
        while (s1.size() > step) {
            a = s1.top();
            s1.pop();
            b = s1.top();
            s1.pop();
            if (a > b) {
                s2.push(b);
                s1.push(a);
            } else {
                s2.push(a);
                s1.push(b);
            }
        }
        while (!s2.empty()) {
            a = s2.top();
            s2.pop();
            s1.push(a);
        }
        step++;
    }

    while (!s1.empty()) {
        cout<<s1.top()<<endl;
        s1.pop();
    }

    return 0;
}
