/*
** EPITECH PROJECT, 2021
** job
** File description:
** Source code
*/

#ifndef F6968C28_EBA2_47A1_AB21_4CB4A613096E
#define F6968C28_EBA2_47A1_AB21_4CB4A613096E

#include <stdbool.h>
#include <SFML/System.h>

typedef struct job_message {
    int type;
    void *content;
} job_message_t;

typedef struct job {
    sfMutex *mutex;
    sfThread *thread;
    void *data;
    void (*action)(struct job *job);
    unsigned char messages_count;
    job_message_t messages[256];
    bool in_progress;
} job_t;

static inline void start_job(job_t *job)
{
    sfThread_launch(job->thread);
}

static inline void stop_job(job_t *job)
{
    sfThread_terminate(job->thread);
}

static inline void wait_job(job_t *job)
{
    sfThread_wait(job->thread);
}

job_t *create_job(void (*action)(job_t *job), void *data);

void destroy_job(job_t *job);

bool send_job_message(job_t *job, int type, void *content);

void *poll_job_message(job_t *job, int type);

#endif /* F6968C28_EBA2_47A1_AB21_4CB4A613096E */
