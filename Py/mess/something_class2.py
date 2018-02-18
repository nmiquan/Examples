class Element():
    def __init__(self, name, symbol, number):
        self.name = name
        self.symbol = symbol
        self.number = number

    def dump(self):
        print(self.name, self.symbol, self.number)

element1 = Element('Hydrogen', 'H', 1)
element_dictionary = {'name':'Hydrogen',\
                      'symbol':'H',\
                      'number':1}

hydrogen = Element(element_dictionary['name'], element_dictionary['symbol'], element_dictionary['number'])

hydrogen.dump()
print(hydrogen)
