GRAPHICS=./libgraphics/box.cpp ./libgraphics/rectangle.cpp ./libgraphics/circle.cpp ./libgraphics/libimage/image.cpp ./libgraphics/libimage/libpixel/pixel.cpp ./libgraphics/libimage/rle.c ./libgraphics/libperspective/perspective.cpp
ENGINE=./engine/screen.cpp
all:
	mkdir -p bin
	g++ ./tools/gameproto.cpp $(GRAPHICS) $(ENGINE) -lncurses -o bin/mycraftproto
	g++ ./tools/engine.cpp $(GRAPHICS) $(ENGINE) -lncurses -o bin/mycraft
	g++ ./tools/editor.cpp $(GRAPHICS) -lncurses -o bin/editor
clean:
	rm -rf bin/
