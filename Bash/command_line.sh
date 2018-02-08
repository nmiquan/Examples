#!/bin/bash
if [ -z "$1" ]; then
    echo usage: $0 directory
    exit
fi
SRCD=$1
TGTD="../../Examples"
OF=home-$(date +%Y%m%d).tar.gz
tar -zcf $TGTD$OF $SRCD
