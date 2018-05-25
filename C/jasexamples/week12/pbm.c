// pbm ... implementation of ADT for PBM-format images

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "pbm.h"

struct pbm {
    int  height;
    int  width;
    int  **pixels;
};

pbm_t pbm_create(int height, int width)
{
    int **pix; int i;
    
    pix = malloc(height * sizeof(int *));
    assert(pix != NULL);
    for (i = 0; i < height; i++) {
#if 0
         pix[i] = malloc(width * sizeof(int));
         assert(pix[i] != NULL);
         for (int j = 0; j < width; j++) 
             pix[i][j] = 0;
#else
         pix[i] = calloc(width, sizeof(int));
         assert(pix[i] != NULL);
#endif
    }
    pbm_t new;
    new = malloc(sizeof(struct pbm));
    new->height = height;
    new->width = width;
    new->pixels = pix;
    return new;   
}

// read image

pbm_t pbm_read(FILE *in)
{
    char first_line[100];
    
    assert(fgets(first_line, 100, in) != NULL);
    sscanf(first_line, "%d %d", &height, &width);
    
    pbm_t image = pbm_create(height,width);
    
    int row = 0; int col = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            row++; col = 0;
        }
#if 0
        else if (ch == '0') {
            assert(row < height && col < width);
            image->pixels[row][col] = 0;
            col++;
        } else if (ch == '1') {
            assert(row < height && col < width);
            image->pixels[row][col] = 1;
            col++;
        }
#else
        else if (ch == '0' || ch == '1') {
            assert(row < height && col < width);
#if 0
            image->pixels[row][col] = (ch == '0')?0:1;
#else
            image->pixels[row][col] = (ch - '0');
#endif
            col++;
        }
#endif
        else {
            assert(ch == '0' || ch == '1');
        }
    }
    return image;
}

// simplest, most concise version

pbm_t pbm_read(FILE *in)
{
    char first_line[100];
    
    assert(fgets(first_line, 100, in) != NULL);
    sscanf(first_line, "%d %d", &height, &width);
    
    pbm_t image = pbm_create(height,width);
    
    int row = 0; int col = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            row++; col = 0;
        }
        else if (ch == '0' || ch == '1') {
            assert(row < height && col < width);
            image->pixels[row][col] = (ch - '0');
            col++;
        }
        else {
            assert(ch == '0' || ch == '1');
        }
    }
    return image;
}


// copy (part of) image

pbm_t pbm_copy(pbm_t image, int tlx, int tly, 
               int brx, int bry)
{
    int nheight, nwidth;
    pbm_t new;
    assert(tlx < brx && tly < bry);
    nheight = bry-tly+1; nwidth = brx-tlx+1;
    new = pbm_create(nheight,nwidth);
    int row, col;
    for (row = tly; row <= bry; row++) {
        for (col = tlx; col <= brx; col++) {
            int r = row-tly;
            int c = col-tlx;
            new->pixels[r][c] = 
                 image->pixels[row][col];
        }
    }
    return new;
}
               
pbm_t pbm_copy_all(pbm_t image)
{
    return pbm_copy(image, 0, 0, 
                    image->height-1, image->width-1);
}
