#!/bin/bash

scriptDir=$(dirname $0)
prefixDir=$HOME/.local/coreutils
mkdir -p $prefixDir

$scriptDir/../../configure --prefix=$prefixDir --with-linux-crypto=no --with-openssl=no
