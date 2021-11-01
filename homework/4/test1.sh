#!/bin/sh

for i in $(seq 1 10)
do
    echo -n '>>> ' >&2
    read n
    echo $n | rev
done