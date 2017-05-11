#ifndef TWIDDLEPID_H
#define TWIDDLEPID_H

#include "PID.h"

class TwiddlePID : public PID {
public:
  /*
  * Twiddle implementation for PID controllers
  */
  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  * Tolerance for twiddle conversion
  */
  double tol;
  double dp[3] = {1,1,1};
  double p[3] = {0,0,0};
  double best_err;
  int indx_converge;
};

#endif /* TWIDDLEPID_H */
