#-----------------------
# @author Riza Kaan Ucak
# @date 21.01.2024
#-----------------------

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
TARGET=plugin

# compiler settings
UNAME:=$(shell uname -s)
ifeq ($(UNAME), Linux)
    CXX=c++
    CFLAGS=-c -g -Wall 
endif
ifeq ($(UNAME), Darwin)
    # MacOs
    CXX=c++
    CFLAGS=-g -Wall 
endif


all: clean ${TARGET}

${TARGET}: ${OBJECTS}
	${CXX} ${CFLAGS} $^ -ldl -o ${BINDIR}/$@

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

clean:
	rm -f ${BINDIR}/*
	rm -f ${OBJDIR}/*.o

run:
	cd ${BINDIR} && ./${TARGET}

print:
	@echo "sources: ${SOURCES}"
	@echo "headers: ${HEADERS}"
	@echo "objects: ${OBJECTS}"

