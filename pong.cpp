#include <iostream>
#include "raylib.h"
#include <thread>
#include <chrono>

using namespace std;

#define ScreenWidth 900
#define ScreenHeight 600
#define BallRadius 15.0
#define BallSpeed 2
#define RectangleLengh 40.0
#define RectangleWidth 10.0
#define RectangleSpeed 2

int main(void){
    int Aiscore = 0;
    int Playerscore = 0;
    int BallX = ScreenWidth/2;
    int BallY = ScreenHeight/2;
    int xBallMv = BallSpeed;
    int yBallMv = BallSpeed;
    int GoTo = ScreenHeight/2;
    int heightRectangle = ScreenHeight/2;
    int heightAIPad = ScreenHeight/2;
    cout<<"Starting the game"<<endl;
    Color green = {15, 100, 40, 255};
    Color othergreen = {15, 200, 40, 255};
    SetTargetFPS(60);
    InitWindow(ScreenWidth, ScreenHeight, "PONG");
    while(!WindowShouldClose()){
        if(BallX<0){
            Playerscore +=1;
            BallX = ScreenWidth/2;
            BallY = ScreenHeight/2;
            xBallMv = BallSpeed;
        }
        else if(BallX>ScreenWidth){
            Aiscore +=1;
            BallX = ScreenWidth/2;
            BallY = ScreenHeight/2;
            xBallMv = BallSpeed * (-1);
        }
        if(heightAIPad<GoTo){
            heightAIPad+=RectangleSpeed;
        }
        if(heightAIPad>GoTo){
            heightAIPad-=RectangleSpeed;
        }
        if(IsKeyDown(KEY_UP) && heightRectangle>0){
            heightRectangle-=RectangleSpeed;
        }
        if(IsKeyDown(KEY_DOWN) && heightRectangle + (RectangleLengh)<ScreenHeight){
            heightRectangle+=RectangleSpeed;
        }
        BallX+=xBallMv;
        BallY+=yBallMv;
        if(BallX+BallRadius>=ScreenWidth && BallY>=heightRectangle && BallY<=heightRectangle + RectangleLengh){
            xBallMv = (-1) * BallSpeed;
        }
        if(BallX-BallRadius<=0 && BallY>=heightAIPad && BallY<=heightAIPad + RectangleLengh){
            xBallMv = BallSpeed;
        }
        if(BallY+BallRadius>=ScreenHeight){
            yBallMv = (-1) * BallSpeed;
            if(xBallMv == (-1) * BallSpeed){
                GoTo = ScreenHeight - BallX;
            }
        }
        if(BallY-BallRadius<=0){
            yBallMv = BallSpeed;
            if(xBallMv == (-1) * BallSpeed){
                GoTo = BallX;
            }
        }
        ClearBackground(green);
        BeginDrawing();
        DrawRectangle(ScreenWidth/2, 0, 10, ScreenWidth, othergreen);
        DrawCircle(0, ScreenHeight/2, 120.0, othergreen);
        DrawCircle(ScreenWidth, ScreenHeight/2, 120.0, othergreen);
        DrawCircle(ScreenWidth/2, ScreenHeight/2, 120.0, othergreen);
        DrawCircle(BallX, BallY, BallRadius, RED);
        DrawRectangle(ScreenWidth - RectangleWidth, heightRectangle, RectangleWidth, RectangleLengh, BLUE);
        DrawRectangle(0, heightAIPad, RectangleWidth, RectangleLengh, GOLD);
        DrawText(("BOTox: " + to_string(Aiscore)).c_str(), ScreenWidth/4 - 70, ScreenHeight/2, 20, GOLD);
        DrawText(("Player: " + to_string(Playerscore)).c_str(), (3*ScreenWidth)/4, ScreenHeight/2, 20, BLUE);
        //DrawText("Hello, Raylib", ScreenWidth/2 - 50, ScreenHeight/2, 20, RED);
        if(Aiscore==10){
            for(int i=0; i<300; i++){
                BeginDrawing();
                DrawText("You lose!\nBetter luck next time!", ScreenWidth/4, ScreenHeight/2, 40, PURPLE);
                EndDrawing();
            }
            break;
        }
        if(Playerscore>Aiscore){
            for(int i=0; i<300; i++){
                BeginDrawing();
                DrawText("You win!\n Congratulations!", ScreenWidth/4, ScreenHeight/2, 40, PURPLE);
                EndDrawing();
            }
            break;
        }
        EndDrawing();
    }
    CloseWindow();
}