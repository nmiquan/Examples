def selSort(nums):
    n = len(nums)

    for bottom in range(n-1):
        mp = bottom
        for i in range(bottom+1, n):
            if nums[i] < nums[mp]:
                mp = 1

        nums[bottom], nums[mp] = nums[mp], nums[bottom]


