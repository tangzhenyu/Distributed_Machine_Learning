#include <string>
#include "param.h"
#include "io/load_data.cc"
#include "learner/ftrl_learner.cc"
#include "predict.h"
#include "mpi.h"

int main(int argc,char* argv[]){  
    int rank, nproc;
    int kRankNameLength = 1024;
    char processor_name[kRankNameLength];
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&nproc);
    MPI_Get_processor_name(processor_name,&kRankNameLength);

    dml::Param param(argc, argv);
    
    char train_data_path[1024];
    snprintf(train_data_path, 1024, "%s-%05d", param.train_data_path.c_str(), rank);
    char test_data_path[1024];
    snprintf(test_data_path, 1024, "%s-%05d", param.test_data_path.c_str(), rank);

    dml::LoadData train_data(train_data_path);

    dml::LoadData test_data(test_data_path);
    test_data.load_all_data();

    dml::Predict predict(&test_data, &param, nproc, rank);

    if(param.isftrl == 1){
        dml::FtrlLearner ftrl(&train_data, &predict, &param, nproc, rank);
        ftrl.run();
        predict.run(ftrl.loc_w, ftrl.loc_v);
    }

    MPI::Finalize();
    return 0;
}
