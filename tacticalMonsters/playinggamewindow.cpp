#include "playinggamewindow.h"
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

using namespace std;

int playerRound = 1;
bool pl1_ag1_clicked = false;
bool pl1_ag2_clicked = false;

struct hexagon {
    int centerX;
    int centerY;
    string id;
    string color;
    string bgPath;
};

hexagon hexa[41];
QPushButton* hexButton[41];


playingGameWindow::playingGameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::playingGameWindow)
{
    ui->setupUi(this);
    /*ui->pl1_ag1->setStyleSheet(
        "#pl1_ag1{"
        "border-image:url(:/src/images/agent1.png) 0 0 0 0 stretch stretch;"
        "border-radius:12px;"
        "}"
    );
    ui->pl1_ag2->setStyleSheet(
        "#pl1_ag2{"
        "border-image:url(:/src/images/agent2.jpg) 0 0 0 0 stretch stretch;"
        "border-radius:12px;"
        "}"
        );*/
}

QPolygonF playingGameWindow::createHexagon(QPointF center, double size){
    QPolygonF hex;
    for(int i = 0; i < 6; i++){
        double angle = M_PI / 3.0 * i;
        hex << QPointF(center.x() + size * std::cos(angle), center.y() + size * std::sin(angle));
    }
    return hex;
}
void playingGameWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Map File", "", "Map File(*.txt)");
    QFile mapFile(fileName);
    mapFile.open(QIODevice::ReadOnly | QIODevice::Text);
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
                hexCount ++;

            }
            position++;
        }
        row++;
        if(row == 10)
            break;
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

void playingGameWindow::hexagonClicked(int index){
    if(playerRound == 1){
        if(hexa[index].id == "1" && (pl1_ag1_clicked || pl1_ag2_clicked)){
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
                hexa[index].bgPath = ":/src/images/agent1.png";
            } else if(pl1_ag2_clicked){
                hexa[index].bgPath = ":/src/images/agent2.jpg";
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

        } else{
            //click invalid hex
        }

    } else {
        ui->messageBox->setText("It's not your turn");
    }
}

void playingGameWindow::on_pl1_ag1_clicked(){
    if(playerRound == 1){
        pl1_ag1_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1"){
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

        ui->messageBox->setText("Select Hex On The Map");
    } else {
        ui->messageBox->setText("It's Not Your Turn");
    }
}

void playingGameWindow::on_pl1_ag2_clicked()
{
    if(playerRound == 1){
        pl1_ag2_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1"){
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

        ui->messageBox->setText("Select Hex On The Map");
    } else {
        ui->messageBox->setText("It's Not Your Turn");
    }
}

playingGameWindow::~playingGameWindow()
{

    delete ui;
}



