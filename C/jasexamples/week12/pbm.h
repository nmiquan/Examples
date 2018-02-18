// pbm.h ... interface of ADT for PBM-format images

#ifndef PBM_H
#define PBM_H

#include <stdio.h>

typedef struct pbm  *pbm_t;

// create (empty) image

pbm_t pbm_create(int height, int width);

// read image

pbm_t pbm_read(FILE *in);

// copy (part of) image

pbm_t pbm_copy(pbm_t image, int tlx, int tly, 
               int brx, int bry);
               
pbm_t pbm_copy_all(pbm_t image);

#endif


