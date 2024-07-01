#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QDateTime>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>


namespace Ui {
class MessageWidget;
}

class MessageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MessageWidget(QString senderId, QString text, QByteArray image,QWidget *parent = nullptr);

    ~MessageWidget();

private:
    Ui::MessageWidget *ui;
    QLabel *senderLabel;
    QLabel *textLabel;
    QLabel *imageLabel;
};

#endif // MESSAGEWIDGET_H
