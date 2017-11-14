#include "load_data.h"

namespace dml{
void LoadData::load_all_data(){
    fea_matrix.clear();
    while(!fin_.eof()){
        std::getline(fin_, line);
        sample.clear();
        const char *pline = line.c_str();
        if(sscanf(pline, "%d%n", &y, &nchar) >= 1){
            pline += nchar;
            label.push_back(y);
            while(sscanf(pline, "%d:%ld:%f%n", &fgid, &fid, &val, &nchar) >= 3){
                pline += nchar;
                keyval.fgid = fgid;
                keyval.fid = fid;
                keyval.val = val;
                sample.push_back(keyval);
            }
        }
        fea_matrix.push_back(sample);
    }
}//end load

void LoadData::load_batch_data(int num){
    fea_matrix.clear();
    for(int i = 0; i < num; i++){
        std::getline(fin_, line);
        if(fin_.eof()) break;
        sample.clear();
        const char *pline = line.c_str();
        if(sscanf(pline, "%d%n", &y, &nchar) >= 1){
            pline += nchar;
            label.push_back(y);
            while(sscanf(pline, "%d:%ld:%f%n", &fgid, &fid, &val, &nchar) >= 3){
                pline += nchar;
                keyval.fgid = fgid;
                keyval.fid = fid;
                keyval.val = val;
                sample.push_back(keyval);
            }//end while
        }//end if
        fea_matrix.push_back(sample);
    }//end for
}//end load

}//end namespace
