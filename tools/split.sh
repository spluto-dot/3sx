#!/bin/bash

# Run splat
python3 -m splat split splat/sfiii.yaml

# Patch linker script with entrypoint
LINKER_SCRIPT=splat/SLPM_656.21.ld
{ echo "ENTRY(__start)"; cat $LINKER_SCRIPT; } > tmp
mv tmp $LINKER_SCRIPT
