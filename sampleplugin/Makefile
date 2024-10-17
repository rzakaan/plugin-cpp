#------------------------
# @author Riza Kaan Ucak
# @date 21.01.2024
#------------------------
# plugin dynamic library
# -----------------------

.PHONY: clean
.SUFFIXES: .cpp .o

# directories
OBJDIR=obj
BINDIR=bin
SRCDIR=src

# pattern subsutution

# sources
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
HEADERS=$(wildcard $(SRCDIR)/*.h)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# build
TARGET=sampleplugin.so

# compiler settings
UNAME:=$(shell uname -s)
ifeq ($(UNAME), Linux)
    CXX=c++
    CFLAGS=-c -g -Wall
endif
ifeq ($(UNAME), Darwin)
    # MacOs
    CXX=c++
    CFLAGS=-g -Wall -std=c++20 -shared -fPIC
endif


all: clean ${TARGET}

${TARGET}: 
	${CXX} ${CFLAGS} ${SOURCES} -o ${BINDIR}/$@

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@echo "compiling object"
	${CXX} ${CFLAGS} -c $^ -o $@

clean:
	rm -rf ${BINDIR}/*
	rm -f ${OBJDIR}/*.o

debug:
	@echo "sources: ${SOURCES}"
	@echo "headers: ${HEADERS}"
	@echo "objects: ${OBJECTS}"

