CC = g++
AR = ar
RM = rm

CDEBUG = -g

INC_DIR = ../include
OBJ_DIR = ../obj
LIB_DIR = ../lib

all: dirs $(LIB_DIR)/libCRegExp.a

dirs:
	@if [ ! -e ../obj ]; then mkdir ../obj; fi
	@if [ ! -e ../lib ]; then mkdir ../lib; fi
	@if [ ! -e ../bin ]; then mkdir ../bin; fi

SRC = \
CRegExp.cpp \

OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

CPPFLAGS = \
-std=c++14 \
-I$(INC_DIR) \
-I../../CStrUtil/include \

clean:
	$(RM) -f $(OBJ_DIR)/*.o
	$(RM) -f $(LIB_DIR)/libCRegExp.a

$(OBJS): $(OBJ_DIR)/%.o: %.cpp
	$(CC) -c $< -o $(OBJ_DIR)/$*.o $(CPPFLAGS)

.SUFFIXES: .cpp

$(LIB_DIR)/libCRegExp.a: $(OBJS)
	$(AR) crv $(LIB_DIR)/libCRegExp.a $(OBJS)
