#include "aboutdialog.h"

#include "Method.h"
#include "mainwindow.h"
#include "ui_aboutdialog.h"
#include "ui_mainwindow.h"

extern MainWindow* mw_one;
extern QString strAppName, strIniFile;
QString CurVerison = "20220122";
QString ocVer = "0.7.7";
QString ocVerDev = "0.7.8";
QString ocFrom, ocFromDev, strOCFrom, strOCFromDev;
bool blDEV = false;

aboutDialog::aboutDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::aboutDialog) {
  ui->setupUi(this);

  strOCFrom = "https://github.com/acidanthera/OpenCorePkg/releases/latest";
  strOCFromDev =
      "https://github.com/acidanthera/OpenCorePkg/actions/runs/1797540408/";

  strIniFile =
      QDir::homePath() + "/.config/" + strAppName + "/" + strAppName + ".ini";

  QSettings Reg(strIniFile, QSettings::IniFormat);
  QString ver = Reg.value("ocVer").toString();
  if (ver > ocVer) {
    ocVer = ver;
  }

  setMaximumWidth(this->width());
  setMaximumHeight(this->height());
  setMinimumWidth(this->width());
  setMinimumHeight(this->height());

  ocVerDev = ocVerDev + " [" + tr("DEV") + "]";
  ocFromDev = "<a href=\"" + strOCFromDev + "\"" + "> " + tr(" Source ");
  ocFrom = "<a href=\"" + strOCFrom + "\"" + "> " + tr(" Source ");

  ui->label->setFixedHeight(85);
  ui->label->setFixedWidth(85);
  ui->label->setText("");

  ui->label->setStyleSheet(
      "QLabel{"
      "border-image:url(:/icon.png) 4 4 4 4 stretch stretch;"
      "}");

  if (!blDEV)
    ui->lblVersion->setText(tr("Version") + "  " + CurVerison +
                            " for OpenCore " + ocVer);
  else
    ui->lblVersion->setText(tr("Version") + "  " + CurVerison +
                            " for OpenCore " + ocVerDev);
  QFont font;
  font.setBold(true);
  font.setPixelSize(25);
  ui->lblOCAT->setFont(font);
}

aboutDialog::~aboutDialog() { delete ui; }

void aboutDialog::initInfoStr() {}
