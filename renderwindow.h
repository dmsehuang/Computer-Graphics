#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include "openglwindow.h"

#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>

// hhj - additional library
#include <QColorDialog>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>

class QOpenGLShaderProgram;
class QOpenGLBuffer;
class QOpenGLVertexArrayObject;

class RenderWindow : public OpenGLWindow
{
public:
    RenderWindow();

    void initialize();
    void render();
    void checkError(const QString& prefix);

private:

    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    QOpenGLShaderProgram *m_program;
    QOpenGLVertexArrayObject* m_vao;
    QOpenGLBuffer *m_vbo;
    QOpenGLBuffer *m_ibo;
    int m_frame;
    bool m_useSourceCode;
};

/* hhj - modify this function to create a more specific render window object */
class RenderWindowWidget : public QWidget
{
public:
  RenderWindowWidget(QWidget* parent): QWidget(parent) {

      renWin = new RenderWindow();

      QWidget* widget = QWidget::createWindowContainer(renWin);
//      QHBoxLayout* layout = new QHBoxLayout(this);
      
      // hhj - add a new button
      QVBoxLayout* layout = new QVBoxLayout(this);
      QPushButton* button = new QPushButton();
      button->setText("Change Background Color");

      layout->addWidget(widget);
      layout->addWidget(button);
      
      // hhj - connect signal with slot
      // hhj - parent means "Demo" in this case
      QObject::connect(button, SIGNAL(clicked()), parent, SLOT(selectColor()));
  }

  RenderWindow* GetRenderWindow() {
      return renWin;
  }

private:
  RenderWindow* renWin;
};

#endif // RENDERWINDOW_H
