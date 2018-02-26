# Written by Eric Martin for COMP9021


'''
Prompts the user for an amount, and outputs the minimal number of banknotes needed
to match that amount, as well as the detail of how many banknotes of each type value are used.

The available banknotes have a face value which is one of $1, $2, $5, $10, $20, $50, and $100.
'''


face_values = [1, 2, 5, 10, 20, 50, 100]
amount = int(input('Input the desired amount: '))

# while amount needed to make change is not 0. Use the highest denominated bill available. Perform calculation. The number of bank note, given the denomination, used is calculated by (integer) dividing the amount needed to make change to the denomination used. The remaining amount needed to make change is calculated by calculating the beginning amount needed to make change modulo the denomination used. 

banknotes = []
amount_left = amount
while amount_left:
    # using the highest denominated bank note first
    value = face_values.pop()
    if amount_left >= value:
        banknotes.append((value, amount_left // value))
        # amount_left // value = the number of given bank note used
        amount_left %= value
        # amount_left % value = the remaining value needed to make change

nb_of_banknotes = sum(banknote[1] for banknote in banknotes)
if nb_of_banknotes == 1:
    print('\n1 banknote is needed.')
else:
    print(f'\n{nb_of_banknotes} banknotes are needed.')
print('The detail is:')
for banknote in banknotes:
    print(f'{"$" + str(banknote[0]):>4}: {banknote[1]}')
