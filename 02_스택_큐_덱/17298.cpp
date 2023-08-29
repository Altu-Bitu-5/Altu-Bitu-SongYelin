#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>


using namespace std;



    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        stack<int> s;
        int n;
        cin>>n; // 수열 a의 크기
        vector<int> sequence(n);
        vector<int> result(n);

        for(int i=0; i<n; i++){
            cin>>sequence[i];//수열 입력 받기
        }

        s.push(0); //수열의 index를 스택에 저장
        for(int i=1; i<n; i++){
            while(!s.empty()&&sequence[i]>sequence[s.top()]){//현재 위치의 수열이 top보다 더 크면
                result[s.top()]=sequence[i];//현재 위치의 수열을 출력 배열에 저장한다
                s.pop();
            }//top보다 작으면 스택에 index가 계속 쌓임
            s.push(i);//스택의 top에 새로운 값(수열의 인덱스)을 넣는다
        }
        while(!s.empty()){//반복문이 끝났는데 스택이 안 비어있으면
            result[s.top()]=-1;
            s.pop();
        }
        //출력
        for(int i=0; i<n; i++){
            cout<<result[i]<<" ";
        }
    return 0;
}
