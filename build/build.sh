#!/bin/bash

scriptDir=$(dirname $0)

cFiles=( md5.c sha1.c sha256.c sha512.c sm3.c io_adapter.c )
for f in "${cFiles[@]}"; do
  targetName="$(basename $f .c).rel.o"
  echo Building $(realpath $targetName)
  emcc \
    "-I$scriptDir/../../lib" \
    "-I$scriptDir/../lib" \
    "$scriptDir/../lib/$f" \
    -sASYNCIFY \
    -O3 -c -o \
    "$scriptDir/$targetName"
done

watFiles=( get_more_pages.wat get_stack_top.wat memcpy.wat )
for f in "${watFiles[@]}"; do
  targetName="$(basename $f .wat).rel.o"
  echo Building $(realpath $targetName)
  wat2wasm "$scriptDir/../lib/$f" -r -o "$scriptDir/$targetName"
done

targetName=out.wasm
echo "Linking $(realpath $targetName) ..."
wasm-ld \
  --no-entry \
  --export=initiate_buffer_hashing \
  --export=get_first_usable_address \
  --export=getmorepages \
  --import-undefined \
  --import-memory=importobjs,shm0 \
  "$scriptDir/memcpy.rel.o" \
  "$scriptDir/get_stack_top.rel.o" \
  "$scriptDir/get_more_pages.rel.o" \
  "$scriptDir/io_adapter.rel.o" \
  "$scriptDir/md5.rel.o" \
  "$scriptDir/sha1.rel.o" \
  "$scriptDir/sha256.rel.o" \
  "$scriptDir/sha512.rel.o" \
  "$scriptDir/sm3.rel.o" \
  -o "$scriptDir/$targetName"

# emcc --no-entry --use-ports=sdl2 -sLINKABLE=1 -sINVOKE_RUN=0 -O0 $scriptDir/out.o -o $scriptDir/out.wasm

# emcc \
#   --no-entry \
#   --use-port=sdl2 \
#   -sIMPORTED_MEMORY=1 \
#   "$scriptDir/memcpy.rel.o" \
#   "$scriptDir/get_stack_top.rel.o" \
#   "$scriptDir/get_more_pages.rel.o" \
#   "$scriptDir/io_adapter.rel.o" \
#   "$scriptDir/md5.rel.o" \
#   "$scriptDir/sha1.rel.o" \
#   "$scriptDir/sha256.rel.o" \
#   "$scriptDir/sha512.rel.o" \
#   "$scriptDir/sm3.rel.o" \
#   -o "$scriptDir/$targetName"
