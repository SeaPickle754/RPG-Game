#include <SFML/Graphics.hpp>
#include "Application.h"

int main(){
Application app;
app.initialize();
while(app.getWindow()->isOpen()){
    app.doEvents();
    app.update();
    app.render();
}
return 0;
}
