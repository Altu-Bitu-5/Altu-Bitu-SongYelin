#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
int priority(char op)
{ // 우선순위를 값으로 return
    switch (op)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

void infix_to_postfix(string infix)
{ // 중위 표기식을 후위표기식으로 바꿔서 출력한다
    char ch;
    char top_op;
    stack<char> s;
    for (int i = 0; i < infix.length(); i++)
    {
        ch = infix[i];
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        { // 연산자인 경우
            while (!s.empty() && (priority(ch) <= priority(s.top())))
            {                    // 우선순위를 확인하여 스택의 연산자가 더 높거나 같으면
                cout << s.top(); // 스택의 연산자들을 출력한다,
                s.pop();
            }
            s.push(ch); // 연산자를  스택에 넣는다
            break;
        }
        case '(': // 괄호가 left면 스택에 넣는다
            s.push(ch);
            break;
        case ')':
        { // 괄호가 right면 left가 나올 때까지 스택에 들어있는 연산자 출력
            top_op = s.top();
            s.pop();
            while (top_op != '(')
            {
                cout << top_op;
                top_op = s.top();
                s.pop();
            }
            break;
        }
        default: // 피연산자 출력
            cout << ch;
            break;
        }
    }
    while (!s.empty())
    { // 마지막으로 스택의 연산자를 모두 출력
        cout << s.top();
        s.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string infix;
    cin >> infix; // 중위 표기식 입력

    infix_to_postfix(infix); // 후위 표기식 출력
    return 0;
}
