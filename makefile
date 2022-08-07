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

# Команди для компіляції під Windows:
#  g++ ./src/ALGOR_CORE.cpp ./src/ALGOR_EXCEPTION.cpp ./src/ALGOR_RANDOM.cpp ./src/ALGOR_ARRAY.cpp ./src/ALGOR_SORTING.cpp ./src/ALGOR_MATRIX.cpp ./src/ALGOR_HEAP.cpp ./src/ALGOR_LIST.cpp -s -shared -o ALGOR.dll
#  g++ -s -o exam.exe ./example/Basic_test.cpp -L. -lALGOR

DIR=/usr/lib/ALGOR

CC=g++
FLAGS=-Wall -c -fPIC -shared -o

CORE=./src/ALGOR_CORE.cpp
EXCEPTION=./src/ALGOR_EXCEPTION.cpp
RANDOM=./src/ALGOR_RANDOM.cpp
ARRAY=./src/ALGOR_ARRAY.cpp
SORTING=./src/ALGOR_SORTING.cpp
MATRIX=./src/ALGOR_MATRIX.cpp
HEAP=./src/ALGOR_HEAP.cpp
LIST=./src/ALGOR_LIST.cpp

PATHALGOR=/usr/lib/ALGOR/libALGOR.so.1.0.0.0
LIBALGOR=-Wl,-soname,libALGOR.so.1.0.0.0
LINKALGOR=/usr/lib/ALGOR/libALGOR.so

HEADER=./include/ALGOR.hpp
HEADERPATH=/usr/include/ALGOR.hpp

.PHONY: install test uninstall

install: lib_ALGOR

lib_ALGOR: ./src/ALGOR.cpp
	@mkdir $(DIR)
	@$(CC) $(CORE) $(EXCEPTION) $(RANDOM) $(ARRAY) $(SORTING) $(MATRIX) $(HEAP) $(LIST) $(FLAGS) $(PATHALGOR) $(LIBALGOR)
	@ln -s $(PATHALGOR) $(LINKALGOR)
	@cp $(HEADER) $(HEADERPATH)
	@echo Library compiled and installed

test:
	$(CC) -no-pie -s -o algor_exam ./example/Basic_test.cpp -L/usr/lib/ALGOR -lALGOR
	./algor_exam
	rm algor_exam

uninstall:
	@rm -rf $(DIR)
	@rm $(HEADERPATH)
