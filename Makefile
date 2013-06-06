GRAPHICS=./libgraphics/box.cpp ./libgraphics/rectangle.cpp ./libgraphics/circle.cpp ./libgraphics/libimage/image.cpp ./libgraphics/libimage/libpixel/pixel.cpp
all:
	mkdir -p bin
	g++ ./tools/gameproto.cpp $(GRAPHICS) -lncurses -o bin/mycraft
	g++ ./tools/editor.cpp $(GRAPHICS) -lncurses -o bin/editor
clean:
	rm -rf bin/
