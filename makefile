CXX = g++
CXXFLAGS = -std=c++20 -Wall -g \
           -ICore -IEngine -IRendering -IThirdParty/glad/include -I/usr/include/glm

SRC = main.cpp \
      $(shell find Core -name "*.cpp") \
      $(shell find Engine -name "*.cpp") \
      $(shell find Rendering -name "*.cpp") \
      $(shell find World -name "*.cpp") \
      ThirdParty/glad/src/glad.c

TARGET = TurnBased3D

LIBS = -lglfw -ldl -lGL -lpthread

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)
