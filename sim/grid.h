#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <random>
#include <math.h>
#include <algorithm>
using namespace std;

class grid{
    vector<bool> world;

    int x_dim;
    int y_dim;

    struct nn_dt{
        int x;
        int y;
        double distance;
    };
    vector<nn_dt> nn_list;

    void set_spin(int row, int col, int spin);

public:
    grid(int x_dim_tmp, int y_dim_tmp);
    void focus_point(int x_focus_tmp, int y_focus_tmp);
    void show();
    void show_nns();
    double get_hamiltonian();
    int get_j_coefficient(int nn_number);
    int get_spin(int row, int col);
    vector<bool> get_grid();
    void flip(int row, int col);
};


#endif // GRID_H
