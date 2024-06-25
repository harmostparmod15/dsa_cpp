#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;


void reverseStr(string& str)
{
    int n = str.length();
 
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

string convertToBinary(int num ){
    string ans = "";
    
    while(num!=0){
        if(num%2==1) ans = ans + "1";
        else ans += "0";
        num /= 2;
    }
    reverseStr(ans);
    return ans;
}


bool checkIthBit(int num , int bit){
    num = num >> bit;
    if (num & 1 !=0 ) return true;
    else return false;
}

int setIthBit(int num , int bit){
    int it = 1 << bit;
    return num | it;
}

int clearIthBit(int num , int bit){
    return num & ~(1<<bit);
}

int toggleIthBit(int num , int bit){
    return num ^ (1<<bit);
}

int clearRightSetBit(int n){
    return n & n-1;
}


int checkPower2(int num){
    if ((num & (num -1)) == 0) return true;
    else return false;
}

int countSetBits(int num){
    int counter =0;
    while(num >1){
        counter += num & 1;
        num = num >> 1;
    }
    if(num == 1) counter ++;
    return counter;
}
int countSetBitsVersion2(int num){
    int counter = 0;
    // while number is not equal to zero i will go on clearing the rightmost set bit (1) and increasing my counter as well
    while(num !=0){
        num = num & (num-1);
        counter ++;
    }
    return counter;
}


int checkOdd(int num){
    if (num & 1 == 1) return true;
     return false;
}


void swapNum(int &n1 , int &n2){
    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;

    return ;
}


  int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool sign = true;
        if(dividend >=0 && divisor <0) sign = false;
        if(dividend <0 && divisor >0) sign = false;
        long n = abs(dividend);
        long d = abs(divisor);
        int ans = 0;
        while(n>=d){
        int count = 0;
        while(n >= (d<<(count+1))){
            count +=1;
        }
            ans += 1<<count;
            n -= d <<count;
        
        }
        if(ans == (1<<31) && sign == true) return INT_MAX;
        if(ans == (1<<31) && sign == false) return INT_MIN;
        return sign ? ans : -1 * ans;
    }


   


int main(){

 // 1:
        // check if ith bit is set or not
        // bool ans = checkIthBit(13,1);
        // ans == true ? cout<<"Yes " : cout<<"No";

 // 2:
        // set ith bit in a given number
        // int ans = setIthBit(13 , 1);
        // cout<<"ans : "<<ans<<endl;

// 3:
        //clear the ith bit
        // int ans = clearIthBit(11 ,  1);
        // cout<<"ans : "<<ans<<endl;

// 4 :
        // toggle the ith bit
        // int ans = toggleIthBit(13 , 1);
        // cout<<"ans : "<<ans<<endl;

// 5:
        // clear the rightmost set bit
        // int ans = clearRightSetBit(13);
        // cout<<"ans : "<<ans<<endl;

// 6:
        //  check if the num is in power of 2   
        // bool ans = checkPower2(64);
        // ans == true ? cout<<" Yes " : cout<<" no";

// 7:
        // count the number of set bits in a given number
        // int ans = countSetBits(7);
        // int ans = countSetBitsVersion2(7);
        // cout<<"ans : "<<ans<<endl;

// 8: 
       // check if number is odd or even by bit manipulation
    //    bool ans = checkOdd(8);
    //    ans == true ? cout<<"no. is odd " : cout<<"no is even ";

// 9:
        // swap two numbers using bit manipulation
        // int a = 5;
        // int b =2;
        // cout<<"before swap .."<<endl;
        // cout<<a<<"  "<<b;
        // swapNum(a,b);
        // cout<<"after swap .."<<endl;
        // cout<<a<<"  "<<b;

//10: 
        // divide 2 integers without using multiplication
        // int ans = divide(12,3);
        // cout<<"ans : "<<ans<<endl;

}