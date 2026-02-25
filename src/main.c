#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

#define W_Height 500
#define W_Width 600
#define PI 3.1415926535

typedef struct {
    SDL_Window* ventana;
    SDL_Renderer* render;
    SDL_Event e;

    int running;
    int state;
} Game;

typedef struct {
    float x_o;
    float y_o;
} Origin;

typedef struct {
    int magnitude;
    double direction;
} Vector;

    // Start subsystems 
int init(Game* game){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }
    
    game->ventana = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_Width, W_Height, 0);
    if (game->ventana == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return 1;
    }

    game->render = SDL_CreateRenderer(game->ventana, -1, SDL_RENDERER_ACCELERATED);
    if (game->render == NULL) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return 1;
    }
    return 0;
}

void desinit()
{
    SDL_Quit();
}

int axis(Game* game, Origin origin, char* c);
int vectorF(Game* game, Origin origin, int x, int y);

int main(int argc, char* argv[])
{
    //  On Linux structs must be initialized!
    Game game = {0};

    Origin origin = {W_Width/2, W_Height/2};

    /**********INITIALIZE GAME STRUCT AND ELEMENTS**********/
    if(init(&game)!=0)
        return 1;

    /**********RENDERING|LOGIC|INPUT|MANAGING**********/
    SDL_RenderClear(game.render);
    SDL_SetRenderDrawColor(game.render, 255, 255, 255, 255);
    // X and Y Axis
    axis(&game, origin, "x");
    axis(&game, origin, "y");

    //  Rendering vectors
    SDL_SetRenderDrawColor(game.render, 56, 39, 245, 255);
//    for(float i=0;i<360;i=i+5)
//        vectorF(&game, origin, i);

    SDL_RenderPresent(game.render);

    SDL_Delay(10000); // Wait for 2 seconds

    /**********END PROGRAM FUNCTIONS**********/
    SDL_DestroyRenderer(game.render);
    SDL_DestroyWindow(game.ventana);
    desinit();


    return 0;
}

//  Draw axis
int axis(Game* game, Origin origin, char* c){
if(c=="x"){
    SDL_RenderDrawLine(game->render, 
        origin.x_o-W_Width/2, 
        origin.y_o,
        origin.x_o+W_Width/2,
        origin.y_o);
    return 0;
}
if(c=="y"){
    SDL_RenderDrawLine(game->render, 
        origin.x_o, 
        origin.y_o-W_Height/2,
        origin.x_o,
        origin.y_o+W_Height/2);
    return 0;
}
else return 1;
}

// Inputs parameter t into the written function
int vectorF(Game* game, Origin origin, int x, int y){
    // F(x,y)=yi
    Vector vec;
    SDL_RenderDrawLineF(game->render,vec.x,vec.y,origin.x_o,origin.y_o);



    return 0;
}

int gameloop(Game* game)
{
    while( game->running == 1 )
    {
        SDL_RenderClear(game->render);
        
        SDL_Delay(20);

        SDL_RenderPresent(game->render);
    }
    return 0;
}
