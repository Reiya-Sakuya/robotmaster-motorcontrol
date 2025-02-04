#include "math.h"
#include "pid.h"
#include "main.h"

float prev_err, intergral_err=0;
extern float dt;

float pid_init(pid_t *args,float arg_kp,float arg_ki,float arg_kd,float top,float bottom)
{
    args->kp = arg_kp;
    args->ki = arg_ki;
    args->kd = arg_kd;
    args->integral_top = top;
    args->integral_bottom = bottom;
    return 0;
}

float calc_pid(pid_t *args,float err)
{
    float sum,d_err;
    d_err = err-prev_err;
    intergral_err += err*dt;
    if(intergral_err>(args->integral_top)) intergral_err = args->integral_top;
    else if (intergral_err<(args->integral_bottom)) intergral_err = args->integral_bottom;
    sum = ((args->kp)*err) + ((args->ki)*intergral_err) + ((args->kd)*d_err/dt);
    prev_err = err;
    return sum;
}
