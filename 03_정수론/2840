#include <iostream>
#include "vector"
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<char> lucky(n,'?');

    int cnt;
    while(k--){
        int s;
        char c;
        //입력
        cin>>s>>c;
        cnt+=s;
        cnt%=n;
        if(lucky[cnt]!='?'&&lucky[cnt]!=c){//전에 나왔던 문자와 다른 문자
            cout<<'!';
            return 0;
        }
        lucky[cnt]=c;

    }

    //한 배열에서 중복값이 나오면 !
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(lucky[i]!='?'&&lucky[i]==lucky[j]){
                cout<<'!';
                return 0;
            }
        }
    }

    //출력
   for(int i=0; i<n; i++){
        cout<<lucky[cnt--];
        if(cnt<0){//음수면 인덱스에 배열의 사이즈를 더함
            cnt+=n;
        }
    }
    return 0;
}