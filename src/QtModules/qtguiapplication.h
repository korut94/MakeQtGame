#ifndef QTGUIAPPLICATION_H
#define QTGUIAPPLICATION_H

#include "iapplication.h"

#include <QGuiApplication>

namespace mqg
{
namespace module
{
namespace Qt
{
/*!
 * \brief The QtGuiApplication class
 */
class QtGuiApplication : public mqg::IApplication
{
private:
    QGuiApplication m_app;

public:
    /*!
     * \brief QtGuiApplication
     * \param argc
     * \param argv
     */
    QtGuiApplication(int &argc, char **argv) : m_app(argc, argv) {}

    void exec(int argc, char **argv) override;
};
} // namespace Qt
} // namespace module
} // namespace mqg

#endif // QTGUIAPPLICATION_H
