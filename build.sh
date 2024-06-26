cmake -S . -G "Unix Makefiles" -B cmake
ln -s cmake/compile_commands.json .
cd cmake
make

