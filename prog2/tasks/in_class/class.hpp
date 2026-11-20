#ifndef PONTO
#define PONTO

class Ponto
{

  private:
    double x, y;

  public:
    Ponto(double x0, double, y0);

    double getX() const;

    double getY() const;

    void mover(double dx, double dy);

    double distancia(const Ponto &outro) const;
};
