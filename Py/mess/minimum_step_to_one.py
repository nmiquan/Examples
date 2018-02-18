from time import time

# Problem: Minimum Steps to One

# Problem Statement: On a positive integer, you can perform any one of the following 3 steps
#	1) Subtract 1 from it;
# 	2) If it's divisible by 2, divide by 2;
# 	3) If it's divisible by 3, divide by 3.
# Given a positive integer n, find the minimum number of steps that takes n to 1.

# Memoization

def mem_getMinSteps(n, solved_memo):
	if n == 1:
		return 0
	if solved_memo[n] != 0:
		return solved_memo[n]

	r = 1 + mem_getMinSteps(n-1, solved_memo)
	if n % 2 == 0:
		r = min(r, 1+ mem_getMinSteps((n//2), solved_memo))
	if n % 3 == 0:
		r = min(r, 1 + mem_getMinSteps((n//3), solved_memo))
	print(solved_memo)
	solved_memo[n] = r
	return r

print('Memoization Solution')
start = time()
print(mem_getMinSteps(20, [0]*(20+1)))
mem_time = time()-start
print(mem_time)
print()
# Bottom-up DP

def dp_getMinSteps(n):
	dp = [0] * (n+1) # create a list to store solution
	dp[1] = 0 # trivial case
	for i in range(2, n+1): # iterate through 1, 2, 3,..., n
		print(dp)
		# if a number is not divisible by 2 or 3
		# then the number takes 1 more step to go to one compare to the previous number
		# if a number is divisible by 2, then the number of steps to one is the number of time that the number divided by 2 to get to 1
		# if a number is divisible by 3, then the number of steps to one is the number of time that the number divided by 3 to get to 1

		dp[i] = 1+dp[i-1]
		if i % 2 == 0:
			dp[i] = min(dp[i], 1 + dp[i//2])
		if i % 3 == 0:
			dp[i] = min(dp[i], 1 + dp[i//3])

	return dp[n]

print()
print('Dynamic Programming Solution')
start = time()
print(dp_getMinSteps(20))
dp_time = time()-start
print(dp_time)

print()
print(dp_time - mem_time)

