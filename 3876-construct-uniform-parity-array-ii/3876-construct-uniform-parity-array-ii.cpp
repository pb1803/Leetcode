class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallest=INT_MAX;
        int cnt_odd = 0;
        int cnt_even = 0;
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]<smallest) smallest = nums1[i];
            if(nums1[i]%2==0) cnt_even++;
            else cnt_odd++;
        }
        if(cnt_odd == 0 || cnt_even == 0 ) return true;
        sort(nums1.begin(),nums1.end());
        if(smallest%2==0)
        {
            for(int i=0;i<nums1[i];i++)
            {
                if(nums1[i]%2==1)
                {   int flag=0;
                    for(int j=0;j<i;j++)
                    {
                        if(nums1[j]%2==1 && nums1[j]<nums1[i])
                        {
                            flag=1;
                            break;
                            
                        }
                    }
                    if(flag==0) return false;
                    else return true;

                }

               
            }

        }
                     else 
                {
                    return true;
                }
        return false;
    }
};