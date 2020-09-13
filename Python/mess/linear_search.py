def search(x, nums):
    for i in range(len(nums)):
        if nums[i] == x:
            return i
    return -1


