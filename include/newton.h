#ifndef NEWTON_H
#define NEWTON_H

double f(double x, int opcion);
double df(double x, int opcion);
double newton(double x0, double tol, int max_iter, int opcion);

#endif