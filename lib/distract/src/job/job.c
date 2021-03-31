/*
** EPITECH PROJECT, 2021
** job
** File description:
** Source code
*/

#include "distract/job.h"
#include <SFML/System.h>
#include <SFML/System/Mutex.h>
#include <SFML/System/Sleep.h>
#include <SFML/System/Thread.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <distract/util.h>
#include <distract/job.h>
#include <distract/debug.h>

static void run_job(void *raw_job)
{
    job_t *job = raw_job;

    sfMutex_lock(job->mutex);
    job->in_progress = true;
    sfMutex_unlock(job->mutex);
    job->action(job);
    sfMutex_lock(job->mutex);
    job->in_progress = false;
    sfMutex_unlock(job->mutex);
}

job_t *create_job(void (*action)(job_t *job), void *data)
{
    job_t *job = dcalloc(1, sizeof(job_t));

    if (job == NULL)
        return (NULL);
    job->data = data;
    job->action = action;
    job->messages_count = 0;
    job->in_progress = false;
    job->thread = sfThread_create(&run_job, job);
    job->mutex = sfMutex_create();
    if (job->thread == NULL || job->mutex == NULL) {
        free(job);
        return (NULL);
    }
    for (int i = 0; i < 255; i++)
        job->messages[i].type = -1;
    return (job);
}

void destroy_job(job_t *job)
{
    sfThread_destroy(job->thread);
    sfMutex_destroy(job->mutex);
    free(job);
}

bool send_job_message(job_t *job, int type, void *content)
{
    if (content == NULL)
        print_error("Your job message content is NULL! It is error prone!");
    sfMutex_lock(job->mutex);
    if (job->messages_count == 255) {
        sfMutex_unlock(job->mutex);
        return (false);
    }
    job->messages[job->messages_count] = (job_message_t) { type, content };
    job->messages_count++;
    sfMutex_unlock(job->mutex);
    return (true);
}

void *poll_job_message(job_t *job, int type)
{
    int i = 0;
    void *content = NULL;

    sfMutex_lock(job->mutex);
    for (i = 0; i < job->messages_count; i++) {
        if (job->messages[i].type == type)
            break;
    }
    if (i == job->messages_count) {
        sfMutex_unlock(job->mutex);
        return (NULL);
    }
    content = job->messages[i].content;
    for (i++; i < job->messages_count; i++)
        job->messages[i - 1] = job->messages[i];
    job->messages[i - 1] = (job_message_t) {-1, 0};
    job->messages_count--;
    sfMutex_unlock(job->mutex);
    return (content);
}