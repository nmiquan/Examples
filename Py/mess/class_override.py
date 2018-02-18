class Bear():
    def eats(self):
        return 'berries'

class Rabbit():
    def eats(self):
        return 'clover'

class Octothorpe():
    def eats(self):
        return 'campers'

some_bear = Bear()
print('Bear:', some_bear.eats())

some_rabbit = Rabbit()
print('Rabbit:', some_rabbit.eats())

some_octothorpe = Octothorpe()
print('Octothorpe:', some_octothorpe.eats())
