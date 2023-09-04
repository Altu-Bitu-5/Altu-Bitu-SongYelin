#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>



using namespace std;

bool check_matching(string a){
    stack<char> s;
    char ch,stack_ch;
    for(int i=0; i<a.size(); i++){
        ch=a[i];
        switch(ch){
            case '(': case '[': //괄호가 left면 stack에 push
                s.push(ch);
                break;
            case ')': case ']': //괄호가 right면, 맞는 left가 있는 지 확인 
                if(s.empty()) {return false;} //stack이 비어있으므로 false를 return
                else{
                    stack_ch=s.top();
                    s.pop();
                    if((stack_ch=='('&&ch!=')')||(stack_ch=='['&&ch!=']')){
                        return false; //괄호가 짝이 안 맞으면 false를 return
                    }
                    break;

                }
        }

    }
    if(!s.empty()) return false; //stack이 비어있지않고 괄호 left가 남아있으므로 false를 return
    return true;

}
int main()
{
    //입출력 시간 절약
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a;
    while(1){
        getline(cin,a); //문장을 입력받음
        if(a=="."){ //'.'이면 반복을 끝냄   
            break;
        }
        bool balance= true; //균형이 잡혀있나? 처음 상태 TRUE 
        balance= check_matching(a); // check_matching() 함수로 문자열 균형 확인
        
        //출력
        if(balance== false) { 
            cout << "no" << "\n";
        }
        else if (balance== true){
            cout<<"yes"<<"\n";
        }

    }


    return 0;
}
