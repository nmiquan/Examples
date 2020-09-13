# Create a class and an instance
class Element():
    def __init__(self, name, symbol, number, private_name):
        self.hidden_name = name
        self.hidden_symbol = symbol
        self.hidden_number = number
        self.__real_hidden_name = private_name

    def get_name(self):
        return self.hidden_name

    def get_symbol(self):
        return self.hidden_symbol

    def get_number(self):
        return self.hidden_number

    def get_real_hidden_name(self):
        return self.__real_hidden_name

hydrogen = Element('Hydrogen', 'H1', 1, 'Fart')
print('get_name:', hydrogen.get_name())
print('get_symbol:', hydrogen.get_symbol())
print('get_number:', hydrogen.get_number())
print('getreal_hidden_name:', hydrogen.get_real_hidden_name())
print()
print('hidden_name:', hydrogen.hidden_name)
print('hidden_symbol:', hydrogen.hidden_symbol)
print('hidden_number:', hydrogen.hidden_number)
print('hydrogen._Element__real_hidden_name:', hydrogen._Element__real_hidden_name)
print('real_hidden_name:', hydrogen.__real_hidden_name)

