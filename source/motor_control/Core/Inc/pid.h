#ifndef PID_H
#define PID_H
typedef struct pid
{
    float kp;
    float ki;
    float kd;
    float integral_top;
    float integral_bottom;
}pid_t;

float pid_init(pid_t *args,float arg_kp,float arg_ki,float arg_kd,float top,float bottom);

float calc_pid(pid_t *args,float err);

#endif
