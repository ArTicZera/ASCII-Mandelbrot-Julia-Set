#include <stdio.h>

#define W 150
#define H 50

typedef struct
{
    double zx; //Real
    double zy; //Imaginary
} complex;

int calculatemandel(int x, int y, int maxiter)
{
    complex c, z, f, fractal;

    fractal.zx = (2.5f / W);
    fractal.zy = (1.9f / H);

    c.zx = x * fractal.zx - 2.f;
    c.zy = y * fractal.zy - 0.95f;

    z.zx = 0.f, z.zy = 0.f;

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

void drawmandel(int maxiter)
{
    for (int y = 0; y <= H; y++)
    {
        for (int x = 0; x <= W; x++)
        {
            if (calculatemandel(x, y, maxiter) >= maxiter)
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

    drawmandel(maxiter);

    return 0;
}
