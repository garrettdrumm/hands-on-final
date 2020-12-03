#build an executable named count from wc.cc
CC = gcc
#compiler flags
# -g add debugging information
# -Wall gets most compiler warnings
CFLAGS = -g -Wall

#build target
TARGET = wc

all: $(TARGET)

$(TARGET): $(TARGET).cc
  $(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cc

clean:
  $(RM) $(TARGET)
