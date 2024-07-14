#!/bin/bash

scriptDir=$(dirname $0)
prefixDir=$HOME/.local/coreutils
mkdir -p $prefixDir

configureExec=$scriptDir/../../configure
$configureExec --prefix=$prefixDir --with-linux-crypto=no --with-openssl=no

makefileDir=$(dirname $configureExec)
cd $makefileDir && make lib/byteswap.h
