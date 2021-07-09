#include "configurationdialog.h"
#include "ui_configurationdialog.h"

ConfigurationDialog::ConfigurationDialog(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::ConfigurationDialog)
{
    ui->setupUi(this);
}

ConfigurationDialog::~ConfigurationDialog()
{
    delete ui;
}

QString ConfigurationDialog::player1Name() const
{
    return ui->player1Name->text();
}

void ConfigurationDialog::setPlayer1Name(const QString &p1Name)
{
    return ui->player1Name->setText(p1Name);
}

QString ConfigurationDialog::player2Name() const
{
    return ui->player2Name->text();
}

void ConfigurationDialog::setPlayer2Name(const QString &p2Name)
{
    ui->player2Name->setText(p2Name);
}
