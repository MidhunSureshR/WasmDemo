#include <iostream>
#include <cmath>
#include <chrono>
#include <emscripten/emscripten.h>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

double EMSCRIPTEN_KEEPALIVE getPrime(int upperBound){
    auto t0 = chrono::high_resolution_clock::now();
    bool* list = new bool[upperBound];   
    fill_n(list, upperBound, true);
    int m = int(sqrt(upperBound));
    for(int i=2; i<=m; ++i){
           if(list[i]){
               for(int j=2; i*j<upperBound; ++j){
                    list[i * j] = false;
               }
           }
    }
    auto t1 = chrono::high_resolution_clock::now();
    double duration = chrono::duration_cast<std::chrono::microseconds>( t1 - t0 ).count() *  0.001;
    return duration;
}

#ifdef __cplusplus
}
#endif

int main(){
   cout << "Running WASM test" << endl;
    return 0;
}
