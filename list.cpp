#include "stratum.h"

//#define _LIST_DEBUG_

void CommonLock(pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
}

void CommonUnlock(pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
}

CommonList::CommonList()
{
	count = 0;
	yaamp_create_mutex(&mutex);

	first = NULL;
	last = NULL;
}

CommonList::~CommonList()
{
//	DeleteAll(NULL);
}

void CommonList::Enter()
{
	pthread_mutex_lock(&mutex);
}

void CommonList::Leave()
{
	pthread_mutex_unlock(&mutex);
}

CLI CommonList::AddTail(void *data)
{
	Enter();

	CLI item = new COMMONLISTITEM;
	item->data = data;

	count++;

	item->prev = last;
	item->next = NULL;

	last = item;

	if(!first) first = item;
	if(item->prev) item->prev->next = item;

	Leave();
	return item;
}

void CommonList::Delete(CLI item)
{
	Enter();

	if(first == item)
		first = item->next;

	if(last == item)
		last = item->prev;

	if(item->prev) item->prev->next = item->next;
	if(item->next) item->next->prev = item->prev;

	count--;
	delete item;

	Leave();
}

void CommonList::Delete(void *data)
{
	CLI item = Find(data);
	if(item) Delete(item);
}

void CommonList::DeleteAll(LISTFREEPARAM freeparam)
{
	Enter();
	for(CLI li1 = first; li1; )
	{
		CLI tmp = li1;
		li1 = li1->next;

		if(freeparam)
			freeparam(tmp->data);

		delete tmp;
	}
	count = 0;
	Leave();
}

CLI CommonList::Find(void *data)
{
	Enter();
	for(CLI item = first; item; item = item->next)
		if(data == item->data)
		{
			Leave();
			return item;
		}

	Leave();
	return NULL;
}

void CommonList::Swap(CLI i1, CLI i2)
{
//	Enter();
	if(i1->prev) i1->prev->next = i2;
	if(i2->next) i2->next->prev = i1;

	i1->next = i2->next;
	i2->prev = i1->prev;

	i1->prev = i2;
	i2->next = i1;

	if(!i2->prev) first = i2;
	if(!i1->next) last = i1;

//	Leave();
}




