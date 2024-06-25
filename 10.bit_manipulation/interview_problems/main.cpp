#include<iostream>
#include<limits.h>
#include<vector>
#include<map>
using namespace std;


  int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int count = 0;
        for(int i=0;i<31;i++){
            if(ans & (1<<i)) count++;
        }
        return count ;
    }


int singleElement(vector<int>nums){
     int ans = 0;
        for(int i=0;i<nums.size();i++){
             ans = ans ^ nums[i] ;
        }
        return ans;
}


int countSubest(int n){
    return 1<<n;
}

vector<vector<int> >powerSet(vector<int>nums){
    vector<vector<int> >finalAns;
    int subsets = countSubest(nums.size());
    for(int i=0;i<subsets;i++){
        vector<int>ans;
        for(int j=0;j<nums.size();j++){
            if(i & (1<<j)) ans.push_back(nums[j]);
        }
    finalAns.push_back(ans);
    }
    return finalAns;
}

 int xor1ToN (int n){
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
         return n;
    }



vector<int> findTwoNums(vector<int>nums){
    // brute [ hashing ] T.C=o(nlogm) || S.C=o(m)
    // map<int , int>mpp;
    // vector<int>ans;
    // storing elements in map
    // for(int i=0;i<nums.size();i++){
    //     mpp[nums[i]]++;
    // }
    // iterating thru map and finding required nums
    // for(auto it : mpp){
    //     if(it.second == 1) ans.push_back(it.first);
    // }
    // return ans;


    //  optimal T.C=o(2n) || S.C=o(1)
    vector<int>ans;
    // take xor of all numbers
    int xorr = 0;
    for(int i=0;i<nums.size();i++){
        xorr = xorr ^ nums[i];
    }
    // figure out the rightmost set bit
    int rtmost = (xorr & xorr-1) ^ xorr;
    // take two buckets and store numbers with rightmost bit to bucket 1 and other to bucket 2
    int b1=0;
    int b2 =0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] & rtmost) b1 = b1 ^ nums[i];
        else b2 = b2^nums[i];
    }
    ans.push_back(b1);
    ans.push_back(b2);
    return ans;
}





int main(){
//1:
        // minimum bit flips to convert number
        // int ans = minBitFlips(13 , 4);
        // cout<<ans<<endl;


//2:
        // return the element appearing for 1 time in the array using bit manipulation
        // vector<int>nums = {2,2,1};
        // int ans = singleElement(nums );
        // cout<<ans<<endl;

//3:
        // power set    
        // vector<int>nums = {1,2,3};
        // vector<vector<int> >ans = powerSet(nums);


//4:
        // find xor from l to r
        // we 've caluclate xor till 1 - n , so 1step is count xor 1 - l-1 , then count 1 - n after that xor these both to get xor of l to r
        // int l = 4;
        // int r = 7;
        // int ans1 = xor1ToN(l-1);
        // int ans2 = xor1ToN(r);
        // cout<<"ans : "<<(ans1 ^ ans2)<<endl;



//5:
        // find the two numbers appearing odd number of times
        // vector<int>nums = {2,4,2,6,3,7,7,3};
        // vector<int>ans = findTwoNums(nums);
        // for(auto it : ans){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

    return 0;
}