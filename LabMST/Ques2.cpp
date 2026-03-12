#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> arr;
    int k;
    cin>>k;
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    int l=0, r=arr.size()-1;
    while(l<r){
        int temp=arr[l];
        arr[l]=arr[l] & arr[r];
        arr[r]=arr[l] | arr[r];
        l++;
        r--;
    }
    int ans=0;
    sort(arr.begin(), arr.end());
    for(int i=arr.size()-1; i>=k; i--){
        ans+=(arr[i]*arr[i]);
    }
    return ans;
}
