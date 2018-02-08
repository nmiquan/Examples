#!/bin/bash
OF=my-back-up$(date +%Y%m%d).tgz
tar -cZf $OF /home/Desktop/Files/Examples/ 
