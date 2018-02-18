class Element():
    def __init__(self, name, symbol, number):
        self.name = name
        self.symbol = symbol
        self.number = number

element_dictionary = {'name':'Hydrogen',\
                      'symbol':'H',\
                      'number':1}

#hydrogen = Element(element_dictionary['name'], element_dictionary['symbol'], element_dictionary['number'])

hydrogen = Element(**element_dictionary)
print(hydrogen)
print('Name:', hydrogen.name)
print('Symbole:', hydrogen.symbol)
print('Number:', hydrogen.number)
