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

DIR=/usr/lib/ALGOR

CC=g++
FLAGS=-no-pie -shared -o
OFLAGS=-Wall -c -fPIC

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
ALIB=/usr/lib/ALGOR/libALGOR.a.1.0.0.0

HEADER=../../include/ALGOR.hpp
HEADERPATH=/usr/include/ALGOR.hpp

.PHONY: install clean uninstall

install: lib_ALGOR

lib_ALGOR: ALGOR_CORE.o ALGOR_EXCEPTION.o ALGOR_RANDOM.o ALGOR_ARRAY.o ALGOR_SORTING.o ALGOR_MATRIX.o ALGOR_HEAP.o ALGOR_LIST.o
	@mkdir $(DIR)
	@$(CC) *.o $(FLAGS) $(PATHALGOR) $(LIBALGOR)
	@ln -s $(PATHALGOR) $(LINKALGOR)
	@ar -r $(ALIB) *.o
	@cp $(HEADER) $(HEADERPATH)
	@echo Library compiled and installed!

ALGOR_CORE.o: $(CORE)
	@$(CC) $(OFLAGS) $(CORE)
	@echo ALGOR_CORE.o done...

ALGOR_EXCEPTION.o: $(EXCEPTION)
	@$(CC) $(OFLAGS) $(EXCEPTION)
	@echo ALGOR_EXCEPTION.o done...

ALGOR_RANDOM.o: $(RANDOM)
	@$(CC) $(OFLAGS) $(RANDOM)
	@echo ALGOR_RANDOM.o done...

ALGOR_ARRAY.o: $(ARRAY)
	@$(CC) $(OFLAGS) $(ARRAY)
	@echo ALGOR_ARRAY.o done...

ALGOR_SORTING.o: $(SORTING)
	@$(CC) $(OFLAGS) $(SORTING)
	@echo ALGOR_SORTING.o done...

ALGOR_MATRIX.o: $(MATRIX)
	@$(CC) $(OFLAGS) $(MATRIX)
	@echo ALGOR_MATRIX.o done...

ALGOR_HEAP.o: $(HEAP)
	@$(CC) $(OFLAGS) $(HEAP)
	@echo ALGOR_HEAP.o done...

ALGOR_LIST.o: $(LIST)
	@$(CC) $(OFLAGS) $(LIST)
	@echo ALGOR_LIST.o done...

clean:
	@rm -rf *.o
	@echo The object files have been deleted!

uninstall:
	@rm -rf $(DIR)
	@rm $(HEADERPATH)
	@echo Library has deleted!
