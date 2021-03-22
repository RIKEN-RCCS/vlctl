#!/bin/bash -x
#PJM --rsc-list "node=1"
#PJM --rsc-list "rscunit=rscunit_ft01"
#PJM --rsc-list "rscgrp=eap-small"
#PJM --rsc-list "elapse=1:00"
#PJM -S

./show_vl

./vlctl 128 ./show_vl

./show_vl

./vlctl 256 ./show_vl

./show_vl
