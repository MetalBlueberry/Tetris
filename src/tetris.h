#ifndef TETRIS_H
#define TETRIS_H

#include "figures.h"

class Tetris
{

public:
    enum TetrisEventType : int{
        gameLost,
        newLine,
        newFigure,
        fixedFigure,
        screenUpdate,

    };
    typedef void(*TetrisEvent)(void*,TetrisEventType);
    Tetris(int display_width, int display_height);
    ~Tetris();

    // void start();
    void reset();

    bool moveLeft();
    bool moveRight();
    bool moveDown();
    bool moveUp();
    bool rotateLeft();
    bool rotateRight();


    bool canMoveLeft();
    bool canMoveRight();
    bool canMoveDown();
    bool canMoveUp();
    bool canRotateRight();
    bool canRotateRight(unsigned char *aux);
    bool canRotateLeft();
    bool canRotateLeft(unsigned char *aux);



    void setEventHandler(TetrisEvent handler, void *object);

    void getDisplay(unsigned char * const external_display);
    int getDisplayWidth();
    int getDisplayHeight();
    void getFigure(unsigned char * const external_figure);
    void getFigure(int number,unsigned char * const external_figure);


    //creates new figure and position it at the top
    void generateNewFigure(unsigned char number);
    //prints the current figure to the screen and allows you create a new one
    void fixFigure();
    bool removeLine();
    void insertLine(int position, unsigned char * const values);
    //you lose the game if the figure is fixed at this value or lower
    int lost_y = 0;
private:
    int display_width;
    int display_height;
    unsigned char * display;
    int figure_x;
    int figure_y;
    unsigned char * figure;

    int getDisplayPosition(int x, int y);
    void sendEvent(TetrisEventType event);
    TetrisEvent eventHandler;
    void *object;

    bool checkColission(unsigned char * const fig, int fig_x, int fig_y);
    void moveToTopLeft(unsigned char * fig);

    void generateNewFigure(unsigned char number,unsigned char *buffer);
};

#endif // TETRIS_H
