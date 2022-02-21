#!/usr/bin/env bash

read -p "Nb files: " nb_files
x=0
while [ $x -lt $nb_files ]
do
    read -p 'Filename: ' file_name
    echo 'SRC += '$file_name >> './datas_makefile/srcs.mk'
    ((x++))
done
echo ""
