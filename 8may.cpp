//leetcode 341
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
        queue<int> q;
    NestedIterator(vector<NestedInteger> &nestedList) {
        flat(nestedList);
    }
    void flat(vector<NestedInteger> &nestedList){
            for(NestedInteger v:nestedList){
                    if(v.isInteger()){
                            q.push(v.getInteger());
                    }
                    else{
                            flat(v.getList());
                    }
            }
    }
    int next() {
        int val=q.front();
            q.pop();
            return val;
    }
    
    bool hasNext() {
        if(q.size()>0){
                return true;
        }
            return false;
    }
};
//leetcode 33 search in rotated sorted array
int search(vector<int>& nums, int target) {
      int l=0;
            int h=nums.size()-1;
            while(l<=h){
                    int m=l+(h-l)/2;
                    if(nums[m]==target){
                            return m;
                    }
                    else if(nums[l]<=nums[m]){
                            if(target>=nums[l] && target<=nums[m]){
                                    h=m-1;
                            }
                            else{
                                    l=m+1;
                            }
                    }
                    else{
                           if(target>=nums[m] && target<=nums[h]){
                                   l=m+1;
                           } 
                            else{
                                    h=m-1;
                            }
                    }
            }
            return -1;
    }
    //missing and repeating
     int *findTwoElement(int *arr, int n) {
        // code here
      int m[100000+7]={0};
     static  int v[2];
       int num1,num2;
       for(int i=0;i<n;i++){
           m[arr[i]]++;
       }
       for(int i=1;i<=n;i++){
           if(m[i]==0){
               num1=i;
               break;
           }
       }
       for(int i=1;i<=n;i++){
           if(m[i]==2){
               num2=i;
               break;
           }
       }
       v[0]=num2;
       v[1]=num1;
         return v;
    }
    //majority element
     int majorityElement(int a[], int size)
    {
        if(size==1) return a[0];
        int count=1;
       sort(a,a+size);
       for(int i=0;i<size-1;i++){
           if(a[i]==a[i+1]){
               count++;
           }
           else{
               count=1;
               continue;
           }
           if(count>size/2)
           return a[i];
       }
        return -1;
    }
//leetcode 2265

        int sum(TreeNode* root) {
        if(!root) return 0;
        return sum(root->left) + sum(root->right) + root->val;
    }
        int k=0;
    int count(TreeNode* root) {
        if(!root) return 0;
        return count(root->left) + count(root->right) + 1;
    }
    int c = 0;
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int s = sum(root->left) + sum(root->right) + root->val;
        int n = count(root->left) + count(root->right) + 1;
        int ans = s/n;
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        if(ans == root->val)
        {
            c++;
        }
        return c;
    }
