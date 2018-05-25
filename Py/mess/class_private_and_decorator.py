class Element():
    def __init__(self, name, symbol, number):
        self.__name = name
        self.__symbol = symbol
        self.__number = number

    @property
    def name(self):
        return self.__name

    @property
    def symbol(self):
        return self.__symbol

    @property
    def number(self):
        return self.__number

element_dictionary = {'name':'Hydrogen', 'symbol':'H', 'number':1}
hydrogen = Element(**element_dictionary)
print('Name:', hydrogen.name)
print('Symbol:', hydrogen.symbol)
print('Number:', hydrogen.number)

print('Private name:', hydrogen.__name)
print('Private symbol:', hydrogen.__symbol)
print('Private number:', hydrogen.__number)
