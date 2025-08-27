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
bool waterBgChanged = false;
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
    string originalBgPath;
    Agent* agent = nullptr;
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
    agentTextBrowsers[&Billy1] = ui->pl1_Billy_hp ;
    agentTextBrowsers[&Reketon1] = ui->pl1_Reketon_hp;
    agentTextBrowsers[&Angus1] = ui->pl1_Angus_hp;
    agentTextBrowsers[&Duraham1] = ui->pl1_Duraham_hp;
    agentTextBrowsers[&ColonelBaba1] = ui->pl1_ColonelBaba_hp;
    agentTextBrowsers[&Medusa1] = ui->pl1_Medusa_hp;
    agentTextBrowsers[&Bunka1] = ui->pl1_Bunka_hp;
    agentTextBrowsers[&Sanka1] = ui->pl1_Sanka_hp;
    agentTextBrowsers[&SirLamorak1] = ui->pl1_SirLamorak_hp;
    agentTextBrowsers[&Kabu1] = ui->pl1_Kabu_hp;
    agentTextBrowsers[&Rajakal1] = ui->pl1_Rajakal_hp;
    agentTextBrowsers[&Salih1] = ui->pl1_Salih_hp;
    agentTextBrowsers[&Khan1] = ui->pl1_Khan_hp;
    agentTextBrowsers[&Boi1] = ui->pl1_Boi_hp;
    agentTextBrowsers[&Eloi1] = ui->pl1_Kanar_hp;
    agentTextBrowsers[&Kanar1] = ui->pl1_Kanar_hp;
    agentTextBrowsers[&Elsa1] = ui->pl1_Elsa_hp;
    agentTextBrowsers[&Karissa1] = ui->pl1_Karissa_hp;
    agentTextBrowsers[&SirPhilip1] = ui->pl1_SirPhilip_hp;
    agentTextBrowsers[&Frost1] = ui->pl1_Frost_hp;
    agentTextBrowsers[&Tusk1] = ui->pl1_Tusk_hp;
    agentTextBrowsers[&Rambu1] = ui->pl1_Rambu_hp;
    agentTextBrowsers[&Sabrina1] = ui->pl1_Sabrina_hp;
    agentTextBrowsers[&Death1] = ui->pl1_Death_hp;

    agentTextBrowsers[&Billy2] = ui->pl2_Billy_hp;
    agentTextBrowsers[&Reketon2] = ui->pl2_Reketon_hp;
    agentTextBrowsers[&Angus2] = ui->pl2_Angus_hp;
    agentTextBrowsers[&Duraham2] = ui->pl2_Duraham_hp;
    agentTextBrowsers[&ColonelBaba2] = ui->pl2_ColonelBaba_hp;
    agentTextBrowsers[&Medusa2] = ui->pl2_Medusa_hp;
    agentTextBrowsers[&Bunka2] = ui->pl2_Bunka_hp;
    agentTextBrowsers[&Sanka2] = ui->pl2_Sanka_hp;
    agentTextBrowsers[&SirLamorak2] = ui->pl2_SirLamorak_hp;
    agentTextBrowsers[&Kabu2] = ui->pl2_Kabu_hp;
    agentTextBrowsers[&Rajakal2] = ui->pl2_Rajakal_hp;
    agentTextBrowsers[&Salih2] = ui->pl2_Salih_hp;
    agentTextBrowsers[&Boi1] = ui->pl2_Boi_hp;
    agentTextBrowsers[&Khan2] = ui->pl2_Khan_hp;
    agentTextBrowsers[&Boi2] = ui->pl2_Boi_hp;
    agentTextBrowsers[&Eloi2] = ui->pl2_Kanar_hp;
    agentTextBrowsers[&Elsa2] = ui->pl2_Elsa_hp;
    agentTextBrowsers[&Karissa2] = ui->pl2_Karissa_hp;
    agentTextBrowsers[&SirPhilip2] = ui->pl2_SirPhilip_hp;
    agentTextBrowsers[&Frost2] = ui->pl2_Frost_hp;
    agentTextBrowsers[&Tusk2] = ui->pl2_Tusk_hp;
    agentTextBrowsers[&Rambu2] = ui->pl2_Rambu_hp;
    agentTextBrowsers[&Sabrina2] = ui->pl2_Sabrina_hp;
    agentTextBrowsers[&Death2] = ui->pl2_Death_hp;
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

    QStringList txtFiles = directory.entryList(QDir::Files);

    if (txtFiles.isEmpty()) {
        qDebug() << "No .txt files found in the directory";
        return;
    }

    int randomIndex = QRandomGenerator::global()->bounded(txtFiles.size());
    QString selectedFile = txtFiles.at(randomIndex);
    QString filePath = directory.filePath(selectedFile);

    qDebug() << "Randomly selected file:" << filePath;

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
                    hexa[hexCount].originalBgPath = ":/src/images/ground.jpg";

                }
                else if(line[position + 1] == "1"){
                    id = "1";
                    hexa[hexCount].bgPath = ":/src/images/ground.jpg";
                    hexa[hexCount].originalBgPath = ":/src/images/ground.jpg";
                }
                else if(line[position + 1] == "2"){
                    id = "2";
                    hexa[hexCount].bgPath = ":/src/images/ground.jpg";
                    hexa[hexCount].originalBgPath = ":/src/images/ground.jpg";
                }
                else if(line[position + 1] == "~"){
                    id = "~";
                    hexa[hexCount].bgPath = ":/src/images/water.jpg";
                    hexa[hexCount].originalBgPath = ":/src/images/water.jpg";
                }
                else if(line[position + 1] == "#"){
                    id = "#";
                    hexa[hexCount].bgPath = ":/src/images/stone.jpg";
                    hexa[hexCount].originalBgPath = ":/src/images/stone.jpg";
                }

                hexa[hexCount].id = id;
                createHexButton(hexCount);
                hexa[hexCount].row = row;
                hexa[hexCount].col = col;
                hexCount ++;
                col++;
                position +=3 ;
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
            } else if(pl1_ag5_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Colonel Baba.png";
                pl1_ag5_clicked = false;
            } else if(pl1_ag6_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Medusa.png";
                pl1_ag6_clicked = false;
            } else if(pl1_ag7_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Bunka.png";
                pl1_ag7_clicked = false;
            } else if(pl1_ag8_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Sanka.png";
                pl1_ag8_clicked = false;
            } else if(pl1_ag9_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Sir Lamorak.png";
                pl1_ag9_clicked = false;
            } else if(pl1_ag10_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Kabu.png";
                pl1_ag10_clicked = false;
            } else if(pl1_ag11_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Rajakal.png";
                pl1_ag11_clicked = false;
            } else if(pl1_ag12_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Salih.png";
                pl1_ag12_clicked = false;
            } else if(pl1_ag13_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Khan.png";
                pl1_ag13_clicked = false;
            } else if(pl1_ag14_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Boi.png";
                pl1_ag14_clicked = false;
            } else if(pl1_ag15_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Eloi.png";
                pl1_ag15_clicked = false;
            } else if(pl1_ag16_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Kanar.png";
                pl1_ag16_clicked = false;
            } else if(pl1_ag17_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Elsa.png";
                pl1_ag17_clicked = false;
            } else if(pl1_ag18_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Karissa.png";
                pl1_ag18_clicked = false;
            } else if(pl1_ag19_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Sir Philip.png";
                pl1_ag19_clicked = false;
            } else if(pl1_ag20_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Frost.png";
                pl1_ag20_clicked = false;
            } else if(pl1_ag21_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Tusk.png";
                pl1_ag21_clicked = false;
            } else if(pl1_ag22_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Rambu.png";
                pl1_ag22_clicked = false;
            } else if(pl1_ag23_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Sabrina.png";
                pl1_ag23_clicked = false;
            } else if(pl1_ag24_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Death.png";
                pl1_ag24_clicked = false;
            }

            updateHexButton(index);


        } else if(hexa[index].id == "1" && hexa[index].bgPath != ":/src/images/ground.jpg" && startSelection == true){
            ui->messageBox->setText("now select your target");
            targetSelection = true;
            startHex = index ;
            startSelection = false ;


            // شرط اینکه هدف انتخابی برای حرکت زمین باشه
        } else if(startSelection == false && targetSelection == true && hexa[index].bgPath == ":/src/images/ground.jpg"){
            targetIndex = index ;
            bfsSet(startHex, targetIndex , 41);
            targetSelection = false ;
            startSelection = true ;
            playerRound = 2 ;
            ui->messageBox->setText("Round 2");

            //شرط این که زمین نباشه و یا آب باشه یا سنگ
        }  else if(startSelection == false && targetSelection == true && hexa[index].bgPath != ":/src/images/ground.jpg"
                   && (hexa[index].bgPath == ":/src/images/water.jpg" || hexa[index].bgPath == ":/src/images/stone.jpg")){
            targetIndex = index;
            waterBgChanged = true;
            bfsSet(startHex, targetIndex , 41);
            targetSelection = false;
            startSelection = true;
            playerRound = 2;
            ui->messageBox->setText("Round 2");

            // شرط اینکه روی ایجنت خودمون یا حریف کلیک کنیم
        }   else if(startSelection == false && targetSelection == true && (hexa[index].id == "1" || hexa[index].id == "2" )){
            targetIndex = index;
            bfsSet(startHex, targetIndex , 41);
            targetSelection = false;
            startSelection = true;
            playerRound = 2;
            ui->messageBox->setText("Round 2");
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
            } else if(pl2_ag5_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Colonel Baba.png";
                pl2_ag5_clicked = false;
            } else if(pl2_ag6_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Medusa.png";
                pl2_ag6_clicked = false;
            } else if(pl2_ag7_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Bunka.png";
                pl2_ag7_clicked = false;
            } else if(pl2_ag8_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Sanka.png";
                pl2_ag8_clicked = false;
            } else if(pl2_ag9_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Sir Lamorak.png";
                pl2_ag9_clicked = false;
            } else if(pl2_ag10_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Kabu.png";
                pl2_ag10_clicked = false;
            } else if(pl2_ag11_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Rajakal.png";
                pl2_ag11_clicked = false;
            } else if(pl2_ag12_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Salih.png";
                pl2_ag12_clicked = false;
            } else if(pl2_ag13_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Khan.png";
                pl2_ag13_clicked = false;
            } else if(pl2_ag14_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Boi.png";
                pl2_ag14_clicked = false;
            } else if(pl2_ag15_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Eloi.png";
                pl2_ag15_clicked = false;
            } else if(pl2_ag16_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Kanar.png";
                pl2_ag16_clicked = false;
            } else if(pl2_ag17_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Elsa.png";
                pl2_ag17_clicked = false;
            } else if(pl2_ag18_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Karissa.png";
                pl2_ag18_clicked = false;
            } else if(pl2_ag19_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Sir Philip.png";
                pl2_ag19_clicked = false;
            } else if(pl2_ag20_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Frost.png";
                pl2_ag20_clicked = false;
            } else if(pl2_ag21_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Tusk.png";
                pl2_ag21_clicked = false;
            } else if(pl2_ag22_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Rambu.png";
                pl2_ag22_clicked = false;
            } else if(pl2_ag23_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Sabrina.png";
                pl2_ag23_clicked = false;
            } else if(pl2_ag24_clicked){
                hexa[index].bgPath = ":/src/images/Agent/Death.png";
                pl2_ag24_clicked = false;
            }

            updateHexButton(index);

            // شرط اینکه هدف انتخابی برای حرکت زمین باشه
        }  else if(hexa[index].id == "2" && hexa[index].bgPath != ":/src/images/ground.jpg" && startSelection ){
            ui->messageBox->setText("now select your target");
            targetSelection = true;
            startHex = index ;
            startSelection = false ;

        } else if(startSelection == false && targetSelection == true){

            targetIndex = index ;
            bfsSet(startHex, targetIndex , 41);
            targetSelection = false ;
            startSelection = true ;
            playerRound = 1 ;
            ui->messageBox->setText("Round 1");

            //شرط این که زمین نباشه و یا آب باشه یا سنگ
        } else if(startSelection == false && targetSelection == true && hexa[index].bgPath != ":/src/images/ground.jpg"
                   && (hexa[index].bgPath == ":/src/images/water.jpg" || hexa[index].bgPath == ":/src/images/stone.jpg")){

            targetIndex = index;
            waterBgChanged = true;
            bfsSet(startHex, targetIndex , 41);
            targetSelection = false;
            startSelection = true;
            playerRound = 1;
            ui->messageBox->setText("Round 1");

            // شرط اینکه روی ایجنت خودمون یا حریف کلیک کنیم
        }   else if(startSelection == false && targetSelection == true && (hexa[index].id == "1" || hexa[index].id == "2" )){

            targetIndex = index;
            bfsSet(startHex, targetIndex , 41);
            targetSelection = false;
            startSelection = true;
            playerRound = 1;
            ui->messageBox->setText("Round 1");
        }

    }

    roundCounter++;
    if(roundCounter == 4)
        playerRound = 2;
    if(roundCounter == 8){
        playerRound = 1;
        agentSelector = false;

        //آپدیت  آیدی همه شش ضلعی هایی که زمین هستن بعد از انتخاب ایجنتها
        for(int i = 0; i < 41; i++){
            if(hexa[i].bgPath == ":/src/images/ground.jpg" && hexa[i].id == "1") {

                hexa[i].id = ".";
                updateHexButton(i);

            }
            if(hexa[i].bgPath == ":/src/images/ground.jpg" && hexa[i].id == "2") {

                hexa[i].id = ".";
                updateHexButton(i);

            }
        }
    }
}

// تابع پیمایش
void playingGameWindow::bfsSet(int startIndex, int targetIndex, int hexCount) {
    int maxLevel;
    bool waterWalking ;
    bool standOnWater ;
    bool rockWalking ;
    bool standOnRock ;

    if (startIndex < 0 || startIndex >= hexCount) return;
    if (targetIndex < 0 || targetIndex >= hexCount) return;
    if (startIndex == targetIndex) return;

    findNeighbors();


    if(hexa[startIndex].bgPath == ":/src/images/Agent/Billy.png"){
        maxLevel = Billy1.getMobility();
        waterWalking = Billy1.getWaterWalking();
        standOnWater = Billy1.getStandOnWater();
        rockWalking = Billy1.getRockWalking();
        standOnRock = Billy1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Reketon.png"){
        maxLevel = Reketon1.getMobility();
        waterWalking = Reketon1.getWaterWalking();
        standOnWater = Reketon1.getStandOnWater();
        rockWalking = Reketon1.getRockWalking();
        standOnRock = Reketon1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Angus.png"){
        maxLevel = Angus1.getMobility();
        waterWalking = Angus1.getWaterWalking();
        standOnWater = Angus1.getStandOnWater();
        rockWalking = Angus1.getRockWalking();
        standOnRock = Angus1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Duraham.png"){
        maxLevel = Duraham1.getMobility();
        waterWalking = Duraham1.getWaterWalking();
        standOnWater = Duraham1.getStandOnWater();
        rockWalking = Duraham1.getRockWalking();
        standOnRock = Duraham1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Colonel Baba.png"){
        maxLevel = ColonelBaba1.getMobility();
        waterWalking = ColonelBaba1.getWaterWalking();
        standOnWater = ColonelBaba1.getStandOnWater();
        rockWalking = ColonelBaba1.getRockWalking();
        standOnRock = ColonelBaba1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Medusa.png"){
        maxLevel = Medusa1.getMobility();
        waterWalking = Medusa1.getWaterWalking();
        standOnWater = Medusa1.getStandOnWater();
        rockWalking = Medusa1.getRockWalking();
        standOnRock = Medusa1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Bunka.png"){
        maxLevel = Bunka1.getMobility();
        waterWalking = Bunka1.getWaterWalking();
        standOnWater = Bunka1.getStandOnWater();
        rockWalking = Bunka1.getRockWalking();
        standOnRock = Bunka1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sanka.png"){
        maxLevel = Sanka1.getMobility();
        waterWalking = Sanka1.getWaterWalking();
        standOnWater = Sanka1.getStandOnWater();
        rockWalking = Sanka1.getRockWalking();
        standOnRock = Sanka1.getStandOnRock();
    }

    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sir Lamorak.png"){
        maxLevel = SirLamorak1.getMobility();
        waterWalking = SirLamorak1.getWaterWalking();
        standOnWater = SirLamorak1.getStandOnWater();
        rockWalking = SirLamorak1.getRockWalking();
        standOnRock = SirLamorak1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Kabu.png"){
        maxLevel = Kabu1.getMobility();
        waterWalking = Kabu1.getWaterWalking();
        standOnWater = Kabu1.getStandOnWater();
        rockWalking = Kabu1.getRockWalking();
        standOnRock = Kabu1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Rajakal.png"){
        maxLevel = Rajakal1.getMobility();
        waterWalking = Rajakal1.getWaterWalking();
        standOnWater = Rajakal1.getStandOnWater();
        rockWalking = Rajakal1.getRockWalking();
        standOnRock = Rajakal1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Salih.png"){
        maxLevel = Salih1.getMobility();
        waterWalking = Salih1.getWaterWalking();
        standOnWater = Salih1.getStandOnWater();
        rockWalking = Salih1.getRockWalking();
        standOnRock = Salih1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Khan.png"){
        maxLevel = Khan1.getMobility();
        waterWalking = Khan1.getWaterWalking();
        standOnWater = Khan1.getStandOnWater();
        rockWalking = Khan1.getRockWalking();
        standOnRock = Khan1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Boi.png"){
        maxLevel = Boi1.getMobility();
        waterWalking = Boi1.getWaterWalking();
        standOnWater = Boi1.getStandOnWater();
        rockWalking = Boi1.getRockWalking();
        standOnRock = Boi1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Eloi.png"){
        maxLevel = Eloi1.getMobility();
        waterWalking = Eloi1.getWaterWalking();
        standOnWater = Eloi1.getStandOnWater();
        rockWalking = Eloi1.getRockWalking();
        standOnRock = Eloi1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Kanar.png"){
        maxLevel = Kanar1.getMobility();
        waterWalking = Kanar1.getWaterWalking();
        standOnWater = Kanar1.getStandOnWater();
        rockWalking = Kanar1.getRockWalking();
        standOnRock = Kanar1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Elsa.png"){
        maxLevel = Elsa1.getMobility();
        waterWalking = Elsa1.getWaterWalking();
        standOnWater = Elsa1.getStandOnWater();
        rockWalking = Elsa1.getRockWalking();
        standOnRock = Elsa1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Karissa.png"){
        maxLevel = Karissa1.getMobility();
        waterWalking = Karissa1.getWaterWalking();
        standOnWater = Karissa1.getStandOnWater();
        rockWalking = Karissa1.getRockWalking();
        standOnRock = Karissa1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sir Philip.png"){
        maxLevel = SirPhilip1.getMobility();
        waterWalking = SirPhilip1.getWaterWalking();
        standOnWater = SirPhilip1.getStandOnWater();
        rockWalking = SirPhilip1.getRockWalking();
        standOnRock = SirPhilip1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Frost.png"){
        maxLevel = Frost1.getMobility();
        waterWalking = Frost1.getWaterWalking();
        standOnWater = Frost1.getStandOnWater();
        rockWalking = Frost1.getRockWalking();
        standOnRock = Frost1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Tusk.png"){
        maxLevel = Tusk1.getMobility();
        waterWalking = Tusk1.getWaterWalking();
        standOnWater = Tusk1.getStandOnWater();
        rockWalking = Tusk1.getRockWalking();
        standOnRock = Tusk1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Rambu.png"){
        maxLevel = Rambu1.getMobility();
        waterWalking = Rambu1.getWaterWalking();
        standOnWater = Rambu1.getStandOnWater();
        rockWalking = Rambu1.getRockWalking();
        standOnRock = Rambu1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sabrina.png"){
        maxLevel = Sabrina1.getMobility();
        waterWalking = Sabrina1.getWaterWalking();
        standOnWater = Sabrina1.getStandOnWater();
        rockWalking = Sabrina1.getRockWalking();
        standOnRock = Sabrina1.getStandOnRock();
    }
    if(hexa[startIndex].bgPath == ":/src/images/Agent/Death.png"){
        maxLevel = Death1.getMobility();
        waterWalking = Death1.getWaterWalking();
        standOnWater = Death1.getStandOnWater();
        rockWalking = Death1.getRockWalking();
        standOnRock = Death1.getStandOnRock();
    }


    std::vector<bool> visited(hexCount, false);
    std::queue<int> q;
    std::queue<int> levelQueue;

    q.push(startIndex);
    levelQueue.push(0);
    visited[startIndex] = true;

    const char* dirName[6] = {"top","bottom","topLeft","topRight","bottomLeft","bottomRight"};

    while (!q.empty()) {
        int current = q.front(); q.pop();
        int level = levelQueue.front(); levelQueue.pop();


        if (level > maxLevel) {
            continue;
        }

        if (current == targetIndex) {


                        if (hexa[targetIndex].bgPath == ":/src/images/ground.jpg"
                || (hexa[targetIndex].bgPath == ":/src/images/water.jpg" && standOnWater)
                || (hexa[targetIndex].bgPath == ":/src/images/stone.jpg" && standOnRock)) {

                qDebug() << "  ✅ Target reached at level:" << level;

                hexa[targetIndex].bgPath = hexa[startIndex].bgPath;
                if (playerRound == 1) hexa[targetIndex].id = "1";
                if (playerRound == 2) hexa[targetIndex].id = "2";
                updateHexButton(targetIndex);

                hexa[startIndex].bgPath = hexa[startIndex].originalBgPath;
                if (hexa[startIndex].originalBgPath == ":/src/images/ground.jpg") {
                    hexa[startIndex].id = ".";
                }
                else if (hexa[startIndex].originalBgPath == ":/src/images/water.jpg") {
                    hexa[startIndex].id = "~";
                }
                else if (hexa[startIndex].originalBgPath == ":/src/images/stone.jpg") {
                    hexa[startIndex].id = "#";
                }
                else {
                    hexa[startIndex].id = ".";
                }

                updateHexButton(startIndex);
                return;
            }
            else if (hexa[targetIndex].id == "2" || hexa[targetIndex].id == "1") {
                if(playerRound == 1){
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Angus.png") hexa[startIndex].agent = &Angus1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Angus.png") hexa[targetIndex].agent = &Angus2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Billy.png") hexa[startIndex].agent = &Billy1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Billy.png") hexa[targetIndex].agent = &Billy2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Boi.png") hexa[startIndex].agent = &Boi1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Boi.png") hexa[targetIndex].agent = &Boi2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Bunka.png") hexa[startIndex].agent = &Bunka1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Bunka.png") hexa[targetIndex].agent = &Bunka2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Colonel Baba.png") hexa[startIndex].agent = &ColonelBaba1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Colonel Baba.png") hexa[targetIndex].agent = &ColonelBaba2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Death.png") hexa[startIndex].agent = &Death1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Death.png") hexa[targetIndex].agent = &Death2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Duraham.png") hexa[startIndex].agent = &Duraham1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Duraham.png") hexa[targetIndex].agent = &Duraham2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Eloi.png") hexa[startIndex].agent = &Eloi1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Eloi.png") hexa[targetIndex].agent = &Eloi2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Elsa.png") hexa[startIndex].agent = &Elsa1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Elsa.png") hexa[targetIndex].agent = &Elsa2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Frost.png") hexa[startIndex].agent = &Frost1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Frost.png") hexa[targetIndex].agent = &Frost2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Kabu.png") hexa[startIndex].agent = &Kabu1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Kabu.png") hexa[targetIndex].agent = &Kabu2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Kanar.png") hexa[startIndex].agent = &Kanar1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Kanar.png") hexa[targetIndex].agent = &Kanar2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Karissa.png") hexa[startIndex].agent = &Karissa1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Karissa.png") hexa[targetIndex].agent = &Karissa2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Khan.png") hexa[startIndex].agent = &Khan1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Khan.png") hexa[targetIndex].agent = &Khan2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Medusa.png") hexa[startIndex].agent = &Medusa1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Medusa.png") hexa[targetIndex].agent = &Medusa2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Rajakal.png") hexa[startIndex].agent = &Rajakal1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Rajakal.png") hexa[targetIndex].agent = &Rajakal2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Rambu.png") hexa[startIndex].agent = &Rambu1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Rambu.png") hexa[targetIndex].agent = &Rambu2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Reketon.png") hexa[startIndex].agent = &Reketon1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Reketon.png") hexa[targetIndex].agent = &Reketon2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sabrina.png") hexa[startIndex].agent = &Sabrina1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Sabrina.png") hexa[targetIndex].agent = &Sabrina2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Salih.png") hexa[startIndex].agent = &Salih1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Salih.png") hexa[targetIndex].agent = &Salih2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sanka.png") hexa[startIndex].agent = &Sanka1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Sanka.png") hexa[targetIndex].agent = &Sanka2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sir Lamorak.png") hexa[startIndex].agent = &SirLamorak1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Sir Lamorak.png") hexa[targetIndex].agent = &SirLamorak2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sir Philip.png") hexa[startIndex].agent = &SirPhilip1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Sir Philip.png") hexa[targetIndex].agent = &SirPhilip2;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Tusk.png") hexa[startIndex].agent = &Tusk1;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Tusk.png") hexa[targetIndex].agent = &Tusk2;
                }else if(playerRound == 2 ){
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Angus.png") hexa[startIndex].agent = &Angus2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Angus.png") hexa[targetIndex].agent = &Angus1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Billy.png") hexa[startIndex].agent = &Billy2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Billy.png") hexa[targetIndex].agent = &Billy1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Boi.png") hexa[startIndex].agent = &Boi2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Boi.png") hexa[targetIndex].agent = &Boi1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Bunka.png") hexa[startIndex].agent = &Bunka2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Bunka.png") hexa[targetIndex].agent = &Bunka1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Colonel Baba.png") hexa[startIndex].agent = &ColonelBaba2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Colonel Baba.png") hexa[targetIndex].agent = &ColonelBaba1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Death.png") hexa[startIndex].agent = &Death2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Death.png") hexa[targetIndex].agent = &Death1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Duraham.png") hexa[startIndex].agent = &Duraham2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Duraham.png") hexa[targetIndex].agent = &Duraham1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Eloi.png") hexa[startIndex].agent = &Eloi2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Eloi.png") hexa[targetIndex].agent = &Eloi1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Elsa.png") hexa[startIndex].agent = &Elsa2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Elsa.png") hexa[targetIndex].agent = &Elsa1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Frost.png") hexa[startIndex].agent = &Frost2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Frost.png") hexa[targetIndex].agent = &Frost1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Kabu.png") hexa[startIndex].agent = &Kabu2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Kabu.png") hexa[targetIndex].agent = &Kabu1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Kanar.png") hexa[startIndex].agent = &Kanar2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Kanar.png") hexa[targetIndex].agent = &Kanar1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Karissa.png") hexa[startIndex].agent = &Karissa2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Karissa.png") hexa[targetIndex].agent = &Karissa1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Khan.png") hexa[startIndex].agent = &Khan2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Khan.png") hexa[targetIndex].agent = &Khan1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Medusa.png") hexa[startIndex].agent = &Medusa2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Medusa.png") hexa[targetIndex].agent = &Medusa1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Rajakal.png") hexa[startIndex].agent = &Rajakal2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Rajakal.png") hexa[targetIndex].agent = &Rajakal1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Rambu.png") hexa[startIndex].agent = &Rambu2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Rambu.png") hexa[targetIndex].agent = &Rambu1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Reketon.png") hexa[startIndex].agent = &Reketon2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Reketon.png") hexa[targetIndex].agent = &Reketon1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sabrina.png") hexa[startIndex].agent = &Sabrina2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Sabrina.png") hexa[targetIndex].agent = &Sabrina1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Salih.png") hexa[startIndex].agent = &Salih2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Salih.png") hexa[targetIndex].agent = &Salih1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sanka.png") hexa[startIndex].agent = &Sanka2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Sanka.png") hexa[targetIndex].agent = &Sanka1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sir Lamorak.png") hexa[startIndex].agent = &SirLamorak2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Sir Lamorak.png") hexa[targetIndex].agent = &SirLamorak1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Sir Philip.png") hexa[startIndex].agent = &SirPhilip2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Sir Philip.png") hexa[targetIndex].agent = &SirPhilip1;
                    if(hexa[startIndex].bgPath == ":/src/images/Agent/Tusk.png") hexa[startIndex].agent = &Tusk2;
                    if(hexa[targetIndex].bgPath == ":/src/images/Agent/Tusk.png") hexa[targetIndex].agent = &Tusk1;
                }


                if (hexa[targetIndex].id != QString::number(playerRound)) {
                    qDebug() << "⚔️ Target is another agent!";

                    std::vector<std::pair<QString, int>> neighborInfo;

                    hexagon* neighbors[] = {
                        hexa[targetIndex].top,
                        hexa[targetIndex].bottom,
                        hexa[targetIndex].topLeft,
                        hexa[targetIndex].topRight,
                        hexa[targetIndex].bottomLeft,
                        hexa[targetIndex].bottomRight
                    };

                    for (int k = 0; k < 6; k++) {
                        hexagon* n = neighbors[k];
                        if (n && n->bgPath == ":/src/images/ground.jpg") {
                            int nIndex = n - &hexa[0];
                            neighborInfo.push_back({QString::fromStdString(n->id), nIndex});
                        }
                    }


                    if (!neighborInfo.empty()) {
                        int r = std::rand() % neighborInfo.size();
                        QString chosenID = neighborInfo[r].first;
                        int chosenIndex = neighborInfo[r].second;

                        hexa[chosenIndex].bgPath = hexa[startIndex].bgPath;
                        hexa[chosenIndex].id = hexa[startIndex].id;
                        hexa[chosenIndex].agent = hexa[startIndex].agent;
                        updateHexButton(chosenIndex);


                        if (hexa[chosenIndex].agent && hexa[targetIndex].agent) {
                            Agent* attacker = hexa[startIndex].agent;
                            Agent* defender = hexa[targetIndex].agent;

                            attacker->setHP(attacker->getHP() - (defender->getDamage() / 2));
                            defender->setHP(defender->getHP() - attacker->getDamage());

                            if (agentTextBrowsers.contains(attacker)){
                                agentTextBrowsers[attacker]->setText(QString::number(attacker->getHP()));
                                agentTextBrowsers[attacker]->setStyleSheet("font-size: 6pt; color: white; font-weight: bold;");
                            }
                            if (agentTextBrowsers.contains(defender)){
                                agentTextBrowsers[defender]->setText(QString::number(defender->getHP()));
                                agentTextBrowsers[defender]->setStyleSheet("font-size: 6pt; color: white; font-weight: bold;");
                            }
                        }

                        hexa[startIndex].bgPath = ":/src/images/ground.jpg";
                        hexa[startIndex].id = ".";
                        hexa[startIndex].agent = nullptr;
                        updateHexButton(startIndex);


                    } else {
                        qDebug() << "No ground neighbors available";
                    }
                }


            }
            else {
                qDebug() << "  ❌ Target found but cannot stand on it!";
            }
        }


        hexagon* neighbors[6] = {
            hexa[current].top,
            hexa[current].bottom,
            hexa[current].topLeft,
            hexa[current].topRight,
            hexa[current].bottomLeft,
            hexa[current].bottomRight
        };

        for (int k = 0; k < 6; k++) {
            if (neighbors[k] == nullptr) {
                continue;
            }

            int nIndex = neighbors[k] - &hexa[0];

            if (!(nIndex >= 0 && nIndex < hexCount)) {
                continue;
            }


            if (visited[nIndex]) {
                continue;
            }

            bool canPass = false;

            if (hexa[nIndex].bgPath == ":/src/images/ground.jpg") {
                canPass = true;
            }
            else if (hexa[nIndex].bgPath == ":/src/images/water.jpg") {
                if (standOnWater || waterWalking) canPass = true;
            }
            else if (hexa[nIndex].bgPath == ":/src/images/stone.jpg") {
                if (standOnRock || rockWalking) canPass = true;
            }


            if (nIndex == targetIndex) {
                canPass = true;
            }

            if (canPass) {
                visited[nIndex] = true;
                q.push(nIndex);
                levelQueue.push(level + 1);
            } else {
            }
        }
    }

    qDebug() << "❌ Target not reachable";
}


void playingGameWindow::findNeighbors() {
    int N = 41;
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

            if (nr == r - 2 && nc == c) hexa[i].top = &hexa[j];
            if (nr == r + 2 && nc == c) hexa[i].bottom = &hexa[j];

            if (r % 2 == 0) {
                if (nr == r - 1 && nc == c) hexa[i].topLeft = &hexa[j];
                if (nr == r - 1 && nc == c + 1)     hexa[i].topRight = &hexa[j];
                if (nr == r + 1 && nc == c ) hexa[i].bottomLeft = &hexa[j];
                if (nr == r + 1 && nc == c + 1)     hexa[i].bottomRight = &hexa[j];
            } else {
                if (nr == r - 1 && nc == c - 1 )     hexa[i].topLeft = &hexa[j];
                if (nr == r - 1 && nc == c) hexa[i].topRight = &hexa[j];
                if (nr == r + 1 && nc == c - 1)     hexa[i].bottomLeft = &hexa[j];
                if (nr == r + 1 && nc == c) hexa[i].bottomRight = &hexa[j];
            }
        }

        auto idx = [&](hexagon* p){ return p ? int(p - &hexa[0]) : -1; };
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

    if (hexa[index].id == "1" && hexa[index].bgPath != ":/src/images/ground.jpg"
        && hexa[index].bgPath != ":/src/images/select_ground.jpg"
        && hexa[index].bgPath != ":/src/images/water.jpg"
        && hexa[index].bgPath != ":/src/images/stone.jpg") {

        painter.setClipping(false);
        QPen pen(QColor(100, 100, 255), 20);
        pen.setJoinStyle(Qt::MiterJoin);
        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawPolygon(hex);
    }
    if (hexa[index].id == "2" && hexa[index].bgPath != ":/src/images/ground.jpg"
        && hexa[index].bgPath != ":/src/images/select_ground.jpg"
        && hexa[index].bgPath != ":/src/images/water.jpg"
        && hexa[index].bgPath != ":/src/images/stone.jpg") {

        painter.setClipping(false);
        QPen pen(QColor(255, 50, 50, 180), 20);
        pen.setJoinStyle(Qt::MiterJoin);
        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawPolygon(hex);
    }

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
