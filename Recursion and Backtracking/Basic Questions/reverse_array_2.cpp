// reverse array using two-pointer method.

#include<iostream>
#include<utility>
using namespace std;

// 2-pointer method
void func(int l,int r,int arr[]) {
    if(l>=r) return;

    swap(arr[l],arr[r]);
    func(l+1,r-1,arr);
}

int main() {
    int n,arr[n];
    cin >> n;
    cout << "Enter elements : ";
    for(int i=0;i<n;i++) cin >> arr[i];

    func(0,n-1,arr);
    cout << "The reversed array is : " << endl;
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}