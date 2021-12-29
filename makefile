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

.PHONY: lib test

lib: libALGOR.so

libALGOR.so: ALGOR.cpp
	@g++ -Wall -c -fPIC ALGOR.cpp -shared -o libALGOR.so.2.0.0 -Wl,-soname,libALGOR.so.2.0.0
	@ln -s libALGOR.so.2.0.0 libALGOR.so
	@echo Library compiled

test: libALGOR.so
	@g++ -no-pie -s -o exam example.cpp -L. -lALGOR
	@echo Test compiled