# ########################################################################## #
# -------------------------------------------------------------------------- #
#                                                                            #
# Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.            #
# Licensed under the Apache License, Version 2.0                             #
#                                                                            #
# Licensed under the Apache License, Version 2.0 (the "License");            #
# you may not use this file except in compliance with the License.           #
# You may obtain a copy of the License at                                    #
#                                                                            #
#     http://www.apache.org/licenses/LICENSE-2.0                             #
#                                                                            #
# Unless required by applicable law or agreed to in writing, software        #
# distributed under the License is distributed on an "AS IS" BASIS,          #
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   #
# See the License for the specific language governing permissions and        #
# limitations under the License.                                             #
#                                                                            #
# -------------------------------------------------------------------------- #
# ########################################################################## #

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