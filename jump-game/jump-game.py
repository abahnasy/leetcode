class Solution:

        
    def canJump(self, nums: List[int]) -> bool:
        
        for i in range(1, len(nums)):
            flag = False
            print("checking", nums[i])
            for j in range(i-1, -1, -1):
                print(i-j, ">>>",nums[j])
                if i-j<= nums[j]:
                    flag = True
                    break
            if flag == False:
                return False
            
        return True
        