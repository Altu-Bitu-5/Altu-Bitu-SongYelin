#include <iostream>
#include <vector>
#include "queue"

using namespace std;

int main() {

    int n;
    priority_queue<int> heap;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(a==0){
            if(heap.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<heap.top()<<'\n';
                heap.pop();
            }
        }
        else{
            while(a--){
                int b;
                cin>>b;//충전
                heap.push(b);
            }
        }
    }

    return 0;
}