#!/usr/bin/env bash

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

g++ -no-pie -s -o algor_exam ../../example/Basic_test.cpp -L/usr/lib/ALGOR -lALGOR -Wl,-rpath,/usr/lib/ALGOR
./algor_exam
rm algor_exam
