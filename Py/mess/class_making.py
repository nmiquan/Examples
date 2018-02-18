class Element():
    def __init__(self, name, symbol, number):
        self.name = name
        self.symbol = symbol
        self.number = number

hydrogen = Element('Hydrogen', 'H', 1)

print(hydrogen)
print('Name:', hydrogen.name)
print('Symbol:', hydrogen.symbol)
print('Number:', hydrogen.number)
