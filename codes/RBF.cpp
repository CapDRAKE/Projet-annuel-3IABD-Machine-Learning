#include <iostream>
#include "Eigen"
#include <time.h>

using namespace Eigen;

int coordo_min (VectorXf tab){
    int min = tab(0);
    int coor =0;
    for(int c=1; c < tab.size(); c++){
        int help = tab(c);
        if (min > help){
            coor = c;
        }
    }
    return coor;
}

MatrixXf Choix_representant (MatrixXf data, int nbrepresentant , int nbdimension){
    srand(time(NULL));
    MatrixXf representant(nbrepresentant, nbdimension);
    for (int a= 0; a < nbrepresentant ; a++){

        int valeur = rand()%(data.rows()-1) + 0;
        std::cout << valeur << std::endl;
        for (int b = 0; b < nbdimension ; b++){

            representant (a,b) = data(valeur, b);


        }
        std::cout << representant << std::endl;

    }

    return representant;
}
VectorX<VectorXf> dist_representant (MatrixXf data, MatrixXf representant){

    VectorX<VectorXf> X;
    X.resize(representant.rows());
    for (int t= 0; t < representant.rows(); t++){
        X(t).resize(0);
    }


    VectorXf save;
    save.resize(representant.rows());
    for (int a = 0; a< data.rows(); a++){

        for (int b = 0; b < representant.rows(); b++) {
            int distance = (data.row(a) - representant.row(b)).norm();
            save(b) = distance;

        }
        int point = coordo_min(save);
        int sizeVdeV = X(point).size();
        X(point).conservativeResize(sizeVdeV +1);
        int sizeVdeV2 = X(point).size();
        X(point)(sizeVdeV2-1)=a;

    }

    return X;

}

MatrixXf choix_nex_representant(VectorX<VectorXf> pos, MatrixXf data , MatrixXf representant, int nbrepresentant, int nbdimension){
    MatrixXf new_representant(nbrepresentant , nbdimension);

    for (int a = 0; a < pos.size(); a++){
        VectorXf somme(nbdimension);
        for (int d = 0; d < somme.size(); d++){
            somme(d)=0;
        }
        for (int b = 0; b < pos(a).size(); b++){
            for (int c = 0; c < data.rows(); c++){
//                std::cout <<  "vecteur somme" << std::endl;
//                std::cout << somme  << std::endl;
//                std::cout << "ligne matrice" << std::endl;
//                std::cout << data.row(c)  << std::endl;
//                std::cout << " boucle a"<< std::endl;
//                std::cout << a << std::endl;
//                std::cout <<  "boucle b"<< std::endl;
//                std::cout << b << std::endl;
//                std::cout << "boucle c" << std::endl;
//                std::cout << c  << std::endl;
                if (c == pos(a)(b)){
                    somme = somme + data.row(c).transpose();
                }
            }


        }
        std::cout << somme << std::endl;
        std::cout << representant.row(a) << std::endl;
        representant.cwiseAbs(); // valeur absolue
        for (int p = 0; p < representant.cols(); p++){
            representant(a,p) = 1/representant(a,p);
            new_representant(a, p) = representant(a,p) * somme(p);
        }
        std::cout << new_representant << std::endl;

//        VectorXf res;
//        res.resize(nbrepresentant);
//        res = somme.cwiseProduct(representant.row(a).transpose());
//        std::cout << res << std::endl;
//        for (int p = 0 ; p< res.size(); p++){
//            res(p) = 1/res(p);
//            new_representant(a,p) = res(p);
//        }

    }

    return new_representant;
}

int main() {
    MatrixXf data(7, 3);
    data(0, 0) = 1;
    data(0, 1) = 1;
    data(1, 0) = 1;
    data(1, 1) = 2;
    data(2, 0) = 3;
    data(2, 1) = 2;
    data(3, 0) = 5;
    data(3, 1) = 4;
    data(4, 0) = 3;
    data(4, 1) = 1;
    data(5, 0) = 6;
    data(5, 1) = 2;
    data(6, 0) = 3;
    data(6, 1) = 3;
    for (int m =0; m < data.rows();m++){
        data(m,2)=m;
    }

    int nb = 2;
    int nbdim = 3;
    MatrixXf representant = Choix_representant(data, nb, nbdim);

    std::cout << representant << std::endl;

    VectorX<VectorXf> rep = dist_representant(data, representant);


//    for (int a = 0;a < rep.size();a++){
//        std::cout << rep(a) << std::endl;
//        std::cout << "/" << std::endl;
//    }


    MatrixXf newRep = choix_nex_representant(rep, data ,representant, nb, nbdim);
    std::cout << newRep << std::endl;

    return 0;
}
