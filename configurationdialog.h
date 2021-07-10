#ifndef CONFIGURATIONDIALOG_H
#define CONFIGURATIONDIALOG_H

#include <QDialog>

namespace Ui {
class ConfigurationDialog;
}

class ConfigurationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigurationDialog(QWidget *parent = nullptr);
    ~ConfigurationDialog();

    QString player1Name() const;
    void setPlayer1Name(const QString &p1Name);
    QString player2Name() const;
    void setPlayer2Name(const QString &p2Name);

private slots:
    void updateOKButtonState();

private:
    Ui::ConfigurationDialog *ui;
};

#endif // CONFIGURATIONDIALOG_H
