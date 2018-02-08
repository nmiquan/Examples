# Class Composition

# A class composition doesn't have inheritance

# How it works: create instances of subclasses, then assign these instances to a superclass

# For example, a robot has laser, claw, and smartphone. Classes of laser, claw and smartphone are created. Instances of these classes are created and assigned as attribute in class Robot().

# Another example, a duck has bill and tail. Classes Bill() and Tail() are created. Theses instances are assigned to attributes in Duck() class. Then, each instances of Bill() and Tail() is assigned to an instance of Duck().

class Laser():
    def does(self):
        return 'disintegrate'

class Claw():
    def does(self):
        return 'crush'

class SmartPhone():
    def does(self):
        return 'ring'

class Robot():
    def __init__(self, laser, claw, smartphone):
        self.laser = laser
        self.claw = claw
        self.smartphone = smartphone

    def does(self):
        print('Laser does', laser.does(), '\nClaw does', claw.does(), '\nSmartphone does', smartphone.does())

laser = Laser()
claw = Claw()
smartphone = SmartPhone()

robot = Robot(laser, claw, smartphone)
robot.does()
