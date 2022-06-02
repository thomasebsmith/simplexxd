CC = g++
CCFLAGS = -std=c++17 -Wall -Wextra -pedantic -Werror -O3

BUILD_DIR = build
CPP_FILES = src/main.cpp

${BUILD_DIR}/simplexxd: ${CPP_FILES}
	mkdir -p ${BUILD_DIR}
	${CC} ${CCFLAGS} ${CPP_FILES} -o $@

.PHONY: clean
clean:
	rm -rf ${BUILD_DIR}
