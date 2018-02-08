def createGenerator():
    mylist = range(3)
    for i in mylist:
        yield i*i # in contrast to return yield return a generator that can be iterated over to obtain the items in mylist declared in this function

mygenerator = createGenerator() # create a generator
print(mygenerator) # mygenerator is an object!
for i in mygenerator:
    print(i)

def createIterator():
    mylist = range(3)
    for i in mylist:
        return i*i # in contrast to yield, return statment returns the first item in the iteration

myiterator = createIterator()
print()
print(myiterator)
