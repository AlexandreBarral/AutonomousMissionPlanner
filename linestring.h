#ifndef LINESTRING_H
#define LINESTRING_H

#include "geographicsmissionitem.h"
#include "locationposition.h"

class LineString : public GeoGraphicsMissionItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit LineString(QObject *parent = 0, QGraphicsItem *parentItem =0);
    
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    
    void write(QJsonObject &json) const override;
    void read(const QJsonObject &json) override;
    
    void addPoint(QGeoCoordinate const &location);
    
    QList<LocationPosition> const &points() const;

public slots:
    void updateProjectedPoints();

private:
    QList<LocationPosition> m_points;
    QRectF m_bbox;
    
    void updateBBox();
    
};

#endif // LINESTRING_H
