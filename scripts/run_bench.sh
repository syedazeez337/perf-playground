#!/usr/bin/env bash
set -e
COMPONENT=$1
if [ -z "$COMPONENT" ]; then
  echo "Usage: $0 <component-name>"
  exit 1
fi

echo ">>> Running component: $COMPONENT"
pushd components/$COMPONENT > /dev/null
make
./bench/bench_factorial || true
popd > /dev/null
