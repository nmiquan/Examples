from random import randint,seed
from collections import defaultdict

def display_grid():
    for i in range(len(grid)):
        print('   ', ' '.join(str(grid[i][j]) for j in range(len(grid[0]))))

def get_neighbors(row, column):

    neighbors = []

    if (column < len(grid[row])-1):
        neighbors.append(((row, column+1), grid[row][column+1]))
    if (column > 0):
        neighbors.append(((row, column-1), grid[row][column-1]))
    if (row < len(grid)-1):
        neighbors.append(((row+1,column), grid[row+1][column]))
    if (row > 0):
        neighbors.append(((row-1, column), grid[row-1][column])) 
    
    return neighbors  

def dfs(row, column):
    # dfs appends all the possible nodes to path. 
    for neighbor in get_neighbors(row, column):
        if neighbor not in paths: # base case
            paths.append(neighbor) # operation to base case
            dfs(neighbor[0][0], neighbor[0][1]) # recursion on each neighbor

seed(0)
max_length = 4
width = 6
height = 6

grid = [[randint(0, max_length) for _ in range(width)] for _ in range(height)]
display_grid()

paths = []

dfs(0,1)
for path in paths:
    print(path)

