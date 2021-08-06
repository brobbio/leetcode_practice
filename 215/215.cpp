using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

int partition(vector<int>& nums, int p){
    int n = nums.size();
    int pivote = nums[p];
    int ultimo = nums[n-1];
    nums[n-1] = pivote;
    nums[p] = ultimo;
    int l = -1;
    for(int i = 0; i<n-1;i++){
        if(nums[i]<nums[n-1]){
            l = l+1;
            int lesimo = nums[l];
            int iesimo = nums[i];
            nums[i] = lesimo;
            nums[l] = iesimo;
        }
    }
    ultimo = nums[n-1];
    int lesimo = nums[l+1];
    nums[n-1] = lesimo;
    nums[l+1] = ultimo;
    return l+1;
}

int quickSelect(vector<int>& nums, int k) {
    int p = nums.size()/2;
    if(nums.size() == 1){
        return nums[0];
    }else{
        int r = partition(nums, p);
        vector<int> primera_mitad;
        vector<int> segunda_mitad;
        primera_mitad = std::vector<int>(nums.begin(), nums.begin()+r);
        segunda_mitad = std::vector<int>(nums.begin()+r+1, nums.end());
        if(k<r){
            return quickSelect(primera_mitad, k);
        }else{
            if(k>r){
                return quickSelect(segunda_mitad, k-r-1);
            }else{
                return nums[r];
            }
        }
        }
    }


int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return quickSelect(nums, n-k);
}

    int main(){
	vector<int> prueba = {-1,0,2};
    int res = findKthLargest(prueba, 3);
/*     int res = partition(prueba, 4); */
/*     for(int e : prueba){
        cout<<e;
    } */
    cout<<res;
return 0;}