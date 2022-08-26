# Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

CONFIG -= qt

TEMPLATE = lib
DEFINES += ALGOR_LIBRARY

VERSION = 1.0.0.0

CONFIG += c++20
CONFIG += build_all

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    include/ALGOR.hpp

SOURCES += \
    src/ALGOR_CORE.cpp \
    src/ALGOR_EXCEPTION.cpp \
	src/ALGOR_RANDOM.cpp \
	src/ALGOR_ARRAY.cpp \
	src/ALGOR_SORTING.cpp \
	src/ALGOR_MATRIX.cpp \
    src/ALGOR_HEAP.cpp \
	src/ALGOR_LIST.cpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
