#!/bin/bash

scriptDir=$(dirname $0)

$scriptDir/../../configure --with-linux-crypto=no --with-openssl=no
