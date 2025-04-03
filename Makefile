# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Iclasses/header_files -std=c++14

# Source files
SRC_DIR = src
CLASSES_DIR = classes/cpp_files
SRCS = $(SRC_DIR)/main.cpp \
       $(CLASSES_DIR)/Book.cpp \
       $(CLASSES_DIR)/librarian.cpp \
       $(CLASSES_DIR)/library.cpp \
       $(CLASSES_DIR)/member.cpp \
       $(CLASSES_DIR)/user.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = library_system.exe

# Windows compatible clean command
ifeq ($(OS),Windows_NT)
    RM = del /Q
    CLEAN_CMD = $(RM) $(subst /,\,$(OBJS)) $(TARGET)
else
    RM = rm -f
    CLEAN_CMD = $(RM) $(OBJS) $(TARGET)
endif

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(CLEAN_CMD)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run