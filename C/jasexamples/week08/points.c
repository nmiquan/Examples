// Simple struct example
// Written by jas@cse

#include <stdlib.h>
#include <stdio.h>

#define MAX_POINTS 5
#define MAX_XCOORD 30
#define MAX_YCOORD 10

// Points on a plane (name,x,y)
struct _point {
    char name; // identifying letter
    int  x;    // x coord (1..30)
    int  y;    // y coord (1..10)
};

// Type naming conventions
// typedef struct _point  Point;
typedef struct _point  point_t;

void putPoint(point_t p);
int  getPoint(point_t *p);
void plotPoints(point_t ps[], int np);

int main(int argc, char *argv[])
{
    point_t p;       // a single (x,y) coord
    point_t *pp;     // a pointer to a point_t
    point_t points[MAX_POINTS];  // array of Points
    int   nPoints; // how many Points in array

    p.name = 'A';
    p.x = 5;
    p.y = 3;
    printf("\np = "); putPoint(p);

    pp = &p;
    pp->name = 'B';
    pp->x = 1;
    pp->y = 1;
    printf("\n*pp = "); putPoint(*pp);
    printf("p = "); putPoint(p);
    
    //return EXIT_SUCCESS;

    printf("Using format (A,5,2), ");
    printf("enter some points:\n");
    nPoints = 0;
    while (getPoint(&p)) {
        if (nPoints == MAX_POINTS) break;
        points[nPoints] = p;   // struct copy
        nPoints++;
    }
    plotPoints(points, nPoints);

    return EXIT_SUCCESS;
}

void putPoint(point_t p)
{
    printf("(%c,%d,%d)\n", p.name, p.x, p.y);
}

// attempt to read a point_t value
// should be in the format (A,1,2)
// returns 1 if successful, otherwise return 0
int getPoint(point_t *p)
{
    int nread;
    char line[1000]; // large line buffer

    if (fgets(line, 999, stdin) == NULL) {
        return 0;
    }
    nread = sscanf(line, "(%c,%d,%d)",
                   &p->name, &p->x, &p->y);
    if (nread != 3
        || p->x < 1 || p->x > MAX_XCOORD
        || p->y < 1 || p->y > MAX_YCOORD) {
        printf("Invalid point value\n");
        return 0;
    }
    return 1;
}

void plotPoints(point_t ps[], int np)
{

    char grid[MAX_YCOORD][MAX_XCOORD];
    int  x, y;
    for (y = 0; y < MAX_YCOORD; y++) {
        for (x = 0; x < MAX_XCOORD; x++) {
            grid[y][x] = '.';
        }
    }
    for (int i = 0; i < np; i++) {
        char name = ps[i].name;
        x = ps[i].x - 1;
        y = ps[i].y - 1;
        grid[y][x] = name;
    }
    for (y = 0; y < MAX_YCOORD; y++) {
        for (x = 0; x < MAX_XCOORD; x++) {
            putchar(grid[y][x]);
        }
        putchar('\n');
    }

/*
	for (int i = 0; i < np; i++)
        putPoint(ps[i]);
*/
}
