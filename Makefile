CXX = g++
CXXFLAGS = -std=c++17 -pthread -Iheaders $(shell pkg-config --cflags sdl2 SDL2_mixer)
LINKER_FLAGS = $(shell pkg-config --libs sdl2 SDL2_mixer) -lSDL2_image -lSDL2_ttf

SRC = src/main.cpp src/TimerThread.cpp src/Counter.cpp src/Alarm.cpp
TARGET = TimerApp

APP_DIR = TimerApp.app
APP_BIN = $(APP_DIR)/Contents/MacOS/TimerApp
PLIST_FILE = $(APP_DIR)/Contents/Info.plist

# LINKER_FLAGS = $(shell sdl2-config --libs) -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all: $(TARGET) 

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LINKER_FLAGS)

mac: $(TARGET)
	@echo "Creating mac app..."

	# Create required directories
	mkdir -p $(APP_DIR)/Contents/MacOS
	mkdir -p $(APP_DIR)/Contents/Resources

	# Copy the compiled binary
	cp $(TARGET) $(APP_BIN)
	chmod +x $(APP_BIN)

	# Create launcher script
	echo "#!/bin/bash" > $(APP_BIN)_launcher
	echo "DIR=\"\$(dirname \"\$0\")\"" >> $(APP_BIN)_launcher
	echo "/usr/bin/open -a Terminal \"\$$DIR/TimerApp\"" >> $(APP_BIN)_launcher
	chmod +x $(APP_BIN)_launcher
	mv $(APP_BIN)_launcher $(APP_BIN)

	# Generate Info.plist
	echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" > $(PLIST_FILE)
	echo "<plist version=\"1.0\">" >> $(PLIST_FILE)
	echo "<dict>" >> $(PLIST_FILE)
	echo "  <key>CFBundleExecutable</key>" >> $(PLIST_FILE)
	echo "  <string>TimerApp</string>" >> $(PLIST_FILE)
	echo "  <key>CFBundleIdentifier</key>" >> $(PLIST_FILE)
	echo "  <string>com.terminal.timerapp</string>" >> $(PLIST_FILE)
	echo "  <key>CFBundleName</key>" >> $(PLIST_FILE)
	echo "  <string>TimerApp</string>" >> $(PLIST_FILE)
	echo "</dict>" >> $(PLIST_FILE)
	echo "</plist>" >> $(PLIST_FILE)

	@echo "Mac App Created!"

clean:
	rm -rf $(TARGET) $(APP_DIR)
	@echo "Erasing previous app file!"
