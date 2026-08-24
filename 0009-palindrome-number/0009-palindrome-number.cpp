class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; 
        long long digit,revdigit=0;
        int a =x;
        while(x>0){
            int digit = x%10;
            revdigit = revdigit * 10 + digit;
            x = x/10;
        }
if(a == revdigit){
    return true;
}
else{
    return false;
}
    }
    };
// int n = x;
// int st =0;
// int end = n-1;
// while(st<end){
//     if(x[st]!=x[end]){
//         return false;
//     }
//     else{
//         st++;
//         end--;
//     }
    
// }
// return true;
//     }   
// };