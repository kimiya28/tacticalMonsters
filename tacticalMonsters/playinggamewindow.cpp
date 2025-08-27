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
#include <queue>
#include <vector>

using namespace std;

int playerRound = 1;
int roundCounter = 0;
int startHex ;
int targetIndex ;
string attacker = "";
bool startSelection = true;
bool targetSelection = false;
bool agentSelector = true;
bool pl1_ag1_clicked = false;
bool pl1_ag2_clicked = false;
bool pl1_ag3_clicked = false;
bool pl1_ag4_clicked = false;
bool pl1_ag5_clicked = false;
bool pl1_ag6_clicked = false;
bool pl1_ag7_clicked = false;
bool pl1_ag8_clicked = false;
bool pl1_ag9_clicked = false;
bool pl1_ag10_clicked = false;
bool pl1_ag11_clicked = false;
bool pl1_ag12_clicked = false;
bool pl1_ag13_clicked = false;
bool pl1_ag14_clicked = false;
bool pl1_ag15_clicked = false;
bool pl1_ag16_clicked = false;
bool pl1_ag17_clicked = false;
bool pl1_ag18_clicked = false;
bool pl1_ag19_clicked = false;
bool pl1_ag20_clicked = false;
bool pl1_ag21_clicked = false;
bool pl1_ag22_clicked = false;
bool pl1_ag23_clicked = false;
bool pl1_ag24_clicked = false;

bool pl2_ag1_clicked = false;
bool pl2_ag2_clicked = false;
bool pl2_ag3_clicked = false;
bool pl2_ag4_clicked = false;
bool pl2_ag5_clicked = false;
bool pl2_ag6_clicked = false;
bool pl2_ag7_clicked = false;
bool pl2_ag8_clicked = false;
bool pl2_ag9_clicked = false;
bool pl2_ag10_clicked = false;
bool pl2_ag11_clicked = false;
bool pl2_ag12_clicked = false;
bool pl2_ag13_clicked = false;
bool pl2_ag14_clicked = false;
bool pl2_ag15_clicked = false;
bool pl2_ag16_clicked = false;
bool pl2_ag17_clicked = false;
bool pl2_ag18_clicked = false;
bool pl2_ag19_clicked = false;
bool pl2_ag20_clicked = false;
bool pl2_ag21_clicked = false;
bool pl2_ag22_clicked = false;
bool pl2_ag23_clicked = false;
bool pl2_ag24_clicked = false;

bool pl1_ag1_selected = true;
bool pl1_ag2_selected = true;
bool pl1_ag3_selected = true;
bool pl1_ag4_selected = true;
bool pl1_ag5_selected = true;
bool pl1_ag6_selected = true;
bool pl1_ag7_selected = true;
bool pl1_ag8_selected = true;
bool pl1_ag9_selected = true;
bool pl1_ag10_selected = true;
bool pl1_ag11_selected = true;
bool pl1_ag12_selected = true;
bool pl1_ag13_selected = true;
bool pl1_ag14_selected = true;
bool pl1_ag15_selected = true;
bool pl1_ag16_selected = true;
bool pl1_ag17_selected = true;
bool pl1_ag18_selected = true;
bool pl1_ag19_selected = true;
bool pl1_ag20_selected = true;
bool pl1_ag21_selected = true;
bool pl1_ag22_selected = true;
bool pl1_ag23_selected = true;
bool pl1_ag24_selected = true;


bool pl2_ag1_selected = true;
bool pl2_ag2_selected = true;
bool pl2_ag3_selected = true;
bool pl2_ag4_selected = true;
bool pl2_ag5_selected = true;
bool pl2_ag6_selected = true;
bool pl2_ag7_selected = true;
bool pl2_ag8_selected = true;
bool pl2_ag9_selected = true;
bool pl2_ag10_selected = true;
bool pl2_ag11_selected = true;
bool pl2_ag12_selected = true;
bool pl2_ag13_selected = true;
bool pl2_ag14_selected = true;
bool pl2_ag15_selected = true;
bool pl2_ag16_selected = true;
bool pl2_ag17_selected = true;
bool pl2_ag18_selected = true;
bool pl2_ag19_selected = true;
bool pl2_ag20_selected = true;
bool pl2_ag21_selected = true;
bool pl2_ag22_selected = true;
bool pl2_ag23_selected = true;
bool pl2_ag24_selected = true;

WaterWalking Billy1(320, 3, 90, 1,true,true,false,false);
WaterWalking Reketon1(320, 2, 80, 2,true,true,false,false);
WaterWalking Angus1(400, 2, 100, 1,true,true,false,false);
WaterWalking Duraham1(320, 2, 100, 2,true,true,false,false);
WaterWalking ColonelBaba1(400, 2, 100, 1,true,true,false,false);
WaterWalking Medusa1(320, 2, 90, 2,true,true,false,false);
WaterWalking Bunka1(320, 3, 100, 1,true,true,false,false);
WaterWalking Sanka1(320, 3, 100, 1,true,true,false,false);
Grounded SirLamorak1(320, 3, 110, 1,false,false,false,false);
Grounded Kabu1(400, 2, 120, 1,false,false,false,false);
Grounded Rajakal1(320, 2, 130, 1,false,false,false,false);
Grounded Salih1(400, 2, 80, 1,false,false,false,false);
Grounded Khan1(320, 2, 90, 1,false,false,false,false);
Grounded Boi1(400, 2, 100, 1,false,false,false,false);
Grounded Eloi1(240, 2, 100, 3,false,false,false,false);
Grounded Kanar1(160, 2, 100, 2,false,false,false,false);
Grounded Elsa1(320, 2, 140, 2,false,false,false,false);
Grounded Karissa1(280, 2, 80, 2,false,false,false,false);
Grounded SirPhilip1(400, 2, 100, 1,false,false,false,false);
Grounded Frost1(260, 2, 80, 2,false,false,false,false);
Grounded Tusk1(400, 2, 100, 1,false,false,false,false);
Flying Rambu1(320, 3, 120, 1,true,false,true,false);
Floating Sabrina1(320, 3, 100, 1,true,true,true,true);
Floating Death1(240, 3, 120, 2,true,true,true,true);


WaterWalking Billy2(320, 3, 90, 1,true,true,false,false);
WaterWalking Reketon2(320, 2, 80, 2,true,true,false,false);
WaterWalking Angus2(400, 2, 100, 1,true,true,false,false);
WaterWalking Duraham2(320, 2, 100, 2,true,true,false,false);
WaterWalking ColonelBaba2(400, 2, 100, 1,true,true,false,false);
WaterWalking Medusa2(320, 2, 90, 2,true,true,false,false);
WaterWalking Bunka2(320, 3, 100, 1,true,true,false,false);
WaterWalking Sanka2(320, 3, 100, 1,true,true,false,false);
Grounded SirLamorak2(320, 3, 110, 1,false,false,false,false);
Grounded Kabu2(400, 2, 120, 1,false,false,false,false);
Grounded Rajakal2(320, 2, 130, 1,false,false,false,false);
Grounded Salih2(400, 2, 80, 1,false,false,false,false);
Grounded Khan2(320, 2, 90, 1,false,false,false,false);
Grounded Boi2(400, 2, 100, 1,false,false,false,false);
Grounded Eloi2(240, 2, 100, 3,false,false,false,false);
Grounded Kanar2(160, 2, 100, 2,false,false,false,false);
Grounded Elsa2(320, 2, 140, 2,false,false,false,false);
Grounded Karissa2(280, 2, 80, 2,false,false,false,false);
Grounded SirPhilip2(400, 2, 100, 1,false,false,false,false);
Grounded Frost2(260, 2, 80, 2,false,false,false,false);
Grounded Tusk2(400, 2, 100, 1,false,false,false,false);
Flying Rambu2(320, 3, 120, 1,true,false,true,false);
Floating Sabrina2(320, 3, 100, 1,true,true,true,true);
Floating Death2(240, 3, 120, 2,true,true,true,true);



struct hexagon {
    int centerX;
    int centerY;
    int row = 0;
    int col = 0;
    int bfsLevel;
    bool visited;
    bool walkable;
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
    findNeighbors();
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
        if(hexa[index].id == "1" && (pl1_ag1_clicked || pl1_ag2_clicked || pl1_ag3_clicked || pl1_ag4_clicked
                                    || pl1_ag5_clicked || pl1_ag6_clicked || pl1_ag7_clicked || pl1_ag8_clicked
                                    || pl1_ag9_clicked || pl1_ag10_clicked || pl1_ag11_clicked || pl1_ag12_clicked
                                    || pl1_ag13_clicked || pl1_ag14_clicked || pl1_ag15_clicked || pl1_ag16_clicked
                                    || pl1_ag17_clicked || pl1_ag18_clicked || pl1_ag19_clicked || pl1_ag20_clicked
                                    || pl1_ag21_clicked || pl1_ag22_clicked || pl1_ag23_clicked || pl1_ag24_clicked)){
            ui->messageBox->setText(QString("You cliked on hex %1 with id %2")
                                        .arg(index)
                                        .arg(QString::fromStdString(hexa[index].id)));

            for(int i = 0; i < 41; i++){
                if(hexa[i].bgPath == ":/src/images/select_ground.jpg") {
                    hexa[i].bgPath = ":/src/images/ground.jpg";

                    updateHexButton(i);

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


            updateHexButton(index);


        } else if(hexa[index].id == "1" && hexa[index].bgPath != ":/src/images/ground.jpg" && startSelection == true){
            ui->messageBox->setText("now select your target");
            targetSelection = true;
            startHex = index ;
            startSelection = false ;

        } else if(startSelection == false && targetSelection == true){


            targetIndex = index ;
            bfsSet(startHex, targetIndex , 41);

            targetSelection = false ;

            playerRound = 2 ;
        }

    } else if(playerRound == 2){
            if(hexa[index].id == "2" && (pl2_ag1_clicked || pl2_ag2_clicked || pl2_ag3_clicked || pl2_ag4_clicked
                                      || pl2_ag5_clicked || pl2_ag6_clicked || pl2_ag7_clicked || pl2_ag8_clicked
                                      || pl2_ag9_clicked || pl2_ag10_clicked || pl2_ag11_clicked || pl2_ag12_clicked
                                      || pl2_ag13_clicked || pl2_ag14_clicked || pl2_ag15_clicked || pl2_ag16_clicked
                                      || pl2_ag17_clicked || pl2_ag18_clicked || pl2_ag19_clicked || pl2_ag20_clicked
                                      || pl2_ag21_clicked || pl2_ag22_clicked || pl2_ag23_clicked || pl2_ag24_clicked)){
                ui->messageBox->setText(QString("You cliked on hex %1 with id %2")
                                            .arg(index)
                                            .arg(QString::fromStdString(hexa[index].id)));

                for(int i = 0; i < 41; i++){
                    if(hexa[i].bgPath == ":/src/images/select_ground.jpg") {
                        hexa[i].bgPath = ":/src/images/ground.jpg";

                        updateHexButton(i);

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


                updateHexButton(index);

            }  else if(hexa[index].id == "2" && hexa[index].bgPath != ":/src/images/ground.jpg"){
                ui->messageBox->setText("now select your target");
                targetSelection = true;






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


void playingGameWindow::bfsSet(int startIndex, int targetIndex, int hexCount) {
    int maxLevel;
    if (startIndex < 0 || startIndex >= hexCount) return;
    if (targetIndex < 0 || targetIndex >= hexCount) return;
    if (startIndex == targetIndex) return;



    if(hexa[startIndex].bgPath == ":/src/images/Agent/Billy.png"){
        maxLevel = Billy1.getMobility();
        bool waterWalking = Billy1.getWaterWalking();
        bool standOnWater = Billy1.getStandOnWater();
        bool rockWalking = Billy1.getRockWalking();
        bool standOnRock = Billy1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Reketon.png"){
        maxLevel = Reketon1.getMobility();
        bool waterWalking = Reketon1.getWaterWalking();
        bool standOnWater = Reketon1.getStandOnWater();
        bool rockWalking = Reketon1.getRockWalking();
        bool standOnRock = Reketon1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Angus.png"){
        maxLevel = Angus1.getMobility();
        bool waterWalking = Angus1.getWaterWalking();
        bool standOnWater = Angus1.getStandOnWater();
        bool rockWalking = Angus1.getRockWalking();
        bool standOnRock = Angus1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Duraham.png"){
        maxLevel = Duraham1.getMobility();
        bool waterWalking = Duraham1.getWaterWalking();
        bool standOnWater = Duraham1.getStandOnWater();
        bool rockWalking = Duraham1.getRockWalking();
        bool standOnRock = Duraham1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Colonel Baba.png"){
        maxLevel = ColonelBaba1.getMobility();
        bool waterWalking = ColonelBaba1.getWaterWalking();
        bool standOnWater = ColonelBaba1.getStandOnWater();
        bool rockWalking = ColonelBaba1.getRockWalking();
        bool standOnRock = ColonelBaba1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Medusa.png"){
        maxLevel = Medusa1.getMobility();
        bool waterWalking = Medusa1.getWaterWalking();
        bool standOnWater = Medusa1.getStandOnWater();
        bool rockWalking = Medusa1.getRockWalking();
        bool standOnRock = Medusa1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Bunka.png"){
        maxLevel = Bunka1.getMobility();
        bool waterWalking = Bunka1.getWaterWalking();
        bool standOnWater = Bunka1.getStandOnWater();
        bool rockWalking = Bunka1.getRockWalking();
        bool standOnRock = Bunka1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sanka.png"){
        maxLevel = Sanka1.getMobility();
        bool waterWalking = Sanka1.getWaterWalking();
        bool standOnWater = Sanka1.getStandOnWater();
        bool rockWalking = Sanka1.getRockWalking();
        bool standOnRock = Sanka1.getStandOnRock();
    }

    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sir Lamorak.png"){
        maxLevel = SirLamorak1.getMobility();
        bool waterWalking = SirLamorak1.getWaterWalking();
        bool standOnWater = SirLamorak1.getStandOnWater();
        bool rockWalking = SirLamorak1.getRockWalking();
        bool standOnRock = SirLamorak1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Kabu.png"){
        maxLevel = Kabu1.getMobility();
        bool waterWalking = Kabu1.getWaterWalking();
        bool standOnWater = Kabu1.getStandOnWater();
        bool rockWalking = Kabu1.getRockWalking();
        bool standOnRock = Kabu1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Rajakal.png"){
        maxLevel = Rajakal1.getMobility();
        bool waterWalking = Rajakal1.getWaterWalking();
        bool standOnWater = Rajakal1.getStandOnWater();
        bool rockWalking = Rajakal1.getRockWalking();
        bool standOnRock = Rajakal1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Salih.png"){
        maxLevel = Salih1.getMobility();
        bool waterWalking = Salih1.getWaterWalking();
        bool standOnWater = Salih1.getStandOnWater();
        bool rockWalking = Salih1.getRockWalking();
        bool standOnRock = Salih1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Khan.png"){
        maxLevel = Khan1.getMobility();
        bool waterWalking = Khan1.getWaterWalking();
        bool standOnWater = Khan1.getStandOnWater();
        bool rockWalking = Khan1.getRockWalking();
        bool standOnRock = Khan1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Boi.png"){
        maxLevel = Boi1.getMobility();
        bool waterWalking = Boi1.getWaterWalking();
        bool standOnWater = Boi1.getStandOnWater();
        bool rockWalking = Boi1.getRockWalking();
        bool standOnRock = Boi1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Eloi.png"){
        maxLevel = Eloi1.getMobility();
        bool waterWalking = Eloi1.getWaterWalking();
        bool standOnWater = Eloi1.getStandOnWater();
        bool rockWalking = Eloi1.getRockWalking();
        bool standOnRock = Eloi1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Kanar.png"){
        maxLevel = Kanar1.getMobility();
        bool waterWalking = Kanar1.getWaterWalking();
        bool standOnWater = Kanar1.getStandOnWater();
        bool rockWalking = Kanar1.getRockWalking();
        bool standOnRock = Kanar1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Elsa.png"){
        maxLevel = Elsa1.getMobility();
        bool waterWalking = Elsa1.getWaterWalking();
        bool standOnWater = Elsa1.getStandOnWater();
        bool rockWalking = Elsa1.getRockWalking();
        bool standOnRock = Elsa1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Karissa.png"){
        maxLevel = Karissa1.getMobility();
        bool waterWalking = Karissa1.getWaterWalking();
        bool standOnWater = Karissa1.getStandOnWater();
        bool rockWalking = Karissa1.getRockWalking();
        bool standOnRock = Karissa1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sir Philip.png"){
        maxLevel = SirPhilip1.getMobility();
        bool waterWalking = SirPhilip1.getWaterWalking();
        bool standOnWater = SirPhilip1.getStandOnWater();
        bool rockWalking = SirPhilip1.getRockWalking();
        bool standOnRock = SirPhilip1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Frost.png"){
        maxLevel = Frost1.getMobility();
        bool waterWalking = Frost1.getWaterWalking();
        bool standOnWater = Frost1.getStandOnWater();
        bool rockWalking = Frost1.getRockWalking();
        bool standOnRock = Frost1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Tusk.png"){
        maxLevel = Tusk1.getMobility();
        bool waterWalking = Tusk1.getWaterWalking();
        bool standOnWater = Tusk1.getStandOnWater();
        bool rockWalking = Tusk1.getRockWalking();
        bool standOnRock = Tusk1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Rambu.png"){
        maxLevel = Rambu1.getMobility();
        bool waterWalking = Rambu1.getWaterWalking();
        bool standOnWater = Rambu1.getStandOnWater();
        bool rockWalking = Rambu1.getRockWalking();
        bool standOnRock = Rambu1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sabrina.png"){
        maxLevel = Sabrina1.getMobility();
        bool waterWalking = Sabrina1.getWaterWalking();
        bool standOnWater = Sabrina1.getStandOnWater();
        bool rockWalking = Sabrina1.getRockWalking();
        bool standOnRock = Sabrina1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Death.png"){
        maxLevel = Death1.getMobility();
        bool waterWalking = Death1.getWaterWalking();
        bool standOnWater = Death1.getStandOnWater();
        bool rockWalking = Death1.getRockWalking();
        bool standOnRock = Death1.getStandOnRock();
    }




    if(hexa[startIndex].bgPath == ":/src/images/Agent/Billy.png") maxLevel = 3 ;
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Reketon.png") maxLevel = 2 ;
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Duraham.png") maxLevel = 2 ;


    std::vector<bool> visited(hexCount, false);
    std::queue<int> q;
    std::queue<int> levelQueue;

    q.push(startIndex);
    levelQueue.push(0);
    visited[startIndex] = true;

    while (!q.empty()) {
        int current = q.front(); q.pop();
        int level = levelQueue.front(); levelQueue.pop();

        if (level > maxLevel) continue;

        // رسیدن به target
        if (current == targetIndex) {
            hexa[current].bgPath = hexa[startIndex].bgPath;
            hexa[startIndex].bgPath = ":/src/images/ground.jpg";
            updateHexButton(current);
            updateHexButton(startIndex);

            qDebug() << "✅ Target hex" << current << "set to money";
            return;
        }

        // همسایه‌ها
        hexagon* neighbors[6] = {
            hexa[current].top,
            hexa[current].bottom,
            hexa[current].topLeft,
            hexa[current].topRight,
            hexa[current].bottomLeft,
            hexa[current].bottomRight
        };

        for (int k = 0; k < 6; k++) {
            if (neighbors[k] != nullptr) {
                int nIndex = neighbors[k] - &hexa[0];

                if (nIndex >= 0 && nIndex < hexCount && !visited[nIndex]) {
                    // 🔹 استارت و تارگت استثناء
                    if (nIndex == startIndex || nIndex == targetIndex) {
                        visited[nIndex] = true;
                        q.push(nIndex);
                        levelQueue.push(level + 1);
                    }
                    // 🔹 بقیه باید ground باشن
                    else if (hexa[nIndex].bgPath == ":/src/images/ground.jpg") {
                        visited[nIndex] = true;
                        q.push(nIndex);
                        levelQueue.push(level + 1);
                    }
                }
            }
        }

    }

    qDebug() << "❌ Target not reachable";
}



void playingGameWindow::findNeighbors() {
    int N = 41; // یا hexCount اگر داری
    for (int i = 0; i < N; i++) {
        if (hexa[i].row == -1) continue;

        int r = hexa[i].row;
        int c = hexa[i].col;

        hexa[i].top = hexa[i].bottom =
            hexa[i].topLeft = hexa[i].topRight =
            hexa[i].bottomLeft = hexa[i].bottomRight = nullptr;

        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            int nr = hexa[j].row;
            int nc = hexa[j].col;

            // هر کدوم مستقل بررسی بشه (if جدا، نه else-if)

            // Top
            if (nr == r - 2 && nc == c)
                hexa[i].top = &hexa[j];

            // Bottom
            if (nr == r + 2 && nc == c)
                hexa[i].bottom = &hexa[j];

            // Top-Left
            if (nr == r - 1 &&
                ((r % 2 == 0 && nc == c - 1) || (r % 2 != 0 && nc == c)))
                hexa[i].topLeft = &hexa[j];

            // Top-Right
            if (nr == r - 1 &&
                ((r % 2 == 0 && nc == c) || (r % 2 != 0 && nc == c + 1)))
                hexa[i].topRight = &hexa[j];

            // Bottom-Left
            if (nr == r + 1 &&
                ((r % 2 == 0 && nc == c - 1) || (r % 2 != 0 && nc == c)))
                hexa[i].bottomLeft = &hexa[j];

            // Bottom-Right
            if (nr == r + 1 &&
                ((r % 2 == 0 && nc == c) || (r % 2 != 0 && nc == c + 1)))
                hexa[i].bottomRight = &hexa[j];
        }
    }
}

void playingGameWindow::updateHexButton(int index) {
    QPixmap pixmap(hexButton[index]->size());
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    QPolygonF hex = createHexagon(QPointF(pixmap.width()/2, pixmap.height()/2), 48);
    QPainterPath path;
    path.addPolygon(hex);
    painter.setClipPath(path);

    QPixmap bgPixmap(QString::fromStdString(hexa[index].bgPath));
    painter.drawPixmap(pixmap.rect(), bgPixmap, bgPixmap.rect());
    painter.end();

    hexButton[index]->setIcon(QIcon(pixmap));
    hexButton[index]->setIconSize(hexButton[index]->size());
}


void playingGameWindow::on_pl1_ag1_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag1_selected){
        pl1_ag1_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
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
                updateHexButton(i);
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
                updateHexButton(i);
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
                updateHexButton(i);
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


void playingGameWindow::on_pl1_ag5_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag5_selected){
        pl1_ag5_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag5_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag5_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag6_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag6_selected){
        pl1_ag6_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag6_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag6_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag7_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag7_selected){
        pl1_ag7_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag7_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag7_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag8_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag8_selected){
        pl1_ag8_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag8_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag8_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag9_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag9_selected){
        pl1_ag9_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag9_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag9_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag10_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag10_selected){
        pl1_ag10_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag10_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag10_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag11_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag11_selected){
        pl1_ag11_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag11_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag11_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag12_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag12_selected){
        pl1_ag12_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag12_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag12_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag13_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag13_selected){
        pl1_ag13_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag13_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag13_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag14_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag14_selected){
        pl1_ag14_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag14_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag14_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag15_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag15_selected){
        pl1_ag15_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag15_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag15_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag16_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag16_selected){
        pl1_ag16_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag16_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag16_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag17_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag17_selected){
        pl1_ag17_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag17_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag17_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag18_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag18_selected){
        pl1_ag18_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag18_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag18_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag19_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag19_selected){
        pl1_ag19_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag19_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag19_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag20_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag20_selected){
        pl1_ag20_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag20_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag20_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag21_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag21_selected){
        pl1_ag21_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag21_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag21_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag22_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag22_selected){
        pl1_ag22_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag22_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag22_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag23_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag23_selected){
        pl1_ag23_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag23_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag23_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl1_ag24_btn_clicked()
{
    if(playerRound == 1 && agentSelector && pl1_ag24_selected){
        pl1_ag24_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "1" && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl1_ag24_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl1_ag24_selected)
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
                updateHexButton(i);
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
                updateHexButton(i);
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
                updateHexButton(i);
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
                updateHexButton(i);
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


void playingGameWindow::on_pl2_ag5_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag5_selected){
        pl2_ag5_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag5_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag5_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag6_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag6_selected){
        pl2_ag6_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag6_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag6_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag7_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag7_selected){
        pl2_ag7_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag7_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag7_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag8_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag8_selected){
        pl2_ag8_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag8_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag8_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag9_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag9_selected){
        pl2_ag9_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag9_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag9_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag10_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag10_selected){
        pl2_ag10_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag10_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag10_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag11_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag11_selected){
        pl2_ag11_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag11_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag11_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag12_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag12_selected){
        pl2_ag12_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag12_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag12_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag13_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag13_selected){
        pl2_ag13_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag13_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag13_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag14_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag14_selected){
        pl2_ag14_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag14_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag14_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag15_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag15_selected){
        pl2_ag15_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag15_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag15_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag16_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag16_selected){
        pl2_ag16_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag16_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag16_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag17_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag17_selected){
        pl2_ag17_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag17_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag17_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag18_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag18_selected){
        pl2_ag18_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag18_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag18_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag19_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag19_selected){
        pl2_ag19_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag19_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag19_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag20_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag20_selected){
        pl2_ag20_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag20_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag20_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag21_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag21_selected){
        pl2_ag21_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag21_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag21_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag22_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag22_selected){
        pl2_ag22_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag22_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag22_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag23_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag23_selected){
        pl2_ag23_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag23_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag23_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}


void playingGameWindow::on_pl2_ag24_btn_clicked()
{
    if(playerRound == 2 && agentSelector && pl2_ag24_selected){
        pl2_ag24_clicked = true;

        for(int i = 0; i < 41; i++){
            if(hexa[i].id == "2"  && hexa[i].bgPath == ":/src/images/ground.jpg"){
                hexa[i].bgPath = ":/src/images/select_ground.jpg";
                updateHexButton(i);
            }
        }
        pl2_ag24_selected = false;
        ui->messageBox->setText("Select Hex On The Map");
    } else {
        if(!pl2_ag24_selected)
            ui->messageBox->setText("already selected");
        else
            ui->messageBox->setText("It's Not Your Turn");
    }
}





playingGameWindow::~playingGameWindow()
{

    delete ui;
}
