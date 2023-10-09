#include <stdio.h>

#define W 150
#define H 50

typedef struct
{
    double zx; //Real
    double zy; //Imaginary
} complex;

int calculatejulia(int x, int y, int maxiter)
{
    complex c, z, f, fractal;

    fractal.zx = (2.8f / W);
    fractal.zy = (2.8f / H);

    c.zx = -0.7f;
    c.zy = 0.27f;

    z.zx = x * fractal.zx - 1.4f;
    z.zy = y * fractal.zy - 1.f;

    int iter = 0;

    while (((z.zx * z.zx) + (z.zy * z.zy)) < 4 && iter < maxiter)
    {
        f.zx = z.zx * z.zx - z.zy * z.zy + c.zx;
        f.zy = 2 * z.zx * z.zy + c.zy;

        z.zx = f.zx;
        z.zy = f.zy;

        iter++;
    }

    return iter;
}

void drawjulia(int maxiter)
{
    for (int y = 0; y <= H; y++)
    {
        for (int x = 0; x <= W; x++)
        {
            if (calculatejulia(x, y, maxiter) == maxiter)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main(void)
{
    int maxiter;

    printf("Max iterations: ");
    scanf("%d", &maxiter);

    drawjulia(maxiter);

    return 0;
}
