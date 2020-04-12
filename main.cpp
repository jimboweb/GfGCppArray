#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// Function to find maximum of all subarray of size two
void maximumAdjacent(int sizeOfArray, int arr[]){

    for(int i=0;i<sizeOfArray-1;i++){
        int largest = arr[i]>arr[i+1]?arr[i]:arr[i+1];
        cout << largest <<" ";
    }

}

vector<long long> reverseInGroups(vector<long long> mv, int n, int k){

    vector <long long> rtrn;
    vector<long long> temp;
    int grpCtr=0;
    for(int i=0;i<n;i++){
        temp.push_back(mv[i]);
        if(grpCtr==k-1||i==n-1){
            int tn =temp.size();
            for(int j=0;j<tn/2;j++){
                std::swap(temp[j],temp[tn-j-1]);
            }
            for(int j=0;j<tn;j++){
                rtrn.push_back(temp[j]);
            }
            grpCtr = 0;
            temp.clear();
        } else {
            grpCtr++;
        }

    }
    return rtrn;
}

//minimum adjacent distance in circular array
// arr[]: input array
// n: size of array
int minAdjDiff(int arr[], int n){
    int rtrn = INT_MAX;
    for(int i=0;i<n;i++){
        int diff = abs(arr[i]-arr[(i+1)%n]);
        if(diff<rtrn)
            rtrn = diff;
    }
    return rtrn;
}

// arr: input array
// n: size of array
void printfrequency(int arr[], int n)
{

    int res[n];
    for(int i=0;i<n;i++){
        res[i]=0;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>0)
            res[arr[i]-1]++;
    }
    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
}

//maximum difference in index between i and j where arr[i]<arr[j] and i<j
// arr[]: input array
// n: size of array
int maxIndexDiff(int arr[], int n)
{
    int maxDiff = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]<=arr[j]&&j-i>maxDiff)
                maxDiff = j-i;
        }
    }
    return maxDiff;
}

//count frequencies of elements in array
// arr: input array
// n: size of array
void printfrequency(int arr[], int n)
{

    int res[n];
    for(int i=0;i<n;i++){
        res[i]=0;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>0)
            res[arr[i]-1]++;
    }
    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
}

//fine equilibrium point in array

// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n) {
    if(n==1)
        return 1;
    int leftSum[n];
    int rightSum[n];
    leftSum[0]=a[0];
    rightSum[n-1]=a[n-1];
    int i=1,j=n-2;
    while(i<n){
        leftSum[i]=a[i]+leftSum[i-1];
        rightSum[j]=a[j]+rightSum[j+1];
        i++;
        j--;
    }
    for(int i=1;i<n-1;i++){
        if(leftSum[i-1]==rightSum[i+1])
            return i+1;
    }
    return -1;
}


void swap(int &a, int &b){
    int temp =a;
    a=b;
    b=temp;
}

//find leaders in array
//leader means a[i] where all a[i+n]<a[i]
vector<int> leaders(int arr[], int n) {

    vector<int> rtrn;
    rtrn.push_back(arr[n - 1]);
    int biggest = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= biggest) {
            biggest = arr[i];
            rtrn.push_back(arr[i]);
        }
    }
    int j=0,k=rtrn.size()-1;
    while(j<k){
        swap(rtrn[j],rtrn[k]); //why doesn't std::swap work here?
        j++;
        k--;
    }

    return rtrn;
}

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){
    int rtrn=0;
    int lMax[n],rMax[n];
    lMax[0]=arr[0];
    for(int i=1;i<n;i++){
        lMax[i]=arr[i]>lMax[i-1]?arr[i]:lMax[i-1];
    }
    rMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        rMax[i]=arr[i]>rMax[i+1]?arr[i]:rMax[i+1];
    }
    for(int i=0;i<n;i++){
        int min = rMax[i]<lMax[i]?rMax[i]:lMax[i];
        rtrn+=min-arr[i];
    }
    return rtrn;
}


// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    int totalProfit = 0;
    int currentProfit = 0;
    int prevLowPos = 0;
    int prevHiPos =0;
    for(int i=1;i<n;i++){
        if(price[i]<price[i-1]){
            prevHiPos=i-1;
            if(prevHiPos>prevLowPos)
                printf("(%d %d) ",prevLowPos, prevHiPos);
            totalProfit+=currentProfit;
            currentProfit=0;
            prevLowPos=i;
        } else if(price[i]>price[i-1]) {
            prevHiPos=i;
            currentProfit+=(price[i]-price[i-1]);
        } else {
            prevLowPos = i;
        }
    }
    if(currentProfit>0)
        printf("(%d %d) ",prevLowPos, prevHiPos);
    totalProfit+=currentProfit;
    if(totalProfit == 0)
        printf("No Profit");
}

// Kadane's algorithm: Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    int curMaxSum = -500000000, maxMaxSum = -500000000;
    for(int i=0;i<n;i++){
        curMaxSum = arr[i]>arr[i]+curMaxSum?arr[i]:arr[i]+curMaxSum;
        if(curMaxSum>maxMaxSum)
            maxMaxSum=curMaxSum;
    }
    return maxMaxSum;
}


// Function to find circular subarray with maximum sume
// arr: input array
// num: size of array
int circularSubarraySum(int arr[], int num){
    int curMaxSum = -500000000, maxMaxSum = -500000000;
    int curMinSum=500000000, minMinSum = 500000000;
    int totalSum=0;
    for(int i=0;i<num;i++){
        totalSum+=arr[i];
        curMaxSum = arr[i]>arr[i]+curMaxSum?arr[i]:arr[i]+curMaxSum;
        if(curMaxSum>maxMaxSum)
            maxMaxSum=curMaxSum;
        curMinSum = arr[i]<arr[i]+curMinSum?arr[i]:arr[i]+curMinSum;
        if(curMinSum<minMinSum)
            minMinSum=curMinSum;
    }
    if(maxMaxSum<0)
        return maxMaxSum;
    int circularMaxSum = totalSum-minMinSum;
    return circularMaxSum>maxMaxSum?circularMaxSum:maxMaxSum;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}