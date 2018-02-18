class Element():
    def __init__(self, name, symbol, number):
        self.name = name
        self.symbol = symbol
        self.number = number

    def dump(self):
        print(f'Name: {self.name} \nSymbol: {self.symbol} \nNumber: {self.number}')

element_dictionary = {'name':'Hydrogen', 'symbol':'H', 'number':1}
hydrogen = Element(**element_dictionary)

print(hydrogen)
hydrogen.dump()
