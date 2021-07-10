#include "configurationdialog.h"
#include "ui_configurationdialog.h"

#include <QPushButton>

ConfigurationDialog::ConfigurationDialog(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::ConfigurationDialog)
{
    ui->setupUi(this);
    // Get ok button and disable
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    okButton->setEnabled(false);
    // Connect signals and to slots
    connect(ui->player1Name,
            &QLineEdit::textChanged,
            this,
            &ConfigurationDialog::updateOKButtonState);
    connect(ui->player2Name,
            &QLineEdit::textChanged,
            this,
            &ConfigurationDialog::updateOKButtonState);
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

void ConfigurationDialog::updateOKButtonState()
{
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    okButton->setEnabled(!ui->player1Name->text().isEmpty() && !ui->player2Name->text().isEmpty());
}
