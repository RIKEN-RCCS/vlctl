#!/bin/bash -x
#PJM --rsc-list "node=1"
#PJM --rsc-list "rscunit=rscunit_ft02"
#PJM --rsc-list "rscgrp=dv1-10"
#PJM --rsc-list "elapse=1:00"
#PJM -S

module load lang

VL=128
#VL=256

./show_vl

./vlctl $VL ./show_vl

./show_vl
