#ifndef VIEW_MAIN_VIEW_H
#define VIEW_MAIN_VIEW_H

#include <QtGui>
#include <QtGui/QWidget>

#include <boost/shared_ptr.hpp>

#include <model/model.h>
#include <controller/controller.h>

class MainView : public QWidget {
  Q_OBJECT

public:
  MainView(QWidget * parent = 0, Qt::WindowFlags f = 0);
  void set_model(Model *model);

  virtual void paintEvent(QPaintEvent *event);

  virtual void mouseMoveEvent( QMouseEvent * event );
  virtual void mousePressEvent( QMouseEvent * event );
  virtual void mouseReleaseEvent( QMouseEvent * event );

private:
  Model *m_model;
  Controller m_controller;

private:
  QPoint m_circle_center;
  double m_radius;

  enum ModificationType {
    CREATE,
    MODIFY
  } m_modification_type;

  Regular::Vertex_handle m_vh;
};

#endif // VIEW_MAIN_VIEW_H
