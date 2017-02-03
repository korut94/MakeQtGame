#ifndef BOXMAN_H
#define BOXMAN_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QRectF>
#include <QStyleOptionGraphicsItem>

namespace mqggame
{
namespace Entity
{
namespace BoxMan
{
class BoxMan : public QGraphicsRectItem
{
public:
  BoxMan(QGraphicsItem *parent = nullptr);

  QRectF  boundingRect() const;
  void    paint(QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget = nullptr);
};
} // namespace BoxMan
} // namespace Entity
} // namespace mqggame

#endif // BOXMAN_H
