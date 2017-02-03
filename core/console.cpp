#include <QAction>
#include <QBoxLayout>
#include <QScrollBar>

#include "console.h"

namespace mqg
{
Console::Console( QWidget *parent)
  : QWidget(parent)
{
  buildInterface();
  bindConnection();
}

void Console::bindConnection()
{
  QAction *pressUp = new QAction;
  pressUp->setShortcut(Qt::Key_Up);
  m_line->addAction(pressUp);

  QAction *pressDown = new QAction;
  pressDown->setShortcut(Qt::Key_Down);
  m_line->addAction(pressDown);

  QObject::connect(m_line,
                   SIGNAL(returnPressed()),
                   this,
                   SLOT(sendEvalRequest()));

  // Bind the pressed key up action with the `undo` slot and the key down
  // action with the `redo` slot.
  QObject::connect(pressUp, SIGNAL(triggered()), m_line, SLOT(undo()));
  QObject::connect(pressDown, SIGNAL(triggered()), m_line, SLOT(redo()));
}

void Console::buildInterface()
{
  m_log = new QTextEdit;
  m_log->setReadOnly(true);

  m_line = new QLineEdit;

  QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom);
  layout->addWidget(m_log);
  layout->addWidget(m_line);

  setLayout(layout);
}

void Console::clear()
{
  m_log->clear();
}

void Console::error(const QString &error)
{
  QTextCharFormat format;
  format.setForeground(Qt::red);

  print(error, format);
}

void Console::sendEvalRequest()
{
  QString cmd = m_line->text();
  m_line->clear();

  if (cmd.length() > 0) {
    logCommand(cmd);

    emit evaluate(cmd);
  }
}

void Console::log(const QString &log)
{
  QTextCharFormat format;
  format.setForeground(Qt::gray);
  format.setFontItalic(true);

  print(log, format);
}

void Console::logCommand(const QString &cmd)
{
  QTextCharFormat format;
  format.setForeground(Qt::black);

  print(">> " + cmd, format);
}

void Console::result(const QString &result)
{
  QTextCharFormat format;
  format.setForeground(Qt::blue);

  print(result, format);
}

void Console::moveScrollBarAtBottom()
{
  QScrollBar *scroll = m_log->verticalScrollBar();

  if (scroll->value() != scroll->maximum()) {
    // Put the scrollbar at the text area's bottom
    scroll->setValue(scroll->maximum());
  }
}

void Console::print(const QString &text, const QTextCharFormat &format)
{
  QTextCursor cursor = m_log->textCursor();

  cursor.insertText(text, format);
  // Carriage return, so the next log will printed below the previous one
  cursor.insertBlock();
  // With this the logger follows the text sequence so the user always will see
  // the last inserted command.
  moveScrollBarAtBottom();
}

void Console::showEvent(QShowEvent *event)
{
  Q_UNUSED(event);
  // Set the focus so to enhance the usability for the user
  m_line->setFocus();
}

void Console::warning(const QString &warning)
{
  QTextCharFormat format;
  format.setForeground(Qt::darkYellow);

  print(warning, format);
}
} // namespace mqg
