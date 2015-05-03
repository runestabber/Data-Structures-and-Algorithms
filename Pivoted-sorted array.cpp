#include <iostream>
using namespace std;
#include <vector>
int pivot(vector<int> &nums,int low,int high)
    {
        if(low>high||low<0)
        return -1;
        
        if(low==high)
        return low;
        int mid=(low+high)/2;
        
        if(mid<high&&nums[mid]>nums[mid+1])
        return mid;
        else if(mid>low&&nums[mid-1]>nums[mid])
        {
            return mid-1;
        }
        
        if(nums[mid]>nums[low])
        {
            return pivot(nums,mid+1,high);
        }
        else
        {
            return pivot(nums,low,mid-1);
        }
    }
    
    int binary(vector<int> &nums,int low,int high,int key)
    {
        if(low>high||low<0)
        return -1;
        int mid=(low+high)/2;
        if(nums[mid]==key)
        return mid;
        else if(nums[mid]>key)
        return binary(nums,low,mid-1,key);
        else 
        return binary(nums,mid+1,high,key);
    }
    int search(vector<int>& nums, int target) {
        
        int piv=pivot(nums,0,nums.size()-1);
        int i= binary(nums,0,piv,target);
        int j=binary(nums,piv+1,nums.size()-1,target);
        
        if(i!=-1)
        return i;
        
        return j;
        }
        int main()
        {
          vector<int> nums;
          cout<<"Enter the number of elements"<<endl;
          int num;
          cin>>num;
          cout<<"Enter the sorted-pivoted array"<<endl;
          for(int i=0;i<num;i++)
          {
          cin>>nums[i];
          }
          cout<<"Enter the key to search"<<endl;
          int key;
          cin>>key;
          cout<<search(nums,0,num-1,key);
        }
