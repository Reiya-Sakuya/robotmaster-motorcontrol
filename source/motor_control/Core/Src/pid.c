#include "math.h"
#include "pid.h"
#include "main.h"

float prev_err, intergral_err=0;
extern float dt;

float pid_init(pid_t *args,float arg_kp,float arg_ki,float arg_kd,float limit)
{
    args->kp = arg_kp;
    args->ki = arg_ki;
    args->kd = arg_kd;
    args->integral_limit = limit;
    return 0;
}

float pid_calc(pid_t *args,float err)
{
    float sum,d_err;
    d_err = err-prev_err;
    intergral_err += err*dt;
    if(intergral_err>(args->integral_limit)) intergral_err = args->integral_limit;
    else if (intergral_err<(-1*args->integral_limit)) intergral_err = -1*args->integral_limit;
    sum = ((args->kp)*err) + ((args->ki)*intergral_err) + ((args->kd)*d_err/dt);
    prev_err = err;
    return sum;
}
