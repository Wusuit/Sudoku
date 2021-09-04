
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int ren_loop(SDL_Window* w, SDL_Renderer* r) {
    int run_status = 1;
    // Telling game to run or not 1 = run 0 = not
    SDL_FRect romb = {400.0f, 0.0f, 200.0f, 200.0f};
    double acc = 0.5;
    double vel = 0;
    double corest = 0.9;
    SDL_Point renwh;

    while (run_status) {
        // Behind the scenes event processing
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    run_status = 0;
                    break;
                case SDL_MOUSEMOTION:
                    //printf("Mouse position: x %d, y %d \n", e.motion.x, e.motion.y);
                    break;
                case SDL_KEYDOWN:
                    printf("Key Pressed: %c \n", 'A' + e.key.keysym.sym - SDLK_a);
                    break;
            }
        }
        // Picture Rendering
        SDL_SetRenderDrawColor(r, 235, 24, 162, 255);
        SDL_RenderClear(r);
        SDL_GetRendererOutputSize(r, &renwh.x, &renwh.y);



        if (romb.y >= ((float)renwh.y - romb.h)) {
            romb.y = ((float)renwh.y - romb.h);
            printf("Before Bounce- vel is: %f, acc is: %f, corest is: %f\n", vel, acc, corest);
            vel = (corest * (-vel));
            printf(" vel is: %f, acc is: %f, corest is: %f\n", vel, acc, corest);
        }


        vel = vel + acc;
        romb.y = (romb.y + (float)vel);




        SDL_Point mp;
        SDL_GetMouseState(&mp.x,&mp.y);
        SDL_Rect romb_int = {(int)romb.x,(int)romb.y, (int)romb.w, (int)romb.h};
        if (!SDL_PointInRect(&mp, &romb_int)) {
            SDL_SetRenderDrawColor(r, 50, 30, 230, 255);
            SDL_RenderFillRectF(r, &romb);
        }



        SDL_RenderPresent(r);
        SDL_Delay(10);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Error\n");
        return 1;
    }

    if (TTF_Init() != 0) {
        printf("TTF Error\n");
        return -1;
    }

    SDL_Window* win = SDL_CreateWindow("Sudoku-chan", 150, 100, 1000, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren_san = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    ren_loop(win, ren_san);














    return 0;
}
