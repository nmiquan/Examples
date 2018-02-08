n = 20

for i in range(0, n):
	LS[i]=1
	for j in range(0, n):
		if a[i] > a[j] and LS[i] < LS[j]:
			LS[i] = LS[j]+1


