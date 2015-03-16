#include <memory>
#include <QtTerminal.h>

int main()
{
    std::unique_ptr<Gui> app(new QtTerminal);

    app->init();
    app->run();

    return 0;
}
