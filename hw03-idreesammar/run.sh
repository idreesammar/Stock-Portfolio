#!/bin/bash
# Cmake into build directory

wget "https://drive.google.com/uc?export=download&id=1BfN4S7lnbHPtdhD8xySwai2JW8sWTgrW" -O hw03.tar.gz
tar xzf hw03.tar.gz

echo "Compiling..."
mkdir build
cd build
RELEASE=ON CC=clang CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. || exit 1
build_failed=0
make 2> >(tee diagnostics.txt >&2)|| { echo "::error::Code did not compile!"; build_failed=1; }
cd ..
./diagnostics-json.py
if [[ "$build_failed" == 1 ]] ; then
	exit 1
fi

# Run student tests
echo "Running student tests..."
timeout 10 build/tests/tests [student]

# Run graded tests
echo "Running graded tests..."
timeout 10 build/tests/tests [graded] -r=github || { echo "::error::Not all graded tests passed!"; exit 1; }
