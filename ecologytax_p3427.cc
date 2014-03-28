#include<iostream>
using namespace std;
 
int max(int a, int b){
        return a > b ? a : b;
}
 
int main(){
        int tree, len;
        while(cin >> tree >> len){
           int hei, ans = 0;
           while(tree --){
               cin >> hei;
               if(hei % len == 0)  continue;
               ans = max(ans, len - hei % len);
           }
           cout << ans << endl;
       }
       return 0;
}
