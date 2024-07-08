#!/bin/bash

scriptDir=$(dirname $0)

for f in $scriptDir/*.wasm; do
	echo deleting: $f
	rm $f
done

