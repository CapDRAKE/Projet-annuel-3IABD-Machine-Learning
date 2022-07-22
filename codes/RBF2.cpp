#include <iostream>
#include <iostream>
#include "Eigen"
#include <time.h>
using namespace Eigen;


int p_rbf( VectorXf W, MatrixXf centers, int gamma, VectorXf Xk){
    float total = 0;
    for (int i=0; i<centers.rows(); i++){
        float p = (Xk.transpose() - centers.row(i)).norm();
        total += exp(-gamma * pow(p,2))*W(i);
//        std::cout << "Xk : " << Xk.transpose() << std::endl;
//        std::cout << "c : " << centers.row(i) << std::endl;
//        std::cout << "total : " << total << std::endl;
//        std::cout << "p : " << p << std::endl;


    }
//    std::cout << "total : " << W << std::endl;
//    std::cout << "total : " << total << std::endl;
    if (total >= 0){
        return 1;
    } else {
        return -1;
    }
}

float train_rbf( float W, int n, float alpha,  VectorXf Xk, MatrixXf centers, float diff){

    for (int j=0; j<centers.rows(); j++){


//        std::cout << Xk << std::endl;
//        std::cout << centers.row(j) << std::endl;
        float p = (Xk.transpose() - centers.row(j)).norm();
//        std::cout << "p : "<< p << std::endl;
//        std::cout << "diff : "<< diff << std::endl;
        std::cout << "avant : "<< W << std::endl;
        W += W + alpha * diff * exp(-2 *pow(p,2));
        std::cout << "apres : "<< W << std::endl;

    }

    return W;
}

int main() {
    int gamma = 2;
    VectorXf Y(4);
    Y(0)= 1;
    Y(1)= -1;
    Y(2)= -1;
    Y(3)= 1;

    MatrixXf X(4,2); // nb colonne nombre d'entrée du percptron
    X(0,0)= 1;
    X(0,1)= 1;
    X(1,0)= 2;
    X(1,1)= 3;
    X(2,0)= 3;
    X(2,1)= 3;
    X(3,0)= 2.5;
    X(3,1)= 3;
    VectorXf b(X.cols());
    VectorXf W(X.rows());
    srand(time(NULL));
    W.setRandom();
    float alpha = 0.01;

    for (int h = 0; h< 10000; h++){
        srand(time(NULL));
        int k = rand()%X.rows();
        VectorXf Xk(X.cols());
        for (int c =0 ; c< X.cols();c++){
            Xk(c) = X(k,c);
        }
        int a = p_rbf(  W,  X,  gamma,  Xk);
        int Yk = Y(k);
        float diff = Yk - a;
//        std::cout << "diff : "<< diff << std::endl;
//        std::cout << "a : "<< a << std::endl;
//        std::cout << "Yk : "<< Yk << std::endl;
        for (int w = 0; w< X.rows(); w++){
//            std::cout << "W(w) : "<< W(w) << std::endl;
            W(w) = train_rbf(  W(w),  w, alpha,   Xk, X,  diff);

        }
    }
    for (int i = 0; i<X.rows();i++) {
        for (int y = 0; y < X.cols(); y++) {
            b(y) = X(i, y);

        }
        int a = p_rbf(W, X, gamma, b);
        std::cout << a << std::endl;

    }


    return 0;
}