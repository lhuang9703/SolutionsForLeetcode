// Source : homework of data structure
// Number : **
// Author : HL
// Date   : 2018-09-14
// Kill   : ***

/********************************************************************************** 
Description
n只猴子要选大王，选举方法如下：所有猴子按 1，2 ……… n 编号并按照顺    序围成一圈，从第 k 个猴子起，由1开始报数，
报到m时，该猴子就跳出圈外，下一只猴子再次由1开始报数，如此循环，直到圈内剩下一只猴子时，这只猴子就是大王。
  求猴王是第几个，要求：顺序表实现。
Input
n m
n、m均为整型。0<n<1000,0<m<10^9
Output
优胜者:
ans
Sample Input
8 3
Sample Output
7
Bonus
无。
**********************************************************************************/

#include <iostream>
#include <list>

using namespace std;

struct Monkey {
    int number;
    Monkey *next;
    Monkey(int a) {
        number = a;
        next = NULL;
    }
};

class MonkeyList {
public:
    MonkeyList() {
        head = NULL;
        tail = NULL;
    }
    ~MonkeyList() {
        delete head;
        delete tail;
    }
    int Insert(int number) {
        if (head == NULL) {
            head = tail = new Monkey(number);
        } else {
            Monkey *p = new Monkey(number);
            tail->next = p;
            tail = p;
        }
        return 0;
    }
    int Delete(int number) {
        Monkey *p = head, *q;
        while (p->number != number) {
            q = p;
            p = p->next;
        }
        if (p == tail) {
            tail = q;
            tail->next = head;
        } else if (p == head) {
            head = p->next;
            tail->next = head;
        } else {
            q->next = p->next;
        }
        delete p;
        return 0;
    }
    int getLength(){
        Monkey *p = head;
        int length = 1;
        while (p != tail) {
            length++;
            p = p->next;
        }
        return length;
    }
    int Circle(){
        tail->next = head;
        return 0;
    }
    Monkey *head, *tail;
};

int main()
{
    int n, m, i, temp;
    cin>>n>>m;

    Monkey *head,*tail;
    MonkeyList monkeys;
    for (i = 1; i <= n; i++) {
        monkeys.Insert(i);
    }
    monkeys.Circle();
    Monkey *p = monkeys.head;
    int count = 1;
    while ( monkeys.getLength() != 1) {
        if (count == m) {
            temp = p->number;
            p = p->next;
            monkeys.Delete(temp);
            count = 1;
        } else {
            p = p->next;
            count++;
        }
    }
    cout<<monkeys.head->number<<endl;

    return 0;
}
