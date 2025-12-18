//
// Created by 66 on 2025/12/18.
//

#include "../include/captor.h"

Captor::Captor() {
    av_log_set_level(AV_LOG_ERROR);
}

void Captor::init_context() {
    av_format_context.reset(avformat_alloc_context(), AVFormatContextDeleter());
}
