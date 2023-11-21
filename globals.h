#ifndef GLOBALS_H
#define GLOBALS_H
#include <QMainWindow>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include "mainwindow.h"
#include <QDateTime>



#define WRONG_INPUT 1

extern QString prod_name;
extern qint32 amount;
extern qint32 qty_sold;
extern QDate date_sold;
extern  QTime time_sold;
extern int amount_sold;
extern int  qty_sold_new;



namespace Search {

struct receipt {
    QDate date_sold;
    QTime time_sold;
    qint32 amount_sold;
    qint32 sum_total;
    qint32 num_of_items;
   qint32 qty_sold;
   QString Product_name;

};

extern receipt rcpts;


}










/*enum Value : int {
  VALUE_ZERO      = 0,
  VALUE_DRAW      = 0,
  VALUE_KNOWN_WIN = 10000,
  VALUE_MATE      = 32000,
  VALUE_INFINITE  = 32001,
  VALUE_NONE      = 32002,

  VALUE_MATE_IN_MAX_PLY  =  VALUE_MATE - 2 * MAX_PLY,
  VALUE_MATED_IN_MAX_PLY = -VALUE_MATE + 2 * MAX_PLY,

  PawnValueMg   = 128,   PawnValueEg   = 213,
  KnightValueMg = 782,   KnightValueEg = 865,
  BishopValueMg = 830,   BishopValueEg = 918,
  RookValueMg   = 1289,  RookValueEg   = 1378,
  QueenValueMg  = 2529,  QueenValueEg  = 2687,

  MidgameLimit  = 15258, EndgameLimit  = 3915
};*/



#endif // GLOBALS_H
