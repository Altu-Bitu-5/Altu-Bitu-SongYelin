#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include "map"


using namespace std;

    stack<int> c; //전역함수로 스택 생성
    void sum(string a,string b){
        int sum;
        int carry=0;
        int i=a.size()-1; //1의 자리 숫자가 들어있는 a 인덱스
        int j=b.size()-1; //1의 자리 숫자가 들어있는 b 인덱스
        while(i>=0&&j>=0){ //일의 자리부터 올라가며 더하기
            sum=(a[i]-'0')+(b[j]-'0'); //int로 변황 후 더하기
            sum+=carry; //carry 더하기
            c.push(sum%10); //스택으로 push
            carry=sum/10; //carry 구하기
            i--;
            j--;
        }
        while (i>=0){ //a 문자열이 더 긴 경우
            sum=(a[i]-'0')+carry;
            c.push(sum%10);//스택에 남은 숫자 다 넣기
            carry=sum/10; //carry를 0으로 만듦
            i--;
        }
        while (j>=0){ //b 문자열이 더 긴 경우
            sum=(b[j]-'0')+carry;
            c.push(sum%10);
            carry=sum/10;
            j--;
        }
        if(carry==1){//문자열의 사이즈가 같을 때 마지막 자리 숫자에서 carry 발생 시
            c.push(1);
        }
    }
    int main()
    {

        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string a,b;
        cin>>a>>b; //입력
        sum(a,b); //sum() 함수로 연산

        //출력
        while (!c.empty()){
            cout<<c.top();
            c.pop();
        }


    return 0;
}
