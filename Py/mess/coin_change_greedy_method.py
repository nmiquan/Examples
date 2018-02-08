from time import time

'''
def recMC(coinValueList, change):
	minCoins = change
	if change in coinValueList:
		return 1
	else:
		# for each denomination in coin if denomination <= change do
		for i in [c for c in coinValueList if c <= change]:
			# given the denomination, find the number of coins needed
			# to make the change
			numCoins = 1 + recMC(coinValueList, change - i)
			print(f'denomination: {i}, number of coins: {numCoins}')
			# if numCoins < minCoins, then assign numCoins to minCoins
			if numCoins < minCoins:
				print(f'Inside if statement:{minCoins}, {numCoins}')
				minCoins = numCoins
			print(f'Outside if statement:{minCoins}, {numCoins}')
	return minCoins

start = time()
print(recMC([1,5,10,25],50))
print(time() - start)

'''
# Using memoization

def recDC(coinValueList,change,knownResults):
	minCoins = change
	if change in coinValueList:
		knownResults[change] = 1
		return 1
	elif knownResults[change] > 0:
		return knownResults[change]
	else:
		for i in [c for c in coinValueList if c <= change]:
			numCoins = 1 + recDC(coinValueList, change-i, knownResults)
			if numCoins < minCoins:
				minCoins = numCoins
				knownResults[change] = minCoins
				print(knownResults)
	return minCoins

start = time()
print()
print(recDC([1,5,10,25],26,[0]*27))
print(time()-start)

