#ifndef _PROC_H_
#define _PROC_H_
#include "type.h"
#include "protect.h"

/* 最大进程个数 */
#define NR_TASKS 4
#define NR_PROCS 2
#define NR_TOTAL_PROCS (NR_TASKS+NR_PROCS)

/* 系统进程 */
#define P_TTY       0
#define P_SYSTASK   1
#define P_TASK_HD	2
#define P_TASK_FS   3

/* obj */
#define ANY	(NR_TOTAL_PROCS + 10)
#define INTERRUPT	-10

#define NO_TASK		(NR_TASKS + NR_PROCS + 20)

/* 进程栈大小 */
#define STACK_SIZE 4096

#define proc2pid(x) (x - procTable)
#define pid2proc(x) (&procTable[x])

#if 0
enum msgtype
{
	HARD_INT = 1,

	/* SYS task */
	GET_TICKS = 2,
};
#endif

#define HARD_INT 1
#define GET_TICKS 2

#define DEV_OPEN 1001

struct StackFrame
{
	u32	gs;
	u32	fs;
	u32	es;
	u32	ds;
	u32	edi;
	u32	esi;
	u32	ebp;
	u32	kernelEsp;
	u32	ebx;
	u32	edx;
	u32	ecx;
	u32	eax;
	u32	retaddr;
	u32	eip;
	u32	cs;
	u32	eflags;
	u32	esp;
	u32	ss;
};

/* 进程描述符 */
struct Process
{
	struct StackFrame regs;          /* process registers saved in stack frame */
    char stack[STACK_SIZE];
    int priority;
    int ticks;
	u32 pid;                   /* process id passed in from MM */
	char name[16];           /* name of the process */
    int tty;

    /* IPC */
    int flag;
    int recvfrom;
    int sendto;
    int hasIntMsg;
    struct Message* msg;    /* 暂存消息 */
    struct Process* sending;
    struct Process* nextSending;
};

void schedule();
int ipc(int function, int obj, struct Message* msg);
void informInt(int taskNr);

#endif /* _PROC_H_ */
