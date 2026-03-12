#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr;
    int maxOp;
    cin>>maxOp;
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int l=1, r=arr.size()-1;
    while(l<r){
        int mid=l+(r-l)/2;
        int op=0;
        for(int a:arr){
            op+=(a-1)/mid;
        }
        if(op>maxOp){
            l=mid+1;
        } else {
            r=mid;
        }
        cout<<l<<endl;
        break;
    }
    return 0;
}
