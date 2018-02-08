from adt_stack import *

T = {1: [2, 4, 5], 2: [3], 5: [6, 11, 13], 6: [7, 8, 10], 8: [9], 11: [12]}

def depth_first_exploration():
    stack = Stack()
    stack.push([1]) # push root into Stack
    while not stack.is_empty():
        path = stack.pop()
        print(path)
        if path[-1] in T:
            # T is a dictionary of possible path
            # that is if a node has children
            # then the node will be key in the dictionary
            for child in reversed(T[path[-1]]):
                # adding node to path
                stack.push(list(path) + [child])
                
depth_first_exploration()
