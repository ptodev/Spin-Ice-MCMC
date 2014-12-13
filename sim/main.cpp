#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QImage>
#include <QBitmap>

#include "grid.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int rows = 100;
    int cols = 100;

    QLabel myLabel;
    myLabel.show();
    myLabel.setFixedWidth(500);
    myLabel.setFixedHeight(500);

    grid g(rows, cols);
    vector<bool> world = g.get_grid();
    uchar* world_uchar = new uchar[rows*cols];

    for(int i=0; i<world.size(); ++i) {
        if(world[i] == true)
            world_uchar[i] = 255;
        else
            world_uchar[i] = 0;
    }

    QImage img(world_uchar, cols, rows, QImage::Format_Indexed8);

    myLabel.setPixmap(QPixmap::fromImage(img).scaled(500, 500, Qt::IgnoreAspectRatio, Qt::FastTransformation));
//    this_thread::sleep_for(std::chrono::milliseconds(1000));

    //    }
    //    int h_no_flip, h_flip;

    //	//g.focus_point(4, 4);
    //	//cout << g.get_hamiltonian() << endl;
    //	//g.flip(4, 4);
    //	//g.focus_point(4, 4);
    //	//cout << g.get_hamiltonian() << endl;

    //    for(int row=0; row<rows; ++row){
    //        for(int col=0; col<cols; ++col){
    //            g.focus_point(col, row);
    //            h_no_flip = g.get_hamiltonian();
    //            g.flip(row, col);
    //			g.focus_point(col, row);
    //            h_flip = g.get_hamiltonian();
    //			//cout << h_flip - h_no_flip << endl;
    //			//g.show();
    //			g.flip(row, col);
    //			//system("cls");
    //            //if(h_flip - h_no_flip > 0) continue;
    //            //cout<<endl;
    //        }
    //    }

    return a.exec();
}
