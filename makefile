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

CC=g++
FLAGS=-Wall -c -fPIC

DIR=/usr/lib/ALGOR
LIBALGOR=/usr/lib/ALGOR/libALGOR.so.1.0.0.0
PATHALGOR=-Wl,-soname,libALGOR.so.1.0.0.0
LINKALGOR=/usr/lib/ALGOR/libALGOR.so
HEADER=/usr/include/ALGOR.hpp

.PHONY: install test uninstall

install: lib_ALGOR

lib_ALGOR: ./src/ALGOR.cpp
	#g++ ALGOR.cpp -s -shared -o ALGOR.dll
	@mkdir $(DIR)
	@$(CC) $(FLAGS) ./src/ALGOR.cpp -shared -o $(LIBALGOR) $(PATHALGOR)
	@ln -s $(LIBALGOR) $(LINKALGOR)
	@cp ./src/ALGOR.hpp $(HEADER)
	@echo Library compiled and installed

test:
	#g++ -s -o exam.exe example.cpp -L. -lALGOR
	$(CC) -no-pie -s -o algor_exam ./example/Basic_test.cpp -L/usr/lib/ALGOR -lALGOR
	./algor_exam
	rm algor_exam

uninstall:
	@rm -rf $(DIR)
	@rm $(HEADER)
