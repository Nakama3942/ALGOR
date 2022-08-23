# ########################################################################## #
# -------------------------------------------------------------------------- #
#                                                                            #
# Copyright © 2021 Kalynovsky Valentin. All rights reserved.                 #
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

DIR=/usr/lib/ALGOR

CC=g++
FLAGS=-Wall -c -fPIC

CORE=../../src/ALGOR_CORE.cpp
EXCEPTION=../../src/ALGOR_EXCEPTION.cpp
RANDOM=../../src/ALGOR_RANDOM.cpp
ARRAY=../../src/ALGOR_ARRAY.cpp
SORTING=../../src/ALGOR_SORTING.cpp
MATRIX=../../src/ALGOR_MATRIX.cpp
HEAP=../../src/ALGOR_HEAP.cpp
LIST=../../src/ALGOR_LIST.cpp

PATHALGOR=/usr/lib/ALGOR/libALGOR.so.1.0.0.0
LIBALGOR=-Wl,-soname,libALGOR.so.1.0.0.0
LINKALGOR=/usr/lib/ALGOR/libALGOR.so

HEADER=../../include/ALGOR.hpp
HEADERPATH=/usr/include/ALGOR.hpp

.PHONY: all install test uninstall

install: lib_ALGOR

lib_ALGOR: ALGOR_CORE.o ALGOR_EXCEPTION.o ALGOR_RANDOM.o ALGOR_ARRAY.o ALGOR_SORTING.o ALGOR_MATRIX.o ALGOR_HEAP.o ALGOR_LIST.o
	@mkdir $(DIR)
	@$(CC) *.o -no-pie -shared -o $(PATHALGOR) $(LIBALGOR)
	@ln -s $(PATHALGOR) $(LINKALGOR)
	@cp $(HEADER) $(HEADERPATH)
	@echo Library compiled and installed

ALGOR_CORE.o: $(CORE)
	@$(CC) $(FLAGS) $(CORE)

ALGOR_EXCEPTION.o: $(EXCEPTION)
	@$(CC) $(FLAGS) $(EXCEPTION)

ALGOR_RANDOM.o: $(RANDOM)
	@$(CC) $(FLAGS) $(RANDOM)

ALGOR_ARRAY.o: $(ARRAY)
	@$(CC) $(FLAGS) $(ARRAY)

ALGOR_SORTING.o: $(SORTING)
	@$(CC) $(FLAGS) $(SORTING)

ALGOR_MATRIX.o: $(MATRIX)
	@$(CC) $(FLAGS) $(MATRIX)

ALGOR_HEAP.o: $(HEAP)
	@$(CC) $(FLAGS) $(HEAP)

ALGOR_LIST.o: $(LIST)
	@$(CC) $(FLAGS) $(LIST)

clean:
	@rm -rf *.o
	@echo The object files have been deleted

test:
	$(CC) -no-pie -s -o algor_exam ../../example/Basic_test.cpp -L/usr/lib/ALGOR -lALGOR -Wl,-rpath,/usr/lib/ALGOR
	./algor_exam
	rm algor_exam

uninstall:
	@rm -rf $(DIR)
	@rm $(HEADERPATH)
