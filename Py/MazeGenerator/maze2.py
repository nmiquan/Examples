# Source : https://en.wikipedia.org/wiki/Maze_genration_algorithm
# This algorithm works by creating n (density) islands of length p (complexity).
# An island is created by choosing a random starting point with odd coordinates, then a random directions is chosen. 
# If the cell two steps in the direction is free, then a wall is added at both one step and two steps in this direction. The process is iterated for n steps for this island. 
# p islands are created, n and p are expressed as float to adapt them to the size of the maze. With a low complexity, islands are very small and maze is easy to solve. With low density, the maze has more "big empty rooms".

import numpy
from numpy.random import random_integers as rand
import matplotlib.pyplot as pyplot

def maze(width=81, height=51, complexity=.75, density=.75):
    # Only odd shapes
    shape = ((height // 2) * 2 + 1, (width // 2) * 2 + 1)
    # Adjust complexity and density relative to maze size
    # Why are complexity and density adjusted this way?
    complexity = int(complexity * (5 * (shape[0] + shape[1])))
    density    = int(density * ((shape[0] // 2) * (shape[1] // 2)))
    # Build actual maze
    Z = numpy.zeros(shape, dtype=bool)
    # Fill borders
    Z[0, :] = Z[-1, :] = 1
    Z[:, 0] = Z[:, -1] = 1
    # Make aisles
    # Why is this program looping through complexity and density?
    # Why does the number of paths made by this program equals to density?
    for i in range(density):
        x, y = rand(0, shape[1] // 2) * 2, rand(0, shape[0] // 2) * 2
        Z[y, x] = 1 # Why marking (y, x) as visited?
        # This program will loop through complexity even when all of (x, y) neighbors are visited
        for j in range(complexity):
            neighbours = []
            if x > 1:            neighbours.append((y, x - 2))
            if x < shape[1] - 2: neighbours.append((y, x + 2))
            if y > 1:            neighbours.append((y - 2, x))
            if y < shape[0] - 2: neighbours.append((y + 2, x))
            if len(neighbours):
                y_, x_ = neighbours[rand(0, len(neighbours) - 1)]
                if Z[y_, x_] == 0:
                    Z[y_, x_] = 1 # marking two-step neighbor as visited
                    Z[y_ + (y - y_) // 2, x_ + (x - x_) // 2] = 1 # marking one-step neighbor as visited
                    x, y = x_, y_ # move to the two-step neighbor
    return Z

pyplot.figure(figsize=(10, 5))
pyplot.imshow(maze(80, 40), cmap=pyplot.cm.binary, interpolation='nearest')
pyplot.xticks([]), pyplot.yticks([])
pyplot.show()
