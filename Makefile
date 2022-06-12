CC = g++
CCFLAGS = -std=c++17 -Wall -Wextra -pedantic -Werror -O3

BUILD_DIR = build
CPP_FILES = src/main.cpp

EXECUTABLE = ${BUILD_DIR}/simplexxd

${EXECUTABLE}: ${CPP_FILES}
	mkdir -p ${BUILD_DIR}
	${CC} ${CCFLAGS} ${CPP_FILES} -o $@

.PHONY: clean
clean:
	rm -rf ${BUILD_DIR}

DIFF = diff

.PHONY: runtests
runtests: ${EXECUTABLE}
	for testdir in ./tests/*; do \
		${EXECUTABLE} $$testdir/input | ${DIFF} $$testdir/output - || exit 1; \
	done
