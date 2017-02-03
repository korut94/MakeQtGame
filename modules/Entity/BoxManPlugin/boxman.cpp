#include "boxman.h"

namespace mqggame
{
namespace Entity
{
namespace BoxMan
{
BoxMan::BoxMan(QGraphicsItem *parent)
  : QGraphicsRectItem(parent) {}

QRectF BoxMan::boundingRect() const
{
  return QRectF(0, 0, 50, 50);
}

void BoxMan::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);

  painter->fillRect(boundingRect(), Qt::black);
}
} // namespace BoxMan
} // namespace Entity
} // namespace mqggame
