# Имя цели и выходного файла
TARGET = main

# Компилятор
CC = g++

# Опции компиляции
CFLAGS = -Wall -std=c++17

# Исходные файлы
SRCS = main.cpp GaussianFilter.cpp BMP24bit.cpp Pixel.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

