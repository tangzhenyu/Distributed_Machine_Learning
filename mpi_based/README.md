1. Introduction

    Distributed LR,FM,FMM[1] solved by FTRL algorithm[2] based on MPI

2. Dependency

    openblas

    mpich-2
	
3. Use

    This folder shoulder in same path on all of your cluseter nodes.

    all of follow action in the folder of Field-aware-Factorization-Machine-ftrl-mpi
    step 1:

        split your data into n parts. (n equal the number of nodes of your cluster), 
        for example, cd ./data and run the command: sh run_split_data.sh

    step 2:
   
        cd ..

        modeify Ip in the file run_ffm_mpi.sh and then rum commend: sh run_ffm_mpi.sh

    Note:         

        if you want to stop the programme, run commend: sh stop.sh 

4. Feature list

    4.1. About model selection:

        4.1.1. if you want to use LR(Logistic Regression) model only, set the parameter in config.h: isffm=0 isfm=0 islr=1

        4.1.2. if you want to use FM(Factorization Machine) model only, set the parameter in config.h: isffm=0 isfm=1 islr=0

        4.1.3. if you want to use FFM(Field-aware Factorization Machine) model only, set the parameter in config.h: isffm=1 isfm=0 islr=0

    4.2. Evaluation
  
        print AUC after some epochs

    4.3 Save Model
   
       dump model to the model folder 

5. Todo list

    1, multithread

    2, same model paralle on Parameter Server
  
    3, load data batch

    4, optimazation the learning algorithm

6. References:

    [1] Field-aware Factorization Machines for CTR Prediction. http://www.csie.ntu.edu.tw/~cjlin/papers/ffm.pdf

    [2] Ad Click Prediction: a View from the Trenches. http://dl.acm.org/citation.cfm?id=2488200

    [3] Factorization Machine. http://www.csie.ntu.edu.tw/~b97053/paper/Rendle2010FM.pdf
