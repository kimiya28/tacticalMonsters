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

WaterWalking Billy1(320, 3, 90, 1,true,true,false,false);
WaterWalking Reketon1(320, 2, 80, 2,true,true,false,false);
WaterWalking Angus1(400, 2, 100, 1,true,true,false,false);
WaterWalking Duraham1(320, 2, 100, 2,true,true,false,false);

WaterWalking Billy2(320, 3, 90, 1,true,true,false,false);
WaterWalking Reketon2(320, 2, 80, 2,true,true,false,false);
WaterWalking Angus2(400, 2, 100, 1,true,true,false,false);
WaterWalking Duraham2(320, 2, 100, 2,true,true,false,false);

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
        if(hexa[index].id == "1" && (pl1_ag1_clicked || pl1_ag2_clicked || pl1_ag3_clicked || pl1_ag4_clicked)){
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
            if(hexa[index].id == "2" && (pl2_ag1_clicked || pl2_ag2_clicked || pl2_ag3_clicked || pl2_ag4_clicked)){
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

    if(playerRound == 1){
        if(hexa[startIndex].bgPath == ":/src/images/Agent/Angus.png"){
            maxLevel = Angus1.getMobility();
            bool waterWalking = Angus1.getWaterWalking();
            bool standOnWater = Angus1.getStandOnWater();


        }
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

playingGameWindow::~playingGameWindow()
{

    delete ui;
}

