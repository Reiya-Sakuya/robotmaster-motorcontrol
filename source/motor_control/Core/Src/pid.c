#include "math.h"
#include "pid.h"
#include "main.h"

extern float dt;

float pid_init(pid_t *args,float arg_kp,float arg_ki,float arg_kd,float limit)
{
    args->kp = arg_kp;
    args->ki = arg_ki;
    args->kd = arg_kd;
    args->integral_limit = limit;
    args->prev_err = 0;
    args->intergral_err = 0;
    return 0;
}

float pid_calc(pid_t *args,float err)
{
    float sum,d_err;
    d_err = err-args->prev_err;
    args->intergral_err += err*dt;
    if(args->intergral_err>(args->integral_limit)) args->intergral_err = args->integral_limit;
    else if (args->intergral_err<(-1*args->integral_limit)) args->intergral_err = -1*args->integral_limit;
    sum = ((args->kp)*err) + ((args->ki)*args->intergral_err) + ((args->kd)*d_err/dt);
    args->prev_err = err;
    return sum;
}
