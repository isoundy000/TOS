#ifndef _IPC_H_
#define _IPC_H_
#include "type.h"
#include "proc.h"

/* function */
#define SEND		1
#define RECEIVE		2
#define BOTH		3	/* BOTH = (SEND | RECEIVE) */

/* flag */
#define SENDING     0x02
#define RECEIVING   0x04

struct mess1
{
	int m1i1;
	int m1i2;
	int m1i3;
	int m1i4;
};

struct mess2
{
	void* m2p1;
	void* m2p2;
	void* m2p3;
	void* m2p4;
};

struct mess3
{
	int	m3i1;
	int	m3i2;
	int	m3i3;
	int	m3i4;
	u64	m3l1;
	u64	m3l2;
	void*	m3p1;
	void*	m3p2;
};

struct Message
{
	int source;
	int type;
	union
    {
		struct mess1 m1;
		struct mess2 m2;
		struct mess3 m3;
	} u;
};

#define	RETVAL		u.m3.m3i1

int sysSendrec(int function, int obj, struct Message* m, struct Process* proc);
int sendrec(int function, int obj, struct Message* m);

void unblock(struct Process* proc);
void block(struct Process* proc);

#endif /* _IPC_H_ */
