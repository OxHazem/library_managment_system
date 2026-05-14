CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iclasses/header_files
LDFLAGS = -lsqlite3

SRC_DIR = src
CLASSES_DIR = classes/cpp_files

SRCS = $(SRC_DIR)/main.cpp \
       $(CLASSES_DIR)/Book.cpp \
       $(CLASSES_DIR)/librarian.cpp \
       $(CLASSES_DIR)/library.cpp \
       $(CLASSES_DIR)/member.cpp \
       $(CLASSES_DIR)/user.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = library_system.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
