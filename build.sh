mkdir -p build
cd build
ninja
cd ..
mkdir -p lib
cp build/core/core lib/core
cp build/game_libraries/*.so lib/