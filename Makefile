CXX = g++


CXXFLAGS = -std=c++17 -pthread -Iheaders


SRC = src/main.cpp src/TimerThread.cpp src/Counter.cpp

TARGET = main


all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
