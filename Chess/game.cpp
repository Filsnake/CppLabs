#include "game.h"
#include <QPixmap>

Game::Game(QWidget *parent) : QGraphicsView (parent)
{
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,480,480);
    setFixedSize(480,480);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    figure = nullptr;
    SetTurn("WHITE");
}

void Game::Start()
{
    chessBoard = new ChessBoard();
    chessBoard->DrawBoxes(width()/2-240,0);
    chessBoard->AddChessPiece();
}

void Game::AddToScene(QGraphicsItem *item){
    gameScene->addItem(item);
}

void Game::RemoveFromScene(QGraphicsItem *item)
{
    gameScene->removeItem(item);
}

void Game::ChangeTurn()
{
    if(GetTurn() == "WHITE")
        SetTurn("BLACK");
    else
        SetTurn("WHITE");
}

void Game::SetTurn(QString turn){
    Turn = turn;
}

void Game::SetBox(ChessBox *box, int x, int y) {
    boxes[x][y] = box;
}

ChessBox* Game::GetBox(int x, int y)
{
    return boxes[x][y];
}

Figure* Game::GetFigure()
{
    return figure;
}

QString Game::GetTurn()
{
    return Turn;
}

void Game::SetFigure(Figure *fig)
{
    figure = fig;
}
