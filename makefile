bin/animacion : src/animacion.cpp src/Dibujo.cpp src/GestorDibujos.cpp src/Corral.cpp
	mkdir -p bin
	c++ src/animacion.cpp src/Dibujo.cpp src/GestorDibujos.cpp src/Corral.cpp -Iinclude -o bin/animacion -std=c++17 -lftxui-screen -lftxui-dom -lftxui-component

runAnimacion : bin/animacion
	./bin/animacion
