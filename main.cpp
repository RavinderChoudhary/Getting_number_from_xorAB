vector<int> singleNumber(vector<int> nums) 
{    
    int sum = 0;
    for(int num : nums)
     sum ^= num; // xor of A and B

    sum &= -sum; // position of last set bit as first difference bit between two number
    // (-sum) 2's complement of sum i.e -sum == ~(sum - 1)

    vector<int> ans = {0, 0};

    for(int num : nums) {
        if((num & sum) == 0)//for unset bit;
        ans[0] ^= num;
        else
        ans[1] ^= num;// this is set bit
    }

    if(ans[0] > ans[1]) swap(ans[0], ans[1]); 
    return ans;
}
