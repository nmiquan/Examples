class Thing3():
    def __init__(self):
        self.letters = 'xyz'

example3 = Thing3()
print('* If Thing3.letters is invoked, type object "Thing3" has no attribute "letters" is raised')
print('* example3:', example3.letters)
print('In this example, letters is an attribute of instances instead of class. Thus, an instance needs to be created in order to get the attribute')

