echo "-> Building project"
cmake ./ -B ./tmp -DCMAKE_TOOLCHAIN_FILE=../cmake/arm_gcc_toolchain.cmake 
cmake --build ./tmp --target all -- -j8
echo "" 
