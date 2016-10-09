CC = g++
RM = rm

CDEBUG = -g
LDEBUG = -g

INC_DIR = ../include
OBJ_DIR = .
LIB_DIR = ../lib
BIN_DIR = ../bin

all: dirs $(BIN_DIR)/CRegExpTest

dirs:
	@if [ ! -e ../bin ]; then mkdir ../bin; fi

SRC = \
CRegExpTest.cpp \

OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

CPPFLAGS = \
$(CDEBUG) \
-std=c++11 \
-I. \
-I$(INC_DIR) \
-I../../CUtil/include \

LFLAGS = \
$(LDEBUG) \
-L$(LIB_DIR) \
-L../../CStrUtil/lib \

LIBS = \
-lCRegExp -lCStrUtil -ltre

clean:
	$(RM) -f $(OBJ_DIR)/*.o
	$(RM) -f $(BIN_DIR)/CRegExpTest

.SUFFIXES: .cpp

.cpp.o:
	$(CC) -c $< -o $(OBJ_DIR)/$*.o $(CPPFLAGS)

$(BIN_DIR)/CRegExpTest: $(OBJS) $(LIB_DIR)/libCRegExp.a
	$(CC) $(LDEBUG) -o $(BIN_DIR)/CRegExpTest $(OBJS) $(LFLAGS) $(LIBS)
