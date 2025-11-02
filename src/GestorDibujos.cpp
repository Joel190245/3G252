#include "../include/GestorDibujos.hpp"

Dibujo GestorDibujos::obtenerPajaro() {
    return Dibujo(R"(
/\ /\
((ovo))
():::()
  VVV
)");
}

Dibujo GestorDibujos::obtenerPajaroSorprendido() {
    return Dibujo(R"(
/\_/\
((@v@))
():::()
 VV-VV
)");
}

Dibujo GestorDibujos::obtenerPistola() {
    return Dibujo(R"(
      __,_____
     / __.==--" 
    /#(-'
    `-',
)");
}

Dibujo GestorDibujos::obtenerManzana() {
    return Dibujo(R"(
      _        ,..
 ,--._\\_.--, (-00)
; #         _:(  -)
:          (_____/
:            :
 '.___..___.`
)");
}

Dibujo GestorDibujos::obtenerAngel() {
    return Dibujo(R"(
____ <==> ____
\___\(**)/___/
 \___|  |___/ 
     L  J 
     |__|
      vv
)");
}

Dibujo GestorDibujos::obtenerSol() {
    return Dibujo(R"(
   \  |  /
    .-*-.
 - *  o  * -
    `-*-'
   /  |  \
)");
}

Dibujo GestorDibujos::obtenerNube() {
    return Dibujo(R"(
     .--. 
  .-(    ). 
 (___.__)__) 
)");
}

Dibujo GestorDibujos::obtenerCazador() {
    return Dibujo(R"(
     _O_
    /-|======>
     / \
    /   \
)");
}

Dibujo GestorDibujos::obtenerArbol() {
    return Dibujo(R"(
      ccee88oo
   C8O8O8Q8PoOb o8oo
  dOB69QO8PdUOpugoO9bD
 CgggbU8OU qOp qOdoUOdcb
     6OuU  /p u gcoUodpP
        \\\//  /douUP
          \\\////
           |||/\
           |||\/
           |||||
     .....//||||\....
)");
}
