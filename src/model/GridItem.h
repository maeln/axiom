#pragma once

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QPoint>
#include <QtCore/QSize>

namespace AxiomModel {

    class GridSurface;

    class GridItem : public QObject {
        Q_OBJECT

    public:
        GridSurface *parent;

        explicit GridItem(GridSurface *parent);

        QPoint pos() const { return m_pos; }

        QSize size() const { return m_size; }

        bool isSelected() const { return m_selected; }

        bool isDragAvailable(QPoint delta);

    public slots:
        void setPos(QPoint pos);

        void setSize(QSize size);

        void setCorners(QPoint topLeft, QPoint bottomRight);

        void select(bool exclusive);

        void deselect();

        void remove();

        void startDragging();

        void dragTo(QPoint delta);

        void finishDragging();

    signals:
        void beforePosChanged(QPoint newPos);
        void posChanged(QPoint newPos);
        void beforeSizeChanged(QSize newSize);
        void sizeChanged(QSize newSize);
        void selected(bool exclusive);
        void deselected();
        void startedDragging();
        void draggedTo(QPoint delta);
        void finishedDragging();
        void removed();

    private:
        QPoint m_pos = QPoint(0, 0);
        QSize m_size = QSize(0, 0);
        bool m_selected = false;

        QPoint dragStartPos;

        void setPos(QPoint pos, bool updateGrid, bool checkPositions);
    };

}