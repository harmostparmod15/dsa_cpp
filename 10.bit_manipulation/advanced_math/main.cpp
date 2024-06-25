#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPrime(int n){
    bool ans = true;
    for(int i=2;i*i<=n;i++){
        if (n % i == 0) ans = false;
    }
    return ans;
}

vector<int> primeFactors(int n){
    // brute T.C=o(n * sqrtn) || S.C=o( for returning vector ans , so its dynamic)
    // vector<int>ans;
    // for(int i=2;i<=n;i++){
    //     // if its a factor of n
    //     if(n%i==0){
    //         // if its a prime number and factor of n also ,then add number in array
    //         if (isPrime(i)) ans.push_back(i);
    //     }
    // }
    // return ans;

    // optimal T.C = o(sqrt n * logn)
    vector<int>ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);   
            while(n %i==0){
                n = n/i;
            }
        }
    }
    if (n!=1) ans.push_back(n);
    return ans;
}

vector<int> getAllDivisors(int n){
    // T.C=o(sqrt n)  || S.C=use for returning the array
    vector<int>ans;
    for(int i=1;i*i<=n;i++){
        if (n%i==0) {
            // store the divisor
            ans.push_back(i);
            // store the 2nd divisor
            if (i != n/i)
                ans.push_back(n/i);
        }
    }
    return ans;
}

void printPrime(int n){
    vector<int>prime(n+1);
    // mark the prime array as 1
    for(int i=2;i<=n;i++){
        prime[i] = 1;
    }
    // if number is prime then mark all its multiple as 0
    for(int i=2;i*i<=n;i++){
        if(prime[i] == 1){
            for(int j=i*i;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }
    // print the prime numbers
    int count = 0;
    for(int i=2;i<n;i++){
        if(prime[i] == 1) {
            cout<<i<<endl;
            count++;
            }
    }
    cout<<"count "<<count<<endl;
}



double powerMan(double x , int n){
     double ans =1;
     double m = n;
     n = abs(n);
    while(n>0){
        if(n%2==1){
            ans = ans * x;
            n = n-1;    
        }
        else{
            n = n/2;
            x     = x*x;
        }
    }
    if(m<0) ans = 1.0/ans;
    return ans;
}




int main(){
//1:
        //  print all prime factors of a given number
        // vector<int>ans = primeFactors(780);
        // for(auto it : ans){
            // cout<<it<<" ";
        // }

//2:

        // print all disvisor of a number
        // vector<int>ans = getAllDivisors(36);
        // for(auto it: ans){
        //     cout<<it<<" ";
        // }

//3:
        // seive of erastotas
        // printPrime(10);

//4:
        // find prime factorisation of a number using sieve 


//5:
        // find a power b
        // double ans = powerMan(2,5);
        // cout<<"ans : "<<ans<<endl;

    return 0;
}