# Source: rosettacode.org/wiki/Maze_generation#Python
# Task:
#    1. Start at a random cell.
#    2. Mark the current cell as visited, and get a list of its neighbors.
#       For each neighbor, starting with a randomly selected neighbor:
#       If that neighbor hasn't been visited, remove the wall betwen this cell
#       and that neighbor, 
#       and then recurse with that neighbor as the current cell.

from random import shuffle, randrange

def make_maze(w = 16, h = 8):
    # vis = visited
    vis = [[0] * w + [1] for _ in range(h)] + [[1] * (w + 1)]
    ver = [["|  "] * w + ['|'] for _ in range(h)] + [[]]
    hor = [["+--"] * w + ['+'] for _ in range(h+1)]
     
    s = ""
    for (a, b) in zip(hor, ver):
        s += ''.join(a + ['\n'] + b + ['\n'])
    print(s)

    # dfs
    def walk(x, y):
        vis[y][x] = 1 # mark visited

        d = [(x - 1, y), (x, y + 1), (x + 1, y), (x, y - 1)]
        # d is a list of neighbors
        shuffle(d) # randomize list of neighbors
        for (xx, yy) in d: # for each neighbor
            if vis[yy][xx]: continue # if visited do nothing
            # removing wall
            if xx == x: hor[max(y, yy)][x] = "+  " # if same row go south/north 
            if yy == y: ver[y][max(x, xx)] = "   " # if same column east/west
            walk(xx, yy) # recursive call on neighbors of this neighbor

    walk(randrange(w), randrange(h)) # begin at a random point

    s = ""
    for (a, b) in zip(hor, ver):
        s += ''.join(a + ['\n'] + b + ['\n'])
    return s
    

if __name__ == '__main__':
    print(make_maze())
