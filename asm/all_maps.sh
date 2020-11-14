#!/bin/bash
rm -f testik;
touch testik;
f="find name \*.s"
for file in $f
do
	sh diff.sh ${file} >> testik
done
