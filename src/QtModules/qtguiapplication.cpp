#include "qtguiapplication.h"

#include <QGuiApplication>

namespace mqg
{
namespace module
{
namespace Qt
{
void QtGuiApplication::exec(int argc, char **argv) {
    m_app.exec();
}
} // namespace Qt
} // namespace module
} // namespace mqg
