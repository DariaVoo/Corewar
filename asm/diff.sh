#!/bin/sh
mkdir asm_good;
mkdir asm_our;
VAR=$(basename "$1" .s);
cp -f $1 asm_good/"${VAR}.s";
cp -f $1 asm_our/"${VAR}.s"
HEH2="asm_good/${VAR}.s";
HEH="asm_our/${VAR}.s";
echo $VAR;
echo $HEH;
echo $HEH2;
#VAR2="asm_good/$(basename "$HEH" .s)";
./asm $HEH;
./asm_mcos $HEH2;
diff "asm_good/${VAR}.cor" "asm_our/${VAR}.cor";
#echo $VAR2;
#echo $VAR;
#diff -u <$(od -A x -t x1 "${VAR}.cor") <$(od -A x -t x1 "${VAR2}.cor");
#echo "\n"
xxd "asm_good/${VAR}.cor" > asm_good/good_asm_output;
xxd "asm_our/${VAR}.cor" > asm_our/our_asm_output;
diff -u asm_good/good_asm_output asm_our/our_asm_output;
