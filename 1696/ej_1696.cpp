using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<deque>
#include<queue>

struct CustomCompare
/* Define a way of comparing tuples of int */
{
    bool operator()(const tuple<int,int>& lhs, const tuple<int,int>& rhs)
    {
        return get<0>(lhs) < get<0>(rhs);
    }
};

int maxResult(vector<int>& nums, int k){
    int n = nums.size();
    /* Use the above comparison to define a maxHeap of tuples */
    priority_queue<tuple<int,int>, vector<tuple<int, int>>, CustomCompare> max_dipis;
    for(int i = 0;i<n;i++){
        if(i==0){
            /* Initialize the maxHeap with the tuple <firstElement, 0> */
            max_dipis.push(make_pair(nums[0],0));
        }else{
            /* Get rid of max tuples that are out of bounds */ 
            while(i - get<1>(max_dipis.top())>k){
                max_dipis.pop();
            }
            /* If I am at the end of the list, return the last element plus maxHeap top */
            if(i==n-1){
                    return get<0>(max_dipis.top())+nums[i];
            }      
            /* Update the maxHeap with the top of the heap plus the ith element of the list */     
            int x = get<0>(max_dipis.top());
            max_dipis.push(make_tuple(nums[i]+x,i));
        }
    }
    return get<0>(max_dipis.top());
}
int main(){
	vector<int> prueba = {100,-1,-100,-1,100};
    int res = maxResult(prueba, 2);
	cout<<res<<endl;
return 0;}
