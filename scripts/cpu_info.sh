#!/usr/bin/env bash
echo "==== CPU INFO ===="
lscpu | grep -E 'Model name|Architecture|CPU\(s\)|Thread|Core'
echo
echo "==== MEM INFO ===="
free -h
echo
echo "==== OS ===="
uname -a
echo
echo "==== COMPILERS ===="
gcc --version | head -n 1
clang --version | head -n 1
echo
if command -v nvidia-smi &>/dev/null; then
  echo "==== NVIDIA GPU ===="
  nvidia-smi --query-gpu=name,driver_version,memory.total --format=csv
fi
