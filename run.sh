#!/bin/sh

exec=`ls *.exe`

export OMP_NUM_THREADS=8
for i in ${exec}
do
    echo $i >> output.txt
    ./${i} >> output.txt
    echo -e "\n\n" >> output.txt
done
