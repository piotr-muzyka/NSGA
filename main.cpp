#include <memory>
#include <Qt4Window.h>

int main()
{
    Gui* app = new Qt4Window();
    app->init();
    app->run();

    return 0;
}
