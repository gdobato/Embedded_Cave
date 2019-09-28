#!/bin/sh

MAKE=/usr/bin/make
STMCUBE_DIR=$PWD/src
usage() { echo "Usage: $0 [-p <Project>] [-o <Option>]" 1>&2; exit 1; }

while getopts ":p:o:" option
  do
    case "${option}" in
      p) 
	 p=${OPTARG}
        ;;
      o)
	 o=${OPTARG}
        ;;
      *)
        ;;
  esac
done

if [ -z "${p}" ]; then
    usage
fi

echo "Entering project directory"
cd ${STMCUBE_DIR}/$p
echo "Buildig $p ..."
$MAKE $o

