#ifndef CONSOLE_H
#define CONSOLE_H

#include <QLineEdit>
#include <QTextEdit>
#include <QScriptEngine>
#include <QShowEvent>
#include <QWidget>

namespace mqg
{
/**
 * @brief The Console class bundles a command line with a text box as logger.
 * The console is thinked to provide both an emitter for the typed commands
 * by the user and insert it into the script environment to use the text box
 * through the object `console`.
 *
 * The console supports the undo e redo command activate them when respectively
 * the key up and the key down are pressed.
 *
 * In the current version the Console class already has one slots for each
 * console's functionality (log, warning, error, etc.) but in the future ones
 * it will aim to supply format text methods and leave the differnet logger
 * levels' implementation to the JS environment.
 */
class Console : public QWidget
{
  Q_OBJECT

public:
  explicit Console(QWidget *parent = nullptr);

public slots:
  /**
   * @brief Clean the text box removing all the output printed text.
   */
  void clear();
  /**
   * @brief Print a message with the error format: text color red.
   * @param The error message to print.
   */
  void error(const QString &error);
  /**
   * @brief Print a message with the log format: text color gray and italic
   * font.
   * @param The log message to print.
   */
  void log(const QString &log);
  /**
   * @brief Print a message with the result format: text color blue. This is
   * the default format to print the result of expressions.
   * @param The result message to print.
   */
  void result(const QString &result);
  /**
   * @brief Print a message with the warning format: text color dark yellow.
   * @param The warning message to print.
   */
  void warning(const QString &warning);

signals:
  /**
   * @brief This signal is emitted when the user has the focus on the command
   * line and he was pressed the return key.
   * @param The command typed by the user.
   */
  void evaluate(QString expression);

private slots:
  /**
   * @brief It is binded with the QLineEdit's returnPressed signal so to get
   * the text currently writed on the command line.
   */
  void sendEvalRequest();

private:
  /**
   * @brief Section where the connection among signals and slots are done.
   */
  void bindConnection();
  /**
   * @brief Section where the user interface is designed.
   */
  void buildInterface();
  /**
   * @brief Like the slot methods, this method performs a print of the entered
   * command with its format. This function rappresents just a Console's
   * behavior with no utility for the script environemnt.
   * @param The script command.
   */
  void logCommand(const QString &cmd);
  /**
   * @brief The method places the logger's scroll-bar on the bottom of the
   * area.
   */
  void moveScrollBarAtBottom();
  /**
   * @brief General method to print text in the logger. For now it takes only
   * a QTextCharFormat to describe the color and font text but in the future a
   * better descriptor (maybe an integratio with html) should be done.
   *
   * If the scrollbar is placed in a position different from the logger area's
   * bottom, it will put there automatically.
   *
   * @param The text to print.
   * @param The format to apply over the text.
   */
  void print(const QString &text, const QTextCharFormat& format);
  void showEvent(QShowEvent *event) override;

  QLineEdit *m_line;
  QTextEdit *m_log;
};
} // namespace mqg

#endif // CONSOLE_H
