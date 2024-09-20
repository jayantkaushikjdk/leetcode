// class Solution {
// public:
//     bool isHappy(int n) {
//     int h=0;
//     while(n>9){
//     int a=n%10;
//     int b=n/10;
//     int h=(a*a)+(b*b);
//     }
//     if(h==1){
//         return true;
//     }
//     else{
//         return false;
//     }

//     }
// };
class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            n = sumDigitSquare(n);
        }
        return n == 1;
    }

    int sumDigitSquare(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};