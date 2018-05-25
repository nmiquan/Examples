from time import time
#CORE

'''

def dpMakeChange(coinValueList, change):

	# iteration from 1 cent to the given cent
	# assuming coinCount consists of all 1 cent
	# for a given denomination, let's call j
	# substract j from coinCount to find out the minimum number of coins needed to make change for [coinCount-j], let's this minimum number of coins needed to make change be minCoins[cents-j]
	# check if an additional coin minCoins[cents-j] added to the previous change make exceeded the assumed coinCount amount

	minCoins=[0]*(change+1)

	for cents in range(change+1):
		coinCount = cents

		for j in [c for c in coinValueList if c <= cents]:
			if minCoins[cents-j] + 1 < coinCount:
				coinCount = minCoins[cents-j]+1
		minCoins[cents] = coinCount
		print(minCoins)
	return minCoins[change]

start = time()
print(dpMakeChange([1,5,10,25], 26))
print(time()-start)


'''

def dpMakeChange(coinValueList,change,minCoins,coinsUsed):
	for cents in range(change+1):
		coinCount = cents
		newCoin = 1
		for j in [c for c in coinValueList if c <= cents]:
			if minCoins[cents-j] + 1 < coinCount:
				coinCount = minCoins[cents-j] + 1
				newCoin = j
		minCoins[cents] = coinCount
		coinsUsed[cents] = newCoin
	return minCoins[change]

def printCoins(coinsUsed, change):
	coin = change
	while coin > 0:
		thisCoin = coinsUsed[coin]
		print(thisCoin)
		coin = coin - thisCoin
	
def main():
	amnt = 26
	clist = [1,5,10,25]
	coinsUsed = [0]*(amnt+1)
	coinCount = [0]*(amnt+1)
	
	print("Making change for", amnt, "requires")
	print(dpMakeChange(clist,amnt, coinCount,coinsUsed),"coins")
	print(coinCount)
	print(coinsUsed)
	print("They are:")
	printCoins(coinsUsed,amnt)
	print("The used list is as follows:")
	print(coinsUsed)

main()

