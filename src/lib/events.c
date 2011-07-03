/*
 * Copyright (c) 2011 Ignasi Barrera
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "events.h"
#include "message_handler.h"
#include "irc.h"


/* ************************ */
/* Event building functions */
/* ************************ */

ErrorEvent error_event(struct raw_msg *raw) {
    int i;
    ErrorEvent event;

    for (i = 0; i < raw->num_params - 1; i++) {
        event.params[i] = raw->params[i];
    }

    event.code = raw->type;
    event.num_params = i;
    event.message = raw->params[raw->num_params - 1];

    return event;
}

GenericEvent generic_event(struct raw_msg *raw) {
    int i;
    GenericEvent event;

    for (i = 0; i < raw->num_params - 1; i++) {
        event.params[i] = raw->params[i];
    }

    event.code = raw->type;
    event.num_params = i;
    event.message = raw->params[raw->num_params - 1];

    return event;
}

PingEvent ping_event(struct raw_msg *raw) {
    PingEvent event;
    event.server = raw->params[0];
    return event;
}

NickInUseEvent nick_in_use_event(struct raw_msg *raw) {
    NickInUseEvent event;
    event.nick = raw->params[1];
    event.message = raw->params[2];
    return event;
}

NoticeEvent notice_event(struct raw_msg *raw) {
    NoticeEvent event;
    event.to = raw->params[0];
    event.text = raw->params[1];
    return event;
}

JoinEvent join_event(struct raw_msg *raw) {
    JoinEvent event;
    UserInfo ui = user_info(raw->prefix);
    event.user = ui;
    event.channel = raw->params[0];
    return event;
}

PartEvent part_event(struct raw_msg *raw) {
    PartEvent event;
    UserInfo ui = user_info(raw->prefix);
    event.user = ui;
    event.channel = raw->params[0];
    event.message = raw->params[1];
    return event;
}

MessageEvent message_event(struct raw_msg *raw) {
    MessageEvent event;
    UserInfo ui = user_info(raw->prefix);
    event.user = ui;
    event.to = raw->params[0];
    event.message = raw->params[1];
    return event;
}

/* ********************************** */
/* User information utility functions */
/* ********************************** */

UserInfo user_info(char* user_ref) {
    UserInfo ui;
    char* c;

    c = user_ref;
    ui.nick = c;

    while (*c != '!') c++;
    *c = '\0';
    ui.user = c + 2;

    while (*c != '@') c++;
    *c = '\0';
    ui.server = c + 1;

    return ui;
}
