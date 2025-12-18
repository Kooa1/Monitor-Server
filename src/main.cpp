//
// Created by 66 on 2025/12/18.
//

// #include <vld.h>
#include <QApplication>
#include <QMainWindow>

#include "captor.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto captor = std::make_unique<Captor>();

    return QApplication::exec();
}
