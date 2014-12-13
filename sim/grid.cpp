#include "grid.h"

grid::grid(int x_dim_tmp, int y_dim_tmp){
    /*
        A function to fill our world with random spins.
    */

    x_dim = x_dim_tmp;
    y_dim = y_dim_tmp;

    for(int i=0; i<x_dim*y_dim; i+=2){
        world.push_back(true);
        world.push_back(false);
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    for(int i=0; i<x_dim*y_dim; ++i){
        bool random_bit = dis(gen);
        world.push_back(random_bit);
    }
}

void grid::focus_point(int x_focus, int y_focus){
    /*
        A function to fill nn_list.
    */

    double distance;
    for(int x=0; x<x_dim; ++x){
        for(int y=0; y<y_dim; ++y){
            distance = pow( pow(x - x_focus, 2) + pow(y - y_focus, 2), 0.5);

            nn_dt tmp;
            tmp.x = x;
            tmp.y = y;
            tmp.distance = distance;
            nn_list.push_back(tmp);
        }
    }

    sort(
        nn_list.begin(),
        nn_list.end(),
        [](const nn_dt &a, const nn_dt &b) {return a.distance < b.distance;}
    );

    double previous_distance = nn_list[0].distance;
    for(int i=1; i<nn_list.size(); ++i){
        if(previous_distance == nn_list[i].distance){
            previous_distance = nn_list[i].distance;
            nn_list[i].distance = nn_list[i-1].distance;
        } else {
            previous_distance = nn_list[i].distance;
            nn_list[i].distance = nn_list[i-1].distance + 1;
        }
    }
}

int grid::get_spin(int row, int col){
    int world_size = x_dim * y_dim;
    return world[world_size + col + row * x_dim];
}

void grid::set_spin(int row, int col, int spin){
    int world_size = x_dim * y_dim;
    world[world_size + col + row * x_dim] = spin;
}

double grid::get_hamiltonian(){
    double hamiltonian = 0;
    // Loop through every point around the focus point
    for(int i=1; i<nn_list.size(); ++i){
        hamiltonian += get_j_coefficient(nn_list[i].distance) * get_spin(nn_list[i].x, nn_list[i].y);
    }
    // Multiply the sum by the spin of the central point
    hamiltonian *= get_spin(nn_list[0].x, nn_list[0].y);
    return hamiltonian;
}

int grid::get_j_coefficient(int nn_order){
    return 1;
}

void grid::show(){
    /*
        A function to print the spins.
    */

    for(int r=0; r<x_dim; ++r){
        for(int c=0; c<y_dim; ++c){
            cout<<get_spin(r, c)<<" ";
        }
        cout<<endl;
    }
}

void grid::show_nns(){
    /*
        A function to print the nearest neighbour values.
    */

    for(int i=0; i<nn_list.size(); ++i){
        cout<<"("
            <<nn_list[i].x
            <<", "
            <<nn_list[i].y
            <<"): "
            <<nn_list[i].distance
            <<endl;
    }
}

vector<bool> grid::get_grid(){
    vector<bool> result;
    for(int r=0; r<x_dim; ++r){
        for(int c=0; c<y_dim; ++c){
            result.push_back(get_spin(r, c));
        }
    }
    return result;
}

void grid::flip(int row, int col){
    int world_size = x_dim * y_dim;
    if(world[world_size + col + row * x_dim] == 0) world[world_size + col + row * x_dim] = 1;
    else world[world_size + col + row * x_dim] = 0;
}
