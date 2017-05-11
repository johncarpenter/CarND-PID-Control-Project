#include "TwiddlePID.h"

#include <limits>
#include <iostream>

using namespace std;


void TwiddlePID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  p_error = i_error = d_error = 0;

  tol = 0.002;
  p[0] = Kp;
  p[1] = Ki;
  p[2] = Kd;
  best_err = 9999;
  indx_converge = 0;
}

void TwiddlePID::UpdateError(double cte) {
  p_error = cte;
  i_error += cte;
  d_error = cte - p_error;

 std:: cout << "Deltap: " << dp[0]+dp[1]+dp[2]<<endl;
  //update parameters
  if(dp[0]+dp[1]+dp[2] >  tol){
    p[indx_converge] += dp[indx_converge];
    std::cout << "Updating parameters Kp:" << p[0] <<" Ki:" << p[1] <<" Kd: "<< p[2];
    if(cte < best_err){
        best_err = cte;
        dp[indx_converge] *= 1.1;
    }else{
       p[indx_converge] -= 2*dp[indx_converge];
       dp[indx_converge] *= 0.95;
    }

    p[indx_converge] += dp[indx_converge];

    indx_converge += 1;
    indx_converge = indx_converge % 3;
  }


}

double TwiddlePID::TotalError() {
  return p[0] * p_error + p[2] * d_error + p[1] * i_error;
}
