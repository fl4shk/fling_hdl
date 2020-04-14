#!/bin/bash
ODIR=dot
../../fling_hdl_debug --odir="$ODIR" --dot "$1"
rm -fv "$ODIR/$1.pdf"
dot -Tpdf "$ODIR/$1.dot" > "$ODIR/$1.pdf"
