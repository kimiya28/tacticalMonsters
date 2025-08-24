#include "playinggamewindow.h"
#include "classes.h"
#include "ui_playinggamewindow.h"
#include "QDebug"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QPainter"
#include "QPolygon"
#include "QRegion"
#include "QPainterPath"
#include "cmath"
#include "string"
#include <QDir>
#include <QRandomGenerator>

using namespace std;

int playerRound = 1;
int roundCounter = 0;
string attacker = "";
bool targetSelection = false;
bool agentSelector = true;
bool pl1_ag1_clicked = false;
bool pl1_ag2_clicked = false;
bool pl1_ag3_clicked = false;
bool pl1_ag4_clicked = false;

bool pl2_ag1_clicked = false;
bool pl2_ag2_clicked = false;
bool pl2_ag3_clicked = false;
bool pl2_ag4_clicked = false;

bool pl1_ag1_selected = true;
bool pl1_ag2_selected = true;
bool pl1_ag3_selected = true;
bool pl1_ag4_selected = true;

bool pl2_ag1_selected = true;
bool pl2_ag2_selected = true;
bool pl2_ag3_selected = true;
bool pl2_ag4_selected = true;

WaterWalking Billy1(320, 3, 90, 1);
WaterWalking Reketon1(320, 2, 80, 2);
WaterWalking Angus1(400, 2, 100, 1);
WaterWalking Duraham1(320, 2, 100, 2);

WaterWalking Billy2(320, 3, 90, 1);
WaterWalking Reketon2(320, 2, 80, 2);
WaterWalking Angus2(400, 2, 100, 1);
WaterWalking Duraham2(320, 2, 100, 2);

struct hexagon {
    int centerX;
    int centerY;
    int row = 0;
    int col = 0;
    string id;
    string color;
    string bgPath;
    hexagon* top = nullptr;
    hexagon* bottom = nullptr;
    hexagon* topRight = nullptr;
    hexagon* topLeft = nullptr;
    hexagon* bottomRight = nullptr;
    hexagon* bottomLeft = nullptr;
};

hexagon hexa[41];
QPushButton* hexButton[41];


playingGameWindow::playingGameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::playingGameWindow)
{
    ui->setupUi(this);

}

QPolygonF playingGameWindow::createHexagon(QPointF center, double size){
    QPolygonF hex;
    for(int i = 0; i < 6; i++){
        double angle = M_PI / 3.0 * i;
        hex << QPointF(center.x() + size * std::cos(angle), center.y() + size * std::sin(angle));
    }
    return hex;
}

//متد انتخاب پوشه نقشه ها
void playingGameWindow::openFile()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, "Select Directory Containing Map Files", "", QFileDialog::ShowDirsOnly);

    if (dirPath.isEmpty()) {
        qDebug() << "No directory selected";
        return;
    }

    QDir directory(dirPath);

    QStringList filters;
    filters << "*.txt";
    directory.setNameFilters(filters);

    // لیست تمام فایلهای داخل پوشه
    QStringList txtFiles = directory.entryList(QDir::Files);

    if (txtFiles.isEmpty()) {
        qDebug() << "No .txt files found in the directory";
        return;
    }

    // انتخاب تصادفی یک فایل از لیست
    int randomIndex = QRandomGenerator::global()->bounded(txtFiles.size());
    QString selectedFile = txtFiles.at(randomIndex);
    QString filePath = directory.filePath(selectedFile);

    qDebug() << "Randomly selected file:" << filePath;

    // باز کردن فایل انتخاب‌شده
    QFile mapFile(filePath);
    if (!mapFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open the file:" << filePath;
        return;
    }

    QTextStream txtStream(&mapFile);
    int hexCount = 0;
    string id;
    int row = 0;
    int width = 960;
    int height = 540;
    int hexSize = 40;
    double hexHeight = sqrt(3) * hexSize;

    while(!txtStream.atEnd()){
        int col = 0;
        int position = 0;
        QString line = txtStream.readLine();
        while(position < line.length() - 3){
            if(line[position] == "/"){
                double offset = 0;
                if(row % 2 != 0)
                    offset = 1.5;
                hexa[hexCount].centerX = ((col * 3) - offset) * hexSize + (width / 3.2);
                hexa[hexCount].centerY = row * (hexHeight / 2) + height / 6;
                if(line[position + 1] == " "){
                    id = ".";
                    hexa[hexCount].bgPath = ":/src/images/ground.jpg";
                    position = position + 3;
                    col += 1;
                }
                else if(line[position + 1] == "1"){
                    id = "1";
                    hexa[hexCount].bgPath = ":/src/images/ground.jpg";
                    position = position + 3;
                    col += 1;
                }
                else if(line[position + 1] == "2"){
                    id = "2";
                    hexa[hexCount].bgPath = ":/src/images/ground.jpg";
                    position = position + 3;
                    col += 1;
                }
                else if(line[position + 1] == "~"){
                    id = "~";
                    hexa[hexCount].bgPath = ":/src/images/water.jpg";
                    position = position + 3;
                    col += 1;
                }
                else if(line[position + 1] == "#"){
                    id = "#";
                    hexa[hexCount].bgPath = ":/src/images/stone.jpg";
                    position = position + 3;
                    col += 1;
                }
                hexa[hexCount].id = id;
                createHexButton(hexCount);
                qDebug()<< row << col << hexCount;
                hexa[hexCount].row = row;
                hexa[hexCount].col = col;
                hexCount ++;
            }
            position++;
        }
        row++;
        col = 0;
        if(row == 10)
            break;
    }

    mapFile.close();
    connectNeighbors(hexCount);
}
void playingGameWindow::connectNeighbors(int hexCount) {
    for (int i = 0; i < hexCount; i++) {
        int r = hexa[i].row;
        int c = hexa[i].col;

        for (int j = 0; j < hexCount; j++) {
            if (i == j) continue;

            int jr = hexa[j].row;
            int jc = hexa[j].col;

            // بالا و پایین
            if (jr == r - 2 && jc == c)
                hexa[i].top = &hexa[j];
            else if (jr == r + 2 && jc == c)
                hexa[i].bottom = &hexa[j];

            // گوشه‌ها بسته به زوج/فرد بودن ردیف
            if (r % 2 == 0) {
                if (jr == r - 1 && jc == c) hexa[i].topLeft = &hexa[j];
                if (jr == r - 1 && jc == c + 1)     hexa[i].topRight = &hexa[j];
                if (jr == r + 1 && jc == c) hexa[i].bottomLeft = &hexa[j];
                if (jr == r + 1 && jc == c + 1)     hexa[i].bottomRight = &hexa[j];
            } else {
                if (jr == r - 1 && jc == c - 1)     hexa[i].topLeft = &hexa[j];
                if (jr == r - 1 && jc == c) hexa[i].topRight = &hexa[j];
                if (jr == r + 1 && jc == c - 1)     hexa[i].bottomLeft = &hexa[j];
                if (jr == r + 1 && jc == c) hexa[i].bottomRight = &hexa[j];
            }
        }
    }
}

void playingGameWindow::createHexButton(int index){
    double hexSize = 40;
    QPushButton* button = new QPushButton(this);
    button->setFixedSize(2 * hexSize, 2 * hexSize);

    QPolygon hex;
    QPoint center(hexSize, hexSize);
    for(int i = 0; i < 6; i++){
        double angle = M_PI / 3 * i;
        hex << QPoint(center.x() + hexSize * cos(angle), center.y() + hexSize * sin(angle));
    }

    QPixmap hexPixmap(button->size());
    hexPixmap.fill(Qt::transparent);

    QPainter painter(&hexPixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addPolygon(hex);
    painter.setClipPath(path);

    QPixmap bg(QString::fromStdString(hexa[index].bgPath));
    painter.drawPixmap(button->rect(), bg);

    painter.end();

    button->setIcon(QIcon(hexPixmap));
    button->setIconSize(button->size());

    QRegion mask(path.toFillPolygon().toPolygon());
    button->setMask(mask);

    button->setStyleSheet("QPushButton {"
                          "border: none;"
                          "background: transparent;"
                          "}"
                          );

    button->move(hexa[index].centerX - hexSize, hexa[index].centerY - hexSize);

    connect(button, &QPushButton::clicked, [this, index]() {
        hexagonClicked(index);
    });

    hexButton[index] = button;
    button->show();
}
// متد کلیک روی شش ضلعی
void playingGameWindow::hexagonClicked(int index){
    if(playerRound == 1){
        if(hexa[index].id == "1" && (pl1_ag1_clicked || pl1_ag2_clicked || pl1_ag3_clicked || pl1_ag4_clicked)){
            ui->messageBox->setText(QString("You cliked on hex %1 with id %2")
                                        .arg(index)
                                        .arg(QString::fromStdString(hexa[index].id)));

            for(int i = 0; i < 41; i++){
                if(hexa[i].bgPath == ":/src/images/select_ground.jpg") {
                    hexa[i].bgPath = ":/src/images/ground.jpg";
                    QPixmap pixmap(hexButton[i]->size());
                    pixmap.fill(Qt::transparent);

                    QPainter painter(&pixmap);
                    painter.setRenderHint(QPainter::Antialiasing);

                    QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                    QPainterPath path;
                    path.addPolygon(hex);
                    painter.setClipPath(path);

                    QPixmap bgPixmap(QString::fromStdString(hexa[i].bgPath));
                    painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                    painter.end();

                    hexButton[i]->setIcon(QIcon(pixmap));
                    hexButton[i]->setIconSize(hexButton[i]->size());
                }
            }
            if(pl1_ag1_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Billy.png";
                pl1_ag1_clicked = false;
            } else if(pl1_ag2_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Reketon.png";
                pl1_ag2_clicked = false;
            } else if(pl1_ag3_clicked){
            hexa[index].bgPath = ":/src/images/Agent/Angus.png";
                pl1_ag3_clicked = false;
            } else if(pl1_ag4_clicked){
            hexa[index].bgPath = ":/src/images/Agent/Duraham.png";
                pl1_ag4_clicked = false;
            }


            QPixmap pixmap(hexButton[index]->size());
            pixmap.fill(Qt::transparent);

            QPainter painter(&pixmap);
            painter.setRenderHint(QPainter::Antialiasing);

            QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
            QPainterPath path;
            path.addPolygon(hex);
            painter.setClipPath(path);

            QPixmap bgPixmap(QString::fromStdString(hexa[index].bgPath));
            painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

            painter.end();

            hexButton[index]->setIcon(QIcon(pixmap));
            hexButton[index]->setIconSize(hexButton[index]->size());

        } else if(hexa[index].id == "1" && hexa[index].bgPath != ":/src/images/ground.jpg"){
            ui->messageBox->setText("now select your target");
            targetSelection = true;
            if(hexa[index].bgPath == ":/src/images/Agent/Billy.png")
                attacker = "Billy1";
            if(hexa[index].bgPath == ":/src/images/Agent/Reketon.png")
                attacker = "Reketon1";
            if(hexa[index].bgPath == ":/src/images/Agent/Angus.png")
                attacker = "Angus1";
            if(hexa[index].bgPath == ":/src/images/Agent/Duraham.png")
                attacker = "Duraham1";
        } else if(hexa[index].id == "2" && hexa[index].bgPath != ":/src/images/ground.jpg" && targetSelection){
            if(hexa[index].bgPath == ":/src/images/Agent/Billy.png"){
                if(attacker == "Billy1"){
                    Billy2.setHP(Billy2.getHP() - Billy1.getDamage());
                    Billy1.setHP(Billy1.getHP() - Billy2.getDamage() / 2);
                    ui->textBrowser->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser->setText("HP: "+QString::number(Billy1.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                    ui->textBrowser_13->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_13->setText("HP: "+QString::number(Billy2.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                }
                if(attacker == "Reketon1"){
                    Billy2.setHP(Billy2.getHP() - Reketon1.getDamage());
                    Reketon1.setHP(Reketon1.getHP() - Billy2.getDamage() / 2);
                    ui->textBrowser_2->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_2->setText("HP: "+QString::number(Reketon1.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                    ui->textBrowser_13->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_13->setText("HP: "+QString::number(Billy2.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");

                }
                if(attacker == "Angus1"){
                    Billy2.setHP(Billy2.getHP() - Angus1.getDamage());
                    Angus1.setHP(Angus1.getHP() - Billy2.getDamage() / 2);
                    ui->textBrowser_3->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_3->setText("HP: "+QString::number(Angus1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                    ui->textBrowser_13->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_13->setText("HP: "+QString::number(Billy2.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");

                }
                if(attacker == "Duraham1"){
                    Billy2.setHP(Billy2.getHP() - Duraham1.getDamage());
                    Duraham1.setHP(Duraham1.getHP() - Billy2.getDamage() / 2);
                    ui->textBrowser_4->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_4->setText("HP: "+QString::number(Duraham1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                    ui->textBrowser_13->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_13->setText("HP: "+QString::number(Billy2.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                }
            }

            if(hexa[index].bgPath == ":/src/images/Agent/Reketon.png"){
                if(attacker == "Billy1"){
                    Reketon2.setHP(Reketon2.getHP() - Billy1.getDamage());
                    Billy1.setHP(Billy1.getHP() - Reketon2.getDamage() / 2);
                    ui->textBrowser->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser->setText("HP: "+QString::number(Billy1.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                    ui->textBrowser_29->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_29->setText("HP: "+QString::number(Reketon2.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                }
                if(attacker == "Reketon1"){
                    Reketon2.setHP(Reketon2.getHP() - Reketon1.getDamage());
                    Reketon1.setHP(Reketon1.getHP() - Reketon2.getDamage() / 2);
                    ui->textBrowser_2->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_2->setText("HP: "+QString::number(Reketon1.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                    ui->textBrowser_29->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_29->setText("HP: "+QString::number(Reketon2.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                }
                if(attacker == "Angus1"){
                    Reketon2.setHP(Reketon2.getHP() - Angus1.getDamage());
                    Angus1.setHP(Angus1.getHP() - Reketon2.getDamage() / 2);
                    ui->textBrowser_3->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_3->setText("HP: "+QString::number(Angus1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                    ui->textBrowser_29->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_29->setText("HP: "+QString::number(Reketon2.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                }
                if(attacker == "Duraham1"){
                    Reketon2.setHP(Reketon2.getHP() - Duraham1.getDamage());
                    Duraham1.setHP(Duraham1.getHP() - Reketon2.getDamage() / 2);
                    ui->textBrowser_4->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_4->setText("HP: "+QString::number(Duraham1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                    ui->textBrowser_29->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_29->setText("HP: "+QString::number(Reketon2.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                }
            }

            if(hexa[index].bgPath == ":/src/images/Agent/Angus.png"){
                if(attacker == "Billy1"){
                    Angus2.setHP(Angus2.getHP() - Billy1.getDamage());
                    Billy1.setHP(Billy1.getHP() - Angus2.getDamage() / 2);
                    ui->textBrowser->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser->setText("HP: "+QString::number(Billy1.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                    ui->textBrowser_30->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_30->setText("HP: "+QString::number(Angus2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                }
                if(attacker == "Reketon1"){
                    Angus2.setHP(Angus2.getHP() - Reketon1.getDamage());
                    Reketon1.setHP(Reketon1.getHP() - Angus2.getDamage() / 2);
                    ui->textBrowser_2->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_2->setText("HP: "+QString::number(Reketon1.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                    ui->textBrowser_30->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_30->setText("HP: "+QString::number(Angus2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                }
                if(attacker == "Angus1"){
                    Angus2.setHP(Angus2.getHP() - Angus1.getDamage());
                    Angus1.setHP(Angus1.getHP() - Angus2.getDamage() / 2);
                    ui->textBrowser_3->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_3->setText("HP: "+QString::number(Angus1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                    ui->textBrowser_30->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_30->setText("HP: "+QString::number(Angus2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                }
                if(attacker == "Duraham1"){
                    Angus2.setHP(Angus2.getHP() - Duraham1.getDamage());
                    Duraham1.setHP(Duraham1.getHP() - Angus2.getDamage() / 2);
                    ui->textBrowser_4->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_4->setText("HP: "+QString::number(Duraham1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                    ui->textBrowser_30->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_30->setText("HP: "+QString::number(Angus2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                }
            }

            if(hexa[index].bgPath == ":/src/images/Agent/Duraham.png"){
                if(attacker == "Billy1"){
                    Duraham2.setHP(Duraham2.getHP() - Billy1.getDamage());
                    Billy1.setHP(Billy1.getHP() - Duraham2.getDamage() / 2);
                    ui->textBrowser->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser->setText("HP: "+QString::number(Billy1.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                    ui->textBrowser_31->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_31->setText("HP: "+QString::number(Duraham2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                }
                if(attacker == "Reketon1"){
                    Duraham2.setHP(Duraham2.getHP() - Reketon1.getDamage());
                    Reketon1.setHP(Reketon1.getHP() - Duraham2.getDamage() / 2);
                    ui->textBrowser_2->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_2->setText("HP: "+QString::number(Reketon1.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                    ui->textBrowser_31->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_31->setText("HP: "+QString::number(Duraham2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                }
                if(attacker == "Angus1"){
                    Duraham2.setHP(Duraham2.getHP() - Angus1.getDamage());
                    Angus1.setHP(Angus1.getHP() - Duraham2.getDamage() / 2);
                    ui->textBrowser_3->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_3->setText("HP: "+QString::number(Angus1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                    ui->textBrowser_31->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_31->setText("HP: "+QString::number(Duraham2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                }
                if(attacker == "Duraham1"){
                    Duraham2.setHP(Duraham2.getHP() - Duraham1.getDamage());
                    Duraham1.setHP(Duraham1.getHP() - Duraham2.getDamage() / 2);
                    ui->textBrowser_4->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_4->setText("HP: "+QString::number(Duraham1.getHP())+"\nMobility: 2\nDamage: 110\nAttackRange: 2");
                    ui->textBrowser_31->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                    ui->textBrowser_31->setText("HP: "+QString::number(Duraham2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                }
            }
            targetSelection = false;
            playerRound = 2 ;
        }

    } else if(playerRound == 2){
            if(hexa[index].id == "2" && (pl2_ag1_clicked || pl2_ag2_clicked || pl2_ag3_clicked || pl2_ag4_clicked)){
                ui->messageBox->setText(QString("You cliked on hex %1 with id %2")
                                            .arg(index)
                                            .arg(QString::fromStdString(hexa[index].id)));

                for(int i = 0; i < 41; i++){
                    if(hexa[i].bgPath == ":/src/images/select_ground.jpg") {
                        hexa[i].bgPath = ":/src/images/ground.jpg";
                        QPixmap pixmap(hexButton[i]->size());
                        pixmap.fill(Qt::transparent);

                        QPainter painter(&pixmap);
                        painter.setRenderHint(QPainter::Antialiasing);

                        QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                        QPainterPath path;
                        path.addPolygon(hex);
                        painter.setClipPath(path);

                        QPixmap bgPixmap(QString::fromStdString(hexa[i].bgPath));
                        painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                        painter.end();

                        hexButton[i]->setIcon(QIcon(pixmap));
                        hexButton[i]->setIconSize(hexButton[i]->size());
                    }
                }
                if(pl2_ag1_clicked){
                    hexa[index].bgPath = ":/src/images/Agent/Billy.png";
                    pl2_ag1_clicked = false;
                } else if(pl2_ag2_clicked){
                    hexa[index].bgPath = ":/src/images/Agent/Reketon.png";
                    pl2_ag2_clicked = false;
                } else if(pl2_ag3_clicked){
                    hexa[index].bgPath = ":/src/images/Agent/Angus.png";
                    pl2_ag3_clicked = false;
                } else if(pl2_ag4_clicked){
                    hexa[index].bgPath = ":/src/images/Agent/Duraham.png";
                    pl2_ag4_clicked = false;
                }


                QPixmap pixmap(hexButton[index]->size());
                pixmap.fill(Qt::transparent);

                QPainter painter(&pixmap);
                painter.setRenderHint(QPainter::Antialiasing);

                QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                QPainterPath path;
                path.addPolygon(hex);
                painter.setClipPath(path);

                QPixmap bgPixmap(QString::fromStdString(hexa[index].bgPath));
                painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                painter.end();

                hexButton[index]->setIcon(QIcon(pixmap));
                hexButton[index]->setIconSize(hexButton[index]->size());

            }  else if(hexa[index].id == "2" && hexa[index].bgPath != ":/src/images/ground.jpg"){
                ui->messageBox->setText("now select your target");
                targetSelection = true;
                if(hexa[index].bgPath == ":/src/images/Agent/Billy.png")
                    attacker = "Billy2";
                if(hexa[index].bgPath == ":/src/images/Agent/Reketon.png")
                    attacker = "Reketon2";
                if(hexa[index].bgPath == ":/src/images/Agent/Angus.png")
                    attacker = "Angus2";
                if(hexa[index].bgPath == ":/src/images/Agent/Duraham.png")
                    attacker = "Duraham2";
            } else if(hexa[index].id == "1" && hexa[index].bgPath != ":/src/images/ground.jpg" && targetSelection){
                if(hexa[index].bgPath == ":/src/images/Agent/Billy.png"){
                    if(attacker == "Billy2"){
                        Billy1.setHP(Billy1.getHP() - Billy2.getDamage());
                        Billy2.setHP(Billy2.getHP() - Billy1.getDamage() / 2);
                        ui->textBrowser_13->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_13->setText("HP: "+QString::number(Billy2.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                        ui->textBrowser->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser->setText("HP: "+QString::number(Billy1.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                    }
                    if(attacker == "Reketon2"){
                        Billy1.setHP(Billy1.getHP() - Reketon2.getDamage());
                        Reketon2.setHP(Reketon2.getHP() - Billy1.getDamage() / 2);
                        ui->textBrowser_29->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_29->setText("HP: "+QString::number(Reketon2.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                        ui->textBrowser->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser->setText("HP: "+QString::number(Billy1.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");

                    }
                    if(attacker == "Angus2"){
                        Billy1.setHP(Billy1.getHP() - Angus2.getDamage());
                        Angus2.setHP(Angus2.getHP() - Billy1.getDamage() / 2);
                        ui->textBrowser_30->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_30->setText("HP: "+QString::number(Angus2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                        ui->textBrowser->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser->setText("HP: "+QString::number(Billy1.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");

                    }
                    if(attacker == "Duraham2"){
                        Billy1.setHP(Billy1.getHP() - Duraham2.getDamage());
                        Duraham2.setHP(Duraham2.getHP() - Billy1.getDamage() / 2);
                        ui->textBrowser_31->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_31->setText("HP: "+QString::number(Duraham2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                        ui->textBrowser->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser->setText("HP: "+QString::number(Billy1.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                    }
                }

                if(hexa[index].bgPath == ":/src/images/Agent/Reketon.png"){
                    if(attacker == "Billy2"){
                        Reketon1.setHP(Reketon1.getHP() - Billy2.getDamage());
                        Billy2.setHP(Billy2.getHP() - Reketon1.getDamage() / 2);
                        ui->textBrowser_13->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_13->setText("HP: "+QString::number(Billy2.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                        ui->textBrowser_2->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_2->setText("HP: "+QString::number(Reketon1.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                    }
                    if(attacker == "Reketon2"){
                        Reketon1.setHP(Reketon1.getHP() - Reketon2.getDamage());
                        Reketon2.setHP(Reketon2.getHP() - Reketon1.getDamage() / 2);
                        ui->textBrowser_29->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_29->setText("HP: "+QString::number(Reketon2.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                        ui->textBrowser_2->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_2->setText("HP: "+QString::number(Reketon1.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                    }
                    if(attacker == "Angus2"){
                        Reketon1.setHP(Reketon1.getHP() - Angus2.getDamage());
                        Angus2.setHP(Angus2.getHP() - Reketon1.getDamage() / 2);
                        ui->textBrowser_30->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_30->setText("HP: "+QString::number(Angus2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                        ui->textBrowser_2->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_2->setText("HP: "+QString::number(Reketon1.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                    }
                    if(attacker == "Duraham2"){
                        Reketon1.setHP(Reketon1.getHP() - Duraham2.getDamage());
                        Duraham2.setHP(Duraham2.getHP() - Reketon1.getDamage() / 2);
                        ui->textBrowser_31->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_31->setText("HP: "+QString::number(Duraham2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                        ui->textBrowser_2->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_2->setText("HP: "+QString::number(Reketon1.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                    }
                }

                if(hexa[index].bgPath == ":/src/images/Agent/Angus.png"){
                    if(attacker == "Billy2"){
                        Angus1.setHP(Angus1.getHP() - Billy2.getDamage());
                        Billy2.setHP(Billy2.getHP() - Angus1.getDamage() / 2);
                        ui->textBrowser_13->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_13->setText("HP: "+QString::number(Billy2.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                        ui->textBrowser_3->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_3->setText("HP: "+QString::number(Angus1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                    }
                    if(attacker == "Reketon2"){
                        Angus1.setHP(Angus1.getHP() - Reketon2.getDamage());
                        Reketon2.setHP(Reketon2.getHP() - Angus1.getDamage() / 2);
                        ui->textBrowser_29->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_29->setText("HP: "+QString::number(Reketon2.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                        ui->textBrowser_3->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_3->setText("HP: "+QString::number(Angus1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                    }
                    if(attacker == "Angus2"){
                        Angus1.setHP(Angus1.getHP() - Angus2.getDamage());
                        Angus2.setHP(Angus2.getHP() - Angus1.getDamage() / 2);
                        ui->textBrowser_30->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_30->setText("HP: "+QString::number(Angus2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                        ui->textBrowser_3->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_3->setText("HP: "+QString::number(Angus1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                    }
                    if(attacker == "Duraham2"){
                        Angus1.setHP(Angus1.getHP() - Duraham2.getDamage());
                        Duraham2.setHP(Duraham2.getHP() - Angus1.getDamage() / 2);
                        ui->textBrowser_31->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_31->setText("HP: "+QString::number(Duraham2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                        ui->textBrowser_3->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_3->setText("HP: "+QString::number(Angus1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                    }
                }

                if(hexa[index].bgPath == ":/src/images/Agent/Duraham.png"){
                    if(attacker == "Billy2"){
                        Duraham1.setHP(Duraham1.getHP() - Billy2.getDamage());
                        Billy2.setHP(Billy2.getHP() - Duraham1.getDamage() / 2);
                        ui->textBrowser_13->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_13->setText("HP: "+QString::number(Billy2.getHP())+"\nMobility: 3\nDamage: 90\nAttackRange: 1");
                        ui->textBrowser_4->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_4->setText("HP: "+QString::number(Duraham1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                    }
                    if(attacker == "Reketon2"){
                        Duraham1.setHP(Duraham1.getHP() - Reketon2.getDamage());
                        Reketon2.setHP(Reketon2.getHP() - Duraham1.getDamage() / 2);
                        ui->textBrowser_29->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_29->setText("HP: "+QString::number(Reketon2.getHP())+"\nMobility: 2\nDamage: 80\nAttackRange: 2");
                        ui->textBrowser_4->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_4->setText("HP: "+QString::number(Duraham1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                    }
                    if(attacker == "Angus2"){
                        Duraham1.setHP(Duraham1.getHP() - Angus2.getDamage());
                        Angus2.setHP(Angus2.getHP() - Duraham1.getDamage() / 2);
                        ui->textBrowser_30->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_30->setText("HP: "+QString::number(Angus2.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 1");
                        ui->textBrowser_4->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_4->setText("HP: "+QString::number(Duraham1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                    }
                    if(attacker == "Duraham2"){
                        Duraham1.setHP(Duraham1.getHP() - Duraham2.getDamage());
                        Duraham2.setHP(Duraham2.getHP() - Duraham1.getDamage() / 2);
                        ui->textBrowser_31->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_31->setText("HP: "+QString::number(Duraham2.getHP())+"\nMobility: 2\nDamage: 110\nAttackRange: 2");
                        ui->textBrowser_4->setStyleSheet("font-size:6pt;""color:white;""font-weight:bold;");
                        ui->textBrowser_4->setText("HP: "+QString::number(Duraham1.getHP())+"\nMobility: 2\nDamage: 100\nAttackRange: 2");
                    }
                }
                targetSelection = false;
                playerRound = 1 ;
            }

    }
    roundCounter++;
    if(roundCounter == 4)
        playerRound = 2;
    if(roundCounter == 8){
        playerRound = 1;
        agentSelector = false;
    }
}




playingGameWindow::~playingGameWindow()
{

    delete ui;
}




void playingGameWindow::on_pl1_ag1_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag1_selected){
        pl1_ag1_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";


                QPixmap pixmap(hexButton[i]->size());
                pixmap.fill(Qt::transparent);

                QPainter painter(&pixmap);
                painter.setRenderHint(QPainter::Antialiasing);

                QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                QPainterPath path;
                path.addPolygon(hex);
                painter.setClipPath(path);

                QPixmap bgPixmap(QString::fromStdString(hexa[i].bgPath));
                painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                painter.end();

                hexButton[i]->setIcon(QIcon(pixmap));
                hexButton[i]->setIconSize(hexButton[i]->size());

            }
        }
        pl1_ag1_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag1_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag2_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag2_selected){
        pl1_ag2_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";


                QPixmap pixmap(hexButton[i]->size());
                pixmap.fill(Qt::transparent);

                QPainter painter(&pixmap);
                painter.setRenderHint(QPainter::Antialiasing);

                QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                QPainterPath path;
                path.addPolygon(hex);
                painter.setClipPath(path);

                QPixmap bgPixmap(QString::fromStdString(hexa[i].bgPath));
                painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                painter.end();

                hexButton[i]->setIcon(QIcon(pixmap));
                hexButton[i]->setIconSize(hexButton[i]->size());

            }
        }
        pl1_ag2_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag2_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag3_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag3_selected){
        pl1_ag3_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";


                QPixmap pixmap(hexButton[i]->size());
                pixmap.fill(Qt::transparent);

                QPainter painter(&pixmap);
                painter.setRenderHint(QPainter::Antialiasing);

                QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                QPainterPath path;
                path.addPolygon(hex);
                painter.setClipPath(path);

                QPixmap bgPixmap(QString::fromStdString(hexa[i].bgPath));
                painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                painter.end();

                hexButton[i]->setIcon(QIcon(pixmap));
                hexButton[i]->setIconSize(hexButton[i]->size());

            }
        }
        pl1_ag3_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag3_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag4_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag4_selected){
        pl1_ag4_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";


                QPixmap pixmap(hexButton[i]->size());
                pixmap.fill(Qt::transparent);

                QPainter painter(&pixmap);
                painter.setRenderHint(QPainter::Antialiasing);

                QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                QPainterPath path;
                path.addPolygon(hex);
                painter.setClipPath(path);

                QPixmap bgPixmap(QString::fromStdString(hexa[i].bgPath));
                painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                painter.end();

                hexButton[i]->setIcon(QIcon(pixmap));
                hexButton[i]->setIconSize(hexButton[i]->size());

            }
        }
        pl1_ag4_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag4_selected)
            ui->messageBox->setText("already selected");
        else
             ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag1_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag1_selected){
        pl2_ag1_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";


                QPixmap pixmap(hexButton[i]->size());
                pixmap.fill(Qt::transparent);

                QPainter painter(&pixmap);
                painter.setRenderHint(QPainter::Antialiasing);

                QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                QPainterPath path;
                path.addPolygon(hex);
                painter.setClipPath(path);

                QPixmap bgPixmap(QString::fromStdString(hexa[i].bgPath));
                painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                painter.end();

                hexButton[i]->setIcon(QIcon(pixmap));
                hexButton[i]->setIconSize(hexButton[i]->size());

            }
        }
        pl2_ag1_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag1_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag2_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag2_selected){
        pl2_ag2_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";


                QPixmap pixmap(hexButton[i]->size());
                pixmap.fill(Qt::transparent);

                QPainter painter(&pixmap);
                painter.setRenderHint(QPainter::Antialiasing);

                QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                QPainterPath path;
                path.addPolygon(hex);
                painter.setClipPath(path);

                QPixmap bgPixmap(QString::fromStdString(hexa[i].bgPath));
                painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                painter.end();

                hexButton[i]->setIcon(QIcon(pixmap));
                hexButton[i]->setIconSize(hexButton[i]->size());

            }
        }
        pl2_ag2_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag2_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag3_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag3_selected){
        pl2_ag3_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";


                QPixmap pixmap(hexButton[i]->size());
                pixmap.fill(Qt::transparent);

                QPainter painter(&pixmap);
                painter.setRenderHint(QPainter::Antialiasing);

                QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                QPainterPath path;
                path.addPolygon(hex);
                painter.setClipPath(path);

                QPixmap bgPixmap(QString::fromStdString(hexa[i].bgPath));
                painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                painter.end();

                hexButton[i]->setIcon(QIcon(pixmap));
                hexButton[i]->setIconSize(hexButton[i]->size());

            }
        }
        pl2_ag3_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag3_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag4_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag4_selected){
        pl2_ag4_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";


                QPixmap pixmap(hexButton[i]->size());
                pixmap.fill(Qt::transparent);

                QPainter painter(&pixmap);
                painter.setRenderHint(QPainter::Antialiasing);

                QPolygonF hex = createHexagon(QPointF(pixmap.width() / 2, pixmap.height() / 2), 48);
                QPainterPath path;
                path.addPolygon(hex);
                painter.setClipPath(path);

                QPixmap bgPixmap(QString::fromStdString(hexa[i].bgPath));
                painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());

                painter.end();

                hexButton[i]->setIcon(QIcon(pixmap));
                hexButton[i]->setIconSize(hexButton[i]->size());

            }
        }
        pl2_ag4_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag4_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}

