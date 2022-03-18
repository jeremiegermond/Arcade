mkdir -p build
cd build
ninja
cd ..
mkdir -p bin
cp build/core/core bin/core
cp build/game_libraries/*.so bin/