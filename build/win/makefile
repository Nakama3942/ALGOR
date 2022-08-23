g++ -Wall -c -fPIC ../../src/ALGOR_CORE.cpp
g++ -Wall -c -fPIC ../../src/ALGOR_EXCEPTION.cpp
g++ -Wall -c -fPIC ../../src/ALGOR_RANDOM.cpp
g++ -Wall -c -fPIC ../../src/ALGOR_ARRAY.cpp
g++ -Wall -c -fPIC ../../src/ALGOR_SORTING.cpp
g++ -Wall -c -fPIC ../../src/ALGOR_MATRIX.cpp
g++ -Wall -c -fPIC ../../src/ALGOR_HEAP.cpp
g++ -Wall -c -fPIC ../../src/ALGOR_LIST.cpp
g++ *.o -no-pie -s -shared -o ALGOR1.dll
echo creating ALGOR1.dll ...
ar -r libALGOR1.a *.o
rm -rf *.o
cp ../../include/ALGOR.hpp ./
echo copying ALGOR.hpp ...
echo Library compiled!