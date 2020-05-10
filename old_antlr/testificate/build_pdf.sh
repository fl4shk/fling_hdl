#!/bin/bash
ODIR="dot"
IFILE="$1"
OFILE_NO_EXT="$ODIR/${IFILE%.*}"
../../fling_hdl_debug --odir="$ODIR" --dot "$IFILE"
rm -fv "$OFILE_NO_EXT.pdf"
dot -Tpdf "$OFILE_NO_EXT.dot" > "$OFILE_NO_EXT.pdf"
